/* 
 * StackTestDriver.cpp
 *
 * Description: Test Driver for Stack class.
 *
 * Author:
 * Date:
 */

/* 
   Feel free to modify this test driver to match your design of the Stack class.
   For example, I designed my push(...) and pop() methods such that they each return
   a bool value. I will then change this test driver to capture this bool value. 
*/ 

#include <iostream> 
#include "Stack.h"

using std::cout;
using std::endl;


int main () {
    Stack * stk = new Stack( );

    int m = stk->peek();
    cout << "top 1: " << m << endl;

    // push 1, 2, 3, 4, 5
    for (int i = 1; i <= 5; i++) {
        stk->push(i);
        cout << "push " << i << endl;
    }


    // pop top two
    int x = stk->peek();
    stk->pop();
    int y = stk->peek();
    stk->pop();
    cout << "top 1: " << x << ", top 2: " << y << endl;


    // push 6, 7, 8, 9, 10
    for (int i = 6; i <= 10; i++) {
        stk->push(i);
        cout << "push " << i << endl;
    }


    // pop all
    while (!stk->isEmpty()) {
        int x = stk->peek();
        stk->pop();
        cout << "pop " << x << endl;
    }

    delete stk;
    stk = nullptr;
    
    return 0;
}

