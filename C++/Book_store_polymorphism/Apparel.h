#ifndef Apparel_H
#define Apparel_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include "defs.h"
#include "Product.h"

class Apparel : public Product {

  public:
    Apparel(string="", string="", int=0, string ="", string ="");
    string  getSize();
    string  getType();
    string    print();
    void    range(int,int);
    void    incStock();
    void    decStock();
    int     getStock();
   
  private:
    string    size;
    string    type;
       int    stock;
};


/******* Apparel *******s
Class takes in four strings brand name,
			     product id,
			     size (e.g. Medium),type (e.g. Hoodie)
           and one integer that stores in price.
*/
#endif

