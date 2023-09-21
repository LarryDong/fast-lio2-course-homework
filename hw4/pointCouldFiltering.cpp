#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/passthrough.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/visualization/pcl_visualizer.h>

ros::Publisher downsampled_pub;
void pointCloudCallback(const sensor_msgs::PointCloud2ConstPtr& cloud_msg)
{
    // --------- 开始你的代码	---------------//




    
    // --------- 结束你的代码	---------------//
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "point_cloud_processing");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("/rslidar_points", 1, pointCloudCallback);
  downsampled_pub = nh.advertise<sensor_msgs::PointCloud2>("/downsampled/cloud", 1);

  ros::spin();

  return 0;
}
