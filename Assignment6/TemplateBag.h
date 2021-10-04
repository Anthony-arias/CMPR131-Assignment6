// TemplateBag.h

// IntegerBag.h

#include <iostream>

#ifndef TEMPLATE_BAG_LCOK
#define TEMPLATE_BAG_LOCK

template <typename T>
class TemplateBag
{
private:
	T* bag = nullptr;
	int size;

public:
	TemplateBag()
	{
		size = 0;
	}

	TemplateBag (int arraySize)
	{
		bag = new T[arraySize];
		size = arraySize;
	}

	~TemplateBag()
	{
		delete[] bag;
		bag = nullptr;
	}

	void insert(T value)
	{
		if (isEmpty())
		{
			bag = new T[1];
			bag[0] = value;
			size++;
		}
		else
		{

			T* holdBag = new T[size + 1];
			copy(bag, holdBag);

			size++;
			holdBag[size - 1] = value;

			bag = new T[size];
			copy(holdBag, bag);
			delete[] holdBag;
		}
	}

	// Precondition: bag must not be empty
	// Postcondition: returns the first index which holds the targetValue
	int search(T targetValue)
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
	void copy(T* original, T* newBag)
	{
		if (isEmpty())
			return;

		for (int index = 0; index < size; index++)
			newBag[index] = original[index];
	}

	// Precondition: bag size must not be empty and newBag size should ideally be -1 than the original
	// Precondition: newBag copies the values of original except for the index of skippedIndex
	void copyAllBut(T* original, T* newBag, int skippedIndex)
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

			T* holdBag = new T[size - 1];
			copyAllBut(bag, holdBag, targetIndex);


			size--;

			bag = new T[size];
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
		bag = new T[size];
	}

	void sort()
	{
		for (int leftBagLocation = 0; leftBagLocation < size; ++leftBagLocation)
		{
			int smallestIndex = leftBagLocation;
			for (int search = leftBagLocation + 1; search < size; ++search)
				if (bag[search] < bag[smallestIndex])
					smallestIndex = search;

			T swapValue = bag[leftBagLocation];
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
			std::cout << "[" << index << "] - " << bag[index] << std::endl;
	}

	int getSize()
	{
		return size;
	}

};

#endif