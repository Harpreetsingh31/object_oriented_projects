#ifndef Product_H
#define Product_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"

class Product {

  public:
    Product(string="", string="",int=0);
    ~Product();
    string  getTitle();
    string  getid();
    int     getPrice();
    void    print() ;

  private:
    string    name;
    string    id;
    int       price;
};

#endif

