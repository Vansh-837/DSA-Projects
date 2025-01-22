#include <iostream>
#include "Event.h"
#include "PriorityQueue.h"  // Include the Priority Queue header

int main() {
    // Create a PriorityQueue of Event objects
    PriorityQueue<Event> eventQueue;

    // Create some Event objects
    Event event1(Event::ARRIVAL, 10);
    Event event2(Event::DEPARTURE, 10);
    Event event3(Event::ARRIVAL, 5);
    Event event4(Event::ARRIVAL, 8);
    Event event5(Event::DEPARTURE, 15);
    Event event6(Event::ARRIVAL, 17);
    Event event7(Event::ARRIVAL, 8);
    Event event8(Event::DEPARTURE, 28);
    Event event9(Event::ARRIVAL, 26);
    Event event10(Event::DEPARTURE, 26);
    Event event11(Event::ARRIVAL, 14);
    Event event12(Event::DEPARTURE, 28);
    Event event13(Event::ARRIVAL, 30);
    Event event14(Event::DEPARTURE, 8);
    Event event15(Event::ARRIVAL, 35);
    Event event16(Event::DEPARTURE, 48);
    Event event17(Event::ARRIVAL, 35);


    // Enqueue the events
    eventQueue.enqueue(event1);
    eventQueue.enqueue(event2);
    eventQueue.enqueue(event3);
    eventQueue.enqueue(event4);
    eventQueue.enqueue(event5);
    eventQueue.enqueue(event6);
    eventQueue.enqueue(event7);
    eventQueue.enqueue(event8);
    eventQueue.enqueue(event9);
    eventQueue.enqueue(event10);
    eventQueue.enqueue(event11);
    eventQueue.enqueue(event12);
    eventQueue.enqueue(event13);
    eventQueue.enqueue(event14);
    eventQueue.enqueue(event15);
    eventQueue.enqueue(event16);
    eventQueue.enqueue(event17);

   

    // Print the events in the Priority Queue
    std::cout << "Priority Queue events:\n";
    for (int i = 0; i < 14; i++)
    {
       Event currentEvent = eventQueue.peek();
        currentEvent.print();
        std::cout << std::endl;
        eventQueue.dequeue();
    }
    
    //while (!eventQueue.isEmpty()) {
        
    //}

    return 0;
}
