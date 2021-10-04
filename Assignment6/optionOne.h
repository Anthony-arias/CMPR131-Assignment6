// optionOne.h

#include "IntegerBag.h"
#include "input.h"

#ifndef OPTION_ONE_LOCK
#define OPTION_ONE_LOCK

void searchValue(IntegerBag MyBag)
{
	int value = inputInteger("\t\tEntr a value to search from MyBag");
	int atIndex = MyBag.search(value);

	if (atIndex == -1)
		std::cout << "\n\t\tValue " << value << " is not found from MyBag" << std::endl;
	else
		std::cout << "\n\t\tValue " << value << " is found at subscript #" << atIndex << " from MyBag";
}

#endif