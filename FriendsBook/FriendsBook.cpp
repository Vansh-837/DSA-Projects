/*
 * FriendsBook.cpp - Assignment 1
 * 
 * Class Description: Social network application (partial implementation).
 *
 * In this version, we use our MyADT.
 *
 * ***You cannot remove/change the code provided in this file.***
 *
 * Author: AL
 * Modified on: Sept. 14, 2023
 */

#include <iostream>
#include <string>
#include <cctype>
#include "Profile.h"
#include "MyADT.h"

using std::cout;
using std::ws;
using std::cin;
using std::endl;


void join(MyADT & theMembers)
{
	Profile newElement;
	string userName;
    string name; 
    string email;
    string birthday;
	
	cout<<endl<<"Enter user name : ";
	cin>>userName;
	cout<<endl<<"Enter name : ";
	cin.ignore();
	getline(cin,name);
	cout<<endl<<"Enter email : ";
	cin>>email;
	cout<<endl<<"Enter birthdate : ";
	cin.ignore();
	getline(cin,birthday);
	
	//newElement.setUserName(userName);
	newElement = Profile(userName);
	//getting ASCII value of FIRST character of username.
	int asciiValue = int(newElement.getFirstLetter());
	//cout<<asciiValue;
	if(asciiValue >= 65 && asciiValue <= 90)
	{
		newElement.setName(name);
		newElement.setEmail(email);
		newElement.setBirthday(birthday);
	}
	
	bool result = theMembers.insert(newElement);
	
	if(result){
		cout<<"Member added successfully."<<endl;
	}
		
	else{
		cout<<endl<<"Member failed to add in list.";
	}
		
	
}

void leave(MyADT & theMembers)
{
	Profile newElement;
	string userName;

	cout<<endl<<"Enter username who wants to leave : ";
	cin>>userName;
	newElement = Profile(userName);
	
	bool result = theMembers.remove(newElement);
	if(result)
		cout<<endl<<"User "<<userName<<" has been removed successfully.";
	else
		cout<<endl<<"User not founded.";
}

void search(MyADT & theMembers)
{
	Profile newElement;
	string userName;

	cout<<endl<<"Enter username you want to search : ";
	cin>>userName;
	newElement = Profile(userName);
	
	Profile* result = theMembers.search(newElement);
	if(result)
		cout<< result->getUserName() << ", " << result->getName() << ", " << result->getEmail() << " born on " << result->getBirthday() << endl; 
	else
		cout<<endl<<"User not founded.";
}

void modify(MyADT & theMembers)
{
	Profile newElement;
	string userName;

	cout<<endl<<"Enter username you want to modify : ";
	cin>>userName;
	newElement = Profile(userName);
	
	Profile* result = theMembers.search(newElement);
	if(result)
	{
		cout<<endl<<"User founded, please enter new details to update:";
		
		string name; 
		string email;
		string birthday;
		
		cout<<endl<<"Enter name : ";
		cin.ignore();
		getline(cin,name);
		cout<<endl<<"Enter email : ";
		cin>>email;
		cout<<endl<<"Enter birthdate : ";
		cin.ignore();
		getline(cin,birthday);
		
		result->setName(name);
		result->setEmail(email);
		result->setBirthday(birthday);
		
		cout<<endl<<"User details updated successfully.";
		
		cout<< result->getUserName() << ", " << result->getName() << ", " << result->getEmail() << " born on " << result->getBirthday() << endl; 
	}
	else
		cout<<endl<<"User not founded.";
}

void print(MyADT & theMembers)
{
	theMembers.print();
}

int main() {

    // Variables declaration
    MyADT members = MyADT();  // Object MyADT on the stack, its arrays on the heap
    bool done = false;
    char input = 0;
        
    // Keep going until the user exits
    while (not done) {
        // Print menu to stdout
        cout << "\n----Welcome to FriendsBook!" << endl << endl;
        cout << endl << "Enter ..." << endl;
        cout << "j -> to join FriendsBook by creating a profile." << endl;
        cout << "l -> to leave FriendsBook." << endl;
        cout << "s -> to search for a friend on FriendsBook." << endl;
        cout << "m -> to modify your profile on FriendsBook." << endl;
        cout << "p -> to print all members on FriendsBook." << endl;
        cout << "x -> to exit FriendsBook." << endl << endl;


        cout << "Your choice: ";
        cin >> input;
        cout << endl;
        input = tolower(input);
        switch(input) {
            case 'j': join(members); break;
            case 'l': leave(members); break;
            case 's': search(members); break;
            case 'm': modify(members); break;
            case 'p': print(members); break;
            case 'x': cout << "\n----Bye!\n" << endl; 
                      done = true; break;
            default: cout << "Not sure what you mean! Please, try again!" << endl;
        }
    }

    return 0;
}
