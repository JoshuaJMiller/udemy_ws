#include "ros/ros.h"
#include "std_msgs/Float32.h"

float wheelDiam;

ros::Publisher speed_pub;

void subCallback(const std_msgs::Float32::ConstPtr& p_msg)
{

  ros::NodeHandle callback_node_handle;
  if (callback_node_handle.getParam("wheel_radius", wheelDiam))
  {
    float rpm = p_msg->data;
    float circumf = wheelDiam * 3.14159;
    std_msgs::Float32 speed;
    speed.data = rpm * circumf;

    speed_pub.publish(speed);
  }
  else
  {
    ROS_WARN("Parameter wheel_radius does not exist");
  }

}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "speed_sub_node");

  ros::NodeHandle node_handle;

  speed_pub = node_handle.advertise<std_msgs::Float32>("speed", 10);

  ros::Subscriber rpm_sub = node_handle.subscribe("rpm", 10, subCallback);

  ros::spin();

  return 0;
}
