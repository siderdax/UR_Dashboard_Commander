// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ur_dshbd_msgs:msg/Result.idl
// generated code does not contain a copyright notice
#include "ur_dshbd_msgs/msg/detail/result__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `answer`
#include "rosidl_runtime_c/string_functions.h"

bool
ur_dshbd_msgs__msg__Result__init(ur_dshbd_msgs__msg__Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // answer
  if (!rosidl_runtime_c__String__init(&msg->answer)) {
    ur_dshbd_msgs__msg__Result__fini(msg);
    return false;
  }
  return true;
}

void
ur_dshbd_msgs__msg__Result__fini(ur_dshbd_msgs__msg__Result * msg)
{
  if (!msg) {
    return;
  }
  // success
  // answer
  rosidl_runtime_c__String__fini(&msg->answer);
}

bool
ur_dshbd_msgs__msg__Result__are_equal(const ur_dshbd_msgs__msg__Result * lhs, const ur_dshbd_msgs__msg__Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // answer
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->answer), &(rhs->answer)))
  {
    return false;
  }
  return true;
}

bool
ur_dshbd_msgs__msg__Result__copy(
  const ur_dshbd_msgs__msg__Result * input,
  ur_dshbd_msgs__msg__Result * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // answer
  if (!rosidl_runtime_c__String__copy(
      &(input->answer), &(output->answer)))
  {
    return false;
  }
  return true;
}

ur_dshbd_msgs__msg__Result *
ur_dshbd_msgs__msg__Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_dshbd_msgs__msg__Result * msg = (ur_dshbd_msgs__msg__Result *)allocator.allocate(sizeof(ur_dshbd_msgs__msg__Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ur_dshbd_msgs__msg__Result));
  bool success = ur_dshbd_msgs__msg__Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ur_dshbd_msgs__msg__Result__destroy(ur_dshbd_msgs__msg__Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ur_dshbd_msgs__msg__Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ur_dshbd_msgs__msg__Result__Sequence__init(ur_dshbd_msgs__msg__Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_dshbd_msgs__msg__Result * data = NULL;

  if (size) {
    data = (ur_dshbd_msgs__msg__Result *)allocator.zero_allocate(size, sizeof(ur_dshbd_msgs__msg__Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ur_dshbd_msgs__msg__Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ur_dshbd_msgs__msg__Result__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ur_dshbd_msgs__msg__Result__Sequence__fini(ur_dshbd_msgs__msg__Result__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ur_dshbd_msgs__msg__Result__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ur_dshbd_msgs__msg__Result__Sequence *
ur_dshbd_msgs__msg__Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_dshbd_msgs__msg__Result__Sequence * array = (ur_dshbd_msgs__msg__Result__Sequence *)allocator.allocate(sizeof(ur_dshbd_msgs__msg__Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ur_dshbd_msgs__msg__Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ur_dshbd_msgs__msg__Result__Sequence__destroy(ur_dshbd_msgs__msg__Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ur_dshbd_msgs__msg__Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ur_dshbd_msgs__msg__Result__Sequence__are_equal(const ur_dshbd_msgs__msg__Result__Sequence * lhs, const ur_dshbd_msgs__msg__Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ur_dshbd_msgs__msg__Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ur_dshbd_msgs__msg__Result__Sequence__copy(
  const ur_dshbd_msgs__msg__Result__Sequence * input,
  ur_dshbd_msgs__msg__Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ur_dshbd_msgs__msg__Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ur_dshbd_msgs__msg__Result * data =
      (ur_dshbd_msgs__msg__Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ur_dshbd_msgs__msg__Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ur_dshbd_msgs__msg__Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ur_dshbd_msgs__msg__Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
