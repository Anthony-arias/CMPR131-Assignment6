// optionTwo.h

#include "TemplateBag.h"
#include "input.h"

#ifndef OPTION_TWO_LOCK
#define OPTION_TWO_LOCK


void searchTemplateValue(TemplateBag<double> MyBag)
{
	if (MyBag.isEmpty())
	{
		cout << "\n\t\tMyBag is empty.\n" << endl;
		return;
	}

	double value = inputDouble("\n\t\tEntr a value to search from MyBag");
	int atIndex = MyBag.search(value);

	if (atIndex == -1)
		std::cout << "\n\t\tValue " << value << " is not found from MyBag" << std::endl;
	else
		std::cout << "\n\t\tValue " << value << " is found at subscript #" << atIndex << " from MyBag";
}

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

void insertTemplate(TemplateBag<double>& MyBag)
{
	double intInserted = inputDouble("\n\t\tEnter a value and insert into MyBag: ");
	MyBag.insert(intInserted);
	cout << "\n\t\t" << intInserted << " has been inserted into MyBag\n" << endl;
}

void removeTemplateIndex(TemplateBag<double>& MyBag)
{
	if (MyBag.isEmpty())
	{
		cout << "\n\t\tMyBag is empty.\n" << endl;
		return;
	}

	int indexRemoved = inputInteger("\n\t\tEnter an index(subscript) from MyBag to be deleted: ", 0, MyBag.getSize() - 1);
	double valueRemoved = MyBag.getValueAt(indexRemoved);
	MyBag.remove(indexRemoved);
	
	cout << "\n\t\tValue " << valueRemoved << " has been deleted from MyBag\n" << endl;

}

void sortTemplate(TemplateBag<double>& MyBag)
{
	if (MyBag.isEmpty())
	{
		cout << "\n\t\tMyBag is empty.\n" << endl;
		return;
	}

	MyBag.sort();
	cout << "\n\t\tMyBag has been sorted\n" << endl;
}

void displayTemplateBag(TemplateBag<double> MyBag)
{
	if (MyBag.isEmpty())
	{
		cout << "\n\t\tMyBag is empty.\n" << endl;
		return;
	}

	cout << endl;
	MyBag.display();
	cout << endl;
}

#endif