#ifndef DLIST_H
#define DLIST_H

#include <iostream>
#include<sstream>
#include <string>
using namespace std;

template <class T>
class Dlist
{
  template <class V>
  class Node
  {
    friend class Dlist;
    private:
      T* data;
      Node<T>* next;
      Node<T>* prev;
  };
  public:
    Dlist();
    ~Dlist();
    int     getSize() const;
    void    cleanData();
    void    add(T*);    
    void    remove(T*);
    void    operator+=(T*);
    void    operator+=(Dlist&);
    void    operator-=(T*);
    void    operator-=(Dlist&);
    template <class X>
    friend ostream& operator<<(ostream&, Dlist<X>&);
    string  fwdPrint();
    string  bwdPrint();
    T* get(int);
    T* find(string);   

  private:
    Node<T>* head;
};

template <class T>
Dlist<T>::Dlist() : head(0) { }

template <class T>
Dlist<T>::~Dlist()
{
  Node<T>* currNode = head;
  Node<T>* nextNode = 0;

  while (currNode != 0) {
    nextNode = currNode->next;  //destructor (clean up Dlist
    delete currNode;
    currNode = nextNode;
  }
}

template <class T>
void Dlist<T>::cleanData(){

   Node<T>* currNode = head;
   Node<T>* nextNode = 0;

  while (currNode != 0) {
    nextNode = currNode->next; //delete all the node data
    delete currNode->data;
    currNode = nextNode;
  }
}

template <class T>
int Dlist<T>::getSize() const{   //current size of list
  
  Node<T>* currNode= head;
  int i=0;

  while(currNode != 0){   
    i++;
    currNode=currNode->next;
   }
   
   return i;
}

template <class T>
T* Dlist<T>::get(int index){ //return the course at the given index

  Node<T>* currNode= head;
  int i=0;

  while(currNode != 0){
    if (index==i)
        return currNode->data;
    i++;
    currNode=currNode->next; 
   }
  return 0;
}

template <class T>
T* Dlist<T>::find(string object){ // find a course by comapring the name

  Node<T>* currNode = head;
  Node<T>* prevNode = 0;

  while (currNode != 0) {
   if(currNode->data->getName() == object)
        return currNode->course;

    prevNode=currNode;
    currNode=currNode->next;    
   }
  return 0;
}

template <class T>
void Dlist<T>::remove(T* object){ // remove a course from the list

  Node<T>* currNode = head;
  Node<T>* prevNode = 0;

   while (currNode != 0) {
    if(currNode->data->getName() == object->getName())
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
   delete currNode->data;
   delete currNode;
}

template <class T>
void Dlist<T>::add(T* object){
  Node<T>* currNode  = head;
  Node<T>* prevNode  = 0;
  Node<T>* newNode = new Node<T>;
  newNode->next = 0;
  newNode->prev = 0;
  newNode->data = object;

  //Empty list
  if(head == 0)
  {
	head = newNode;
    return;
  } 

  //find insertion position
  while (currNode != 0)
  {
	  if (object->getName() < currNode->data->getName())
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

template <class T>
string Dlist<T>::fwdPrint(){

  Node<T>* currNode = head;
  stringstream ss;
  
  while(currNode != 0) {
    ss << currNode->data->print() << endl;
    
    currNode = currNode->next;
  }
  return ss.str();
}

template <class T>
string Dlist<T>::bwdPrint(){
 
  Node<T>* currNode = head;
  Node<T>* prevNode = 0;
  stringstream ss;
  
  while(currNode != 0) {
    prevNode = currNode;
    currNode = currNode->next;
  }
 
  while(prevNode != 0) {
    ss << prevNode->data->print() <<endl;
    
    prevNode = prevNode->prev;
  }
  cout << endl;
  return ss.str();
}

template <class T>
void Dlist<T>::operator+=(T* c) { //list + single course
   
   this->add(c);

}

template <class T>
void Dlist<T>::operator+=(Dlist& L){ // list + another list
   
  Node<T>* otherNode = L.head;

  while(otherNode!=0){
   *(this)+=otherNode->data;
   otherNode=otherNode->next;
  }
}

template <class T>
void Dlist<T>::operator-=(T* object) { //list - a single course
   
   this->remove(object);

}

template <class T>
void Dlist<T>::operator-=(Dlist& L){ //list - another list of courses
   
   Node<T>* otherNode = L.head;
   
   while(otherNode!=0){
   *(this)-=otherNode->data;
   otherNode=otherNode->next;
   } 
}

template <class T>
ostream& operator<<(ostream& out, Dlist<T>& L){ // overloaded ostram for printing courses
 
    out << L.fwdPrint() << endl;
    return out;
}
#endif

