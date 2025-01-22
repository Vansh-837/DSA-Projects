#include "BinaryHeap.h"
#include "Event.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    // Test the Binary Heap with Event objects
    BinaryHeap<Event> eventHeap;

    // Create some Event objects
    Event event1('A', 10);
    Event event2('D', 7);
    Event event3('A', 5);
    Event event4('A', 4);
    Event event5('D', 8);
    Event event6('A', 9);

    Event event7('A', 17);
    Event event8('D', 8);
    Event event9('A', 26);


    // Insert events
    eventHeap.insert(event1);
    eventHeap.insert(event2);
    eventHeap.insert(event3);
    eventHeap.insert(event4);
    eventHeap.insert(event5);
    eventHeap.insert(event6);
    eventHeap.insert(event7);
    eventHeap.insert(event8);
    eventHeap.insert(event9);

    // Retrieve and print the minimum event
    cout << "Minimum Event: ";
    eventHeap.retrieve().print();
    cout << endl;
    cout<<eventHeap.getElementCount()<<endl;
    // Remove the minimum event
    eventHeap.remove();

    // Retrieve and print the new minimum event
    cout << "Minimum Event after removal: ";
    eventHeap.retrieve().print();
    cout << endl;
    cout<<eventHeap.getElementCount()<<endl;

    return 0;
}

