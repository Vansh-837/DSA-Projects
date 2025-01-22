all: td

td: BSTTestDriver.o WordPair.o BST.o BSTNode.o ElementAlreadyExistsException.o ElementDoesNotExistException.o EmptyDataCollectionException.o UnableToInsertException.o
	g++ -Wall -o td BSTTestDriver.o WordPair.o BST.o BSTNode.o ElementAlreadyExistsException.o ElementDoesNotExistException.o EmptyDataCollectionException.o UnableToInsertException.o
	
BSTTestDriver.o: BSTTestDriver.cpp
	g++ -Wall -c BSTTestDriver.cpp 
		
WordPair.o: WordPair.h WordPair.cpp
	g++ -Wall -c WordPair.cpp
			
BST.o: BST.h BST.cpp
	g++ -Wall -c BST.cpp
	
BSTNode.o: BSTNode.h BSTNode.cpp
	g++ -Wall -c BSTNode.cpp
	
ElementDoesNotExistException.o: ElementDoesNotExistException.h ElementDoesNotExistException.cpp
	g++ -Wall -c ElementDoesNotExistException.cpp

ElementAlreadyExistsException.o: ElementAlreadyExistsException.h ElementAlreadyExistsException.cpp
	g++ -Wall -c ElementAlreadyExistsException.cpp
		
EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -c EmptyDataCollectionException.cpp
	
UnableToInsertException.o: UnableToInsertException.h UnableToInsertException.cpp
	g++ -Wall -c UnableToInsertException.cpp

clean:
	rm -f td *.o
