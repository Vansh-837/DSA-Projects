/* 
 * BinaryHeap.cpp
 *
 * Description: ____________ Binary Heap ADT class.
 *
 * Class Invariant:  Always a ____________ Binary Heap.
 * 
 * Author: 
 * Last Modification: Nov. 2023
 *
 */  

#include <iostream>
#include <cmath>

#include "BinaryHeap.h"  // Header file

using std::cout;
using std::endl;


// Description: Default constructor
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap() {
    elements = new ElementType[MAX_HEAP];
    capacity = MAX_HEAP;
    elementCount = 0;
}

// Description: Destructor
template <class ElementType>
BinaryHeap<ElementType>::~BinaryHeap() {
    if (elements)
    {
        delete[] elements;
    }
    
    
}

// Description: Returns the number of elements in the Binary Heap.
// Postcondition: The Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const {
    return elementCount;
}

// Description: Inserts newElement into the Binary Heap.
//              It returns true if successful, otherwise false.
// Time Efficiency: O(log2 n)
template <class ElementType>
bool BinaryHeap<ElementType>::insert( ElementType &newElement) {
    if (elementCount == capacity) {
        resize(capacity * 2);
    }

    unsigned int indexOfBottom = elementCount;
    elements[indexOfBottom] = newElement;
    elementCount++;

    reHeapUp(indexOfBottom);

    return true;
    
}

// Utility method
// Description: Recursively put the array back into a Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapUp(unsigned int indexOfBottom) {
    if (indexOfBottom > 0) {
        unsigned int indexOfParent = floor((indexOfBottom - 1) / 2);

        // If search key value of parent > search key value of child
        if (!(elements[indexOfParent] <= elements[indexOfBottom])) {
            // Swap the element with its parent
            ElementType temp = elements[indexOfBottom];
            elements[indexOfBottom] = elements[indexOfParent];
            elements[indexOfParent] = temp;

            // Recursively put the array back into a heap
            reHeapUp(indexOfParent);
        }
    }
}

// Description: Removes (but does not return) the necessary element.
// Precondition: This Binary Heap is not empty.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove() {  

    if (elementCount == 0) {
        throw EmptyDataCollectionException("remove() called with an empty BinaryHeap.");
    }

    elements[0] = elements[elementCount - 1];
    elementCount--;
    if(elementCount > 0){
        reHeapDown(0);
    }
    

    if (elementCount <= capacity / 4 && capacity / 2 >= MAX_HEAP) {
        resize(capacity / 2);
    }

}

// Utility method
// Description: Recursively put the array back into a ____________ Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot) {

   unsigned int indexOfMinChild = indexOfRoot;
   
   // Find indices of children.
   unsigned int indexOfLeftChild = 2 * indexOfRoot + 1;
   unsigned int indexOfRightChild = 2 * indexOfRoot + 2;

   // Base case: elements[indexOfRoot] is a leaf as it has no children
   if (indexOfLeftChild > elementCount-1) return;

   // If we need to swap, select the smallest child
   // If (elements[indexOfRoot] > elements[indexOfLeftChild])
   if ( ! (elements[indexOfRoot] <= elements[indexOfLeftChild]) )
      indexOfMinChild = indexOfLeftChild;

   // Check if there is a right child, is it the smallest?
   if (indexOfRightChild < elementCount) {
      // if (elements[indexOfMinChild] > elements[indexOfRightChild])
      if ( ! (elements[indexOfMinChild] <= elements[indexOfRightChild]) )
         indexOfMinChild = indexOfRightChild;
   }

   // Swap parent with smallest of children.
   if (indexOfMinChild != indexOfRoot) {
      
      ElementType temp = elements[indexOfRoot];
      elements[indexOfRoot] = elements[indexOfMinChild];
      elements[indexOfMinChild] = temp;
      
      // Recursively put the array back into a heap
      reHeapDown(indexOfMinChild);
   }
   return;
} 
// Description: Retrieves (but does not return) the necessary element.
// Precondition: This Binary Heap is not empty.
// Postcondition: This Binary Heap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType &BinaryHeap<ElementType>::retrieve() const {
    if (elementCount == 0) {
        throw EmptyDataCollectionException("retrieve() called on an empty BinaryHeap.");
    }

    // Return the root element
    return elements[0];
}

template <class ElementType>
void BinaryHeap<ElementType>::resize(unsigned newlen) {
    if (newlen == capacity) return;

    if (newlen < MAX_HEAP) return;

    ElementType* newElements = new ElementType[newlen];
    if (newElements == nullptr) return;

    for (unsigned int i = 0; i < elementCount; i++) {
        newElements[i] = elements[i];
    }

    delete[] elements;
    elements = newElements;

    capacity = newlen;
}