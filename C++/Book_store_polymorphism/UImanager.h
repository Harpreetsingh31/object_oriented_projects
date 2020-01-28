#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "Dlist.h"
#include "Course.h"
#include "Product.h"
#include "Computer.h"
#include "Apparel.h"
#include "Book.h"
#include "Pen.h"
#define TEST_MODE

class UImanager {
  public:
    void mainMenu(int*);
template <class T>
    void getCourseData(Dlist<T>*);
template <class T>
    void deleteCourse(Dlist<T>*);
template <class T>
    void deleteCourses(Dlist<T>*);
template <class T>
    void printCourses(Dlist<T>*);
    void pause();
template <class T>
    void addTextBook(Dlist<T>*);
template <class T>
    void addCourses(Dlist<T>*);
template <class T>
    void listTextbooks(Dlist<T>*);
template <class T>
    void addComputer(Dlist<T>*);
template <class T>
    void addApparel(Dlist<T>*);
template <class T>
    void addBook(Dlist<T>*);
template <class T>
    void addPen(Dlist<T>*);
template <class T>
    void printInventory(Dlist<T>*);
template <class T>
    void buyProduct(Dlist<T>*);
  private:
    int getInt();
};
template <class T>
void UImanager::getCourseData(Dlist<T>* Clist)
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

