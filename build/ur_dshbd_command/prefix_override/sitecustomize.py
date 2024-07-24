import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/root/Project/ros_ur_dashboard2mqtt/install/ur_dshbd_command'
