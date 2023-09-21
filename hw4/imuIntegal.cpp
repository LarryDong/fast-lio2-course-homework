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
  double dt = 1.0/200;    // IMU frequency is 200Hz;
  #define G 9.8
  ROS_INFO("Receive IMU");
  double ax, ay, az;
  double wx, wy, wz;
  ax = msg_in->linear_acceleration.x*G;         // livox IMU is normalized.
  ay = msg_in->linear_acceleration.y*G;
  az = msg_in->linear_acceleration.z*G;

  wx = msg_in->angular_velocity.x;
  wy = msg_in->angular_velocity.y;
  wz = msg_in->angular_velocity.z;
 
  ROS_INFO_STREAM("IMU data: acc:[ " << ax << ", " << ay << ", " << az << "], gyro: [" << wx << ", " << wy << ", " << wz << "]. ");

  Sophus::Vector3d w(wx, wy, wz);
  Sophus::Vector3d a(ax, ay, az);
  
  pos = pos + vel*dt;
  vel = vel + rot*((a-ba)+grav)*dt;
  rot = rot * Sophus::SO3::exp((w-bg)*dt);
  ROS_INFO_STREAM("IMU update: R(t+dt): " << rot <<" \n  v: " << vel.transpose() <<" \n  p: " << pos.transpose());

  //------------- 结束你的代码 --------------------//
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "imu_integal");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("/livox/imu", 10000, imuCallback);
  ros::spin();

  return 0;
}
