#include "Computer.h"

Computer::Computer(string n, string id, int p, string pr,string rm):Product(n,id,p),processor(pr),ram(rm),stock(0)  // Derived class of product
{

}

string Computer::getProcessor() { return processor; }
string Computer::getRam()       { return ram;  }
int    Computer::getStock()     { return stock;} 
void   Computer::incStock()     {  stock++; } 
void   Computer::decStock()     {  stock--; }
string Computer::print() {
   
   stringstream ss;
   ss << endl << "Computer"  << endl;
   ss << "Brand Name: "      << name      << endl;
   ss << "Serial Id:  "      << id        << endl;
   ss << "Processor:  "      << processor << endl;
   ss << "Price:      "      << price     << endl;   
   ss << "Ram:        "      << ram       << endl;

   return ss.str();
}

void   Computer::range(int lr,int hr){

  if(price < hr && price > lr ){
    cout << print();

  }else if (price >hr) {
    return ;

  }else if (price <lr) {
    return ;
  }
  
}

