#include "Product.h"

Product::Product(string n, string i, int p)
{
   name   = n;
   id     = i;
   price  = p;
}
Product::~Product(){}
string Product::getTitle()   { return name;  }
string Product::getid()      { return id;    }
int    Product::getPrice()   { return price; }
void   Product::print(){ 

   cout<<"Name:     "      << name  << endl;
   cout<<"Serial Id: "     << id    << endl;
   cout<<"Price:  "        << price << endl;

}


