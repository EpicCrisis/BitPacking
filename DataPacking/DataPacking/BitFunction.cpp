
#include "BitFunction.h"
#include <iostream>
#include <bitset>

BitFunction::BitFunction()
{
	for (int i = 0; i < DATACOUNT; ++i)
	{
		_value[i] = 0;
	}

	InitializeBitRange();
}

BitFunction::BitFunction(unsigned int num0, unsigned int num1, unsigned int num2, unsigned int num3)
{
	_value[0] = num0;
	_value[1] = num1;
	_value[2] = num2;
	_value[3] = num3;

	InitializeBitRange();
}

BitFunction::~BitFunction()
{
}

void BitFunction::InitializeBitRange()
{
	_bit[0] = 4;
	_bit[1] = 1;
	_bit[2] = 5;
	_bit[3] = 1;
}

_bitdata BitFunction::Pack()
{
	_bitdata bitValue = 0;

	for (int i = 0; i < DATACOUNT; ++i)
	{
		bitValue = (bitValue << _bit[i]) | _value[i];
	}

	return _bitdata();
}

void BitFunction::UnPack(_bitdata data)
{
	// Count the values in reverse order.
	for (int i = DATACOUNT - 1; i >= 0; --i)
	{
		_value[i] = data & ~(((_bitdata)0 - 1) << _bit[i]);
		data = data >> _bit[i];
	}
}

void BitFunction::Print()
{
	for (int i = 0; i < DATACOUNT; ++i)
	{
		std::cout << _value[i] << std::endl;
	}
}
