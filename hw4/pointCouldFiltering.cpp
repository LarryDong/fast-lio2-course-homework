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
    pcl::PointCloud<pcl::PointXYZ> pc, pc_out, pc_out2;
    pcl::fromROSMsg(*cloud_msg, pc);
    ROS_INFO_STREAM("Input cloud size: " << pc.points.size());

    pcl::VoxelGrid<pcl::PointXYZ> dsFilter;
    dsFilter.setLeafSize(0.1,0.1,0.1);
    dsFilter.setInputCloud(pc.makeShared());
    dsFilter.filter(pc_out);
    ROS_INFO_STREAM("Downsize filter: " << pc_out.points.size());

    for(auto p : pc_out.points){
        if(abs(p.x) < 3)
          pc_out2.points.push_back(p);
    }
    ROS_INFO_STREAM("Remove x>3 : " << pc_out2.points.size());

    // publish 
    sensor_msgs::PointCloud2 pc_msg;
    pcl::toROSMsg(pc_out2, pc_msg);
    pc_msg.header = cloud_msg->header;
    downsampled_pub.publish(pc_msg);
    // --------- 结束你的代码	---------------//
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "point_cloud_processing");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("/livox/lidar", 1, pointCloudCallback);
  downsampled_pub = nh.advertise<sensor_msgs::PointCloud2>("/downsampled/cloud", 1);

  ros::spin();

  return 0;
}
