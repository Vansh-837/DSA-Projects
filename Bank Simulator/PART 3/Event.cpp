/*
 * Event.cpp
 *
 * Description: Models arrival and departure events.
 *
 * Class Invariant: Arrival events have type 'A'.
 *                  Departure events have type 'D'.
 *
 * Author: AL
 * Last Modified: Nov. 2023
 */

#include <iostream>
#include "Event.h"

using std::cout;
using std::endl;


// Constructor
Event::Event() : type(ARRIVAL) { }

Event::Event(char aType, int aTime) : type(aType), time(aTime) { }

Event::Event(char aType, int aTime, int aLength) : type(aType), time(aTime), length(aLength) { }

// Getters
char Event::getType() const {
   return type;
}

int Event::getTime() const {
   return time;
}

// Postcondition: The length makes sense only when the type is "A".
int Event::getLength() const {
   return length;
}

// Setters
// Not expected to be used in this simulation
void Event::setType( char aType ) {
   type = aType;
   return;
}

void Event::setTime( int aTime ) {
   time = aTime;
   return;
}

void Event::setLength( int aLength ) {
   if( type == ARRIVAL )
      length = aLength;
   else
      length = 0;
   return;
}

// Description: Return true if this event is an arrival event, false otherwise.
bool Event::isArrival(){
   return type == ARRIVAL;
}

// Overloaded Operators
// Description: Comparison <= operator. 
bool Event::operator<=(const Event& rhs) {

   // Compare both Event objects
   if (time == rhs.getTime() )
      return (type == rhs.getType()) || (type == ARRIVAL && rhs.getType() == DEPARTURE);
   else
      return time < rhs.getTime();
} 

// For Testing Purposes
// Description: Prints the content of "this".
void Event::print() const {

   cout << "Event - Type: " << this->getType() << ", Time: " << this->getTime();
   if ( this->getType() == Event::ARRIVAL ) cout << ", Length: " << this->getLength();
   return;
}