#include "ros/ros.h"
#include "std_msgs/String.h"

void subCallback(const std_msgs::StringConstPtr& p_msg)
{
  std::string msgString = p_msg->data;
  ROS_INFO("%s", msgString.c_str());
}

int main(int argc, char** argv)
{

  ros::init(argc, argv, "hello_world_sub_node");
  ros::NodeHandle node_handle;

  ros::Subscriber hello_world_sub = node_handle.subscribe("hello_world", 10, subCallback);

  ros::spin();

  return 0;
}
