#include <unistd.h>
#include <iostream>
#include <string.h>
#include "esc_lib.h"


int main() 
{
	std::cout << "ESC test initiated" << std::endl;
	int left_esc_pin = 17;
	int right_esc_pin = 27;

	esc_lib esc_left(left_esc_pin);
	esc_lib esc_right(right_esc_pin);
	
	char input = ' ';
	int speed_left = 0;
	int speed_right = 0;
	double increment = 100;
	bool run = true;
	while(run == true)
	{
		std::cout << "Enter (r) for left esc: +" << increment << std::endl;
		std::cout << "Enter (f) for left esc: -" << increment << std::endl;
		std::cout << "Enter (o) for right esc: +" << increment << std::endl;
		std::cout << "Enter (l) for right esc: -" << increment << std::endl << std::endl;
		std::cout << "Enter (s) to stop the motors " << std::endl;
		std::cout << "Enter (q) to quit correctly " << std::endl;
		std::cin >> input;

		if (input == 'r') 
		{
			speed_left = speed_left + increment; 
			esc_left.setSpeed(esc_left.NEUTRAL + speed_left);
			std::cout << "speed: " << speed_left << std::endl << std::endl;
		}
		else if (input == 'f') 
		{
			speed_left = speed_left - increment;
			esc_left.setSpeed(esc_left.NEUTRAL + speed_left);
			std::cout << "speed: " << speed_left << std::endl << std::endl;
		}
		else if (input == 'o') 
		{
			speed_right = speed_right + increment;
			esc_right.setSpeed(esc_right.NEUTRAL + speed_right);
			std::cout << "speed: " << speed_right << std::endl << std::endl;
		}
		else if (input == 'l') 
		{
			speed_right = speed_right - increment;
			esc_right.setSpeed(esc_right.NEUTRAL + speed_right);
			std::cout << "speed: " << speed_right << std::endl << std::endl;
		}
		else if (input == 's') 
		{
			speed_left = 0;
			speed_right = 0;

			esc_left.setSpeed(esc_left.NEUTRAL);
			esc_right.setSpeed(esc_right.NEUTRAL);
			std::cout << "Motors have been stopped" << std::endl << std::endl;
		}
		else if (input == 'q') 
		{
			run = false;
		}
		else 
		{
			std::cout << std::endl << "MORON.... You entered an invalid key, try again" << std::endl << std::endl;
		}
	}

	esc_left.end();
	esc_right.end();

	return 0;
}

