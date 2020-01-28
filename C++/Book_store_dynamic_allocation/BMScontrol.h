#ifndef BMS_CONTROL_H
#define BMS_CONTROL_H

#include "defs.h"
#include "UImanager.h"
#include "CourseArray.h"

class BMScontrol {
  public:
    BMScontrol();
    ~BMScontrol();
    void launch();
    void initBMS();
  private:
    UImanager*   view;
    CourseArray* courses;
};

#endif

