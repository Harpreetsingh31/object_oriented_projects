#include "Apparel.h"

Apparel::Apparel(string n, string id, int p, string sz, string ty):Product(n,id,p),size(sz),type(ty),stock(0) //Derived class of product
{

}
string Apparel::getSize() { return size;  }
string Apparel::getType() { return type;  }
int    Apparel::getStock(){ return stock; } 
void   Apparel::incStock(){  stock++; } 
void   Apparel::decStock(){  stock--; } 
string Apparel::print()   {

   stringstream ss;
   ss << endl << "Apparel" << endl;
   ss << "Brand Name: "    << name  << endl;
   ss << "Serial Id:  "    << id    << endl;
   ss << "Price:      "    << price << endl;
   ss << "Type:       "    << type  << endl;
   ss << "Size:       "    << size  << endl;

   return ss.str();
}

void   Apparel::range(int lr,int hr){

  if(price < hr && price > lr ){
    cout << print();

  }else if (price >hr) {
    return ;

  }else if (price <lr) {
    return ;
  }
  
}

