all: tdQ

tdQ: testDriver_Q.o PriorityQueue.h BinaryHeap.h Event.o EmptyDataCollectionException.o
	g++ -o tdQ -Wall testDriver_Q.o Event.o EmptyDataCollectionException.o
	
testDriver_Q.o: testDriver_Q.cpp 
	g++ -c -Wall testDriver_Q.cpp
	
Event.o: Event.cpp Event.h
	g++ -c -Wall Event.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h 
	g++ -c -Wall EmptyDataCollectionException.cpp

clean:	
	rm -f tdQ *.o
