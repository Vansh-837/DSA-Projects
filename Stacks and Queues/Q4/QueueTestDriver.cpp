/* 
 * main.cpp
 *
 * Description: Queue test driver.
 *
 * Author:
 * Date:
 */

#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;


int main () {
    Queue * Q = new Queue();

    // enqueue 1, 2, 3, 4, 5
    for (int i = 1; i <= 5; i++) {
        Q->enqueue(i);
        cout << "enqueue " << i << endl;
    }


    // dequeue 2x elements
    for (int i = 0; i < 2; i++) {
        int y = Q->peek();
        Q->dequeue();
        cout << "peek " << y << endl;
    }


    // enqueue 6, 7, 8, 9, 10
    for (int i = 6; i <= 10; i++) {
        Q->enqueue(i);
        cout << "enqueue " << i << endl;
    }


    // dequeue all elements
    while (!Q->isEmpty()) {
        int y = Q->peek();
        Q->dequeue();
        cout << "peek " << y << endl;
    }

    delete Q;
    Q = nullptr;
    
    return 0;
}

