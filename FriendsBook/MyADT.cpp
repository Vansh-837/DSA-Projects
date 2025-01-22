/*
 * MyADT.cpp
 * 
 * Class Description: A linear data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - This is a value-oriented data collection: the elements are kept in 
 *                     ascending sort order of search key. 
 *                   - Its data structure is not expandable, i.e., resizable. 
 *
 * Author: AL
 * Last modified on: Sept. 2023
 */


#include <iostream>
#include <cctype>
#include "MyADT.h"  // Header file
#include "Profile.h"

using std::cout;
using std::endl;


    
// Default constructor.
MyADT::MyADT() {

	//row = 0;
	//col = 0;
	for (int i = 0; i < MAX_ALPHA; i++)
	{
		// Declare a memory block of size MAX_ELEMENTS in each ROW 
		elements[i] = new Profile[MAX_ELEMENTS];

		//Initially each row contains ZERO (0) elements.
		elementCount[i] = 0;
	}

}  // end default constructor


// Copy constructor - Covered in Lab 3
MyADT::MyADT(const MyADT& rhs) {

	// Copy elements and element counts from rhs
	for (unsigned int i = 0; i < MAX_ALPHA; ++i)
	{
		elementCount[i] = rhs.elementCount[i];
		elements[i] = new Profile[elementCount[i]];
		for (unsigned int j = 0; j < elementCount[i]; ++j)
		{
			elements[i][j] = Profile(rhs.elements[i][j].getUserName(), rhs.elements[i][j].getName(), rhs.elements[i][j].getEmail(), rhs.elements[i][j].getBirthday());
		}
	}
}  // end copy constructor


// Destructor
// Description: Destruct this object, releasing heap-allocated memory.
MyADT::~MyADT() {

	for (int i = 0; i < MAX_ALPHA; ++i)
	{
		delete[] elements[i];
	}
} // end destructor

// Description: Returns the total element count of elements currently stored in MyADT.
unsigned int MyADT::getElementCount() const {
	int totalElements = 0;
	for (int i = 0; i < MAX_ALPHA; i++)
	{
		totalElements += elementCount[i];
	}
	return totalElements;

}  // end getElementCount


// Description: Inserts an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
bool MyADT::insert(const Profile& newElement) {
	
	//getting ASCII value of FIRST character of username.
	int asciiValue = int(newElement.getFirstLetter());
	int currentElements;

	unsigned int i;
	
	//getting proper position in ADT array to insert this new element
	asciiValue = asciiValue - 65;
	i = asciiValue;
	currentElements = elementCount[asciiValue];
	
	//return false if array is full (No elements can be inserted)
	if(currentElements == MAX_ELEMENTS){
		cout<<"No more profiles whose usernames start with these letter can be added.";
		return false;
	}
		
		
	int insertIndex = -1;
	//checking if user name is already exist or not in array
	
	for(unsigned int x = 0; x < currentElements; x++)
	{
		//looping iteration to reach at the location where new element can be inserted into a sorted elements.
		if (!(elements[i][x] < newElement))
		{
            insertIndex = x;
            break;
		}
	}
	
	if(insertIndex != -1)
	{
		//if given username is alreary exist then this will not insert user and return false.
		//returning false means user name is already exist and no new user added in array
		if(elements[i][insertIndex] == newElement && insertIndex < currentElements) 
		{
			cout<<"Username already added.";
			return false;				
		}
	}
	//inserting element at last position
	if(insertIndex == -1)
	{
		//inserting new element at (insertIndex) as per sorting elements.
		elements[i][currentElements] = Profile(newElement.getUserName(), newElement.getName(), newElement.getEmail(), newElement.getBirthday());
		//incrementing total number of elements in array 
		currentElements++;
		elementCount[asciiValue] = currentElements;
		return true;
	}
	cout<<endl<<currentElements;
	//iterate loop from reverse to shift elements for inserting new element at position of (insertIndex)	
	for (unsigned int j = currentElements; j > insertIndex; j--)
	{
		cout<<elements[i][j-1];
		elements[i][j] = Profile(elements[i][j-1].getUserName(), elements[i][j-1].getName(), elements[i][j-1].getEmail(), elements[i][j-1].getBirthday());
	}
	
	//inserting new element at (insertIndex) as per sorting elements.
	elements[i][insertIndex] = Profile(newElement.getUserName(), newElement.getName(), newElement.getEmail(), newElement.getBirthday());

	//incrementing total number of elements in array 
	currentElements++;
	elementCount[asciiValue] = currentElements;
	return true;
	
}  // end insert


// Description: Search for target element. 
//              Returns a pointer to the element if found,
//              otherwise, returns nullptr.
Profile* MyADT::search(const Profile& target)
{
	//getting ASCII value of FIRST character of username.
	int asciiValue = int(target.getFirstLetter());
	int currentElements;
	asciiValue = asciiValue - 65;
	
	currentElements = elementCount[asciiValue];
	
	//checking if user name is already exist or not in array
	for(unsigned int x = 0; x < currentElements; x++)
	{
		//if given username is alreary exist then this will not insert user and return false.
		if(elements[asciiValue][x] == target)	//this conditional statement calling (==) OPERATOR OVERLOADING function from profile class 
		{
			Profile* ptrToProfile = &elements[asciiValue][x];
			return ptrToProfile;
			//return elements[asciiValue];		//returning Profile pointer means user name is founded
		}
	}
	
	//return NULL if user does not found
	return nullptr;

}  // end of search

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and the appropriate elementCount has been decremented.
bool MyADT::remove(const Profile& toBeRemoved)
{
	//getting ASCII value of FIRST character of username.
	int asciiValue = int(toBeRemoved.getFirstLetter());
	
	unsigned int i;
	
	//getting proper position in ADT array to insert this new element
	asciiValue = asciiValue - 65;
	i = asciiValue;
	int currentElements = elementCount[asciiValue];
	
	//if total elements are ZERO (0) means no elements founded so return FALSE
	if(currentElements <= 0)
		return false;
		
	unsigned int removeIndex = -1;
	
	//checking if user name is already exist or not in array
	//looping iteration to reach at the location of element which need to remove.
	for(unsigned int x = 0; x < currentElements; x++)
	{
		if (elements[i][x] == toBeRemoved)
		{
            removeIndex = x;
            break;
		}
	}
	
	//no elements founded to remove
	if(removeIndex == -1)
		return false;
		
	for(unsigned int x = removeIndex; x < (currentElements - 1); x++)
	{
		elements[i][x] = Profile(elements[i][x+1].getUserName(), elements[i][x+1].getName(), elements[i][x+1].getEmail(), elements[i][x+1].getBirthday());
	}
	//decrement total number of elements in array after removing element
	currentElements--;
	elementCount[asciiValue] = currentElements;
	return true;
}  // end remove


// Description: Remove all elements.
void MyADT::removeAll()
{
	for (int i = 0; i < MAX_ALPHA; ++i)
	{
		delete[] elements[i];
		elementCount[i] = 0;
	}
}  // end removeAll


void MyADT::print()
{
	int currentElements;
	for (unsigned int i = 0; i < MAX_ALPHA; i++)
	{
		currentElements = elementCount[i];
		for (unsigned int j = 0; j < currentElements; j++)
			cout<<elements[i][j];
	}

} // end of print 

//  End of implementation file
