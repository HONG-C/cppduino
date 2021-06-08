#include "ros/ros.h"                            // ROS기본 헤더 파일 
#include "std_msgs/Float64.h"			//토픽 전달을 위한 메시지 헤더 파일 
#include "cppduino/MsgTutorial.h"    // 메시지 헤더파일. 헤더파일은 빌딩 시에 기본으로 생성 

int main(int argc, char **argv)                 // 노드 메인 함수 
{
  ros::init(argc, argv, "cpp_talker");     // 노드 이름 초기화 
  ros::NodeHandle nh;                           //ros와 통신을 위한 노드핸들 선언 

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
