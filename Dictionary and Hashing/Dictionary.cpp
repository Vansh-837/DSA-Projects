/*
 * Dictionary.cpp
 * 
 * Class Description: Dictionary data collection ADT class.
 *                    The implementation of this class is based on 
 *                    the hashing strategy and the open addressing 
 *                    collision resolution strategy called linear probing hashing.             
 * Class Invariant: Each element stored in this Dictionary is unique (no duplications allowed).
 *
 * Author: AL
 * Date: Last modified: Nov. 2023
 */

// You can add more #include statements if you wish.

#include <iostream>
#include <cstring>
#include "Dictionary.h"  
#include "Profile.h"
#include <cmath>
#include "UnableToInsertException.h"
#include "ElementAlreadyExistsException.h"
#include "EmptyDataCollectionException.h"
#include "ElementDoesNotExistException.h"

using std::cout;
using std::endl;
using std::stoul;

// Constructor
Dictionary::Dictionary() {
  
  
}

// Destructor
// Description: Destruct a Dictionary object, releasing heap-allocated memory.
Dictionary::~Dictionary() {
  // Release all heap memory
  if ( hashTable != nullptr ) { 
    for ( unsigned int i = 0; i < CAPACITY; i++ ) 
      if ( hashTable[i] != nullptr ) {      
        delete hashTable[i]; // Delete object of Profile class on heap
        hashTable[i] = nullptr;
      }
    delete [] hashTable;
    hashTable = nullptr;	
  }
}

// Description: Returns the total element count currently stored in Dictionary.
// Postcondition: Dictionary remains unchanged.
unsigned int Dictionary::getElementCount() const {
   return elementCount;
}

// Description: Returns the CAPACITY (size) of the Dictionary.
// Postcondition: Dictionary remains unchanged.
unsigned int Dictionary::getCapacity() const{
   return CAPACITY;
}

// Hash Function
// Description: Hashes the given indexingKey producing a "hash table index".
// Time Efficiency: For you to complete!
// Example of Time Efficiency: max(O(1),O(1)) = O(1) 
// Space Efficiency: For you to complete!
// Example of Space Efficiency: O(1)
unsigned int Dictionary::hashFunction( string indexingKey ) {

  // Implement your own hash function here!

  // Time Efficiency Analysis: Two statements done in sequence: max(O(1),O(1)) = O(1) 
  // Space Efficiency Analysis: Hash Function does not require another 
  //                            data structure (of size n) to operate: O(1)
  uint64_t indexingKeyInt = stoul(indexingKey);  // O(1)
  
  // "hashCode" is an intermediate result
  //unsigned int hashCode = indexingKeyInt % CAPACITY; // O(1)

  const unsigned int MULTIPLIER = 739;
  const unsigned long DIVISOR = 1000000000000;

  // Multiply, divide, and take the integer part
  unsigned int hashCode = floor((indexingKeyInt * MULTIPLIER) / DIVISOR);
  hashCode = hashCode % CAPACITY;
  cout<<hashCode<<endl;
  return hashCode;
}

// Description: Inserts an element into the Dictionary and increments "elementCount".
//              For this Assignment 5, you do not have to expand the hashTable when it is full. 
// Precondition: newElement must not already be in in the Dictionary.  
// Exception: Throws UnableToInsertException if we cannot insert newElement in the Dictionary.
//            For example, if the operator "new" fails, or Dictionary is full (temporary solution).
// Exception: Throws ElementAlreadyExistsException if newElement is already in the Dictionary. 
void Dictionary::insert(Profile* newElement) {

  // Initialize hashTable to nullptr
  try
  {
    hashTable = new Profile*[CAPACITY];
  }
  catch(const std::exception& e)
  {
    cout << e.what() << endl;
  }
  
  
  for (unsigned int i = 0; i < CAPACITY; ++i) {
    hashTable[i] = nullptr;
  }

  if (newElement == nullptr) {
    throw UnableToInsertException("Cannot insert a null element.");
  }

  if (elementCount >= CAPACITY) {
    throw UnableToInsertException("Dictionary is full.");
  }

  string userName = newElement->getUserName();
  unsigned int index = hashFunction(userName);
  unsigned int newind=index;
  const int maxIterations = CAPACITY - 1;  // Set a maximum number of iterations for quadratic probing
  int i = 1;
  while (hashTable[newind] != nullptr && i <= maxIterations) {
    if (*(hashTable[newind]) == *newElement) {
      throw ElementAlreadyExistsException("Element already exists in the Dictionary.");
    }

    int offset;
    if (i % 2 == 0) {
      offset = (i / 2) * (i / 2);
    } 
    else {
      offset = (-1)*(floor(i / 2) * floor(i / 2));
    }

    newind = (index + offset) % CAPACITY;

    cout<<newind<<endl;
    i++;
  }

  if (i > maxIterations) {
    throw UnableToInsertException("Exceeded maximum iterations for quadratic probing.");
  }

  hashTable[newind] = newElement;
  cout<<newind<<endl;
  cout<<"==========="<<endl;
  elementCount++;
}


// Description: Returns a pointer to the target element if found.
// Postcondition: Dictionary remains unchanged.
// Exception: Throws EmptyDataCollectionException if the Dictionary is empty.
// Exception: Throws ElementDoesNotExistException if target is not found in the Dictionary.
Profile * Dictionary::get( Profile & target )  {
  if (elementCount == 0) {
    throw EmptyDataCollectionException("Dictionary is empty.");
  }

  string targetUserName = target.getUserName();
  unsigned int index = hashFunction(targetUserName);
  unsigned int newind=index;

  const int maxIterations = CAPACITY - 1;  // Set a maximum number of iterations for quadratic probing
  int i = 1;
  while (hashTable[newind] != nullptr && i <= maxIterations) {
    if (*(hashTable[newind]) == target) {
      return hashTable[newind];
    }
    int offset;
    if (i % 2 == 0) {
      offset = (i / 2) * (i / 2);
    } 
    else {
      offset = (-1)*(floor(i / 2) * floor(i / 2));
    }

    newind = (index + offset) % CAPACITY;

    i++;
  }

  if (i > maxIterations) {
    throw ElementDoesNotExistException("Element not found in the Dictionary.");
  }

  throw ElementDoesNotExistException("Element not found in the Dictionary.");
}


   
// Description: Prints all elements stored in the Dictionary (unsorted).
// Postcondition: Dictionary remains unchanged.
// Exception: Throws EmptyDataCollectionException if the Dictionary is empty.
void Dictionary::printDictionary()  const {
  if ( elementCount == 0 ) 
     throw EmptyDataCollectionException("In printDictionary(): hashTable is empty.");

  cout << endl << "Printing the Dictionary with " << this->elementCount << " elements: " << endl;
  for (unsigned int index = 0; index < CAPACITY; index++) {
    if ( hashTable[index] != nullptr ) 
		cout << "HashTable[" << index << "] = " << *(hashTable[index]) << endl; 
  }   
  return;
}


