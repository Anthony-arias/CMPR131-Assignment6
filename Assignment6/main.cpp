// main.cpp

// Team: Anthony, An, Van, Vincent, Nhan
// Chapter 6: 
// 10/??/2021


/*
    October 6
        - Cleaned up Integer and Template bag classes. 
        - Began work on challenge 3, demo of template class
        - waiting on response of professor to continue.
*/

#include <iostream>
#include <string>
#include "optionOne.h"
#include "optionTwo.h"
#include "optionThree.h"
#include "input.h"
#include "Course.h"
#include "menus.h"
#include<memory>

void mainMenu(void);
void programOne(void);
void programTwo(void);
void programThree(void);

using namespace std;

int main(void)
{
    mainMenu();
    return 0;
}

//PreCondition: NA
//PostCondition: redirects user to different menus based on their choice
void mainMenu(void)
{
    do
    {
        clearScreen();

        displayMainMenu();

        int userInput = inputInteger("\t\tOption: ", 0, 3);
        switch (userInput)
        {
        case 0: clearScreen(); return;
        case 1: clearScreen(); programOne(); break;
        case 2: clearScreen(); programTwo(); break;
        case 3: clearScreen(); programThree(); break;
        default: cout << "\t\tERROR-3A: Invalid input. Must be from 0..3." << endl;
        }

    } while (true);
}

//PreCondition: NA
//PostCondition:
void programOne(void)
{
    clearScreen();
    IntegerBag MyBag;
    cout << "\n\t1> Non-template MyBag of integers" << endl;
    cout << "\t" + string(100, char(205)) << endl;
    do
    {
        
        displayOptionOneMenu();

        int option = inputChar("\t\tOption: ");

        switch (option)
        {
        case '0': return;
        case 'a': case 'A': emptyIntBag(MyBag); break;
        case 'b': case 'B': insertInt(MyBag); break;
        case 'c': case 'C': searchIntValue(MyBag); break;
        case 'd': case 'D': removeIntIndex(MyBag); break;
        case 'e': case 'E': sortInt(MyBag); break;
        case 'f': case 'F': displayIntBag(MyBag); break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R', or 'S'" << endl;
        }
    } while (true);
}


//PreCondition: NA
//PostCondition:
void programTwo(void)
{
    clearScreen();
    TemplateBag<double> MyBag;
    cout << "\n\t2> Template MyBag<double> container" << endl;
    cout << "\t" + string(100, char(205)) << endl;
    do
    {

        displayOptionTwoMenu();

        int option = inputChar("\t\tOption: ");

        switch (option)
        {
        case '0': return;
        case 'a': case 'A': emptyTemplateBag(MyBag); break;
        case 'b': case 'B': insertTemplate(MyBag); break;
        case 'c': case 'C': searchTemplateValue(MyBag); break;
        case 'd': case 'D': removeTemplateIndex(MyBag); break;
        case 'e': case 'E': sortTemplate(MyBag); break;
        case 'f': case 'F': displayTemplateBag(MyBag); break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R', or 'S'" << endl;
        }
    } while (true);
}

//PreCondition: NA
//PostCondition:
void programThree(void)
{
    clearScreen();
    Course* newCourse;
    int size = 0;
    newCourse = new Course[size];
    cout << "\n\t3> Courses using MyBags of integers, strings, doubles, and chars" << endl;
    cout << "\t" + string(100, char(205)) << endl;
    do
    {

        displayOptionThreeMenu();

        int option = inputChar("\t\tOption: ");

        switch (option)
        {
        case '0': return;
        case 'a': case 'A': determineSize(newCourse, size); break;
        case 'b': case 'B': readCourseData(newCourse, size);  break;
        case 'c': case 'C': searchStudent(newCourse, size);  break;
        case 'd': case 'D': printCourses(newCourse, size);  break;
        case 'e': case 'E': printCourses(newCourse, size);  break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D' or 'E'" << endl;
        }
        cout << endl;
    } while (true);
}