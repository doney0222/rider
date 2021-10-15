"""
Rider state 퍼블리싱

"""

import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    # 라이더 모델 지정
    RIDER_MODEL = os.environ['RIDER_MODEL']

    # time init
    use_sim_time = LaunchConfiguration('use_sim_time', default='false')

    # URDF 지정
    urdf_dir = get_package_share_directory('rider_description')
    urdf_name = 'rider_' + RIDER_MODEL + '.urdf'

    print("urdf_file_name : {}".format(urdf_name))

    urdf = os.path.join(urdf_dir, 'urdf', urdf_name)

    # Major refactor of the robot_state_publisher
    # Reference page: https://github.com/ros2/demos/pull/426
    with open(urdf, 'r') as infp:
        robot_description = infp.read()

    rsp_params = {'robot_description': robot_description}

    # print (robot_description) # Printing urdf information.

    return LaunchDescription([
        DeclareLaunchArgument(
            'use_sim_time',
            default_value='false',
            description='Use simulation (Gazebo) clock if true'),

        # robot state publish
        Node(
            package= 'robot_state_publisher',
            executable= 'robot_state_publisher',
            output= 'screen',
            parameters= [rsp_params, {'use_sim_time': use_sim_time}]),

        Node(
            package= 'joint_state_publisher',
            executable= 'joint_state_publisher',
            output= 'screen',
            parameters= [rsp_params, {'use_sim_time': use_sim_time}]),
    ])
