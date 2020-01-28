#ifndef DLIST_H
#define DLIST_H

#include "Course.h"
#include <iostream>
class Dlist
{

  class Node
  {
    friend class Dlist;
    private:
      Course* course;
      Node* next;
      Node* prev;
  };
  public:
    Dlist();
    ~Dlist();
    int     getSize() const;
    void    cleanData();
    void    add(Course*);    
    void    remCourse(Course*);
    void    operator+=(Course*);
    void    operator+=(Dlist&);
    void    operator-=(Course*);
    void    operator-=(Dlist&);
    friend ostream& operator<<(ostream&, Dlist&);
    string  fwdPrint();
    string  bwdPrint();
    Course* getCourse(int);
    Course* findCourse(string);   

  private:
    Node* head;
};
#endif
