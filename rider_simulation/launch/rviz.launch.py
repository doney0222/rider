"""
설계한 모델을 Rviz와 연동하기

"""

import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    # 라이더 모델 지정
    RIDER_MODEL = os.environ['RIDER_MODEL']

    # URDF 지정
    urdf_dir = get_package_share_directory('rider_description')
    urdf_name = 'rider_' + RIDER_MODEL + '.urdf'
    urdf = os.path.join(urdf_dir, 'urdf', urdf_name)

    # Rviz config 지정
    rviz_config_dir = get_package_share_directory('rider_simulation')
    rviz_config_file = os.path.join(rviz_config_dir, 'rviz', 'simple_config.rviz')

    with open(urdf, 'r') as infp:
        robot_description = infp.read()

    return LaunchDescription([
        # robot_state_publisher
        Node(
            package= 'robot_state_publisher',
            executable= 'robot_state_publisher',
            name= 'robot_state_publisher',
            output= 'screen',
            parameters= [{'robot_description': robot_description}],
            arguments= [urdf]),

        # joint_state_publisher
        Node(
            package= 'joint_state_publisher_gui',
            executable= 'joint_state_publisher_gui',
            name= 'joint_state_publisher_gui',
            output= 'screen',
            parameters= [{'robot_description': robot_description}],
            arguments= [urdf]),

        # rviz2
        Node(
            package= 'rviz2',
            executable= 'rviz2',
            name= 'rviz2',
            output= 'screen',
            arguments= ['-d', rviz_config_file]
            )
    ])