template <class T>
void UImanager::addCourses(Dlist<T>* Clist){
  
  Dlist<T> templist;
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

template <class T>
void UImanager::deleteCourse(Dlist<T>* Clist){
 
  Course* course;
  string  sr;

  while (sr.length() != 8) {  //valid input 
    cout << endl << "Enter Course Code:   "; 
    getline (cin, sr);
  } 
 
  while(Clist->getSize()!=0){
   for (int i=0;i<Clist->getSize();++i){
     
     if(sr==Clist->get(i)->getCode()) {//Course exists
       course = Clist->get(i);
       *(Clist)-=(course);
       return;
      }//end if
    }//end for 
   }//end while        
}

template <class T>
// Function uses delete function to delete one or more courses
void UImanager::deleteCourses(Dlist<T>* Clist){
  
  Course* course;
  Dlist<T> templist;
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
	  if(sr==Clist->get(i)->getCode()) {//Course exists
	   course = Clist->get(i);
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

template <class T>
void UImanager::addTextBook(Dlist<T>* Clist){
      
  string sr;

   while (sr.length() != 8) {  //valid input 
     cout << "Enter Course Code:   "; 
     getline (cin, sr);
   }   
   for(int i=0;i<Clist->getSize();++i){
     if(sr==Clist->get(i)->getCode()){ //Course exists
	   
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
        Clist->get(i)->addBook(bookNew);
     }	
   }
        cout << "Course does not exist."<< endl; 
}

template <class T>
void UImanager::printCourses(Dlist<T> *Clist)
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

template <class T>
void UImanager::listTextbooks(Dlist<T> *Clist){

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
   if(sr==Clist->get(i)->getCode()){      //Course exists 					
      for(int k = 0; k<Clist->get(i)->getNumBooks(); k++){ 
   				       //Header line for printing all the books			
	cout << endl << "Title           Author         ISBN         Edition        Year" << endl;
	book = Clist->get(i)->getBooks()->getBook(k);    //getting book from the course
	cout << endl << book->getName() <<"            "<< book->getAuthors() <<"          "<< 	book->getISBN() << "          " << book->getEdition() << "        " << book->getYear();
      }//end for printing books
   
   }else{
 	cout<<"The course code doesn't exist"<<endl;
   }//end if    
   
  }//end for courselist size equals zero
       
 }//end larger if
}

template <class T>
void UImanager::addComputer(Dlist<T>* Plist){

  string    str = "";
  string    name,id,pro,rm;
  int       pr;

  cout << endl;
  cout << endl << "Enter computer model name (e.g. HP Envy):  "; getline(cin, name);
  cout << endl << "Enter product id (e.g. B5T11XXXXXX):       "; getline(cin, id);
  cout << endl << "Enter processor  (e.g. intel i3):          "; getline(cin, pro);
  cout << endl << "Enter ram:         "        		       ; getline(cin, rm);
  cout << endl << "Enter price:       "        		       ; cin>>pr;

  Computer* comp = new Computer(name,id,pr,pro,rm);
  comp->incStock();
  Plist->add(comp); 
}

template <class T>
void UImanager::addPen(Dlist<T>* Plist){

  string    str = "";
  string    name, id , ty,cl;
  int       pr;

  cout << endl;
  cout << endl << "Enter brand name (e.g. BIC):    "	      ; getline(cin, name);
  cout << endl << "Enter product id (e.g. B5T11XXXXXX):      "; getline(cin, id);
  cout << endl << "Enter type (Fountain):   "                 ; getline(cin, ty);
  cout << endl << "Enter color:       "          	      ; getline(cin, cl);
  cout << endl << "Enter price:       "        		      ; cin>>pr;

  Pen* pen = new Pen(name,id,pr,ty,cl);
  pen->incStock();
  Plist->add(pen); 
}

template <class T>
void UImanager::addApparel(Dlist<T>* Plist){

  string    str = "";
  string    name,id,size,ty;
  int       pr;
 
  cout << endl;
  cout << endl << "Enter Apparel brand name (e.g. Bench.):  "; getline(cin, name);
  cout << endl << "Enter product id (e.g. B5T11XXXXXX):     "; getline(cin, id);
  cout << endl << "Enter type:    "                          ; getline(cin, ty);
  cout << endl << "Enter size:    "                          ; getline(cin, size);
  cout << endl << "Enter price:   "                          ; cin>>pr;
  
  Apparel* app = new Apparel(name,id,pr,size,ty);
  app->incStock();
  Plist->add(app); 
}

template <class T>
void UImanager::addBook(Dlist<T>* Plist){

  string b="",a="",is="",id="";
  int ed=0,ye=0,p=0;

  cout << endl << "Enter Book name:   ";getline(cin, b);
  cout << endl << "Enter Author name: ";getline(cin, a);
  cout << endl << "Enter ISBN:        ";getline(cin, is);
  cout << endl << "Enter edition:     ";cin>>ed;
  cout << endl << "Enter year:        ";cin>>ye;
  cout << endl << "Enter serial id:   ";cin>>id;
  cout << endl << "Enter price:       ";cin>>p;
  
  Book* book= new Book(b,a,is,ed,ye,id,p);
  book->incStock();
  Plist->add(book);

}

template <class T>
void UImanager::printInventory(Dlist<T>* Plist){

   for(int i=0;i<Plist->getSize(); ++i)  
   Plist->get(i)->print(); 
}

template <class T>
void UImanager::buyProduct(Dlist<T>* Plist){

  int lr,hr,choice =-1;
  string pro;
  Dlist<T> cart;

  cout << endl;
  while (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5) {

      cout << endl << "   (1)  List products in the Stock        ";
      cout << endl << "   (2)  List products for given price range   "; 
      cout << endl << "   (3)  Add  product  to your cart        "; 
      cout << endl << "   (4)  Products in your cart             ";
      cout << endl << "   (5)  Check out             "      <<endl;
      cout << "   (0)  Return to main menu" 		   << endl << endl;
      cout << endl << "Enter your selection:      ";
      choice = getInt();
  }
  while (1) {
  if (choice == 0){
     break;
  }else if (choice == 1){

      for(int i=0;i<Plist->getSize(); ++i)  
      cout<<Plist->get(i)->print();   
      return;

  }else if(choice == 2){
 
      cout << endl << " Enter a price range like (100 - 1000)      "; 
      cout << endl << " The  least  amount you could  pay:      "; cin  >> lr;
      cout << endl << " The highest amount you could spend:  "; cin  >> hr;
 
       for(int i=0; i<Plist->getSize();++i)
        Plist->get(i)->range(lr,hr);
        return;

  }else if(choice ==3){
       
      cout << endl << "Enter Product id:   "; 
      cin  >> pro; 
       while(Plist->getSize()!=0){
        for (int i=0;i<Plist->getSize();++i){
       
         if(pro==Plist->get(i)->getid()) {//Product exists
          cart+=(Plist->get(i));
         // return;
         }//end if
        }//end for 
       }//end while  

  }else if(choice ==4){

      //cout << endl << cart.fwdPrint();
      for(int i=0; i<cart.getSize();++i)
      cout<<cart.get(i)->print();   
      return;
     
  }else if(choice ==5){
    
     //decrementing stock of each item sold
      for(int i=0;i<Plist->getSize(); ++i){
       if(Plist->get(i)->getid() == cart.get(i)->getid())   
          Plist->get(i)->decStock();
       }
      
      *(Plist)-=cart;
      return;
 
   }//end of else if's
  }//endwhile
}

#endif
