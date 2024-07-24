import sys

from ur_dashboard_msgs.srv import Popup
import rclpy
from rclpy.node import Node


class MinimalClientAsync(Node):

    def __init__(self):
        super().__init__("minimal_client_async")
        self.cli = self.create_client(Popup, "/dashboard_client/popup")
        while not self.cli.wait_for_service(timeout_sec=3.0):
            self.get_logger().info("service not available, waiting again...")
        self.req = Popup.Request()

    def send_request(self, a):
        self.req.message = a
        return self.cli.call_async(self.req)


def main():
    rclpy.init()

    minimal_client = MinimalClientAsync()
    future = minimal_client.send_request("Test")
    rclpy.spin_until_future_complete(minimal_client, future)
    response = future.result()
    minimal_client.get_logger().info(
        "Result of /dashboard_client/popup: %s" % (str(response))
    )

    minimal_client.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
