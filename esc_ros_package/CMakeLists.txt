cmake_minimum_required(VERSION 2.8.3)
project(nodes)

## Compile as C++11, supported in ROS Kinetic and newer
#add_compile_options(-std=c++11)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS 
	roscpp 
	rospy 
	std_msgs 
	genmsg
)

## Declare ROS messages and services
#add_message_files(FILES Num.msg)
#add_service_files(FILES AddTwoInts.srv)

## Generate added messages and services
#generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package(
	INCLUDE_DIRS include
 	LIBRARIES esc_lib
)

## Build talker and listener
include_directories(
	include 
	${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
add_library(
  esc_lib src/esc_lib.cpp
)

add_executable(esc_talker src/esc_talker.cpp)
target_link_libraries(esc_talker ${catkin_LIBRARIES})

add_executable(esc_interface src/esc_interface.cpp)
target_link_libraries(esc_interface
	esc_lib
	pigpiod_if2 
	pthread
	${catkin_LIBRARIES}
)

#add_executable(esc_lib src/esc_lib.cpp)
#target_link_libraries(esc_lib ${catkin_LIBRARIES} pigpiod_if2 pthread)
