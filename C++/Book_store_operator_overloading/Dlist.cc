#include <iostream>
#include<sstream>
#include <string>
using namespace std;

#include "Dlist.h"

Dlist::Dlist() : head(0) { }

Dlist::~Dlist()
{
  Node* currNode = head;
  Node* nextNode = 0;

  while (currNode != 0) {
    nextNode = currNode->next;
    delete currNode;
    currNode = nextNode;
  }
}
void Dlist::cleanData(){

   Node* currNode = head;
   Node* nextNode = 0;

  while (currNode != 0) {
    nextNode = currNode->next;
    delete currNode->course;
    currNode = nextNode;
  }
}

int Dlist::getSize() const{   
  
  Node* currNode= head;
  int i=0;

  while(currNode != 0){
    i++;
    currNode=currNode->next;
   }
   
   return i;
}

Course* Dlist::getCourse(int index){

  Node* currNode= head;
  int i=0;

  while(currNode != 0){
    if (index==i)
        return currNode->course;
    i++;
    currNode=currNode->next;
   }
  return 0;
}

Course* Dlist::findCourse(string course){

  Node* currNode = head;
  Node* prevNode = 0;

  while (currNode != 0) {
   if(currNode->course->getName() == course)
        return currNode->course;

    prevNode=currNode;
    currNode=currNode->next;    
   }
  return 0;
}

void Dlist::remCourse(Course* course){

  Node* currNode = head;
  Node* prevNode = 0;

   while (currNode != 0) {
    if(currNode->course->getName() == course->getName())
	break;
      prevNode=currNode;
      currNode=currNode->next;   
   }

   if(currNode == 0) {
      cout << "No courses" << endl;
      return;
    }
   
   //removing head
   if(prevNode == 0)
   {
      head = currNode->next;
	  if (head != 0)		//checking for empty list
		head->prev = 0;
   }
   else
   {
      prevNode->next = currNode->next;			//removing from end
	  if (currNode->next != 0)
		  currNode->next->prev = prevNode;		//removing from middle
   }
   delete currNode->course;
   delete currNode;
}

void Dlist::add(Course* course){
  Node* currNode  = head;
  Node* prevNode  = 0;
  Node* newNode = new Node;
  newNode->next = 0;
  newNode->prev = 0;
  newNode->course = course;

  //Empty list
  if(head == 0)
  {
	head = newNode;
    return;
  } 

  //find insertion position
  while (currNode != 0)
  {
	  if (course->getCode() < currNode->course->getCode())
	  {
		  break;
	  }
	  prevNode = currNode;
	  currNode = currNode->next;
  }

  //Adding before head
  if (prevNode == 0)
  {
	  head = newNode;
	  newNode->next = currNode;
	  currNode->prev = newNode;
	  return;
  }

  //Adding to end
  if (currNode == 0)
  {
	  prevNode->next = newNode;
	  newNode->prev = prevNode;
	  return;
  }

  //Adding to middle
  prevNode->next = newNode;
  newNode->prev = prevNode;
  newNode->next = currNode;
  currNode->prev = newNode;
  return;
}

string Dlist::fwdPrint(){

  Node* currNode = head;
  stringstream ss;
  
  while(currNode != 0) {
    ss <<"Course:     " << currNode->course->getCode() << " " << currNode->course->getName() << endl;
    ss <<"Instructor: " << currNode->course->getInstr() << endl;
    ss <<"Enrolment:  " << currNode->course->getEnrol() << endl;
    ss <<"Textbooks:  " << currNode->course->getNumBooks() << endl;
    
    currNode = currNode->next;
  }
  return ss.str();
}

string Dlist::bwdPrint(){
 
  Node* currNode = head;
  Node* prevNode = 0;
  stringstream ss;
  
  while(currNode != 0) {
    prevNode = currNode;
    currNode = currNode->next;
  }
 
  while(prevNode != 0) {
    ss <<"Course:     " << prevNode->course->getCode() << " " << prevNode->course->getName() << endl;
    ss <<"Instructor: " << prevNode->course->getInstr() << endl;
    ss <<"Enrolment:  " << prevNode->course->getEnrol() << endl;
    ss <<"Textbooks:  " << prevNode->course->getNumBooks() << endl;
    
    prevNode = prevNode->prev;
  }
  cout << endl;
  return ss.str();
}

void Dlist::operator+=(Course* c) {
   
   this->add(c);

}
void Dlist::operator+=(Dlist& L){
   
  Node* otherNode = L.head;

  while(otherNode!=0){
   *(this)+=otherNode->course;
   otherNode=otherNode->next;
  }
}

void Dlist::operator-=(Course* c) {
   
   this->remCourse(c);

}

void Dlist::operator-=(Dlist& L){
   
   Node* otherNode = L.head;
   
   while(otherNode!=0){
   *(this)-=otherNode->course;
   otherNode=otherNode->next;
   } 
}

ostream& operator<<(ostream& out, Dlist& L){
 
    out << L.fwdPrint() << endl;
    return out;
}




