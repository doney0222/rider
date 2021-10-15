
#include "rider_node/devices/sound.hpp"

#include <memory>
#include <string>

using robotis::rider::devices::Sound;

Sound::Sound(
  std::shared_ptr<rclcpp::Node> & nh,
  std::shared_ptr<DynamixelSDKWrapper> & dxl_sdk_wrapper,
  const std::string & server_name)
: Devices(nh, dxl_sdk_wrapper)
{
  RCLCPP_INFO(nh_->get_logger(), "Succeeded to create sound server");
  srv_ = nh_->create_service<turtlebot3_msgs::srv::Sound>(
    server_name,
    [this](
      const std::shared_ptr<turtlebot3_msgs::srv::Sound::Request> request,
      std::shared_ptr<turtlebot3_msgs::srv::Sound::Response> response) -> void
    {
      this->command(static_cast<void *>(request.get()), static_cast<void *>(response.get()));
    }
  );
}

void Sound::command(const void * request, void * response)
{
  turtlebot3_msgs::srv::Sound::Request req = *(turtlebot3_msgs::srv::Sound::Request *)request;
  turtlebot3_msgs::srv::Sound::Response * res = (turtlebot3_msgs::srv::Sound::Response *)response;

  res->success = dxl_sdk_wrapper_->set_data_to_device(
    extern_control_table.sound.addr,
    extern_control_table.sound.length,
    reinterpret_cast<uint8_t *>(&req.value),
    &res->message);
}

void Sound::request(
  rclcpp::Client<turtlebot3_msgs::srv::Sound>::SharedPtr client,
  turtlebot3_msgs::srv::Sound::Request req)
{
  auto request = std::make_shared<turtlebot3_msgs::srv::Sound::Request>(req);
  auto result = client->async_send_request(request);
}
