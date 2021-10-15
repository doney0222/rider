from setuptools import setup
from glob import glob
import os

package_name = 'rider_bringup'

setup(
    name=package_name,
    version='0.0.2',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.py')),
        (os.path.join('share', package_name, 'param'), glob('param/*.yaml')),
        (os.path.join('share', package_name, 'script'), glob('script/*')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Sung',
    maintainer_email='doney0222@naver.com',
    description='ROS 2 Project : rider_bringup',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        ],
    },
)
