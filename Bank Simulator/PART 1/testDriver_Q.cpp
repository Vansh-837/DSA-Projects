#include "Queue.h"
#include "Event.h"
#include <iostream>

using std::cout;
using std::endl;


int main() {
   // Test the Queue with Event objects
   Queue <Event> eventQueue;

   // Create some Event objects
   Event event1('A', 10);
   Event event2('D', 15);
   Event event3('A', 20);
   Event event4('A', 30);
   Event event5('D', 35);
   Event event6('A', 25);
   Event event7('A', 12);
   Event event8('D', 28);
   Event event9('A', 26);
   Event event10('A', 25);
   Event event11('A', 12);
   Event event12('D', 28);
   Event event13('A', 26);


   // Enqueue events
   eventQueue.enqueue(event3);
   eventQueue.enqueue(event1);
   eventQueue.enqueue(event2);
   eventQueue.enqueue(event4);
   eventQueue.enqueue(event5);
   eventQueue.enqueue(event6);
   eventQueue.enqueue(event7);
   eventQueue.enqueue(event9);
   eventQueue.enqueue(event8);
   eventQueue.enqueue(event9);
   eventQueue.enqueue(event10);
   eventQueue.enqueue(event11);
   eventQueue.enqueue(event12);
   eventQueue.enqueue(event13);
   
   
   for (int i = 0; i <= 13; i++)
   {
      Event currentEvent = eventQueue.peek();
     
      eventQueue.dequeue();
      currentEvent.print();
      cout << endl;
   }
   

   // Dequeue and print events
   //while (!eventQueue.isEmpty()) {
      
   //}

   return 0;
}
