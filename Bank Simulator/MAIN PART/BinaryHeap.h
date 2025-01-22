#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include "EmptyDataCollectionException.h"  // Include the exception class

template <class ElementType>
class BinaryHeap {

private:
    // Private member variables and helper methods as per the implementation
    
    static const unsigned int MAX_HEAP = 6; // Set a maximum heap size
    ElementType* elements; // Array to hold the heap elements
    unsigned int elementCount; // Number of elements in the heap
    unsigned int capacity; // Capacity of the heap
    // Utility method for re-heap down
    void reHeapDown(unsigned int indexOfRoot);
    void reHeapUp(unsigned int indexOfBottom);
    void resize(unsigned newlen);

public:
    // Public methods

    // Description: Default constructor
    BinaryHeap();

    // Description: Destructor
    ~BinaryHeap();

    // Description: Returns the number of elements in the Binary Heap.
    // Postcondition: The Binary Heap is unchanged by this operation.
    // Time Efficiency: O(1)
    unsigned int getElementCount() const;

    // Description: Inserts newElement into the Binary Heap.
    //              It returns true if successful, otherwise false.
    // Time Efficiency: O(log2 n)
    bool insert( ElementType &newElement);

    // Description: Removes (but does not return) the necessary element.
    // Precondition: This Binary Heap is not empty.
    // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
    // Time Efficiency: O(log2 n)
    void remove();

    // Description: Retrieves (but does not return) the necessary element.
    // Precondition: This Binary Heap is not empty.
    // Postcondition: This Binary Heap is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
    // Time Efficiency: O(1)
    ElementType &retrieve() const;

};

#include "BinaryHeap.cpp"  // Include the implementation file

#endif
