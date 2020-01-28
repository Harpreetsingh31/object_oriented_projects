#include "Book.h"

Book::Book(string t, string a, string i, int e, int y, string id, int p): Product(t,id,p)
{
  // title   = t;
   authors = a;
   isbn    = i;
   edition = e;
   year    = y;
}

//string Book::getTitle()    { return title; }
string Book::getAuthors()  { return authors; }
string Book::getISBN()     { return isbn; }
int    Book::getEdition()  { return edition; }
int    Book::getYear()     { return year; }
void   Book::print() {

   Product::print();
    cout << endl << "Enter Author name: " << authors;
    cout << endl << "Enter ISBN:        " << isbn;
    cout << endl << "Enter edition:     " << edition;
    cout << endl << "Enter year:        " << year;

}
