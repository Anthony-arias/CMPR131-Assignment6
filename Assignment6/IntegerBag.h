// IntegerBag.h

#include <iostream>

#ifndef INTEGER_BAG_LOCK
#define INTEGER_BAG_LOCK	

class IntegerBag
{
private:
	int *bag = nullptr;
	int size;

public:
	IntegerBag()
	{
		size = 0;
	}

	IntegerBag(int arraySize)
	{
		bag = new int[arraySize];
		size = arraySize;
	}

	~IntegerBag()
	{
		delete[] bag;
		bag = nullptr;
	}

	void insert(int value)
	{
		if (isEmpty())
		{
			bag = new int[1];
			bag[0] = value;
			size++;
		}
		else
		{
			
			int *holdBag = new int[size + 1];
			copy(bag, holdBag);

			size++;
			holdBag[size - 1] = value;

			bag = new int[size];
			copy(holdBag, bag);
			delete[] holdBag;
		}
	}

	// Precondition: bag must not be empty
	// Postcondition: returns the first index which holds the targetValue
	int search(int targetValue)
	{
		if (isEmpty())
			return -1;

		for (int index = 0; index < size; index++)
			if (bag[index] == targetValue)
				return index;

		return -1; // might want to throw an exception instead?
	}

	// Pecondition: bag must not be empty
	// contents of the original are copied into the newBag
	void copy(int *original, int *newBag)
	{
		if (isEmpty())
			return;

		for (int index = 0; index < size; index++)
			newBag[index] = original[index];
	}

	// Precondition: bag size must not be empty and newBag size should ideally be -1 than the original
	// Precondition: newBag copies the values of original except for the index of skippedIndex
	void copyAllBut(int* original, int* newBag, int skippedIndex)
	{
		if (!isValidIndex(skippedIndex))
			return;

		if (isEmpty())
			return;

		for (int index = 0; index < size; index++)
		{
			if (index == skippedIndex)
			{
				for (int i = index; i < size; i++)
					newBag[i] = original[i + 1];

				break;
			}
			newBag[index] = original[index];
		}
	}

	bool remove(int targetIndex)
	{
		std::cout << size << std::endl;

		if (isEmpty())
		{
			std::cout << "ERROR (7.1): Bag is Empty" << std::endl;
			return false;
		}
		else if (!isValidIndex(targetIndex))
		{
			std::cout << "ERROR (7.2): Index is Out of Range" << std::endl;
		}
		else if (size == 1)
		{
			clear();
		}
		else
		{

			int* holdBag = new int[size - 1];
			copyAllBut(bag, holdBag, targetIndex);


			size--;

			bag = new int[size];
			copy(holdBag, bag);
			delete[] holdBag;

		}
	}

	bool isEmpty()
	{
		if (size == 0)
			return true;

		return false;
	}

	void clear()
	{
		size = 0;
		bag = new int[size];
	}

	void sort()
	{
		for (int leftBagLocation = 0; leftBagLocation < size; ++leftBagLocation)
		{
			int smallestIndex = leftBagLocation;
			for (int search = leftBagLocation + 1; search < size; ++search)
				if (bag[search] < bag[smallestIndex])
					smallestIndex = search;

			int swapValue = bag[leftBagLocation];
			bag[leftBagLocation] = bag[smallestIndex];
			bag[smallestIndex] = swapValue;
		}
	}

	bool isValidIndex(int index)
	{
		return index >= 0 && index < size;
	}

	void display()
	{
		if (isEmpty())
			return;

		for (int index = 0; index < size; index++)
			std::cout << "\t\t[" << index << "] - " << bag[index] << std::endl;
	}

	int getSize()
	{
		return size;
	}

};

#endif