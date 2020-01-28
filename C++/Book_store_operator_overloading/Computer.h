#ifndef computer_H
#define computer_H
#include <iostream>
#include <string>

using namespace std;

#include "defs.h"
#include "Product.h"

class Computer : public Product {

  public:
    Computer(string= "HPENVY", string= "B5T11XXXXXX", int = 99, string =" i3",string =" 128 MB");
    string  getProcessor();
    string  getRam();
    void    print();
  private:
    string    processor;
    string    ram;
};
/*
******* Computer *******
Class takes in four strings model name,
			     product id,
			     processor,ram
           and one integer that stores in price.
*/
#endif

