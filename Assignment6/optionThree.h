// optionThree.h

#include "Course.h"
#include "input.h"
#include <fstream>
#include <vector>
#include <sstream>

#ifndef OPTION_THREE_LOCK
#define OPTION_THREE_LOCK

// October 6 ~ might not be abe to use TemplateBag for course array... waiting on response from Prof
void determineSize(Course* course, int &size)
{
	size = inputInteger("\n\t\t1> Enter the number of courses: ",true);
	course = new Course[size];
	
	cout << "\t\t" << size << " Course(s) has been created.\n" << endl;
}

void readCourseData(Course course[], const int size)
{
	if (size == 0)
	{
		cout << "\n\t\tERROR: Number of courses has not been assigned.\n" << endl;
		return;
	}

	ifstream source;

	for (int index = 0; index < size; index++)
	{

		while (true)
		{
			std::string s;
			std::string fileName = inputString("\n\t\t2> Enter a data file name for course[" + std::to_string(index) + "] (STOP - Return): ", true);
			
			if (fileName == "STOP" || fileName == "stop")
				return;
			
			source.open(fileName);
			if (!source.fail()) break;

			cout << "\n\t\tERROR: file, aes, cannot be found. Please re-specify." << endl;
		}

		std::vector<std::string> lines;

		while (true)
		{
			std::string line;

			std::getline(source, line);
			if (source.fail()) break;

			lines.push_back(line);
		}

		std::vector<std::string> tokens;
		std::string token;
		// starting after course name
		for (int index = 1; index < size; index++)
		{
			std::stringstream check1(lines[index]);
			token;

			while (std::getline(check1, token, ' '))
				tokens.push_back(token);
		}

		if (lines.size() == 0)
		{
			cout << "\n\t\tFile is empty. Course not filled with information.\n" << std::endl;
			return;
		}

		course[index].setName(lines[0]);
		for (int index = 0; index < size; index++)
		{			
			int section = 1;
			for (int i = 0; i < tokens.size(); i++)
			{
				if (section == 1)
				{
					std::stringstream s(tokens.at(i));
					int id = 0;
					s >> id;
					course[index].addStudentID(id);
					section++;
				}
				else if (section == 2)
				{
					course[index].addStudentName(tokens[i]);
					section++;
				}
				else if (section == 3)
				{
					std::stringstream s(tokens.at(i));
					double score = 0;
					s >> score;
					course[index].addStudentScore(score);
					section = 1;
				}
			}
		}


		for (int index = 0; index < size; index++)
		{
			cout << "course name: " << course[index].getName() << endl;
			cout << "student names" << endl;
			for (int i = 0; i < course[index].getNumberOfStudents(); i++)
			{
				cout << "student " << i << ". " << course[index].getStudentNameAt(i) << endl;
			}

			cout << "student ids" << endl;
			for (int i = 0; i < course[index].getNumberOfStudents(); i++)
			{
				cout << "student " << i << ". " << course[index].getStudentIDAt(i) << endl;
			}

			cout << "student scores" << endl;
			for (int i = 0; i < course[index].getNumberOfStudents(); i++)
			{
				cout << "student " << i << ". " << course[index].getStudentScoreAt(i) << endl;
			}

			cout << "student grades" << endl;
			for (int i = 0; i < course[index].getNumberOfStudents(); i++)
			{
				cout << "student " << i << ". " << course[index].getStudentGradeAt(i) << endl;
			}



		}
	}
}

#endif