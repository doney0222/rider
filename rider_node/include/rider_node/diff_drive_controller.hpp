
#ifndef RIDER_NODE__DIFF_DRIVE_CONTROLLER_HPP_
#define RIDER_NODE__DIFF_DRIVE_CONTROLLER_HPP_

#include <rclcpp/rclcpp.hpp>

#include <memory>

#include "rider_node/odometry.hpp"

namespace robotis
{
namespace rider
{
class DiffDriveController : public rclcpp::Node
{
public:
  explicit DiffDriveController(const float wheel_seperation, const float wheel_radius);
  virtual ~DiffDriveController() {}

private:
  std::shared_ptr<rclcpp::Node> nh_;
  std::unique_ptr<Odometry> odometry_;
};
}  // namespace rider
}  // namespace robotis
#endif  // RIDER_NODE__DIFF_DRIVE_CONTROLLER_HPP_
