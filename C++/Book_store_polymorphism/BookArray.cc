#include <iostream>
#include <string>
using namespace std;

#include "BookArray.h"

BookArray::BookArray() 
{ 
   for (int i = 0; i < MAX_BOOKS; i++)
    books[i] = 0;
}

int   BookArray::getSize()        { return size; }
Book*  BookArray::getBook(int i)   { return books[i]; }
BookArray::~BookArray()
{
   for(int i =0 ;i<MAX_BOOKS;i++)
    {
	if(books[i]!=0)
	delete books[i];
    }
}
void BookArray::add(Book* book)
{
  if (size == MAX_BOOKS)
    return;

  books[size] = book;
  size++;
}

