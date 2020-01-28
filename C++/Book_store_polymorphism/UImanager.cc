#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include "UImanager.h"

using namespace std; //Menu for user to interact with program

void UImanager::mainMenu(int* choice)
{
  string str;

  *choice = -1;

  cout << endl << endl << "WELCOME TO THE BOOKSTORE MANAGEMENT SYSTEM" << endl<<endl;
  cout << "  Course Management:" 	<< endl;
  cout << "  ( 1 )  Add course" 	<< endl;
  cout << "  ( 2 )  List all courses"   << endl;
  cout << "  ( 3 )  Delete course"         << endl << endl;
  cout << "  Textbook Management:" 	<< endl;
  cout << "  ( 4 )  Add textbook" 	<< endl;
  cout << "  ( 5 )  List course textbooks" << endl << endl;
  cout << "  Product Management:" 	<< endl;
  cout << "  ( 6 )  Add Computer" 	<< endl;
  cout << "  ( 7 )  Add Apparel" 	<< endl;
  cout << "  ( 8 )  Add Book" 	 	<< endl;
  cout << "  ( 9 )  Add Pen" 	 	<< endl;
  cout << "  ( 10 ) Buy Product"        << endl;

  cout << "  ( 0 )  Exit" 		   << endl << endl;

  while (*choice < 0 || *choice > 10) {
    cout << "Enter your selection:  ";
    *choice = getInt();
  }
}

void UImanager::pause()
{
  string str;

  cout << endl << "\nPress enter to continue...";
  getline(cin, str);
}

int UImanager::getInt()
{
  string str;
  int    num;

  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  return num;

}
