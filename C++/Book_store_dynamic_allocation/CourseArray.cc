#include <iostream>
#include <string>
using namespace std;

#include "CourseArray.h"

CourseArray::CourseArray() 
{ 
    for (int i = 0; i < MAX_COURSES; i++)
      courses[i] = 0;
}

int    CourseArray::getSize()        { return size; }
Course* CourseArray::getCourse(int i) { return courses[i]; }

CourseArray::~CourseArray(){

   for(int i =0 ;i<MAX_COURSES;i++)
	{
	if(courses[i]!=0)
	delete courses[i];
	}
}

void CourseArray::add(Course* course)
{
  if (size == MAX_COURSES)
    return;

  courses[size] = course;
  size++;
}

