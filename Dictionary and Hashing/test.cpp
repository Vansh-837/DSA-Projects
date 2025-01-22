#include <iostream>
#include <fstream>
#include <string>
#include "Dictionary.h"
#include "Profile.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "UnableToInsertException.h"
#include "EmptyDataCollectionException.h"

using namespace std;

int main() {
  // Create a Dictionary object
    Dictionary myDictionary;

  // Read usernames from the file
    ifstream inputFile("dataFile_100_16.txt");
    if (inputFile.is_open())
    {
        cout << "open" << endl;
    }
    

    string username;
    while (getline(inputFile, username)) {
    // Create a Profile with the current username
        Profile* newProfile = new Profile(username);
        
        
        try
        {
          myDictionary.insert(newProfile);
        }
        catch(const std::exception& e)
        {
          cout << e.what() << endl;
        }
        
        
        
    }

    inputFile.close();





  // Get profiles from the dictionary
  inputFile.open("datafile_100_16.txt");
  while (getline(inputFile, username)) {
    Profile targetProfile(username);

    try {
      // Attempt to get the profile from the dictionary
      Profile* retrievedProfile = myDictionary.get(targetProfile);
      cout << "Retrieved: " << *retrievedProfile << endl;
    } catch (ElementDoesNotExistException& e) {
      cerr << "Error: " << e.what() << endl;
    }
  }

  inputFile.close();  
}
 
