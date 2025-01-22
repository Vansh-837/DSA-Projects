#include "Queue.h"
#include <iostream>

// Constructor
template <typename ElementType>
Queue<ElementType>::Queue(){
   frontindex=0;
   backindex=0;
   elementCount=0;
   capacity=INITIAL_CAPACITY;
   elements = new ElementType[capacity];
} 
   

// Destructor
template <typename ElementType>
Queue<ElementType>::~Queue() {
   if (elements)
   {
      delete[] elements;
   }
   
   
}

// Resize
template <typename ElementType>
void Queue<ElementType>::resize(unsigned newlen) {
   // no size change => nothing to do
   if (newlen == capacity) return;

   // precondition check
   if (newlen < INITIAL_CAPACITY) return;

   // allocate new space
   ElementType* newElements = new ElementType[newlen];
   if (newElements == nullptr) return;

   // copy elements to new space
   for (unsigned int i = 0; i < elementCount; i++) {
      newElements[i] = elements[(i + frontindex) % capacity];
   }

   // recycle new space
   delete[] elements;
   elements = newElements;

   // update properties
   capacity = newlen;
   frontindex = 0;
   backindex = elementCount % capacity;

   return;
}


// Returns true if the queue is empty
template <typename ElementType>
bool Queue<ElementType>::isEmpty() const {
   return elementCount == 0;
}


// Enqueue
template <typename ElementType>
bool Queue<ElementType>::enqueue(ElementType &newElement) {
  if (elementCount == capacity) {
      // no more space:  double the capacity
      resize(capacity * 2);
      // cout << "resizing to " << capacity << "   "; print();
   }

   elementCount++;
   elements[backindex] = newElement;
   backindex = (backindex + 1) % capacity;
}

// Dequeue
template <typename ElementType>
void Queue<ElementType>::dequeue() {
   if (isEmpty()) {
      throw EmptyDataCollectionException("dequeue() called on an empty queue.");
   }

   if (elementCount <= capacity / 4) {
      if (capacity / 2 >= INITIAL_CAPACITY) {
         resize(capacity / 2);
         // cout << "resizing to " << capacity << "   "; print();
      }
   }

   elementCount--;
   frontindex = (frontindex + 1) % capacity;
}


// Peek
template <typename ElementType>
ElementType &Queue<ElementType>::peek() const {
   if (isEmpty()) {
      throw EmptyDataCollectionException("peek() called on an empty queue.");
   }

   return elements[frontindex];
}
