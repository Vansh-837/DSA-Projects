
all: qtd

qtd: Queue.o QueueTestDriver.o
	g++ -o qtd Queue.o QueueTestDriver.o

Queue.o: Queue.cpp Queue.h
	g++ -c Queue.cpp

QueueTestDriver.o: QueueTestDriver.cpp Queue.h
	g++ -c QueueTestDriver.cpp

clean:	
	rm -f qtd *.o

