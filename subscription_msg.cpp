// Copyright (c) 2017 Intel Corporation. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <map>
#include <functional>

#include "rclcpp/rclcpp.hpp"
#include "rcutils/cmdline_parser.h"

#include "builtin_interfaces/msg/time.hpp"
#include "std_msgs/msg/bool.hpp"
#include "std_msgs/msg/byte.hpp"
#include "std_msgs/msg/char.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/int8.hpp"
#include "std_msgs/msg/u_int8.hpp"
#include "std_msgs/msg/int16.hpp"
#include "std_msgs/msg/u_int16.hpp"
#include "std_msgs/msg/int32.hpp"
#include "std_msgs/msg/u_int32.hpp"
#include "std_msgs/msg/int64.hpp"
#include "std_msgs/msg/u_int64.hpp"
#include "std_msgs/msg/float32.hpp"
#include "std_msgs/msg/float64.hpp"
#include "std_msgs/msg/color_rgba.hpp"
#include "std_msgs/msg/byte_multi_array.hpp"
#include "std_msgs/msg/header.hpp"
#include "sensor_msgs/msg/joint_state.hpp"

rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr bool_pub = nullptr;
rclcpp::Publisher<std_msgs::msg::Byte>::SharedPtr byte_pub = nullptr;
rclcpp::Publisher<std_msgs::msg::Char>::SharedPtr char_pub = nullptr;
rclcpp::Publisher<std_msgs::msg::String>::SharedPtr str_pub = nullptr;
rclcpp::Publisher<std_msgs::msg::Int8>::SharedPtr int8_pub = nullptr;
rclcpp::Publisher<std_msgs::msg::UInt8>::SharedPtr uint8_pub = nullptr;
rclcpp::Publisher<std_msgs::msg::Int16>::SharedPtr int16_pub = nullptr;
rclcpp::Publisher<std_msgs::msg::UInt16>::SharedPtr uint16_pub = nullptr;
rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr int32_pub = nullptr;
rclcpp::Publisher<std_msgs::msg::UInt32>::SharedPtr uint32_pub = nullptr;
rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr int64_pub = nullptr;
rclcpp::Publisher<std_msgs::msg::UInt64>::SharedPtr uint64_pub = nullptr;
rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr float32_pub = nullptr;
rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr float64_pub = nullptr;
rclcpp::Publisher<std_msgs::msg::ColorRGBA>::SharedPtr color_pub = nullptr;
rclcpp::Publisher<std_msgs::msg::ByteMultiArray>::SharedPtr array_pub = nullptr;
rclcpp::Publisher<std_msgs::msg::Header>::SharedPtr header_pub  = nullptr;
rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr jointstate_pub = nullptr;

auto node = rclcpp::Node::make_shared("cpp_subscription");

