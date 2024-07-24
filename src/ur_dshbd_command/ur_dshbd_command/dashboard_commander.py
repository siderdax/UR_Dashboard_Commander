import functools
import time
from typing import List
import rclpy
from rclpy.node import Node, Client
from rclpy import Parameter
from rcl_interfaces.msg import SetParametersResult

from std_msgs.msg import String
from std_srvs.srv import Trigger
from ur_dashboard_msgs import srv as DashboardSrv
from ur_dshbd_msgs.msg import Command, Result

import paho.mqtt.client as mqtt
import threading
import json
from asyncio import Future
import time


class DashboardCommander(Node):
    is_done = False
    mqtt_config = {
        "host": "localhost",
        "port": 1883,
        "command_topic": "urDashboardCommand",
        "result_topic": "urDashboardResult",
    }
    mqttc_thread = None
    service_clients = None

    def __init__(self):
        super().__init__("dashbd_command")
        self.mqttc = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
        self.mqttc.on_connect = self.on_connect
        self.mqttc.on_disconnect = self.on_disconnect
        self.mqttc.on_message = self.on_message
        self.mqttc.on_subscribe = self.on_subscribe
        self.mqttc.on_unsubscribe = self.on_unsubscribe
        self.add_on_set_parameters_callback(self.on_set_parameters)
        self.declare_parameter("mqtt_config.host", "localhost")
        self.declare_parameter("mqtt_config.port", 1883)
        self.declare_parameter("mqtt_config.command_topic", "urDashboardCommand")
        self.declare_parameter("mqtt_config.result_topic", "urDashboardResult")

        self.service_clients = {
            "brake_release": self.create_client(
                Trigger, "/dashboard_client/brake_release"
            ),
            "clear_operational_mode": self.create_client(
                Trigger, "/dashboard_client/clear_operational_mode"
            ),
            "close_popup": self.create_client(Trigger, "/dashboard_client/close_popup"),
            "close_safety_popup": self.create_client(
                Trigger, "/dashboard_client/close_safety_popup"
            ),
            "connect": self.create_client(Trigger, "/dashboard_client/connect"),
            "pause": self.create_client(Trigger, "/dashboard_client/pause"),
            "play": self.create_client(Trigger, "/dashboard_client/play"),
            "power_off": self.create_client(Trigger, "/dashboard_client/power_off"),
            "power_on": self.create_client(Trigger, "/dashboard_client/power_on"),
            "quit": self.create_client(Trigger, "/dashboard_client/quit"),
            "restart_safety": self.create_client(
                Trigger, "/dashboard_client/restart_safety"
            ),
            "shutdown": self.create_client(Trigger, "/dashboard_client/shutdown"),
            "stop": self.create_client(Trigger, "/dashboard_client/stop"),
            "unlock_protective_stop": self.create_client(
                Trigger, "/dashboard_client/unlock_protective_stop"
            ),
            "get_loaded_program": self.create_client(
                DashboardSrv.GetLoadedProgram, "/dashboard_client/get_loaded_program"
            ),
            "get_robot_mode": self.create_client(
                DashboardSrv.GetRobotMode, "/dashboard_client/get_robot_mode"
            ),
            "get_safety_mode": self.create_client(
                DashboardSrv.GetSafetyMode, "/dashboard_client/get_safety_mode"
            ),
            "add_to_log": self.create_client(
                DashboardSrv.AddToLog, "/dashboard_client/add_to_log"
            ),
            "load_installation": self.create_client(
                DashboardSrv.Load, "/dashboard_client/load_installation"
            ),
            "load_program": self.create_client(
                DashboardSrv.Load, "/dashboard_client/load_program"
            ),
            "popup": self.create_client(DashboardSrv.Popup, "/dashboard_client/popup"),
            "program_running": self.create_client(
                DashboardSrv.IsProgramRunning, "/dashboard_client/program_running"
            ),
            "program_saved": self.create_client(
                DashboardSrv.IsProgramSaved, "/dashboard_client/program_saved"
            ),
            "program_state": self.create_client(
                DashboardSrv.GetProgramState, "/dashboard_client/program_state"
            ),
            "raw_request": self.create_client(
                DashboardSrv.RawRequest, "/dashboard_client/raw_request"
            ),
        }

        for key, cli in self.service_clients.items():
            while not cli.wait_for_service(timeout_sec=1.0):
                self.get_logger().info(
                    key + ": service not available, waiting again..."
                )

        self.mqttc_thread = threading.Thread(target=self.mqtt_loop)
        self.mqttc_thread.start()

    def on_set_parameters(self, params: List[Parameter]):
        for param in params:
            config_name = param.name.replace("mqtt_config.", "")
            if (
                config_name in self.mqtt_config
                and self.mqtt_config[config_name] != param.value
            ):
                self.get_logger().info(
                    f"config {config_name} is changed from {self.mqtt_config[config_name]} to {param.value}"
                )
                self.mqtt_config[config_name] = param.value
                self.mqttc.disconnect()

        return SetParametersResult(successful=True)

    def on_subscribe(self, client, userdata, mid, reason_code_list, properties):
        if reason_code_list[0].is_failure:
            self.get_logger().error(
                f"Broker rejected you subscription: {reason_code_list[0]}"
            )
        else:
            self.get_logger().info(
                f"Broker granted the following QoS: {reason_code_list[0].value}"
            )

    def on_unsubscribe(self, client, userdata, mid, reason_code_list, properties):
        if len(reason_code_list) == 0 or not reason_code_list[0].is_failure:
            self.get_logger().debug(
                "unsubscribe succeeded (if SUBACK is received in MQTTv3 it success)"
            )
        else:
            self.get_logger().warn(
                f"Broker replied with failure: {reason_code_list[0]}"
            )
        client.disconnect()

    def on_connect(self, client, userdata, flags, reason_code, properties):
        if reason_code.is_failure:
            self.get_logger().error(
                f"Failed to connect: {reason_code}. loop_forever() will retry connection"
            )
        else:
            topic = self.mqtt_config["command_topic"]
            self.get_logger().debug(f"mqttc connected, subscribe {topic}")
            client.subscribe(topic)

    def on_disconnect(self, client, userdata, flags, reason_code, properties):
        self.get_logger().debug("disconnect mqttc")

    def on_message(self, client, userdata, msg):
        self.get_logger().info(msg.topic + " " + str(msg.payload))
        json_dict = json.loads(msg.payload.decode("utf-8"))
        command = json_dict["command"]

        if command in self.service_clients:
            future = self.send_request(command, json_dict["data"])

            def done(future):
                self.get_logger().info(str(future.result()))
                self.mqttc.publish(
                    self.mqtt_config["result_topic"],
                    json.dumps(future.result()._fields_and_field_types),
                )

            future.add_done_callback(done)

    def create_request(self, cmd, data):
        if cmd == "get_loaded_program":
            return DashboardSrv.GetLoadedProgram.Request()
        elif cmd == "get_robot_mode":
            req = DashboardSrv.GetRobotMode.Request()
            return req
        elif cmd == "get_safety_mode":
            return DashboardSrv.GetSafetyMode.Request()
        elif cmd == "add_to_log":
            req = DashboardSrv.AddToLog.Request()
            req.message = data["message"]
            return req
        elif cmd == "load_installation":
            req = DashboardSrv.Load.Request()
            req.filename = data["filename"]
            return req
        elif cmd == "load_program":
            req = DashboardSrv.Load.Request()
            req.filename = data["filename"]
            return req
        elif cmd == "popup":
            req = DashboardSrv.Popup.Request()
            req.message = data["message"]
            return req
        elif cmd == "program_running":
            return DashboardSrv.IsProgramRunning.Request()
        elif cmd == "program_saved":
            return DashboardSrv.IsProgramSaved.Request()
        elif cmd == "program_state":
            return DashboardSrv.GetProgramState.Request()
        elif cmd == "raw_request":
            req = DashboardSrv.RawRequest.Request()
            req.query = data["query"]
            return req
        else:
            return Trigger.Request()

    def send_request(self, cmd, data) -> Future:
        if not cmd in self.service_clients:
            self.get_logger().error(cmd + " command is not available.")
            return None

        cli = self.service_clients[cmd]
        req = self.create_request(cmd, data)
        return cli.call_async(req)

    def mqtt_loop(self):
        while self.is_done == False:
            try:
                host = self.mqtt_config["host"]
                port = self.mqtt_config["port"]
                self.get_logger().info(f"connect mqttc {host}:{port}")
                self.mqttc.connect(host, port)
                self.mqttc.loop_forever()
                self.get_logger().info(f"disconnected mqttc {host}:{port}")
            except Exception as e:
                pass
            time.sleep(1)


def main():
    rclpy.init()
    dshbd_commander = DashboardCommander()
    rclpy.spin(dshbd_commander)
    dshbd_commander.is_done = True
    dshbd_commander.mqttc.disconnect()
    dshbd_commander.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
