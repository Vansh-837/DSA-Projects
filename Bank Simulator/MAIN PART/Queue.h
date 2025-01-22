#ifndef QUEUE_H
#define QUEUE_H

#include "EmptyDataCollectionException.h"


template <typename ElementType>
class Queue {
private:
    ElementType* elements;
    static unsigned const INITIAL_CAPACITY=6;
    unsigned elementCount;                      // Number of elements in the Queue
    unsigned capacity;                          // Actual capacity of the data structure (number of cells in the array)
    unsigned frontindex;                        // Index the topmost element
    unsigned backindex;                        // Index where the next element will be placed                     
    // Description:  Change the capacity of the array to newlen
	// Precondition:  newlen >= INITIAL_CAPACITY
    void resize(unsigned len);

public:
   // Constructor
   Queue();
   
   // Destructor
   ~Queue();

   // Other member functions...


    // Description: Returns true if this Queue is empty, otherwise false.
    // Postcondition: This Queue is unchanged by this operation.
    // Time Efficiency: O(1)
    bool isEmpty() const;
   
    // Description: Inserts newElement at the "back" of this Queue 
    //              (not necessarily the "back" of this Queue's data structure) 
    //              and returns true if successful, otherwise false.
    // Time Efficiency: O(1)
    bool enqueue(ElementType & newElement);
   
    // Description: Removes (but does not return) the element at the "front" of this Queue 
    //              (not necessarily the "front" of this Queue's data structure).
    // Precondition: This Queue is not empty.
    // Exception: Throws EmptyDataCollectionException if this Queue is empty.   
    // Time Efficiency: O(1)
    void dequeue(); 

    // Description: Returns (but does not remove) the element at the "front" of this Queue
    //              (not necessarily the "front" of this Queue's data structure).
    // Precondition: This Queue is not empty.
    // Postcondition: This Queue is unchanged by this operation.
    // Exception: Throws EmptyDataCollectionException if this Queue is empty.
    // Time Efficiency: O(1)
    ElementType & peek() const;
};

#include "Queue.cpp"

#endif
