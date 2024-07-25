# UrDashboard Bridge

## 소개

ROS2의 ur_robot_driver 기능 중 /dashboard_client 서비스에서 사용할 수 있는 기능들을 MQTT를 통해 사용 가능하도록하는 Node



## 기능

### /dashboard_client의 기능들

[Universal_Robots_Client_Library](https://github.com/UniversalRobots/Universal_Robots_Client_Library)을 이용해 만들어진 서비스. 대부분의 기능들이 들어 있다. 일부 기능은 로봇 상태에 따라 안 보이는 경우가 있음. (아마 Remote 관련 설정 활성화 안 하면 그런 듯)

**서비스 리스트**

| 이름 | 타입 |
| ---- | ---- |
| /dashboard_client/brake_release | std_srvs/srv/Trigger |
| /dashboard_client/clear_operational_mode | std_srvs/srv/Trigger |
| /dashboard_client/close_popup | std_srvs/srv/Trigger |
| /dashboard_client/close_safety_popup | std_srvs/srv/Trigger |
| /dashboard_client/connect | std_srvs/srv/Trigger |
| /dashboard_client/pause | std_srvs/srv/Trigger |
| /dashboard_client/play | std_srvs/srv/Trigger |
| /dashboard_client/power_off | std_srvs/srv/Trigger |
| /dashboard_client/power_on | std_srvs/srv/Trigger |
| /dashboard_client/quit | std_srvs/srv/Trigger |
| /dashboard_client/restart_safety | std_srvs/srv/Trigger |
| /dashboard_client/shutdown | std_srvs/srv/Trigger |
| /dashboard_client/stop | std_srvs/srv/Trigger |
| /dashboard_client/unlock_protective_stop | std_srvs/srv/Trigger |
| /dashboard_client/get_loaded_program | ur_dashboard_msgs/srv/GetLoadedProgram |
| /dashboard_client/get_robot_mode | ur_dashboard_msgs/srv/GetRobotMode |
| /dashboard_client/get_safety_mode | ur_dashboard_msgs/srv/GetSafetyMode |
| /dashboard_client/add_to_log | ur_dashboard_msgs/srv/AddToLog |
| /dashboard_client/load_installation | ur_dashboard_msgs/srv/Load |
| /dashboard_client/load_program | ur_dashboard_msgs/srv/Load |
| /dashboard_client/popup | ur_dashboard_msgs/srv/Popup |
| /dashboard_client/program_running | ur_dashboard_msgs/srv/IsProgramRunning |
| /dashboard_client/program_saved | ur_dashboard_msgs/srv/IsProgramSaved |
| /dashboard_client/program_state | ur_dashboard_msgs/srv/GetProgramState |
| /dashboard_client/raw_request | ur_dashboard_msgs/srv/RawRequest |

#### 서비스 타입

| 이름                                         | 구조                                                         |
| -------------------------------------------- | ------------------------------------------------------------ |
| std_srvs/srv/Trigger                         | ---<br/>bool success   # indicate successful run of triggered service<br/>string message # informational, e.g. for error messages |
| ur_dashboard_msgs/srv/<br />GetLoadedProgram | ---<br/>string answer<br/>string program_name<br/>bool success |
| ur_dashboard_msgs/srv/<br />GetRobotMode     | ---<br/>RobotMode robot_mode<br/>        int8 NO_CONTROLLER=-1<br/>        int8 DISCONNECTED=0<br/>        int8 CONFIRM_SAFETY=1<br/>        int8 BOOTING=2<br/>        int8 POWER_OFF=3<br/>        int8 POWER_ON=4<br/>        int8 IDLE=5<br/>        int8 BACKDRIVE=6<br/>        int8 RUNNING=7<br/>        int8 UPDATING_FIRMWARE=8<br/>        int8 mode<br/>string answer<br/>bool success |
| ur_dashboard_msgs/srv/<br />GetSafetyMode    | ---<br/>SafetyMode safety_mode<br/>        uint8 NORMAL=1<br/>        uint8 REDUCED=2<br/>        uint8 PROTECTIVE_STOP=3<br/>        uint8 RECOVERY=4<br/>        uint8 SAFEGUARD_STOP=5<br/>        uint8 SYSTEM_EMERGENCY_STOP=6<br/>        uint8 ROBOT_EMERGENCY_STOP=7<br/>        uint8 VIOLATION=8<br/>        uint8 FAULT=9<br/>        uint8 VALIDATE_JOINT_ID=10<br/>        uint8 UNDEFINED_SAFETY_MODE=11<br/>        uint8 AUTOMATIC_MODE_SAFEGUARD_STOP=12<br/>        uint8 SYSTEM_THREE_POSITION_ENABLING_STOP=13<br/>        uint8 mode<br/>string answer<br/>bool success |
| ur_dashboard_msgs/srv/<br />AddToLog         | string message<br/>---<br/>string answer<br/>bool success    |
| ur_dashboard_msgs/srv/<br />Load             | string filename<br/>---<br/>string answer<br/>bool success   |
| ur_dashboard_msgs/srv/<br />Popup            | string message<br/>---<br/>string answer<br/>bool success    |
| ur_dashboard_msgs/srv/<br />IsProgramRunning | ---<br/>string answer<br/>bool program_running # is a program running?<br/>bool success # Did the dashboard server call succeed? |
| ur_dashboard_msgs/srv/<br />IsProgramSaved   | ---<br/>string answer<br/>string program_name<br/>bool program_saved # is the current program saved?<br/>bool success # Did the dashboard server call succeed? |
| ur_dashboard_msgs/srv/<br />GetProgramState  | ---<br/>ProgramState state<br/>        string STOPPED=STOPPED<br/>        string PLAYING=PLAYING<br/>        string PAUSED=PAUSED<br/>        string state<br/>string program_name<br/>string answer<br/>bool success |
| ur_dashboard_msgs/srv/<br />RawRequest       | string query<br/>---<br/>string answer                       |

### Node 기능

#### MQTT로 보내는 데이터 구조

1. 토픽 2개

   1. /ur_dshbd_command/command

   2. /ur_dshbd_command/result

2. 인터페이스

   1. command
      1. string command
      2. string data
   2. result
      1. bool success
      2. string answer

3. 데이터

   1. JSON으로 전달한다.

      1. command: 서비스 이름. /dashboard_client/는 제외한 나머지를 사용

      2. data: 타입에서 보내야 하는 내용들 서비스 타입 보내야 하는 데이터 이름을 그대로 사용

      3. 예시

         ```json
         // ur_dashboard_msgs/srv/Popup의 경우 아래와 같음
         {
             "command": "Popup",
             "data": {
                 "message": "This is popup message."
             }
         }
         ```
