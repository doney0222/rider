
#ifndef RIDER_NODE__DEVICES__MOTOR_POWER_HPP_
#define RIDER_NODE__DEVICES__MOTOR_POWER_HPP_

#include <std_srvs/srv/set_bool.hpp>

#include <memory>
#include <string>

#include "rider_node/devices/devices.hpp"

namespace robotis
{
namespace rider
{
namespace devices
{
class MotorPower : public Devices
{
public:
  static void request(
    rclcpp::Client<std_srvs::srv::SetBool>::SharedPtr client,
    std_srvs::srv::SetBool::Request req);

  explicit MotorPower(
    std::shared_ptr<rclcpp::Node> & nh,
    std::shared_ptr<DynamixelSDKWrapper> & dxl_sdk_wrapper,
    const std::string & server_name = "motor_power");

  void command(const void * request, void * response) override;

private:
  rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr srv_;
};
}  // namespace devices
}  // namespace rider
}  // namespace robotis
#endif  // RIDER_NODE__DEVICES__MOTOR_POWER_HPP_
