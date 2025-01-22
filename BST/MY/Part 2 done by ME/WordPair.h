/*
 * WordPair.h
 * 
 * Description: Models an English word and its translation in another language.
 * 
 * Author: AL
 * Date of last modification: Oct. 2023
 */

#ifndef WORD_PAIR_H
#define WORD_PAIR_H

#include <string>
#include <ostream>

using std::string;
using std::ostream;
using std::endl;

class WordPair {

private:
   string english;
   string translation;
   
public:
   // Constructors
   WordPair() ;
   WordPair(string english) ;
   WordPair(string english, string translation) ;

   // Getters
   string getEnglish() const ;
   string getTranslation() const ;

   // Setters
   void setEnglish(string english) ;
   void setTranslation(string translation) ;

   // Overloaded Operators
   bool operator==(const WordPair& rhs) const;
   bool operator<(const WordPair& rhs) const;
   bool operator>(const WordPair& rhs) const;

   // For testing purposes!
   // Description: Prints the content of "wP".
   friend ostream & operator<<(ostream & os, const WordPair & wP);

}; // end of WordPair.h
#endif
