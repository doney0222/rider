

#ifndef RIDER_NODE__SENSORS__BATTERY_STATE_HPP_
#define RIDER_NODE__SENSORS__BATTERY_STATE_HPP_

#include <sensor_msgs/msg/battery_state.hpp>

#include <memory>
#include <string>

#include "rider_node/sensors/sensors.hpp"

namespace robotis
{
namespace rider
{
namespace sensors
{
class BatteryState : public Sensors
{
public:
  explicit BatteryState(
    std::shared_ptr<rclcpp::Node> & nh,
    const std::string & topic_name = "battery_state");

  void publish(
    const rclcpp::Time & now,
    std::shared_ptr<DynamixelSDKWrapper> & dxl_sdk_wrapper) override;

private:
  rclcpp::Publisher<sensor_msgs::msg::BatteryState>::SharedPtr pub_;
};
}  // namespace sensors
}  // namespace rider
}  // namespace robotis
#endif  // RIDER_NODE__SENSORS__BATTERY_STATE_HPP_
