#include "Product.h"

Product::Product(string n, string i, int p) //Base class for all products (currently only these properties are printed0
{
   name   = n;
   id     = i;
   price  = p;
}
Product::~Product(){}
string Product::getName()    { return name;  }
string Product::getid()      { return id;    }
int    Product::getPrice()   { return price; }


