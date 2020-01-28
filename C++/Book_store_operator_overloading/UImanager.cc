#include <iostream>
#include <stdio.h>
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
  cout << "  ( 9 )  Print Inventory"    << endl;
  cout << "  ( 0 )  Exit" 		   << endl << endl;

  while (*choice < 0 || *choice > 9) {
    cout << "Enter your selection:  ";
    *choice = getInt();
  }
}

void UImanager::getCourseData(Dlist* Clist)
{
  string    str = "";
  string    subj, num, name, inst;
  int       enrol;
  Course*   courseNew;
  cout << endl;

  while (str.length() != 8) {
    cout << "Enter course code (e.g. COMP2404):  "; getline(cin, str);
  } 

  subj = str.substr(0,4);
  num  = str.substr(4);

  cout << endl << "Enter course name (e.g. Introduction to SE):  "; getline(cin, name);
  cout << endl << "Enter instructor name:  "			  ; getline(cin, inst);
  cout << endl << "Enter enrolment:        "			  ; getline(cin, str);
  stringstream ss(str);
  ss >> enrol;

  courseNew = new Course(subj, num, name, inst, enrol);
  *(Clist)+=(courseNew);
  cout << endl << Clist->getSize();
    
}
void UImanager::addCourses(Dlist* Clist){
  
  Dlist templist;

  int num,choice;
  choice = -1;
  
  while (choice != 1 && choice != 2) {
    cout << "Choose (1) to add one course and (2) to add list of courses: ";
    choice = getInt();
  }
 
  if (choice == 1){
     getCourseData(Clist);
  }else if(choice == 2){
     cout <<"Number of courses to be added: ";
     cin>>num;
     
     for(int i=0;i<num;i++){
       getCourseData(&templist);
     }
    *(Clist)+=templist;  
   }
     
}

void UImanager::deleteCourse(Dlist* Clist){
 
  Course* course;
  string  sr;

  while (sr.length() != 8) {  //valid input 
    cout << endl << "Enter Course Code:   "; 
    getline (cin, sr);
  } 
 
  while(Clist->getSize()!=0){
   for (int i=0;i<Clist->getSize();++i){
     
     if(sr==Clist->getCourse(i)->getCode()) {//Course exists
       course = Clist->getCourse(i);
       *(Clist)-=(course);
       return;
      }//end if
    }//end for 
   }//end while        
}

// Function uses delete function to delete one or more courses
void UImanager::deleteCourses(Dlist* Clist){
  
  Course* course;
  Dlist templist;
  string sr ="";
  int num,choice;
  choice = -1;
  cout << endl;

  while (choice != 1 && choice != 2) {
    cout << "Choose (1) to delete one course and (2) to delete list of courses: ";
    choice = getInt();
  }
 
  if (choice == 1){
      deleteCourse(Clist);
  }else if(choice == 2){

   cout << endl <<"Number of courses to be deleted: ";
   cin>>num;

    if (num <=  Clist->getSize()) {
     for(int i=0;i<num;i++){
        while (sr.length() != 8) {  //valid input 
         cout << endl << "Enter Course Code:   "; 
         getline (cin, sr);
        } 

        for (int i=0;i<Clist->getSize();++i){
	  if(sr==Clist->getCourse(i)->getCode()) {//Course exists
	   course = Clist->getCourse(i);
           templist+=course;
	  }//end if        
        }//end for  
	 sr ="";

      }//end for
	     *(Clist)-=templist;
   } else {
	cout << "Courses to delete is larger than actual list" << endl;
	return;
   }// end else if
  }
}

void UImanager::addTextBook(Dlist* Clist){
      
  string sr;

   while (sr.length() != 8) {  //valid input 
     cout << "Enter Course Code:   "; 
     getline (cin, sr);
   }   
   for(int i=0;i<Clist->getSize();++i){
     if(sr==Clist->getCourse(i)->getCode()){ //Course exists
	   
	Book* bookNew;
        string b="",a="",is="",id="";
        int ed=0,ye=0,p=0;

        cout << endl << "Enter Book name:   ";getline(cin, b);
        cout << endl << "Enter Author name: ";getline(cin, a);
        cout << endl << "Enter ISBN:        ";getline(cin, is);
        cout << endl << "Enter edition:     ";cin>>ed;
        cout << endl << "Enter year:        ";cin>>ye;
        cout << endl << "Enter Serial id:   ";cin>>id;
        cout << endl << "Enter Price:       ";cin>>p;
        bookNew = new Book(b,a,is,ed,ye,id,p);
        Clist->getCourse(i)->addBook(bookNew);
     }	
   }
        cout << "Course does not exist."<< endl; 
}

