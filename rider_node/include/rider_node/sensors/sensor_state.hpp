
#ifndef RIDER_NODE__SENSORS__SENSOR_STATE_HPP_
#define RIDER_NODE__SENSORS__SENSOR_STATE_HPP_

#include <turtlebot3_msgs/msg/sensor_state.hpp>

#include <memory>
#include <string>

#include "rider_node/sensors/sensors.hpp"

namespace robotis
{
namespace rider
{
namespace sensors
{
class SensorState : public Sensors
{
public:
  explicit SensorState(
    std::shared_ptr<rclcpp::Node> & nh,
    const std::string & topic_name = "sensor_state",
    const bool & bumper_forward = false,
    const bool & bumper_backward = false,
    const bool & illumination = false,
    const bool & cliff = false,
    const bool & sonar = false);

  void publish(
    const rclcpp::Time & now,
    std::shared_ptr<DynamixelSDKWrapper> & dxl_sdk_wrapper) override;

private:
  rclcpp::Publisher<turtlebot3_msgs::msg::SensorState>::SharedPtr pub_;

  bool bumper_forward_;
  bool bumper_backward_;
  bool illumination_;
  bool cliff_;
  bool sonar_;
};
}  // namespace sensors
}  // namespace rider
}  // namespace robotis
#endif  // RIDER_NODE__SENSORS__SENSOR_STATE_HPP_
