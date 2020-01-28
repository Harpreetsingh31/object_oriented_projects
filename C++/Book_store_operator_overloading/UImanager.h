#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "Dlist.h"
#include "ProductArray.h"
#include "Computer.h"
#include "Apparel.h"
#include "Book.h"
#include "Pen.h"
#define TEST_MODE

class UImanager {
  public:
    void mainMenu(int*);
    void getCourseData(Dlist*);
    void deleteCourse(Dlist*);
    void deleteCourses(Dlist*);
    void printCourses(Dlist*);
    void pause();
    void addTextBook(Dlist*);
    void addCourses(Dlist*);
    void listTextbooks(Dlist*);
    void addComputer(ProductArray* );
    void addApparel(ProductArray* );
    void addBook(ProductArray* );
    void addPen(ProductArray* );
    void printInventory(ProductArray*);
  private:
    int getInt();
};

#endif

