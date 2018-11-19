#include "ros/ros.h"
#include "std_msgs/Int16.h"

#include <iostream>
//#include <sstream>

using namespace std;

int main(int argc, char **argv) {

  	ros::init(argc, argv, "esc_talker");
	ros::NodeHandle n;
	// Portside is left-hand side
	ros::Publisher chatter_pub = n.advertise<std_msgs::Int16>("portside_stern_thruster", 1000);
  	ros::Rate loop_rate(10);

  	while (ros::ok()) {
    		std_msgs::Int16 msg;
		int speed;

		while(1){
			cout << "Enter 0 to quit" << endl;
			cout << "Enter desired motor speed [500 - 2500]: ";
			cin >> speed;
			msg.data = speed; 
			chatter_pub.publish(msg);
			ros::spinOnce();
			if(speed == 0){
				cout << endl << "Ending program" << endl << endl;
				exit(0);
			}
		}
  	}

  	return 0;
}