#include "Book.h"

Book::Book(string t, string a, string i, int e, int y, string id, int p): Product(t,id,p) ,stock(0) //Derived class of product
{
   authors = a;
   isbn    = i;
   edition = e;
   year    = y;
}

string Book::getAuthors()  { return authors; }
string Book::getISBN()     { return isbn;    }
int    Book::getEdition()  { return edition; }
int    Book::getYear()     { return year; }
int    Book::getStock()    { return stock;} 
void   Book::incStock()    {  stock++; } 
void   Book::decStock()    {  stock--; } 
string Book::print() {
 
  stringstream ss;
    ss << endl <<  "Book" << endl;
    ss << "Name:        " << name    << endl ;
    ss << "Serial Id:   " << id      << endl ;
    ss << "Author name: " << authors << endl ;
    ss << "ISBN:        " << isbn    << endl ;
    ss << "Edition:     " << edition << endl ;
    ss << "Year:        " << year    << endl ;
    ss << "Price:       " << price   << endl ;

  return ss.str();
}

void   Book::range(int lr,int hr){

  if(price < hr && price > lr ){
    cout << print();

  }else if (price >hr) {
    return ;

  }else if (price <lr) {
    return ;
  }

}

