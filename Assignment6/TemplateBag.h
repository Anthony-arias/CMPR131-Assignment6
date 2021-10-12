// TemplateBag.h

// IntegerBag.h

#include <iostream>

#ifndef TEMPLATE_BAG_LOCK
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

	TemplateBag(TemplateBag& newBag)
	{
		bag = new T[newBag.getSize()];
		size = newBag.getSize();
		copy(newBag.getArray(), bag);
	}

	~TemplateBag()
	{
		delete[] bag;
		bag = nullptr;
	}

	// Precondition: size cannot be less than 0
	// Postcondition: the bag is cleared and is set to a new size
	void setBagSize(int newSize)
	{
		if (size < 0)
			return;

		clear();
		bag = new T[newSize];
		size = newSize;
	}

	// Precondition: NA
	// Postcondition: returns a pointer to the array in this bag
	T* getArray()
	{
		return bag;
	}

	// Precondition: value must be an integer
	// Postcondition: value is added to the end of the array
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

	// Precondition: bag cannot be empty and targetIndex must be within range
	// Postcondition: value is inserted into the bag at subscript targetIndex
	void insertAt(int targetIndex, T value)
	{
		if (!isValidIndex(targetIndex))
			return;

		if (isEmpty())
			return;

		bag[targetIndex] = value;
	}

	// Precondition: Bag must not be empty and targetIndex must be within range
	// Postcondition: returns the value at the targetIndex of the bag
	T getValueAt(int targetIndex)
	{
		if (isEmpty())
			return NULL;
		else if (!isValidIndex(targetIndex))
			return NULL;
		else
			return bag[targetIndex];

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

	// Precondition list must not be empty, targetIndex must be within range
	// Postcondition: the index at targetIndex is removed from the array
	bool remove(int targetIndex)
	{
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

	// Precondition: NA
	// Postcondition: returns true if the list is empty, false otherwise
	bool isEmpty()
	{
		if (size == 0)
			return true;

		return false;
	}

	// Precondition: NA
	// Postcondition: clears the array
	void clear()
	{
		size = 0;
		bag = new T[size];
	}

	// Precondition: list should not be empty
	// Postcondition: sorts the array from least to greatest
	void sort()
	{
		if (isEmpty())
			return;

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

	// Precondition: NA
	// Postcondition returns true if the index at targetIndex is valid
	bool isValidIndex(int targetIndex)
	{
		return targetIndex >= 0 && targetIndex < size;
	}

	// Precondition: list should not be empty
	// Postcondition: The list is displayed
	void display()
	{
		if (isEmpty())
			return;

		for (int index = 0; index < size; index++)
			std::cout << "\t\t[" << index << "] - " << bag[index] << std::endl;
	}

	// Precondition: NA
	// Postcondition: returns the size of the list
	int getSize()
	{
		return size;
	}

};

#endif