#include "ros/ros.h"
#include "std_msgs/Int16.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "esc_lib.h"

int rec = 0;

void chatterCallback(const std_msgs::Int16::ConstPtr& msg) 
{
	rec = msg->data;
	std::cout << "rec: " << rec << std::endl;
}

int main(int argc, char** argv){

	ros::init(argc, argv, "esc_interface");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("portside_stern_thruster", 1000, chatterCallback);

	int esc_left_pin = 17;
	esc_lib esc_left(esc_left_pin);

	int pre_rec = 0;
	bool run = true;
	while(ros::ok() && run) {

		if(pre_rec != rec)
		{
			esc_left.setSpeed(rec);
			std::cout << "Speed: " << rec << std::endl;
			if(rec == 0)
			{
				break;
			}
			pre_rec = rec; 
		}
		ros::spinOnce(); 
	}

	esc_left.end();
	return 0;
}
