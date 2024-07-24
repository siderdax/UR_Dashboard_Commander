// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ur_dshbd_msgs:msg/Result.idl
// generated code does not contain a copyright notice

#ifndef UR_DSHBD_MSGS__MSG__DETAIL__RESULT__TRAITS_HPP_
#define UR_DSHBD_MSGS__MSG__DETAIL__RESULT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ur_dshbd_msgs/msg/detail/result__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ur_dshbd_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: answer
  {
    out << "answer: ";
    rosidl_generator_traits::value_to_yaml(msg.answer, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: answer
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "answer: ";
    rosidl_generator_traits::value_to_yaml(msg.answer, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace ur_dshbd_msgs

namespace rosidl_generator_traits
{

[[deprecated("use ur_dshbd_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ur_dshbd_msgs::msg::Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  ur_dshbd_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ur_dshbd_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ur_dshbd_msgs::msg::Result & msg)
{
  return ur_dshbd_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ur_dshbd_msgs::msg::Result>()
{
  return "ur_dshbd_msgs::msg::Result";
}

template<>
inline const char * name<ur_dshbd_msgs::msg::Result>()
{
  return "ur_dshbd_msgs/msg/Result";
}

template<>
struct has_fixed_size<ur_dshbd_msgs::msg::Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ur_dshbd_msgs::msg::Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ur_dshbd_msgs::msg::Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UR_DSHBD_MSGS__MSG__DETAIL__RESULT__TRAITS_HPP_
