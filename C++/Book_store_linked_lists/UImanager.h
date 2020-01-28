#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "Dlist.h"

#define TEST_MODE

class UImanager {
  public:
    void mainMenu(int*);
    void getCourseData(Dlist*);
    void deleteCourse(Dlist*);
    void printCourses(Dlist*);
    void pause();
    void addTextBook(Dlist*);
    void listTextbooks(Dlist*);
  private:
    int getInt();
};

#endif

