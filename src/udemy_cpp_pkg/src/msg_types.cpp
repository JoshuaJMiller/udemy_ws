#include <iostream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"
#include "std_msgs/Float64.h"

int main()
{

  std_msgs::String myString;
  myString.data = "Ricky";

  for (size_t i{0}; i < 10; ++i)
  {
    std::cout << myString;
  }

  std_msgs::Bool myBool;
  myBool.data = true;

  std::cout << std::boolalpha;

  for (size_t i{0}; i < 10; ++i)
  {
    std::cout << myBool;
  }

  return 0;
}
