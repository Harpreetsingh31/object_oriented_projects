#ifndef Pen_H
#define Pen_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include "defs.h"
#include "Product.h"

class Pen : public Product {

  public:
    Pen(string="", string="", int=0, string ="",string ="");
    string  getColor();
    string  getType();
    string  print();
    void    range(int,int);
    void    decStock();
    void    incStock();
     int    getStock();
  private:
    string    color;
    string    type;
       int    stock;
};



/******* Pen *******
Class takes in four strings brand name,
			     product id,
			     Color (e.g. red),type (e.g. Fountain)
           and one integer that stores in price.
*/
#endif

