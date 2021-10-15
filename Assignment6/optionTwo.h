// optionTwo.h

#ifndef OPTION_TWO_LOCK
#define OPTION_TWO_LOCK

#include "TemplateBag.h"
#include "input.h"

// Precondition: valid TemplateBag object that has double data type
// Postcondition: search the value from MyBag and display where it is
void searchTemplateValue(TemplateBag<double> MyBag)
{
	if (MyBag.isEmpty())
	{
		cout << "\n\t\tMyBag is empty.\n" << endl;
		return;
	}

	double value = inputDouble("\n\t\tEnter a value to search from MyBag: ");
	int atIndex = MyBag.search(value);

	if (atIndex == -1)
		cout << "\n\t\tValue " << value << " is not found from MyBag.\n" << endl;
	else
		cout << "\n\t\tValue " << value << " is found at subscript #" << atIndex << " from MyBag.\n";
}

// Precondition: valid reference TemplateBag object that has double data type
// Postcondition: clear all elements in MyBag
void emptyTemplateBag(TemplateBag<double>& MyBag)
{
	if (MyBag.isEmpty())
	{
		cout << "\n\t\tMyBag is empty.\n" << endl;
		return;
	}

	MyBag.clear();
	cout << "\n\t\tMyBag is cleared of all elements.\n" << endl;
}

// Precondition: valid reference TemplateBag object that has double data type
// Postcondition: enter a value and insert it into MyBag
void insertTemplate(TemplateBag<double>& MyBag)
{
	double intInserted = inputDouble("\n\t\tEnter a value and insert into MyBag: ");
	MyBag.insert(intInserted);
	cout << "\n\t\t" << intInserted << " has been inserted into MyBag.\n" << endl;
}

// Precondition: valid reference TemplateBag object that has double data type
// Postcondition: enter the MyBag's index and remove value from it.
void removeTemplateIndex(TemplateBag<double>& MyBag)
{
	if (MyBag.isEmpty())
	{
		cout << "\n\t\tMyBag is empty.\n" << endl;
		return;
	}

	int size = MyBag.getSize() - 1;
	int indexRemoved = inputInteger("\n\t\tEnter an index(subscript) from MyBag to be deleted (0.." + to_string(size) + "): ", 0, size);
	double valueRemoved = MyBag.getValueAt(indexRemoved);
	MyBag.remove(indexRemoved);
	
	cout << "\n\t\tValue " << valueRemoved << " has been deleted from MyBag.\n" << endl;

}

// Precondition: valid reference TemplateBag object that has double data type
// Postcondition: sort the value in MyBag
void sortTemplate(TemplateBag<double>& MyBag)
{
	if (MyBag.isEmpty())
	{
		cout << "\n\t\tMyBag is empty.\n" << endl;
		return;
	}

	MyBag.sort();
	cout << "\n\t\tMyBag has been sorted.\n" << endl;
}

// Precondition: valid TemplateBag object that has double data type
// Postcondition: display all contents in MyBag
void displayTemplateBag(TemplateBag<double> MyBag)
{
	if (MyBag.isEmpty())
	{
		cout << "\n\t\tMyBag is empty.\n" << endl;
		return;
	}

	MyBag.display();
	cout << endl;
}

#endif
