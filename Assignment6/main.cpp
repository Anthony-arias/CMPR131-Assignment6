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
#include "menus.h"

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
    IntegerBag MyBag;

    do
    {
        clearScreen();
        displayOptionOneMenu();

        int option = inputChar("\t\tOption: ");

        switch (option)
        {
        case '0': return;
        case 'a': case 'A': emptyIntBag(MyBag); pause("\n\t\tPress enter to continue..."); break;
        case 'b': case 'B': insertInt(MyBag); pause("\n\t\tPress enter to continue...");  break;
        case 'c': case 'C': searchIntValue(MyBag); pause("\n\t\tPress enter to continue..."); break;
        case 'd': case 'D': removeIntIndex(MyBag); pause("\n\t\tPress enter to continue...");  break;
        case 'e': case 'E': sortInt(MyBag); pause("\n\t\tPress enter to continue...");  break;
        case 'f': case 'F': displayIntBag(MyBag); pause("\n\t\tPress enter to continue...");  break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R', or 'S'" << endl;
            pause("\n\t\tPress enter to continue...");
        }
    } while (true);
}


//PreCondition: NA
//PostCondition:
void programTwo(void)
{
    TemplateBag<double> MyBag;

    do
    {
        clearScreen();
        displayOptionTwoMenu();

        int option = inputChar("\t\tOption: ");

        switch (option)
        {
        case '0': return;
        case 'a': case 'A': emptyTemplateBag(MyBag); pause("\n\t\tPress enter to continue..."); break;
        case 'b': case 'B': insertTemplate(MyBag);  pause("\n\t\tPress enter to continue...");  break;
        case 'c': case 'C': searchTemplateValue(MyBag); pause("\n\t\tPress enter to continue...");  break;
        case 'd': case 'D': removeTemplateIndex(MyBag); pause("\n\t\tPress enter to continue...");  break;
        case 'e': case 'E': sortTemplate(MyBag); pause("\n\t\tPress enter to continue...");  break;
        case 'f': case 'F': displayTemplateBag(MyBag); pause("\n\t\tPress enter to continue...");  break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R', or 'S'" << endl;
            pause("\n\t\tPress enter to continue...");
        }
    } while (true);
}

//PreCondition: NA
//PostCondition:
void programThree(void)
{
    do
    {
        clearScreen();
        displayOptionThreeMenu();

        int option = inputChar("\t\tOption: ");

        switch (option)
        {
        case '0': return;
        case 'a': case 'A': /*Function here*/ pause("\n\t\tPress enter to continue..."); break;
        case 'b': case 'B': /*Function here*/ pause("\n\t\tPress enter to continue...");  break;
        case 'c': case 'C': /*Function here*/ pause("\n\t\tPress enter to continue...");  break;
        case 'd': case 'D': /*Function here*/ pause("\n\t\tPress enter to continue...");  break;
        case 'e': case 'E': /*Function here*/ pause("\n\t\tPress enter to continue...");  break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C', or 'D'" << endl;
            pause("\n\t\tPress enter to continue...");
        }
    } while (true);
}