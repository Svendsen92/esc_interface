# define constants
CXXFLAGS = -Wall -O
CXX=g++

increment_test: increment_test.o esc_lib.o
	$(CXX) $(CXXFLAGS) -pthread -o increment_test increment_test.o esc_lib.o -lpigpiod_if2

esc_lib.o: esc_lib.h esc_lib.cpp
	$(CXX) $(CXXFLAGS) -c esc_lib.cpp
	
increment_test.o: increment_test.cpp
	$(CXX) $(CXXFLAGS) -c increment_test.cpp 

clean: 
	rm -f *.o
