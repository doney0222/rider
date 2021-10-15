

#ifndef RIDER_NODE__DEVICES__SOUND_HPP_
#define RIDER_NODE__DEVICES__SOUND_HPP_

#include <turtlebot3_msgs/srv/sound.hpp>

#include <memory>
#include <string>

#include "rider_node/devices/devices.hpp"

namespace robotis
{
namespace rider
{
namespace devices
{
class Sound : public Devices
{
public:
  static void request(
    rclcpp::Client<turtlebot3_msgs::srv::Sound>::SharedPtr client,
    turtlebot3_msgs::srv::Sound::Request req);

  explicit Sound(
    std::shared_ptr<rclcpp::Node> & nh,
    std::shared_ptr<DynamixelSDKWrapper> & dxl_sdk_wrapper,
    const std::string & server_name = "sound");

  void command(const void * request, void * response) override;

private:
  rclcpp::Service<turtlebot3_msgs::srv::Sound>::SharedPtr srv_;
};
}  // namespace devices
}  // namespace rider
}  // namespace robotis
#endif  // RIDER_NODE__DEVICES__SOUND_HPP_
