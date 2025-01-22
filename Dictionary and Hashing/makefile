all: tst

tst: test.o Profile.o Dictionary.o ElementAlreadyExistsException.o ElementDoesNotExistException.o EmptyDataCollectionException.o UnableToInsertException.o
	g++ -Wall -o tst test.o Profile.o Dictionary.o ElementAlreadyExistsException.o ElementDoesNotExistException.o EmptyDataCollectionException.o UnableToInsertException.o

test.o: test.cpp
	g++ -Wall -c test.cpp 

Profile.o: Profile.h Profile.cpp
	g++ -Wall -c Profile.cpp

Dictionary.o: Dictionary.h Dictionary.cpp
	g++ -Wall -c Dictionary.cpp
		
ElementDoesNotExistException.o: ElementDoesNotExistException.h ElementDoesNotExistException.cpp
	g++ -Wall -c ElementDoesNotExistException.cpp

ElementAlreadyExistsException.o: ElementAlreadyExistsException.h ElementAlreadyExistsException.cpp
	g++ -Wall -c ElementAlreadyExistsException.cpp
		
EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -c EmptyDataCollectionException.cpp

UnableToInsertException.o: UnableToInsertException.h UnableToInsertException.cpp
	g++ -Wall -c UnableToInsertException.cpp

clean:
	rm -f tst *.o