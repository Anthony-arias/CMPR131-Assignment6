// optionOne.h

#ifndef OPTION_ONE_LOCK
#define OPTION_ONE_LOCK

#include "IntegerBag.h"
#include "input.h"

// Precondition: valid IntegerBag object
// Postcondition: search the value from MyBag and display where it is
void searchIntValue(IntegerBag MyBag)
{
	if (MyBag.isEmpty())
	{
		cout << "\n\t\tMyBag is empty.\n" << endl;
		return;
	}

	int value = inputInteger("\n\t\tEnter a value to search from MyBag: ");
	int atIndex = MyBag.search(value);

	if (atIndex == -1)
		cout << "\n\t\tValue " << value << " is not found from MyBag.\n" << endl;
	else
		cout << "\n\t\tValue " << value << " is found at subscript #" << atIndex << " from MyBag.\n" << endl;
}

// Precondition: valid IntegerBag object
// Postcondition: clear all elements in MyBag
void emptyIntBag(IntegerBag &MyBag)
{
	if (MyBag.isEmpty())
	{
		cout << "\n\t\tMyBag is empty.\n" << endl;
		return;
	}

	MyBag.clear();
	cout << "\n\t\tMyBag is cleared of all elements.\n" << endl;
}

// Precondition: valid reference IntegerBag object
// Postcondition: enter a value and insert it into MyBag
void insertInt(IntegerBag &MyBag)
{
	int intInserted = inputInteger("\n\t\tEnter a value and insert into MyBag: ");
	MyBag.insert(intInserted);
	cout << "\n\t\t" << intInserted << " has been inserted into MyBag.\n" << endl;
}

// Precondition: valid IntegerBag object
// Postcondition: enter the MyBag's index and remove value from it.
void removeIntIndex(IntegerBag &MyBag)
{
	if (MyBag.isEmpty())
	{
		cout << "\n\t\tMyBag is empty.\n" << endl;
		return;
	}
	int size = MyBag.getSize() - 1;

	int indexRemoved = inputInteger("\n\t\tEnter an index(subscript) from MyBag to be deleted (0.." + to_string(size) + "): ", 0, size);
	int valueRemoved = MyBag.getValueAt(indexRemoved);
	MyBag.remove(indexRemoved);

	cout << "\n\t\tValue " << valueRemoved << " has been deleted from MyBag.\n" << endl;
}

// Precondition: valid IntegerBag object
// Postcondition: sort the value in MyBag
void sortInt(IntegerBag &MyBag)
{
	if (MyBag.isEmpty())
	{
		cout << "\n\t\tMyBag is empty.\n" << endl;
		return;
	}

	MyBag.sort();
	cout << "\n\t\tMyBag has been sorted.\n" << endl;
}

// Precondition: valid IntegerBag object
// Postcondition: display all contents in MyBag
void displayIntBag(IntegerBag MyBag)
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
