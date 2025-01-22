#include "Dictionary.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"
#include "UnableToInsertException.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "BST.h"
#include "WordPair.h"



using std::cin;
using std::cout;
using std::ifstream;


// Default constructor
Dictionary::Dictionary() {
    keyValuePairs = new BST();
}

// Destructor
Dictionary::~Dictionary() {
    delete keyValuePairs;
}

// Returns the number of elements currently stored in the Dictionary.
unsigned int Dictionary::getElementCount() const {
    return keyValuePairs->getElementCount();
}

// Puts "newElement" (association of key-value) into the Dictionary.
void Dictionary::put(WordPair &newElement) {
    try {
        // Insert aWordPair into "testing" using a try/catch block
        keyValuePairs->insert(newElement);
    } 
    catch (ElementAlreadyExistsException &e) {
        // Handle the case where the element already exists
        cout << "Element already exists: " << newElement << endl;
    }
    catch(UnableToInsertException &e){
        cout << "Element can not be inserted: " << newElement << endl;
    }

}




  
// Gets "newElement" (i.e., the associated value of a given key) from the Dictionary.
WordPair &Dictionary::get(WordPair &targetElement) const {
    try {
        return keyValuePairs->retrieve(targetElement);
    } catch (ElementDoesNotExistException &e) {
        throw ElementDoesNotExistException("");
    } catch (EmptyDataCollectionException &e) {
        throw EmptyDataCollectionException("");
    }
}

// Prints the content of the Dictionary in ascending alphabetical order based on English word.
void Dictionary::displayContent(void visit(WordPair &)) const {
    try {
        keyValuePairs->traverseInOrder(visit);
    } catch (EmptyDataCollectionException &e) {
        throw EmptyDataCollectionException("Dictionary is empty.");
    }
}
