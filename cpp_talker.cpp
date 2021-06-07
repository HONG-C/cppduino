#include "ros/ros.h"                            // ROS Default Header File
#include "std_msgs/Float64.h"
#include "cppduino/MsgTutorial.h"    // MsgTutorial Message File Header. The header file is automatically created when building the package.

int main(int argc, char **argv)                 // Node Main Function
{
  ros::init(argc, argv, "cpp_talker");     // Initializes Node Name
  ros::NodeHandle nh;                           // Node handle declaration for communication with ROS system

  // Declare publisher, create publisher 'ros_tutorial_pub' using the 'MsgTutorial'
  // message file from the 'ros_tutorials_topic' package. The topic name is
  // 'ros_tutorial_msg' and the size of the publisher queue is set to 100.
  ros::Publisher cppduino_pub = nh.advertise<std_msgs::Float64>("your_topic", 100);

  // Set the loop period. '10' refers to 10 Hz and the main loop repeats at 0.1 second intervals
  ros::Rate loop_rate(10);

  std_msgs::Float64 msg;
  float count = 11.23;                            // Variable to be used in message

  while (ros::ok())
  {

    msg.data  = count;                      // Save the the 'count' value in the data of 'msg'


    ROS_INFO("send msg = %f", msg.data);        // Prints the 'data' message

    cppduino_pub.publish(msg);          // Publishes 'msg' message

    loop_rate.sleep();                      // Goes to sleep according to the loop rate defined above.

  }

  return 0;
}
