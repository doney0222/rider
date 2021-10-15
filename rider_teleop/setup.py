from setuptools import setup
from setuptools import find_packages

package_name = 'rider_teleop'

setup(
    name=package_name,
    version='0.0.2',
    packages=find_packages(exclude=[]),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Sung',
    maintainer_email='doney0222@naver.com',
    description='ROS 2 Project : rider_teleop',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'teleop_keyboard = rider_teleop.script.teleop_keyboard:main'
        ],
    },
)
