// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ur_dshbd_msgs:msg/Result.idl
// generated code does not contain a copyright notice

#ifndef UR_DSHBD_MSGS__MSG__DETAIL__RESULT__STRUCT_HPP_
#define UR_DSHBD_MSGS__MSG__DETAIL__RESULT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ur_dshbd_msgs__msg__Result __attribute__((deprecated))
#else
# define DEPRECATED__ur_dshbd_msgs__msg__Result __declspec(deprecated)
#endif

namespace ur_dshbd_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Result_
{
  using Type = Result_<ContainerAllocator>;

  explicit Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->answer = "";
    }
  }

  explicit Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : answer(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->answer = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _answer_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _answer_type answer;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__answer(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->answer = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ur_dshbd_msgs::msg::Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const ur_dshbd_msgs::msg::Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ur_dshbd_msgs::msg::Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ur_dshbd_msgs::msg::Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ur_dshbd_msgs::msg::Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ur_dshbd_msgs::msg::Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ur_dshbd_msgs::msg::Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ur_dshbd_msgs::msg::Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ur_dshbd_msgs::msg::Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ur_dshbd_msgs::msg::Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ur_dshbd_msgs__msg__Result
    std::shared_ptr<ur_dshbd_msgs::msg::Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ur_dshbd_msgs__msg__Result
    std::shared_ptr<ur_dshbd_msgs::msg::Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Result_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->answer != other.answer) {
      return false;
    }
    return true;
  }
  bool operator!=(const Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Result_

// alias to use template instance with default allocator
using Result =
  ur_dshbd_msgs::msg::Result_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ur_dshbd_msgs

#endif  // UR_DSHBD_MSGS__MSG__DETAIL__RESULT__STRUCT_HPP_
