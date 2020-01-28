#include <iostream>
#include <string>
using namespace std;

#include "ProductArray.h"

ProductArray::ProductArray() 
{ 
    size = 0;
    for (int i = 0; i < MAX_PRODUCTS; i++)
     products[i] = 0;
}

int    ProductArray::getSize()        { return size; }
Product* ProductArray::getProduct(int i) { return products[i]; }

ProductArray::~ProductArray(){

   for(int i =0 ;i<MAX_PRODUCTS;i++)
	{
	if(products[i]!=0)
	delete products[i];
	}
}

void ProductArray::add(Computer* computer)
{
  if (size == MAX_PRODUCTS)
    return;

  products[size] = computer;
  size++;
}
void ProductArray::add(Apparel* apparel)
{
  if (size == MAX_PRODUCTS)
    return;

  products[size] = apparel;
  size++;
}
void ProductArray::add(Book* book)
{
  if (size == MAX_PRODUCTS)
    return;

  products[size] = book;
  size++;
}
void ProductArray::add(Pen* pen)
{
  if (size == MAX_PRODUCTS)
    return;

  products[size] = pen;
  size++;
}

