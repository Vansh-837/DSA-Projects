/* 
 * Queue.cpp - Does not work well!
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author:
 * Date:
 */
 
#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;



//constructor
Queue::Queue() {
    elements = new int[INITIAL_CAPACITY];
}

//destructor
Queue::~Queue() {
    delete[] elements;
}

//Helper method to double the size
void Queue::resizedbl() {
    if (elementCount == capacity) {
        //Double the capacity if it is full
        unsigned int newcap = capacity * 2;
        int *newelm = new int[newcap];

        //Copy in new array
        for (unsigned int i = 0; i < elementCount; ++i) {
            newelm[i] = elements[(frontindex + i) % capacity];
        }

        //update
        frontindex = 0;
        backindex = elementCount;
        capacity = newcap;

        //delete old array 
        delete[] elements;
        elements = newelm;
    } 

}

//Helper method to half the size
void Queue::resizehlf(){
    if (elementCount > 0 && elementCount * 4 < capacity && capacity > INITIAL_CAPACITY) {
        //Half the capacity if it is less than 1/4 full
        unsigned int newcap = capacity / 2;
        int *newelm = new int[newcap];

        //Copy elements to the new array
        for (unsigned int i = 0; i < elementCount; ++i) {
            newelm[i] = elements[(frontindex + i) % capacity];
        }

        // Update indices and capacity
        frontindex = 0;
        backindex = elementCount;
        capacity = newcap;

        // Delete old array and point to the new array
        delete[] elements;
        elements = newelm;
    }
}


// Inserts newElement at the back of Queue
void Queue::enqueue(int newElement) {
    // Call resize to check and handle capacity changes
    resizedbl();

    elements[backindex] = newElement;
    backindex = (backindex + 1) % capacity;
    ++elementCount;
}

// Removes the frontmost element
void Queue::dequeue() {
    if (elementCount > 0) {
        frontindex = (frontindex + 1) % capacity;
        --elementCount;

        // Check if resizing is needed after dequeue
        resizehlf();
    }
}

// Returns a copy of the frontmost element
int Queue::peek() const {
    return elements[frontindex];
}

// Returns true if and only if Queue is empty
bool Queue::isEmpty() const {
    return (elementCount == 0);
}
