#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "CourseArray.h"

#define TEST_MODE

class UImanager {
  public:
    void mainMenu(int*);
    void getCourseData(CourseArray*);
    void printCourses(CourseArray*);
    void pause();
    void addTextBook(CourseArray*);
    void listTextbooks(CourseArray*);
  private:
    int getInt();
};

#endif

