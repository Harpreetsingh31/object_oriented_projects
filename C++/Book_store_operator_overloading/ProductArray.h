#ifndef PRODUCT_ARRAY_H
#define PRODUCT_ARRAY_H

#include "Product.h"
#include "Computer.h"
#include "Apparel.h"
#include "Book.h"
#include "Pen.h"

class ProductArray
{
  public:
    ProductArray();
    ~ProductArray();
    void   add(Computer*);
    void   add(Apparel*);
    void   add(Book*);
    void   add(Pen*);
    Product* getProduct(int);
    int    getSize();
  private:
    int size;
    Product* products[MAX_PRODUCTS];
};

#endif