template <typename U, typename T>
void callback(const T msg) {
  // if (bool_pub)
  //   bool_pub->publish(msg);
  auto pub = node->create_publisher<U>(
    std::string("back_") + std::string("Bool_js_cpp_channel"));
  pub->publish(msg);
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  // Bool
  // bool_pub = node->create_publisher<std_msgs::msg::Bool>(
  //   std::string("back_") + std::string("Bool_js_cpp_channel"), rmw_qos_profile_default);
  using namespace std::placeholders;
  // auto cpp_subscription = std::bind(callback, _1, node);

  auto bool_sub = node->create_subscription<std_msgs::msg::Bool>(std::string("Bool_js_cpp_channel"),
    callback<std_msgs::msg::Bool, std_msgs::msg::Bool::SharedPtr>);
  
  // Byte

  // auto byte_sub = node->create_subscription<std_msgs::msg::Byte>(std::string("Byte_js_cpp_channel"),
  //   chatterCallback<std_msgs::msg::Byte::SharedPtr>, rmw_qos_profile_default);

  // // Char
  // auto char_sub = node->create_subscription<std_msgs::msg::Char>(std::string("Char_js_cpp_channel"),
  //   chatterCallback<std_msgs::msg::Char::SharedPtr>, rmw_qos_profile_default);

  // // String
  // auto string_sub = node->create_subscription<std_msgs::msg::String>(std::string("String_js_cpp_channel"),
  //   chatterCallback<std_msgs::msg::String::SharedPtr>, rmw_qos_profile_default);

  // // Int8
  // auto int8_sub = node->create_subscription<std_msgs::msg::Int8>(std::string("Int8_js_cpp_channel"),
  //   chatterIntCastCallback<std_msgs::msg::Int8::SharedPtr>, rmw_qos_profile_default);    

  // // UInt8
  // auto uint8_sub = node->create_subscription<std_msgs::msg::UInt8>(std::string("UInt8_js_cpp_channel"),
  //   chatterIntCastCallback<std_msgs::msg::UInt8::SharedPtr>, rmw_qos_profile_default);

  // // Int16
  // auto int16_sub = node->create_subscription<std_msgs::msg::Int16>(std::string("Int16_js_cpp_channel"),
  // chatterHexCallback<std_msgs::msg::Int16::SharedPtr>, rmw_qos_profile_default);

  // // UInt16
  // auto uint16_sub = node->create_subscription<std_msgs::msg::UInt16>(std::string("UInt16_js_cpp_channel"),
  // chatterHexCallback<std_msgs::msg::UInt16::SharedPtr>, rmw_qos_profile_default);
  
  // // Int32
  // auto int32_sub = node->create_subscription<std_msgs::msg::Int32>(std::string("Int32_js_cpp_channel"),
  // chatterHexCallback<std_msgs::msg::Int32::SharedPtr>, rmw_qos_profile_default);

  // // UInt32
  // auto uint32_sub = node->create_subscription<std_msgs::msg::UInt32>(std::string("UInt32_js_cpp_channel"),
  // chatterHexCallback<std_msgs::msg::UInt32::SharedPtr>, rmw_qos_profile_default);
  
  // // Int64
  // auto int64_sub = node->create_subscription<std_msgs::msg::Int64>(std::string("Int64_js_cpp_channel"),
  // chatterHexCallback<std_msgs::msg::Int64::SharedPtr>, rmw_qos_profile_default);

  // // UInt64
  // auto uint64_sub = node->create_subscription<std_msgs::msg::UInt64>(std::string("UInt64_js_cpp_channel"),
  // chatterHexCallback<std_msgs::msg::UInt64::SharedPtr>, rmw_qos_profile_default);

  // // Float32
  // auto float32_sub = node->create_subscription<std_msgs::msg::Float32>(std::string("Float32_js_cpp_channel"),
  // chatterCallback<std_msgs::msg::Float32::SharedPtr>, rmw_qos_profile_default);

  // // UInt64
  // auto float64_sub = node->create_subscription<std_msgs::msg::Float64>(std::string("Float64_js_cpp_channel"),
  // chatterPrecisionCallback, rmw_qos_profile_default);
  
  // // ColorRGBA
  // auto colorrgba_sub = node->create_subscription<std_msgs::msg::ColorRGBA>(std::string("ColorRGBA_js_cpp_channel"),
  //   chatterColorRGBACallback, rmw_qos_profile_default);
  
  // // Array
  // auto array_sub = node->create_subscription<std_msgs::msg::ByteMultiArray>(std::string("Array_js_cpp_channel"),
  //   chatterArrayCallback, rmw_qos_profile_default);

  // // Header
  // auto header_sub = node->create_subscription<std_msgs::msg::Header>(std::string("Header_js_cpp_channel"),
  //   chatterHeaderCallBack, rmw_qos_profile_default);

  // // Complex object: JointState
  // auto jointstate_sub = node->create_subscription<sensor_msgs::msg::JointState>(std::string("JointState_js_cpp_channel"),
  //   chatterJointStateCallback, rmw_qos_profile_default);

  rclcpp::spin(node);

  return 0;
}
