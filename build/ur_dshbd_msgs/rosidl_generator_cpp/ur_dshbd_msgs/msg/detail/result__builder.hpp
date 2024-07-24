// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ur_dshbd_msgs:msg/Result.idl
// generated code does not contain a copyright notice

#ifndef UR_DSHBD_MSGS__MSG__DETAIL__RESULT__BUILDER_HPP_
#define UR_DSHBD_MSGS__MSG__DETAIL__RESULT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ur_dshbd_msgs/msg/detail/result__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ur_dshbd_msgs
{

namespace msg
{

namespace builder
{

class Init_Result_answer
{
public:
  explicit Init_Result_answer(::ur_dshbd_msgs::msg::Result & msg)
  : msg_(msg)
  {}
  ::ur_dshbd_msgs::msg::Result answer(::ur_dshbd_msgs::msg::Result::_answer_type arg)
  {
    msg_.answer = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ur_dshbd_msgs::msg::Result msg_;
};

class Init_Result_success
{
public:
  Init_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Result_answer success(::ur_dshbd_msgs::msg::Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Result_answer(msg_);
  }

private:
  ::ur_dshbd_msgs::msg::Result msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur_dshbd_msgs::msg::Result>()
{
  return ur_dshbd_msgs::msg::builder::Init_Result_success();
}

}  // namespace ur_dshbd_msgs

#endif  // UR_DSHBD_MSGS__MSG__DETAIL__RESULT__BUILDER_HPP_
