

#ifndef RIDER_NODE__DEVICES__RESET_HPP_
#define RIDER_NODE__DEVICES__RESET_HPP_

#include <std_srvs/srv/trigger.hpp>

#include <memory>
#include <string>

#include "rider_node/devices/devices.hpp"

namespace robotis
{
namespace rider
{
namespace devices
{
class Reset : public Devices
{
public:
  static void request(
    rclcpp::Client<std_srvs::srv::Trigger>::SharedPtr client,
    std_srvs::srv::Trigger::Request req);

  explicit Reset(
    std::shared_ptr<rclcpp::Node> & nh,
    std::shared_ptr<DynamixelSDKWrapper> & dxl_sdk_wrapper,
    const std::string & server_name = "reset");

  void command(const void * request, void * response) override;

private:
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr srv_;
};
}  // namespace devices
}  // namespace rider
}  // namespace robotis
#endif  // RIDER_NODE__DEVICES__RESET_HPP_
