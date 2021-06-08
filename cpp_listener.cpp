#include "ros/ros.h"                          // ROS Default Header File
#include "std_msgs/Float64.h"
#include "cppduino/MsgTutorial.h"  // MsgTutorial Message File Header. The header file is automatically created when building the package.
// Message callback function. This is a function is called when a topic
// message named 'ros_tutorial_msg' is received. As an input message,
// the 'MsgTutorial' message of the 'ros_tutorials_topic' package is received.
void msgCallback(const std_msgs::Float64 msg)
{
  ROS_INFO("recieve msg = %f", msg.data);        // Prints the 'data' message
}

int main(int argc, char **argv)                         // Node Main Function
{
  ros::init(argc, argv, "cpp_listener");            // Initializes Node Name

  ros::NodeHandle nh;                                   // Node handle declaration for communication with ROS system

  ros::Subscriber cppduino_sub = nh.subscribe("my_topic", 100, msgCallback);

  // A function for calling a callback function, waiting for a message to be
  // received, and executing a callback function when it is received.
  ros::spin();

  return 0;
}
