all: translate

translate: Translator.o WordPair.o Dictionary.o BST.o BSTNode.o ElementAlreadyExistsException.o ElementDoesNotExistException.o EmptyDataCollectionException.o
	g++ -Wall -o translate Translator.o WordPair.o Dictionary.o BST.o BSTNode.o ElementAlreadyExistsException.o ElementDoesNotExistException.o EmptyDataCollectionException.o

Translator.o: Translator.cpp
	g++ -Wall -c Translator.cpp 

Dictionary.o: Dictionary.h Dictionary.cpp
	g++ -Wall -c Dictionary.cpp
	
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

clean:
	rm -f translate *.o