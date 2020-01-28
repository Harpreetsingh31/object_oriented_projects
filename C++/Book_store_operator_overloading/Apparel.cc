#include "Apparel.h"

Apparel::Apparel(string n, string id, int p, string sz, string ty):Product(n,id,p),size(sz),type(ty)
{

}
string Apparel::getSize() { return size; }
string Apparel::getType() { return type; }
void   Apparel::print() {

   Product::print();

   cout<<"Type:  "      << type << endl;
   cout<<"Size:  "      << size << endl;

}
