//Course.h

#include <string>
#include "TemplateBag.h"

class Course
{
private:
	std::string name;
	TemplateBag<int> studentIDs;
	TemplateBag<std::string> studentNames;
	TemplateBag<double> studentScores;
	TemplateBag<char> studentGrades;

public:
	Course()
	{
		name = "Unknown";
	}

	Course(std::string newName)
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

	std::string getName()
	{
		return name;
	}

	void setName(std::string newName)
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

	void addStudentName(std::string studentName)
	{
		studentNames.insert(studentName);
	}

	std::string getStudentNameAt(int targetIndex)
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

		if (score >= 90)
			grade = 'A';
		else if (grade >= 80)
			grade = 'B';
		else if (grade >= 70)
			grade = 'C';
		else if (grade >= 60)
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