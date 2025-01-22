
all: std

std: Stack.o StackTestDriver.o
	g++ -o std Stack.o StackTestDriver.o

Stack.o: Stack.cpp Stack.h
	g++ -c Stack.cpp

StackTestDriver.o: StackTestDriver.cpp Stack.h
	g++ -c StackTestDriver.cpp

clean:	
	rm -f std *.o

