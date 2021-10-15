// optionThree.h

#include "Course.h"
#include "input.h"
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

#ifndef OPTION_THREE_LOCK
#define OPTION_THREE_LOCK


// Precondition: valid dynamic reference Course object and valid reference integer size
// Postcondition: Create the number of courses assigned by user
void determineSize(Course* &course, int &size)
{
	size = inputInteger("\n\t\tEnter the number of courses: ",true);
	course = new Course[size];
	if (size == 1)
		cout << "\t\t" << size << " course has been created.\n" << endl;
	else
		cout << "\t\t" << size << " courses has been created.\n" << endl;
}

// Precondition: valid dynamic reference Course class and valid integer size
// Postcondition: read contents from file and store them in Course object
void readCourseData(Course*& course, int size)
{
	if (size == 0)
	{
		cout << "\n\t\tERROR: Number of courses has not been assigned.\n" << endl;
		return;
	}
	ifstream source;
	course = new Course[size];
	for (int index = 0; index < size; index++)
	{
		string fileName;
		while (true)
		{
			string s;
			fileName = inputString("\n\t\tEnter a data file name for course[" + to_string(index) + "] (STOP - Return): ", true);

			if (fileName == "STOP" || fileName == "stop")
			{
				course = new Course[size];
				return;
			}
			source.open(fileName);
			if (!source.fail()) break;

			cout << "\n\t\tERROR: file, " << fileName << ", cannot be found. Please re - specify." << endl;
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

		cout << "\n\t\tData from file, " << fileName << ", has been read and stored into Courses[" << index << "]" <<  "." << endl;
	}

}


// Precondition: valid static Course array and valid integer size
// Postcondition: search a student ID and show where it is
void idSearch(Course course[], int size)
{
	int userInput = inputInteger("\t\t\tEnter a student ID to search: ", true);
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		for(int j =0;j<course[i].getNumberOfStudents();j++)
			if (course[i].getStudentIDAt(j) == userInput)
			{

				cout << "\n\t\t\tStudent ID: " << userInput << " has been found in Course : " << course[i].getName() << "." << endl;
				count++;
			}
	}
	if (count == 0)
		cout << "\n\t\t\tStudent ID: " << userInput << " can not be found." << endl;
}

// Precondition: valid static Course array and valid integer size
// Postcondition: search a student name and show where it is
void nameSearch(Course course[], int size)
{
	string userInput = inputString("\t\t\tEnter a student name to search: ", true);
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < course[i].getNumberOfStudents(); j++)
			if (course[i].getStudentNameAt(j) == userInput)
			{
				cout << "\n\t\t\tStudent name: " << userInput << " has been found in Course: " << course[i].getName() << "." << endl;
				count++;
			}
	}
	if (count == 0)
		cout << "\n\t\t\tStudent Name: " << userInput << " can not be found." << endl;
}

// Precondition: valid static Course array and valid integer size
// Postcondition: give user the options between searching the student ID or student's name
void searchStudent(Course course[], int size)
{
	if (size == 0 || course[0].getName() == "Unknown")
	{
		cout << "\n\t\tERROR: No data file has been read and stored into Courses.\n" << endl;
		return;
	}
	else
	{
		do
		{
			cout << "\n\t\tSearch by" << endl;
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

// Precondition: valid reference Course object
// Postcondition: search the student ID and delete it
void searchAndDeleteStudent(Course &course)
{
	int userInput = inputInteger("\t\t\tEnter a student ID to search and delete: ", true);
	int count = 0;
	for (int i = 0; i < course.getNumberOfStudents(); i++)
		if (course.getStudentIDAt(i) == userInput)
		{
			cout << "\n\t\t\tStudent ID: " << userInput << " has been found in Course : " << course.getName() << "." << endl;
			course.removeStudentAt(course,i);
			cout << ", and has been removed." << endl;
			count++;
		}
	if (count == 0)
		cout << "\n\t\t\tStudent ID: " << userInput << " can not be found." << endl;
}

// Precondition: valid static Course array and valid integer size
// Postcondition: display the number of courses that have been stored, and ask the user to choose which course to remove a student
void removeStudent(Course course[], int size)
{
	if (size == 0 || course[0].getName() == "Unknown")
	{
		cout << "\n\t\tERROR: No data file has been read and stored into Courses.\n" << endl;
		return;
	}
	else
	{
		cout << "\n\t\tCourses:" << endl;
		cout << "\t\t" + string(80, char(196)) << endl;
		for (int i = 0; i < size; i++)
			cout << "\t\t" << i + 1 << ". " << course[i].getName() << endl;
		cout << "\t\t" + string(80, char(196)) << endl;
		int userInput = inputInteger("\t\tOption: ", 1, size);
		searchAndDeleteStudent(course[userInput - 1]);


	}

}

// Precondition: valid Course object
// Postcondition: print the contents 
void printOneCourse(Course course)
{
	cout << "\n\t\t" << course.getName() << endl;
	cout << "\t\t" << setw(10) << left << "Index";
	cout << setw(15) << left << "StudentID";
	cout << setw(30) << left << "StudentName";
	cout << setw(10) << left << "Score";
	cout << setw(10) << left << "Grade" << endl;
	double totalScores = 0.0;
	double averagedScore = 0.0;
	for (int i = 0; i < course.getNumberOfStudents(); i++)
	{
		cout << "\t\t" << setw(10) << left << i;
		cout << setw(15) << left << course.getStudentIDAt(i);
		cout << setw(30) << left << course.getStudentNameAt(i);
		cout << setw(10) << left << course.getStudentScoreAt(i);
		cout << setw(10) << left << course.getStudentGradeAt(i) << endl;
		totalScores = totalScores + course.getStudentScoreAt(i);
	}
	averagedScore = totalScores / course.getNumberOfStudents();
	char grade = 'F';
	if (averagedScore > 89.9)
		grade = 'A';
	else if (averagedScore > 79.9)
		grade = 'B';
	else if (averagedScore > 69.9)
		grade = 'C';
	else if (averagedScore > 59.9)
		grade = 'D';
	else
		grade = 'F';
	cout << "\n\t\tAverage score and grade: " << averagedScore << "(" << grade << ")" << endl;
	cout << endl;

}

// Precondition: valid static Course array and valid integer size
// Postcondition: display the number of courses that have been stored, and ask the user to choose which course to display all contents
void printCourses(Course course[], int size)
{
	if (size == 0 || course[0].getName() == "Unknown")
	{
		cout << "\n\t\tERROR: No data file has been read and stored into Courses.\n" << endl;
		return;
	}
	else
	{
		cout << "\n\t\tCourses:" << endl;
		cout << "\t\t" + string(80, char(196)) << endl;
		for (int i = 0; i < size; i++)
			cout <<"\t\t"<< i + 1 << ". " << course[i].getName() << endl;
		cout <<"\t\t"<< size + 1 << ". All courses" << endl;
		cout << "\t\t" + string(80, char(196)) << endl;
		int userInput = inputInteger("\t\tOption: ", 1, size + 1);
		if (userInput <= size)
			printOneCourse(course[userInput - 1]);
		else
		{
			for (int i = 0; i < size; i++)
				printOneCourse(course[i]);
		}
	}
}

#endif