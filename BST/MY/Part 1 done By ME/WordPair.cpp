/*
 * WordPair.cpp
 * 
 * Description: Models an English word and its translation in another language.
 * 
 * Author: AL
 * Date of last modification: Oct. 2023
 */
 
#include "WordPair.h"

// Constructors
WordPair::WordPair() {
   this->english = "";
   this->translation = "";
}

WordPair::WordPair(string english) {
   this->english = english;
   this->translation = "";
}

WordPair::WordPair(string english, string translation) {
   this->english = english;
   this->translation = translation;
}

// Getters
string WordPair::getEnglish() const {
   return this->english;
}

string WordPair::getTranslation() const {
   return this->translation;
}

// Setters
void WordPair::setEnglish(string english) {
   this->english = english;
   return;
}

void WordPair::setTranslation(string translation) {
   this->translation = translation;
   return;
}

// Overloaded Operators
bool WordPair::operator==(const WordPair& rhs) const {
   return (this->english.compare(rhs.getEnglish()) ) == 0;
} 

bool WordPair::operator<(const WordPair& rhs) const {
   return (this->english.compare(rhs.getEnglish()) ) < 0;
} 

bool WordPair::operator>(const WordPair& rhs) const {
   return (this->english.compare(rhs.getEnglish()) ) > 0;
} 

// For testing purposes!
// Description: Prints the content of "wP".
ostream & operator<<(ostream & os, const WordPair & wP) {
   
   os << wP.english << ":" << wP.translation << endl; 
        
   return os;
} 