void UImanager::printCourses(Dlist *Clist)
{
   Course* course;
   string string;
 
   cout << endl << endl << "ALL COURSES: " << endl << endl;
   if (Clist->getSize()==0) {
        cout << endl << "Empty"<< endl;
   }else{
	cout << endl << "Forward printing"   << endl;
	cout << *Clist; //using operator '<<'
	cout << endl << "Reverse printing"   << endl;
        cout << endl << Clist->bwdPrint()    <<endl;
   }
}

void UImanager::listTextbooks(Dlist *Clist){

 Book* book;
 string sr;

 if (Clist->getSize()==0){
    cout << "No Courses" << endl;
 }else{
   while (sr.length() != 8) {  //valid input  
    cout << "Enter Course Code:   ";   
    getline (cin, sr);
    }

  for(int i=0;i<Clist->getSize(); ++i){  
   if(sr==Clist->getCourse(i)->getCode()){      //Course exists 					
      for(int k = 0; k<Clist->getCourse(i)->getNumBooks(); k++){ 
   				       //Header line for printing all the books			
	cout << endl << "Title           Author         ISBN         Edition        Year" << endl;
	book = Clist->getCourse(i)->getBooks()->getBook(k);    //getting book from the course
	cout << endl << book->getTitle() <<"            "<< book->getAuthors() <<"          "<< 	book->getISBN() << "          " << book->getEdition() << "        " << book->getYear();
      }//end for printing books
   
   }else{
 	cout<<"The course code doesn't exist"<<endl;
   }//end if    
   
  }//end for courselist size equals zero
       
 }//end larger if
}

void UImanager::addComputer(ProductArray* Parray){

  string    str = "";
  string    name,id,pro,rm;
  int       pr;

  cout << endl;
  cout << endl << "Enter computer model name (e.g. HP Envy):  "; getline(cin, name);
  cout << endl << "Enter product id (e.g. B5T11XXXXXX):       "; getline(cin, id);
  cout << endl << "Enter processor  (e.g. intel i3):          "; getline(cin, pro);
  cout << endl << "Enter ram:         "        		       ; getline(cin, rm);
  cout << endl << "Enter price:       "        		       ; cin>>pr;

  Parray->add(new Computer(name,id,pr,pro,rm) ); 
}

void UImanager::addPen(ProductArray* Parray){

  string    str = "";
  string    name, id , ty,cl;
  int       pr;

  cout << endl;
  cout << endl << "Enter brand name (e.g. BIC):    "	      ; getline(cin, name);
  cout << endl << "Enter product id (e.g. B5T11XXXXXX):      "; getline(cin, id);
  cout << endl << "Enter type (Fountain):   "                 ; getline(cin, ty);
  cout << endl << "Enter color:       "          	      ; getline(cin, cl);
  cout << endl << "Enter price:       "        		      ; cin>>pr;

  Parray->add(new Computer(name,id,pr,ty,cl) ); 
}

void UImanager::addApparel(ProductArray* Parray){

  string    str = "";
  string    name,id,size,ty;
  int       pr;
 
  cout << endl;
  cout << endl << "Enter Apparel brand name (e.g. Bench.):  "; getline(cin, name);
  cout << endl << "Enter product id (e.g. B5T11XXXXXX):     "; getline(cin, id);
  cout << endl << "Enter type:    "                          ; getline(cin, ty);
  cout << endl << "Enter size:    "                          ; getline(cin, size);
  cout << endl << "Enter price:   "                          ; cin>>pr;
  

  Parray->add(new Apparel(name,id,pr,size,ty)); 
}

void UImanager::addBook(ProductArray* Parray){

  string b="",a="",is="",id="";
  int ed=0,ye=0,p=0;

  cout << endl << "Enter Book name:   ";getline(cin, b);
  cout << endl << "Enter Author name: ";getline(cin, a);
  cout << endl << "Enter ISBN:        ";getline(cin, is);
  cout << endl << "Enter edition:     ";cin>>ed;
  cout << endl << "Enter year:        ";cin>>ye;
  cout << endl << "Enter serial id:   ";cin>>id;
  cout << endl << "Enter price:       ";cin>>p;
  
  Parray->add(new Book(b,a,is,ed,ye,id,p));

}

void UImanager::printInventory(ProductArray* Parray){
  
   for(int i=0;i<Parray->getSize(); ++i)  
   Parray->getProduct(i)->print();  

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
