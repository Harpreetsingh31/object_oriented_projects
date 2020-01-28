#include "Pen.h"

Pen::Pen(string n, string id, int p, string cl,string ty):Product(n,id,p),color(cl),type(ty)
{

}
string Pen::getColor() { return color; }
string Pen::getType()  { return type; }
void   Pen::print() {

   Product::print();
   cout<<"Color:  "      << color << endl;
   cout<<"Type:  "       << type << endl;
}
