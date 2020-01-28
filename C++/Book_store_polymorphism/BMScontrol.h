#ifndef BMS_CONTROL_H
#define BMS_CONTROL_H

#include "defs.h"
#include "UImanager.h"
#include "Dlist.h"
#include "Product.h"
#include "Course.h"

class BMScontrol {
  public:
    BMScontrol();
    ~BMScontrol();
    void launch();
    void initBMS();
  private:
    UImanager*   view;
    Dlist<Course>* courses;
    Dlist<Product>* products;
};

//Using Templated Dlist to store in both course and products
#endif

