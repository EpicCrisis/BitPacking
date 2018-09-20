
#include "BitPackage.h"
#include <iostream>

BitPackage::BitPackage()
{
	// Reset all the value and initialize the value;
	for (int i = 0; i < DATACOUNT; ++i)
	{
		value[i] = 0;
	}

	InitializeBit();
}

BitPackage::BitPackage(unsigned int _num0, unsigned int _num1, unsigned int _num2, unsigned int _num3)
{
	// Assign the value and initialize the value.
	value[0] = _num0;
	value[1] = _num1;
	value[2] = _num2;
	value[3] = _num3;

	InitializeBit();
}

BitPackage::~BitPackage()
{
	// Destroy the constructor.
}

void BitPackage::InitializeBit()
{
	bit[0] = 4;
	bit[1] = 1;
	bit[2] = 5;
	bit[3] = 1;
}

__DATA BitPackage::Pack()
{
	// Storing the bit inside the data that was created to store the bits.
	__DATA returnData = 0;

	for (int i = 0; i < DATACOUNT; ++i)
	{
		// Shifting bit to left (based on the number of bits or BITCOUNT) needed to store the value.
		// Using the "OR" operator to retain previous data that was stored.
		returnData = (returnData << bit[i]) | value[i];
	}

	return returnData;
}

void BitPackage::UnPack(__DATA _data)
{
	// Get the existing data that was used to store the value.
	// Reverse the data (with for loop) by shifting right.
	// Use "AND" operator because we want specific bit within the range to be chosen.
	for (int i = DATACOUNT - 1; i >= 0; --i)
	{
		value[i] = _data & ~(((__DATA)0 - 1) << bit[i]);
		_data = _data >> bit[i];
	}
}

void BitPackage::PrintValue()
{
	// Using for loop to print the results.
	for (int i = 0; i < DATACOUNT; ++i)
	{
		std::cout << "Value for data " << i << " : " << value[i] << std::endl;
	}
}
