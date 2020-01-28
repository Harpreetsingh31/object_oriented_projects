#ifndef BOOK_H
#define BOOK_H

#include "Product.h"
#include <iostream>
#include <string>
using namespace std;

#include "defs.h"

class Book: public Product
{

  public:
    Book(string="", string="", string="", int=1, int=0, string="",int=0);
    //string  getTitle();
    string  getAuthors();
    string  getISBN();
    int     getEdition();
    int     getYear();
    void    print();
  private:
    string    title;
    string    authors;
    string    isbn;
    int       edition;
    int       year;
};

#endif

