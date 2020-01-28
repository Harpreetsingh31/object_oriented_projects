#ifndef DLIST_H
#define DLIST_H

#include "Course.h"

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
    void add(Course*);
    int  getSize() const;
    void remCourse(Course*);
    Course* findCourse(string);
    string fwdPrint();
    string bwdPrint();
    Course* getCourse(int);
  private:
    Node* head;
    int size;
};
#endif
