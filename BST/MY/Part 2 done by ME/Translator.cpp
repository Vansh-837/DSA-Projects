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
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;


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
    size_t pos = 0;
    ifstream myfile("myDataFile.txt");
   
       
    if (myfile.is_open()) {
        cout << "Reading from a file:" << endl;
        while (getline(myfile, aLine)) {
            // Extract English and Translation from each line
            pos = aLine.find(delimiter);
            englishW = aLine.substr(0, pos);
            aLine.erase(0, pos + delimiter.length());
            translationW = aLine;
            WordPair aWordPair(englishW, translationW);
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

        if ((argc > 1) && (strcmp(argv[1], "display") == 0)){
            // Display content in ascending alphabetical order based on English word
            cout << "Displaying the content of the BST:" << endl;
            dictionary.displayContent(display);
        }
        else if (argc == 1) {
            // While the user has not entered CTRL+D
            cout << "Enter words to retrieve (CTRL+D to end):" << endl;
            while (getline(cin, aWord)) {
                WordPair aWordPair(aWord);
                try
                {
                    WordPair retrievedPair = dictionary.get(aWordPair);
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
                /* 
                catch (const std::exception &e) {
                    cout << e.what() << endl;
                }
                */


            }
        }
    
    }
    
    else {
        cout << "Unable to open file" << endl;
    }
    
  
    
    return 0;
}
   



