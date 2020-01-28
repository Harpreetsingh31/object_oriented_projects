#include "Course.h"

Course::Course(string s, string nu, string na, string i, int e)
{
   subj  = s;
   num   = nu;
   name  = na;
   instr = i;
   enrol = e;
   books = new BookArray();
}
Course::~Course(){
   delete books;
}
string Course::getCode()      { return subj + num; }
string Course::getName()      { return name; }
string Course::getInstr()     { return instr; }
int    Course::getEnrol()     { return enrol; }
BookArray* Course::getBooks()  { return books; }
int    Course::getNumBooks()  { return books->getSize(); }
void   Course::addBook(Book* b)  
{ 
  books->add(b);
}

