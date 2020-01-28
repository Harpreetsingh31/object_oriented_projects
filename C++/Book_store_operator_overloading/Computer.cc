#include "Computer.h"

Computer::Computer(string n, string id, int p, string pr,string rm):Product(n,id,p),processor(pr),ram(rm)
{

}

string Computer::getProcessor() { return processor; }
string Computer::getRam()       { return ram; }
void   Computer::print() {

   Product::print();
   cout<<"Processor:  "      << processor << endl;
   cout<<"Ram:  "      	     << ram << endl;
}
