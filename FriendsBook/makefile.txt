all: fb

fb: FriendsBook.o MyADT.o Profile.o
	g++ -Wall -o fb FriendsBook.o MyADT.o Profile.o

FriendsBook.o: FriendsBook.cpp MyADT.h Profile.h
	g++ -Wall -c FriendsBook.cpp

MyADT.o: MyADT.h MyADT.cpp
	g++ -Wall -c MyADT.cpp

Profile.o: Profile.h Profile.cpp
	g++ -Wall -c Profile.cpp

clean:
	rm -f fb *.o