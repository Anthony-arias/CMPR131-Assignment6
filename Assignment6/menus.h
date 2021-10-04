// menus.h

#include <iostream>
#include <string>

using namespace std;

//PreCondition: NA
//PostCondition: displays main menu options
void displayMainMenu(void)
{
    cout << "\n\tCMPR131 Chapter 6: non-template and template Container by Anthony, An, Van, Vincent, Nhan (10/7/21)" << endl;
    cout << "\t" + string(100, char(205)) << endl;
    cout << "\t\t1> Non-template MyBag container of int" << endl;
    cout << "\t\t2> Template MyBag<double> container" << endl;
    cout << "\t\t3> Application using MyBag container" << endl;
    cout << "\t" + string(100, char(196)) << endl;
    cout << "\t\t0> exit" << endl;
    cout << "\t" + string(100, char(205)) << endl;
}

//PreCondition: NA
//PostCondition: displays option one menu options
void displayOptionOneMenu(void)
{
    cout << "\n\t1> Non-template MyBag of integers" << endl;
    cout << "\t" + string(100, char(205)) << endl;
    cout << "\t\tA> clear" << endl;
    cout << "\t\tB> insert" << endl;
    cout << "\t\tC> search" << endl;
    cout << "\t\tD> remove" << endl;
    cout << "\t\tE> sort" << endl;
    cout << "\t\tF> display" << endl;
    cout << "\t" + string(100, char(196)) << endl;
    cout << "\t\t0> return" << endl;
    cout << "\t" + string(100, char(205)) << endl;
}

//PreCondition: NA
//PostCondition: displays option two menu options
void displayOptionTwoMenu(void)
{
    cout << "\n\t2> Template MyBag of integers" << endl;
    cout << "\t" + string(100, char(205)) << endl;
    cout << "\t\tA> clear" << endl;
    cout << "\t\tB> insert" << endl;
    cout << "\t\tC> search" << endl;
    cout << "\t\tD> remove" << endl;
    cout << "\t\tE> sort" << endl;
    cout << "\t\tF> display" << endl;
    cout << "\t" + string(100, char(196)) << endl;
    cout << "\t\t0> return" << endl;
    cout << "\t" + string(100, char(205)) << endl;
}

//PreCondition: NA
//PostCondition: displays option three menu options
void displayOptionThreeMenu(void)
{
    cout << "\n\t3> Courses using MyBags of integers, strings, doubles, and chars" << endl;
    cout << "\t" + string(100, char(205)) << endl;
    cout << "\t\tA> Specify the number of courses" << endl;
    cout << "\t\tB> Read in data file and insert into courses" << endl;
    cout << "\t\tC> Search for a student record from a course" << endl;
    cout << "\t\tD> Remove a student record from a course" << endl;
    cout << "\t\tE> Display course(s)" << endl;
    cout << "\t" + string(100, char(196)) << endl;
    cout << "\t\t0> return" << endl;
    cout << "\t" + string(100, char(205)) << endl;
}