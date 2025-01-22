/*
 * Dictionary.h
 * 
 * Description: Dictonary data collection ADT class.
 *              BST-based implementation.
 *              Duplicated elements not allowed.
 *              
 * Author: AL
 * Date of last modification: Oct. 2023
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "BST.h"

class Dictionary {
   
private:

/* You cannot change the following data member of this class. */
    BST * keyValuePairs = nullptr;                  
   
/* Feel free to add private methods to this class. */
   
public:

/* You cannot change the prototype of the public methods of this class.
   Remember, if you add public methods to this class, our test driver 
   - the one we will use to mark this assignment - will not know about them
   since we will use these public method prototypes to create our test driver. */

   // Constructors and destructor:
   Dictionary();                             // Default constructor
   ~Dictionary();                            // Destructor 
   
   // Dictionary operations
   
   // Description: Returns the number of elements currently stored in the Dictionary.
   unsigned int getElementCount() const;
    
   // Description: Puts "newElement" (association of key-value) into the Dictionary.
   // Precondition: "newElement" does not already exist in the Dictionary.
   //               This is to say: no duplication allowed.
   // Exception: Throws the exception "UnableToInsertException" 
   //            when newElement cannot be inserted in the Dictionary.  
   // Exception: Throws the exception "ElementAlreadyExistsException" 
   //            if "newElement" already exists in the Dictionary.  
   void put(WordPair & newElement);
 
   // Description: Gets "newElement" (i.e., the associated value of a given key) 
   //              from the Dictionary.
   // Precondition: Dictionary is not empty.
   // Exception: Throws the exception ElementDoesNotExistException
   //            if the key is not found in the Dictionary.
   // Exception: Throws the exception EmptyDataCollectionException if the Dictionary is empty.
   WordPair & get(WordPair & targetElement) const;

   // Description: Prints the content of the Dictionary.
   // Precondition: Dictionary is not empty.
   // Exception: Throws the exception EmptyDataCollectionException if the Dictionary is empty.
   void displayContent(void visit(WordPair &)) const;
   
}; // end Dictionary
#endif
