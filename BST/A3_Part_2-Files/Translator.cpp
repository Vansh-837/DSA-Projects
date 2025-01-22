/*
 * Translator.cpp
 * 
 * Description: Drives the user-based translation of Dictionary class. 
 *
 * Author: AL
 * Last Modification Date: Oct. 2023
 */

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "Dictionary.h"
#include "WordPair.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"
#include "UnableToInsertException.h"


using std::cin;
using std::cout;
using std::endl;
using std::ifstream;

//display format
void display(WordPair &anElement) {
  cout << anElement;
}

int main(int argc, char *argv[]) {

    Dictionary dictionary;
    string aLine = "";
    string aWord = "";
    string englishW = "";
    string translationW = "";
    string delimiter = ":";
    string filename="myDataFile.txt";
    size_t pos = 0;
    ifstream myfile(filename);
   
       
    if (myfile.is_open()) {
        cout << "Reading from a file:" << endl;
        while (getline(myfile, aLine)) {
            // Seperate english and translated word in each line
            pos = aLine.find(delimiter);
            englishW = aLine.substr(0, pos);
            aLine.erase(0, pos + delimiter.length());
            translationW = aLine;
            WordPair aWordPair(englishW, translationW);
            //insert using try/catch block
            try
            {
                dictionary.put(aWordPair);
            }
            catch(const std::exception& e)
            {
                cout<< e.what() << endl;
            }
            
            
        }
        myfile.close();

        // If user entered "display" at the command line
        if ((argc > 1) && (strcmp(argv[1], "display") == 0)){
            //ascending alphabetical order based on english word
            cout << "Displaying the content of the BST:" << endl;
            dictionary.displayContent(display);
        }
        else if (argc == 1) {
            // while user has not entered CTRL+D
            cout << "Enter words to retrieve (CTRL+D to end):" << endl;
            while (getline(cin, aWord)) {
                //retrieve using try/catch block
                WordPair aWordPair(aWord);
                try
                {
                    WordPair retrievedPair = dictionary.get(aWordPair);
                    //get the translated word
                    cout << "Translation: " << retrievedPair.getTranslation()<< endl;
                }
                catch(ElementDoesNotExistException &e)
                {
                    cout<<"**NOT FOUND**"<< endl;
                }
                catch(EmptyDataCollectionException &e)
                {
                    cout<<"Dictionary is empty."<< endl;
                }
                


            }
        }
    
    }
    
    else {
        cout << "Unable to open file" << endl;
    }
    
    return 0;
}
   



