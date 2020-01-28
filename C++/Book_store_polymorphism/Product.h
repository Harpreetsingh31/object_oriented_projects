#ifndef Product_H
#define Product_H

#include <iostream>
#include <string>
//#include "Dlist.h"
using namespace std;

#include "defs.h"

class Product {

  public:
    Product(string="", string="",int=0);
    ~Product();
    string  getName();
    string  getid();
    int     getPrice();
    virtual void    range(int,int) =0;
    virtual void    decStock() =0;
    virtual string  print()    =0;
    virtual int     getStock() =0;

  protected:
    string    name;
    string    id;
    int       price;
};

#endif

