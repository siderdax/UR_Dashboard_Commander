// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ur_dshbd_msgs:msg/Result.idl
// generated code does not contain a copyright notice

#ifndef UR_DSHBD_MSGS__MSG__DETAIL__RESULT__STRUCT_H_
#define UR_DSHBD_MSGS__MSG__DETAIL__RESULT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'answer'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Result in the package ur_dshbd_msgs.
typedef struct ur_dshbd_msgs__msg__Result
{
  bool success;
  rosidl_runtime_c__String answer;
} ur_dshbd_msgs__msg__Result;

// Struct for a sequence of ur_dshbd_msgs__msg__Result.
typedef struct ur_dshbd_msgs__msg__Result__Sequence
{
  ur_dshbd_msgs__msg__Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ur_dshbd_msgs__msg__Result__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UR_DSHBD_MSGS__MSG__DETAIL__RESULT__STRUCT_H_
