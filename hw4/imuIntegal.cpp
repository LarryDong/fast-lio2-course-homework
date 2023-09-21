#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include "sophus/so3.h"

Eigen::Vector3d pos = Eigen::Vector3d(0,0,0);
Sophus::SO3     rot = Sophus::SO3(Eigen::Matrix3d::Identity());
Eigen::Vector3d vel = Eigen::Vector3d(0,0,0);
Eigen::Vector3d bg = Eigen::Vector3d(0,0,0);
Eigen::Vector3d ba = Eigen::Vector3d(0,0,0);
Eigen::Vector3d grav = Eigen::Vector3d(0,0,-9.8);
double last_timeStamp;
bool first_imu = true;

void imuCallback(const sensor_msgs::Imu::ConstPtr &msg_in)
{
  //------------- 开始你的代码 --------------------//





  //------------- 结束你的代码 --------------------//
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "imu_integal");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("/imu/data", 10000, imuCallback);
  ros::spin();

  return 0;
}
