// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ur_dshbd_msgs:msg/Command.idl
// generated code does not contain a copyright notice

#ifndef UR_DSHBD_MSGS__MSG__DETAIL__COMMAND__BUILDER_HPP_
#define UR_DSHBD_MSGS__MSG__DETAIL__COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ur_dshbd_msgs/msg/detail/command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ur_dshbd_msgs
{

namespace msg
{

namespace builder
{

class Init_Command_data
{
public:
  explicit Init_Command_data(::ur_dshbd_msgs::msg::Command & msg)
  : msg_(msg)
  {}
  ::ur_dshbd_msgs::msg::Command data(::ur_dshbd_msgs::msg::Command::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ur_dshbd_msgs::msg::Command msg_;
};

class Init_Command_command
{
public:
  Init_Command_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Command_data command(::ur_dshbd_msgs::msg::Command::_command_type arg)
  {
    msg_.command = std::move(arg);
    return Init_Command_data(msg_);
  }

private:
  ::ur_dshbd_msgs::msg::Command msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur_dshbd_msgs::msg::Command>()
{
  return ur_dshbd_msgs::msg::builder::Init_Command_command();
}

}  // namespace ur_dshbd_msgs

#endif  // UR_DSHBD_MSGS__MSG__DETAIL__COMMAND__BUILDER_HPP_
