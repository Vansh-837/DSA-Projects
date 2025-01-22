/* 
 * BankSimApp.cpp
 *
 * Description: Implementation File using all the classes.
 * 
 * Author: Vansh Bhatt
 * Student number: 301471598
 * Last Modification: Nov. 2023
 *
 */  


#include "Event.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include <iostream>
#include <fstream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;


// Processes an arrival event.
void processArrival(Event arrivalEvent, PriorityQueue<Event>&eventPriorityQueue, Queue<Event>& bankLine, 
bool & tellerAvailable, int currentTime,int &totalArrivalTime,int &totalProcessingTime ) {

    // Remove this event from the event queue
    try
    {
        eventPriorityQueue.dequeue();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    if (bankLine.isEmpty() && tellerAvailable) {

        
        int departTime = currentTime + arrivalEvent.getLength();
        Event newDepartureEvent('D',departTime);   
        eventPriorityQueue.enqueue(newDepartureEvent);
        tellerAvailable = false;
    } 
    else {
        
        bankLine.enqueue(arrivalEvent);
    }

    totalArrivalTime+=arrivalEvent.getTime();
    totalProcessingTime+=arrivalEvent.getLength();

    cout<<"Processing an arrival event at time:\t"<<currentTime<<endl;
    
}


// Processes a departure event.
void processDeparture(Event departureEvent, PriorityQueue<Event>& eventPriorityQueue, Queue<Event>& bankLine,
bool &tellerAvailable, int currentTime,int &totalDepartureTime) {

    // Remove this event from the event queue
    try
    {
        eventPriorityQueue.dequeue();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    if (!(bankLine.isEmpty())) {

        // Customer at front of line begins transaction
        Event customer = bankLine.peek();

        try
        {
            bankLine.dequeue();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    
        int departTime = currentTime + customer.getLength();
        Event newDepartureEvent('D', departTime);
        eventPriorityQueue.enqueue(newDepartureEvent);
       
    } else {
        tellerAvailable = true;
    }

    totalDepartureTime+=currentTime;
    cout<<"Processing a departure event at time:\t"<<currentTime<<endl;

}




//============MAIN================

int main() {

    //initialize all the used varriables
    int eventsCount = 0;
    int totalArrivalTime = 0;
    int totalDepartureTime = 0;
    int totalProcessingTime = 0;
    float avgwait = 0;
    int ariv;
    int transc;
    bool tellerAvailable = true;
   
    PriorityQueue<Event> eventPriorityQueue;
    Queue<Event> bankLine;

    // Create and add arrival events to event queue
    while (cin>>ariv>>transc)
    {
        Event farrival(Event::ARRIVAL,ariv,transc);
        eventPriorityQueue.enqueue(farrival);
    }


    cout<<endl;
    cout << "Simulation Begins" << endl;

    // Event Loop
    while (!(eventPriorityQueue.isEmpty())) {

        Event newEvent = eventPriorityQueue.peek();

        // Get current time
        int currentTime = newEvent.getTime();

        if (newEvent.isArrival()) {
             
            processArrival(newEvent,eventPriorityQueue,bankLine,tellerAvailable,currentTime,totalArrivalTime,totalProcessingTime);
            eventsCount++;
        } 
        else {
            
            processDeparture(newEvent,eventPriorityQueue,bankLine,tellerAvailable,currentTime,totalDepartureTime);
        }
    }

    // Calculate the average waiting time 
    avgwait = totalDepartureTime - totalProcessingTime;
    avgwait = avgwait - totalArrivalTime;
    avgwait = avgwait / eventsCount;
    
    // Output the results of the simulation
    cout << "Simulation Ends" << endl << endl;

    cout << "Final Statistics:" << endl;
    cout<<endl;

    cout << "\tTotal number of people processed: " << eventsCount << endl;
    cout << "\tAverage amount of time spent waiting: " << avgwait << endl;

    cout<<endl;

    return 0;
}

