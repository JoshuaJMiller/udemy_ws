#include "ros/ros.h"
#include "udemy_cpp_pkg/OddEvenCheck.h"
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "odd_even_service_client_node");
  ros::NodeHandle node_handle;
  ros::ServiceClient client = node_handle.serviceClient<udemy_cpp_pkg::OddEvenCheck>("odd_even_check");
  udemy_cpp_pkg::OddEvenCheck odd_even_check_srv;

  std::cout << "Enter 0 to quit" << std::endl;

  int input;

  while (ros::ok())
  {
    std::cout << "Enter integer to check >";
    std::cin >> input;
    odd_even_check_srv.request.number = input;

    if (input == 0)
    {
      ROS_INFO("input 0, exiting application . . .");
      return 0;
    }

    if (client.call(odd_even_check_srv))
    {
      std::string response;
      response = odd_even_check_srv.response.answer;
      std::cout << "the number is " << response << std::endl;
    }
    else
    {
      ROS_ERROR("service call failed");
      return 1;
    }

    std::cin.clear();

  }

  return 0;
}
