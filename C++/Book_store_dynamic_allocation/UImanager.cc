#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include "UImanager.h"

using namespace std;

void UImanager::mainMenu(int* choice)
{
  string str;

  *choice = -1;

  cout << endl << endl << "WELCOME TO THE BOOKSTORE MANAGEMENT SYSTEM" << endl<<endl;
  cout << "  Course Management:" << endl;
  cout << "  ( 1 )  Add course" << endl;
  cout << "  ( 2 )  List all courses" << endl << endl;
  cout << "  Textbook Management:" << endl;
  cout << "  ( 3 )  Add textbook" << endl;
  cout << "  ( 4 )  List course textbooks" << endl << endl;

  cout << "  ( 0 )  Exit" << endl << endl;

  while (*choice < 0 || *choice > 4) {
    cout << "Enter your selection:  ";
    *choice = getInt();
  }
}

void UImanager::getCourseData(CourseArray* Carray)
{
  string    str = "";
  string    subj, num, name, inst;
  int       enrol;
  Course*   courseNew;
  cout << endl;

  while (str.length() != 8) {
    cout << "Enter course code (e.g. COMP2404):  ";
    getline(cin, str);
  }
  subj = str.substr(0,4);
  num  = str.substr(4);

  cout << endl << "Enter course name (e.g. Introduction to SE):  ";
  getline(cin, name);

  cout << endl << "Enter instructor name:   ";
  getline(cin, inst);

  cout << endl << "Enter enrolment:   ";
  getline(cin, str);
  stringstream ss(str);
  ss >> enrol;

  courseNew = new Course(subj, num, name, inst, enrol);
  Carray->add(courseNew);
  cout << endl << Carray->getSize();

}
void UImanager::addTextBook(CourseArray* Carray){
      
  string sr;
 
    while (sr.length() != 8) {  //valid input 
      cout << "Enter Course Code:   "; 
      getline (cin, sr);
    }   
      for(int i=0;i<Carray->getSize();++i){
	  if(sr==Carray->getCourse(i)->getCode()) //Course exists
	   { 
	            Book* bookNew;
		    string b="",a="",is="";
        	    int ed=0,ye=0;

		    cout << endl << "Enter Book name:   ";getline(cin, b);
 		    cout << endl << "Enter Author name: ";getline(cin, a);
  		    cout << endl << "Enter ISBN:        ";getline(cin, is);
		    cout << endl << "Enter edition:     ";cin>>ed;
	            cout << endl << "Enter year:        ";cin>>ye;

		    bookNew = new Book(b,a,is,ed,ye);
		    Carray->getCourse(i)->addBook(bookNew);
      	 }	
      	}
		    cout << "Course does not exist."<< endl; 
}

void UImanager::printCourses(CourseArray *arr)
{
   Course* course;
   cout << endl << endl << "ALL COURSES: " << endl << endl;
    if (arr->getSize()==0) {
        cout <<"Empty"<< endl;
    }else{
  	for (int i=0; i<arr->getSize(); ++i) {
	  course = arr->getCourse(i);
	
		cout<<"Course:     "<<course->getCode()<<course->getName()<< endl;
    		cout<<"Instructor: "<< course->getInstr()<< endl;
    		cout<<"Enrolment:  "<< course->getEnrol()<< endl;
    		cout<<"Textbooks:  ";

    		  for(int k=0;k<course->getNumBooks();++k)
		  { 
 		     if(k==0){
		       cout << course->getBooks()->getBook(k)->getTitle() << endl;
		     }else{
    		       cout <<"          "<< course->getBooks()->getBook(k)->getTitle() << endl;
		     }
		  }
    		cout<<endl;
  	}
  }
  
}

void UImanager::listTextbooks(CourseArray *Carray)
{
  Book* book;
  string sr;

  if (Carray->getSize()==0){
      cout << "No Courses" << endl;
  }else{
     while (sr.length() != 8) {  //valid input  
      cout << "Enter Course Code:   "; 
      getline (cin, sr);
    }
	//if(sr!=""){
  	  for(int i=0;i<Carray->getSize(); ++i)
	  {
	    if(sr==Carray->getCourse(i)->getCode()){      		//Course exists 					
		 for(int k = 0; k<Carray->getCourse(i)->getNumBooks(); k++)
		 { 
   				       //Header line for printing all the books			
		   cout << endl << "Title           Author         ISBN         Edition        Year" << endl;
		   book = Carray->getCourse(i)->getBooks()->getBook(k);	//getting the book from the course
		   cout << endl << book->getTitle() <<"            "<< book->getAuthors() <<"          "<< book->getISBN() << "          " << book->getEdition() << "        " << book->getYear();
	  	 }//end for printing books
	     }else{
		 cout<<"The course code doesn't exist"<<endl;
             }//end if    
           }//end for coursearray size equals zero
       
   }//end larger if
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

