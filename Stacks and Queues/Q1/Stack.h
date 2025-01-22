/*
 * Stack.h
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author:
 * Date:
 */

#ifndef STACK_H
#define STACK_H
#include <cstddef>

class Stack {

private:

    // Description: Nodes for a singly-linked list - Do not modify!
    class StackNode {
    public:
        int data;
        StackNode* next;
    };

    // Pointer to the top of the stack
    StackNode* top;

public:

    // Default constructor
    Stack();

    // Destructor
    ~Stack();

    // Description: Adds a new element to the top of the stack.
    void push(int newelm);

    // Description: Removes the element at the top of the stack.
    void pop();

    // Description: Retrieves the element at the top of the stack.
    int peek() const;

    // Description: Checks if the stack is empty.
    bool isEmpty() const;
};

#endif // STACK_H
