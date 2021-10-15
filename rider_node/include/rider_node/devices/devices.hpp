
#ifndef RIDER_NODE__DEVICES__DEVICES_HPP_
#define RIDER_NODE__DEVICES__DEVICES_HPP_

#include <rclcpp/rclcpp.hpp>

#include <memory>
#include <string>
#include <utility>

#include "rider_node/control_table.hpp"
#include "rider_node/dynamixel_sdk_wrapper.hpp"

namespace robotis
{
namespace rider
{
extern const ControlTable extern_control_table;
namespace devices
{
class Devices
{
public:
  explicit Devices(
    std::shared_ptr<rclcpp::Node> & nh,
    std::shared_ptr<DynamixelSDKWrapper> & dxl_sdk_wrapper)
  : nh_(nh),
    dxl_sdk_wrapper_(dxl_sdk_wrapper)
  {
  }

  virtual void command(const void * request, void * response) = 0;

protected:
  std::shared_ptr<rclcpp::Node> nh_;
  std::shared_ptr<DynamixelSDKWrapper> dxl_sdk_wrapper_;
  rclcpp::QoS qos_ = rclcpp::QoS(rclcpp::ServicesQoS());
};
}  // namespace devices
}  // namespace rider
}  // namespace robotis
#endif  // RIDER_NODE__DEVICES__DEVICES_HPP_
