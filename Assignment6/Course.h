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

	Course(string newName = "Unknown")
	{
		name = newName;
	}

	Course(Course &course)
	{
		name = course.getName();
		for (int index = 0; index < course.getNumberOfStudents(); index++)
		{
			studentIDs.insert(course.getStudentIDAt(index));
			studentNames.insert(course.getStudentNameAt(index));
			studentScores.insert(course.getStudentScoreAt(index));
		}
	}

	string getName()
	{
		return name;
	}

	void setName(string newName)
	{
		name = newName;
	}

	void addStudentID(int studentID)
	{
		studentIDs.insert(studentID);
	}

	int getStudentIDAt(int targetIndex)
	{
		if (!studentIDs.isValidIndex(targetIndex))
			return -1;

		return studentIDs.getValueAt(targetIndex);
	}

	void addStudentName(string studentName)
	{
		studentNames.insert(studentName);
	}

	string getStudentNameAt(int targetIndex)
	{
		if (!studentNames.isValidIndex(targetIndex))
			return "Unknown";

		return studentNames.getValueAt(targetIndex);
	}

	int getNumberOfStudents()
	{
		return studentNames.getSize();
	}

	void addStudentScore(double score)
	{
		studentScores.insert(score);
		addStudentGrade(score);
	}

	double getStudentScoreAt(int targetIndex)
	{
		if (!studentScores.isValidIndex(targetIndex))
			return -1.0;

		return studentScores.getValueAt(targetIndex);
	}

	void addStudentGrade(double score)
	{
		char grade = ' ';

		if (score >= 90.0)
			grade = 'A';
		else if (grade >= 80.0)
			grade = 'B';
		else if (grade >= 70.0)
			grade = 'C';
		else if (grade >= 60.0)
			grade = 'D';
		else
			grade = 'F';

		studentGrades.insert(grade);
	}

	char getStudentGradeAt(int targetIndex)
	{
		if (!studentGrades.isValidIndex(targetIndex))
			return 'U';

		return studentGrades.getValueAt(targetIndex);
	}

};
#endif