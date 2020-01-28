#ifndef Apparel_H
#define Apparel_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"
#include "Product.h"

class Apparel : public Product {

  public:
    Apparel(string="", string="", int=0, string ="", string ="");
    string  getSize();
    string  getType();
    void    print();
  private:
    string    size;
    string    type;
};

/******* Apparel *******
Class takes in four strings brand name,
			     product id,
			     size (e.g. Medium),type (e.g. Hoodie)
           and one integer that stores in price.
*/
#endif

