// optionThree.h

#include "Course.h"
#include "input.h"
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

#ifndef OPTION_THREE_LOCK
#define OPTION_THREE_LOCK

// October 6 ~ might not be abe to use TemplateBag for course array... waiting on response from Prof
void determineSize(Course* &course, int &size)
{
	size = inputInteger("\n\t\tEnter the number of courses: ",true);
	course = new Course[size];
	
	cout << "\t\t" << size << " Course(s) has been created.\n" << endl;
}


void readCourseData(Course course[], int size)
{
	if (size == 0)
	{
		cout << "\n\t\tERROR: Number of courses has not been assigned.\n" << endl;
		return;
	}

	ifstream source;

	for (int index = 0; index < size; index++)
	{
		string fileName;
		while (true)
		{
			string s;
			fileName = inputString("\n\t\t Enter a data file name for course[" + to_string(index) + "] (STOP - Return): ", true);

			if (fileName == "STOP" || fileName == "stop")
				return;

			source.open(fileName);
			if (!source.fail()) break;

			cout << "\n\t\tERROR: file, " << fileName << ", cannot be found.Please re - specify." << endl;
		}

		string line;
		getline(source, line);
		course[index].setName(line);
		while (true)
		{
			if (source.fail()) break; // not "failure", just end of file
			else
			{
				string s;
				if (getline(source, s, ','))
				{
					course[index].addStudentID(stoi(s));
					source.seekg(1, 1);
					getline(source, s, ',');
					course[index].addStudentName(s);
					getline(source, s);
					double score = stod(s);
					course[index].addStudentScore(score);
					course[index].addStudentGrade(score);
				}
			}
		}
		source.close();
		cout << "\n\t\tData from file, " << fileName << ", has been readand stored into Courses[" << index << "]" << endl;
	}

}

void idSearch(Course course[], int size)
{
	int userInput = inputInteger("\t\t\tEnter a student ID to search: ", true);
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		for(int j =0;j<course[i].getNumberOfStudents();j++)
			if (course[i].getStudentIDAt(j) == userInput)
			{
				cout << "\n\t\t\tStudent ID: " << userInput << " has been found in Course : " << course[i].getName() << endl;
				count++;
			}
	}
	if (count == 0)
		cout << "\n\t\t\tStudent ID: " << userInput << " can not be found." << endl;
}

void nameSearch(Course course[], int size)
{
	string userInput = inputString("\t\t\tEnter a student name to search: ", true);
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < course[i].getNumberOfStudents(); j++)
			if (course[i].getStudentNameAt(j) == userInput)
			{
				cout << "\n\t\t\tStudent name: " << userInput << " has been found in Course : " << course[i].getName() << endl;
				count++;
			}
	}
	if (count == 0)
		cout << "\n\t\t\tStudent Name: " << userInput << " can not be found." << endl;
}

void searchStudent(Course course[], int size)
{
	if (size == 0)
	{
		cout << "\n\t\tERROR: No data file has been read and stored into Courses.\n" << endl;
		return;
	}
	else
	{
		do
		{
			cout << "\n\t\t3> Search by" << endl;
			cout << "\t\t" + string(50, char(205)) << endl;
			cout << "\t\t\t1. ID Number" << endl;
			cout << "\t\t\t2. Name" << endl;
			cout << "\t\t" + string(50, char(196)) << endl;
			cout << "\t\t\t0. return" << endl;
			cout << "\t\t" + string(50, char(205)) << endl;

			int userInput = inputInteger("\t\t\tOption: ", 0, 2);

			switch (userInput)
			{
			case 0: return;
			case 1: idSearch(course, size); break;
			case 2: nameSearch(course, size);  break;
			default: cout << "\t\t\tERROR-3A: Invalid input. Must be from 0..2." << endl;
			}
		} while (true);
	}

}

#endif