#ifndef BOOK_ARRAY_H
#define BOOK_ARRAY_H

#include "Book.h"

class BookArray
{
  public:
    BookArray();
    void add(Book*);
    Book* getBook(int);
    int  getSize();
    ~BookArray();
  private:
    int  size;
    Book* books[MAX_BOOKS];
};

#endif
