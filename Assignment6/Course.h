//Course.h
#ifndef COURSE_LOCK
#define COURSE_LOCK	
#include <string>
#include "TemplateBag.h"
using namespace std;

class Course
{
private:
	string name = "Unknown";
	TemplateBag<int> studentIDs;
	TemplateBag<string> studentNames;
	TemplateBag<double> studentScores;
	TemplateBag<char> studentGrades;

public:

	// Argument constructor
	Course(string newName = "Unknown")
	{
		name = newName;
	}

	// Argument constructor
	Course(Course &course)
	{
		name = course.getName();
		for (int index = 0; index < course.getNumberOfStudents(); index++)
		{
			studentIDs.insert(course.getStudentIDAt(index));
			studentNames.insert(course.getStudentNameAt(index));
			studentScores.insert(course.getStudentScoreAt(index));
			studentGrades.insert(course.getStudentGradeAt(index));
		}
	}
	
	// Precondition: NA
	// Postcondition: return name
	string getName()
	{
		return name;
	}

	// Precondition: valid string variable
	// Postcondition: name is assigned in newName
	void setName(string newName)
	{
		name = newName;
	}

	// Precondition: valid student ID
	// Postcondition: add student ID
	void addStudentID(int studentID)
	{
		studentIDs.insert(studentID);
	}

	// Precondition: valid index
	// Postcondition: get student ID at indicated index
	int getStudentIDAt(int targetIndex)
	{
		if (!studentIDs.isValidIndex(targetIndex))
			return -1;

		return studentIDs.getValueAt(targetIndex);
	}

	// Precondition: valid string student's name
	// Postcondition: add student's name
	void addStudentName(string studentName)
	{
		studentNames.insert(studentName);
	}

	// Precondition: valid index
	// Postcondition: get student's name at indicated index
	string getStudentNameAt(int targetIndex)
	{
		if (!studentNames.isValidIndex(targetIndex))
			return "Unknown";

		return studentNames.getValueAt(targetIndex);
	}

	// Precondition: NA
	// Postcondition: get the number of students
	int getNumberOfStudents()
	{
		return studentNames.getSize();
	}

	// Precondition: valid double score
	// Postcondition: add student's score
	void addStudentScore(double score)
	{
		studentScores.insert(score);
	}

	// Precondition: valid index
	// Postcondition: get student's score at indicated index
	double getStudentScoreAt(int targetIndex)
	{
		if (!studentScores.isValidIndex(targetIndex))
			return -1.0;

		return studentScores.getValueAt(targetIndex);
	}

	// Precondition: valid double score
	// Postcondition: check student's grade and add it
	void addStudentGrade(double score)
	{
		char grade = 'F';
		if (score > 89.9)
			grade = 'A';
		else if (score > 79.9)
			grade = 'B';
		else if (score > 69.9)
			grade = 'C';
		else if (score > 59.9)
			grade = 'D';
		else
			grade = 'F';

		studentGrades.insert(grade);
	}

	// Precondition: valid index
	// Postcondition: get student's grade at indicated index, if index is not found, assigned as 'U'
	char getStudentGradeAt(int targetIndex)
	{
		if (!studentGrades.isValidIndex(targetIndex))
			return 'U';

		return studentGrades.getValueAt(targetIndex);
	}

	// Precondition: valid reference Course object and valid index
	// Postcondition: remove student's data at indicated index
	void removeStudentAt(Course& course, int targetIndex)
	{

		course.studentIDs.remove(targetIndex);
		course.studentNames.remove(targetIndex);
		course.studentScores.remove(targetIndex);
		course.studentGrades.remove(targetIndex);

	}

};
#endif
