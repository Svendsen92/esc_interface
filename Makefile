# define constants
CXXFLAGS = -Wall -O
CXX=g++

esc_test: esc_test.o esc_lib.o
	$(CXX) $(CXXFLAGS) -pthread -o esc_test esc_test.o esc_lib.o -lpigpiod_if2

esc_lib.o: esc_lib.h esc_lib.cpp
	$(CXX) $(CXXFLAGS) -c esc_lib.cpp

esc_test.o: esc_test.cpp
	$(CXX) $(CXXFLAGS) -c esc_test.cpp 

clean: 
	rm -f *.o