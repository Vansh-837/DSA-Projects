/*
 * Event.h
 * 
 * Description: Models arrival and departure events.
 *
 * Class Invariant: Arrival events have type 'A'.
 *                  Departure events have type 'D'.
 *
 * Author: AL
 * Last Modified: Nov. 2023
 */

#ifndef EVENT_H
#define EVENT_H

class Event {

private:
   char type;
   int time = 0;
   int length = 0; //only used for arrival events
   
public:
   const static char ARRIVAL = 'A';
   const static char DEPARTURE = 'D';
   
   // Constructor
   Event();
   Event(char type, int time);
   Event(char type, int time, int length);
   
   // Getters
   char getType() const;
   int getTime() const;
   int getLength() const;
    
   // Setters
   void setType( char aType );
   void setTime( int aTime );
   void setLength( int aLength );
   
   // Description: Return true if this event is an arrival event, false otherwise.
   bool isArrival();

   // Overloaded Operators
   // Description: Comparison <= operator. 
   bool operator<=(const Event& rhs);

   // For Testing Purposes
   // Description: Prints the content of "this". 
   void print() const;

};
#endif