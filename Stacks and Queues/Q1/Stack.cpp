#include "Stack.h"
using namespace std;

// Default constructor
Stack::Stack() {
    // Initialize an empty stack
    top = nullptr;
}

// Destructor
Stack::~Stack() {
    // Deallocate memory for all nodes in the stack
    while (!isEmpty()) {
        pop();
    }
}

// Description: Retrieves the element at the top of the stack.
int Stack::peek() const {
    if (!isEmpty()) {
        // Find the last node in the list
        StackNode* cur = top;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        // Return the data of the last node
        return cur->data;
    }
    
    
    return -9999;

}

// Description: Checks if the stack is empty.
bool Stack::isEmpty() const {
    return top == nullptr;
}


// Description: Adds a new element to the top of the stack.
void Stack::push(int newelm) {
    // Create a new node
    StackNode* Node = new StackNode;
    Node->data = newelm;
    Node->next = nullptr;

    // If the stack is empty, set the new node as the top
    if (isEmpty()) {
        top = Node;
    } else {
        // Otherwise, insert the new node at the back
        StackNode* cur = top;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = Node;
    }
}

// Description: Removes the element at the top of the stack.
void Stack::pop() {
    if (!isEmpty()) {
        // If the stack has only one element, delete it and set top to nullptr
        if (top->next == nullptr) {
            delete top;
            top = nullptr;
        } else {
            // Otherwise, find the second-to-last node
            StackNode* cur = top;
            while (cur->next->next != nullptr) {
                cur = cur->next;
            }
            // Delete the last node and set the next of the second-to-last node to nullptr
            delete cur->next;
            cur->next = nullptr;
        }
    }
}

