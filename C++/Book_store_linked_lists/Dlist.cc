#include <iostream>
#include<sstream>
#include <string>
using namespace std;

#include "Dlist.h"

Dlist::Dlist() : head(0) { }

Dlist::~Dlist()
{
  Node* currNode = head;
  Node* nextNode;

  while (currNode != 0) {
    nextNode = currNode->next;
    delete currNode->next;
    delete currNode;
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
   if(currNode==0)
	cout<<"Course not found"<<endl;
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
     
   if(prevNode==0){
      head=currNode->next;
   }else{
      prevNode=currNode->next;
      delete currNode;
   }
}

void Dlist::add(Course* course){
  Node* currNode  = head;
  Node* prevNode  = 0;
  Node* newCourse = new Node;
  newCourse->next = 0;
  newCourse->prev = 0;
  newCourse->course = course;
  //Getting to the node in middle of greater and lower
   if(currNode==0){
      head = newCourse;
      return;
    } 
    if((course->getCode() < currNode->course->getName()) && currNode->next==0){
    //Creating new head
      newCourse->next = currNode;
      head = newCourse;
      return;
    }
    if((course->getCode() > currNode->course->getName()) && currNode->next==0){
    //Adding after head
      currNode->next = newCourse;
      return;       
    }

   while (currNode != 0){ //Adding to the middle list
    if(currNode->course->getCode()==course->getCode()||currNode->course->getName()==course->getName()){
        cout << endl << "Course with the same code already Exists - Please Try Again" << endl;
        return;
    }
    if(prevNode==0){
	newCourse->next=currNode;
	head = newCourse;
	size++;
	return;
     }
     if(currNode==0){
	prevNode->next = newCourse;
	currNode->prev = newCourse;
	newCourse->next= currNode;
	newCourse->prev= prevNode;
	size++;
	return;
      }
        newCourse->next= currNode->next;
	newCourse->prev= prevNode;

	size++;
       
      }
}

string Dlist::fwdPrint(){

  Node* currNode = head;
  stringstream ss;
  string sr;
  
  while(currNode != 0) {
    ss <<"Course:     " << currNode->course->getCode() << " " << currNode->course->getName() << endl;
    ss <<"Instructor: " << currNode->course->getInstr() << endl;
    ss <<"Enrolment:  " << currNode->course->getEnrol() << endl;
    ss <<"Textbooks:  " << currNode->course->getNumBooks() << endl;
    
    sr = ss.str();
    currNode = currNode->next;
  }
  return sr;
}

string Dlist::bwdPrint(){
 
  Node* currNode = head;
  Node* prevNode = 0;
  stringstream ss;
  string sr;
  
  while(currNode != 0) {
    prevNode = currNode;
    currNode = currNode->next;
  }
 
 
  while(prevNode != 0) {
    ss <<"Course:     " << prevNode->course->getCode() << " " << prevNode->course->getName() << endl;
    ss <<"Instructor: " << prevNode->course->getInstr() << endl;
    ss <<"Enrolment:  " << prevNode->course->getEnrol() << endl;
    ss <<"Textbooks:  " << prevNode->course->getNumBooks() << endl;
    
    sr = ss.str();
    prevNode = prevNode->prev;
  }
  cout << endl;
  return sr;
}





