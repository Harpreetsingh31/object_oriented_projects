#include "Pen.h"

Pen::Pen(string n, string id, int p, string cl,string ty):Product(n,id,p),color(cl),type(ty),stock(0) 
{

}
string Pen::getColor() { return color; }
string Pen::getType()  { return type;  }
int    Pen::getStock() { return stock; } 
void   Pen::incStock() {  stock++; } 
void   Pen::decStock() {  stock--; } 
string Pen::print() {
 
     stringstream ss;
     ss << endl <<  "Pen"   << endl;
     ss << "Brand Name: "   << name  << endl;
     ss << "Serial Id:  "   << id    << endl;
     ss << "Price:      "   << price << endl;
     ss << "Color:      "   << color << endl;
     ss << "Type:       "   << type  << endl;
  return ss.str();
}
  
void   Pen::range(int lr,int hr){

 if(price < hr && price > lr ){
    cout << print();

  }else if (price >hr) {
    return ;

  }else if (price <lr) {
    return ;
  }
}

