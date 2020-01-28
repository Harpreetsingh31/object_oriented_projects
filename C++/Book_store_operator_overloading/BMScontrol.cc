#include <iostream>
#include "BMScontrol.h"

using namespace std;

BMScontrol::BMScontrol()
{
	view = new UImanager();
	courses = new Dlist();
        products = new ProductArray();
}

BMScontrol::~BMScontrol()
{
	delete view;
        courses->cleanData();
	delete courses;
        delete products;
}


void BMScontrol::launch()
{
  int    choice;
  string code;

  while (1) {
    choice = -1;
    view->mainMenu(&choice);
    if (choice == 0) {
      break;
    }
    else if (choice == 1) {
      view->addCourses(courses);
    }
    else if (choice == 2) {
      view->printCourses(courses);
    }
    else if (choice ==3)  {
      view->deleteCourses(courses);
    }
    else if (choice == 4) {
      view->addTextBook(courses);
    }
    else if (choice == 5) {
      view->listTextbooks(courses);
    }
    else if (choice == 6)  {
      view->addComputer(products);
    }
    else if (choice == 7) {
      view->addApparel(products);
    }
    else if (choice == 8) {
      view->addBook(products);
    }
    else if (choice == 9) {
      view->printInventory(products);
    }  
    view->pause();
    
  }
}

