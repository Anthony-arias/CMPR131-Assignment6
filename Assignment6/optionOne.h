// optionOne.h

#include "IntegerBag.h"
#include "input.h"

#ifndef OPTION_ONE_LOCK
#define OPTION_ONE_LOCK

void searchIntValue(IntegerBag MyBag)
{
	if (MyBag.isEmpty())
	{
		cout << "\n\t\tMyBag is empty.\n" << endl;
		return;
	}

	int value = inputInteger("\n\t\tEntr a value to search from MyBag");
	int atIndex = MyBag.search(value);

	if (atIndex == -1)
		std::cout << "\n\t\tValue " << value << " is not found from MyBag" << std::endl;
	else
		std::cout << "\n\t\tValue " << value << " is found at subscript #" << atIndex << " from MyBag\n" << std::endl;
}

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

void insertInt(IntegerBag &MyBag)
{
	int intInserted = inputInteger("\n\t\tEnter a value and insert into MyBag: ");
	MyBag.insert(intInserted);
	cout << "\n\t\t" << intInserted << " has been inserted into MyBag\n" << endl;
}

void removeIntIndex(IntegerBag &MyBag)
{
	if (MyBag.isEmpty())
	{
		cout << "\n\t\tMyBag is empty.\n" << endl;
		return;
	}

	int indexRemoved = inputInteger("\n\t\tEnter an index(subscript) from MyBag to be deleted: ", 0, MyBag.getSize() - 1);
	int valueRemoved = MyBag.getValueAt(indexRemoved);
	MyBag.remove(indexRemoved);

	cout << "\n\t\tValue " << valueRemoved << " has been deleted from MyBag\n" << endl;
}

void sortInt(IntegerBag &MyBag)
{
	if (MyBag.isEmpty())
	{
		cout << "\n\t\tMyBag is empty.\n" << endl;
		return;
	}

	MyBag.sort();
	cout << "\nMyBag has been sorted\n" << endl;
}

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