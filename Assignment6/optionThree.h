// optionThree.h

#include "TemplateBag.h"
#include "Course.h"
#include "input.h"

#ifndef OPTION_THREE_LOCK
#define OPTION_THREE_LOCK

// October 6 ~ might not be abe to use TemplateBag for course array... waiting on response from Prof
void determineSize(TemplateBag<Course> &course)
{
	int size = inputInteger("\n\t\t1> Enter the number of courses: ",true);

	course.setBagSize(size);
	cout << size << " Course(s) has been created\n" << endl;
}

void readCourseData(TemplateBag<Course> course)
{


	for (int index = 0; index < course.getSize(); index++)
	{

	}
}

#endif