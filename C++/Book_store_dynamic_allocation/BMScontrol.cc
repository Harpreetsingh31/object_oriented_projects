#include <iostream>
#include "BMScontrol.h"

using namespace std;

BMScontrol::BMScontrol()
{
	view = new UImanager();
	courses = new CourseArray();
}

BMScontrol::~BMScontrol()
{
	delete view;
	delete courses;
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
      view->getCourseData(courses);
    }
    else if (choice == 2) {
      view->printCourses(courses);
    }
    else if (choice == 3) {
      view->addTextBook(courses);
    }
    else if (choice == 4) {
      view->listTextbooks(courses);
    view->pause();
    }
  }
}

