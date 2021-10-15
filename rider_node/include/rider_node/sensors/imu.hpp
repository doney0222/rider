

#ifndef RIDER_NODE__SENSORS__IMU_HPP_
#define RIDER_NODE__SENSORS__IMU_HPP_

#include <sensor_msgs/msg/imu.hpp>
#include <sensor_msgs/msg/magnetic_field.hpp>

#include <memory>
#include <string>

#include "rider_node/sensors/sensors.hpp"

namespace robotis
{
namespace rider
{
namespace sensors
{
class Imu : public Sensors
{
public:
  explicit Imu(
    std::shared_ptr<rclcpp::Node> & nh,
    const std::string & imu_topic_name = "imu",
    const std::string & mag_topic_name = "magnetic_field",
    const std::string & frame_id = "imu_link");

  void publish(
    const rclcpp::Time & now,
    std::shared_ptr<DynamixelSDKWrapper> & dxl_sdk_wrapper) override;

private:
  rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr imu_pub_;
  rclcpp::Publisher<sensor_msgs::msg::MagneticField>::SharedPtr mag_pub_;
};
}  // namespace sensors
}  // namespace rider
}  // namespace robotis
#endif  // RIDER_NODE__SENSORS__IMU_HPP_
