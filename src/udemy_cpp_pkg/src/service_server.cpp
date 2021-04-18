#include "ros/ros.h"
#include "udemy_cpp_pkg/OddEvenCheck.h"

bool determineOddEven(udemy_cpp_pkg::OddEvenCheck::Request& p_req, udemy_cpp_pkg::OddEvenCheck::Response& p_res)
{
  if (p_req.number % 2 == 0)
  {
    p_res.answer = "even";
  }
  else if (p_req.number % 2 > 0)
  {
    p_res.answer = "odd";
  }
  else
  {
    return false;
  }
    return true;
}

int main(int argc, char** argv)
{
  ros::init (argc, argv, "odd_even_service_server_node");
  ros::NodeHandle node_handle;
  ros::ServiceServer service = node_handle.advertiseService("odd_even_check", determineOddEven);
  ROS_INFO("Odd Even Service Running . . . ");
  ros::spin();

  return 0;
}
