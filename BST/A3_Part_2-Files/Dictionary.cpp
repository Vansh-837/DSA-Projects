/*
 * Dictionary.cpp
 * 
 * Description: Dictonary data collection ADT class.
 *              BST-based implementation.
 *              Duplicated elements not allowed.
 *              
 * Author: AL
 * Date of last modification: Oct. 2023
 */



#include "Dictionary.h"
#include <iostream>


using std::cout;
using std::endl;



// Default constructor
Dictionary::Dictionary() {
    keyValuePairs = new BST();
}

// Destructor
Dictionary::~Dictionary() {
    delete keyValuePairs;
}

// Description: Returns the number of elements currently stored in the binary search tree.
unsigned int Dictionary::getElementCount() const {
    return keyValuePairs->getElementCount();
}

// Description: Inserts an element into the binary search tree.
// Exception: Catches the exception "UnableToInsertException" when newElement 
//            cannot be inserted because the "new" operator failed. 
// Exception: Catches the exception "ElementAlreadyExistsException" 
//            if "newElement" already exists in the binary search tree.
void Dictionary::put(WordPair &newElement) {
    try {
        
        keyValuePairs->insert(newElement);
    } 
    catch (ElementAlreadyExistsException &e) {
        
        cout << "Element already exists: " << newElement << endl;
    }
    catch(UnableToInsertException &e){
        cout << "Element can not be inserted: " << newElement << endl;
    }

}




  
// Description: Retrieves "targetElement" from the binary search tree.
// Exception: Throws the exception "EmptyDataCollectionException" 
//            if the binary search tree is empty.
// Exception: Throws (propagates) the exception "ElementDoesNotExistException" 
//            thrown from the retrieveR(...)
//            if "targetElement" is not in the binary search tree.

WordPair &Dictionary::get(WordPair &targetElement) const {
    try {
        return keyValuePairs->retrieve(targetElement);
    } catch (ElementDoesNotExistException &e) {
        throw ElementDoesNotExistException("");
    } catch (EmptyDataCollectionException &e) {
        throw EmptyDataCollectionException("");
    }
}

// Description: Traverses the binary search tree in order.(thus alphabetical)
// Exception: Throws the exception "EmptyDataCollectionException" 
//         if the binary search tree is empty.
void Dictionary::displayContent(void visit(WordPair &)) const {
    try {
        keyValuePairs->traverseInOrder(visit);
    } catch (EmptyDataCollectionException &e) {
        throw EmptyDataCollectionException("Dictionary is empty.");
    }
}
