
#include "BitFunction.h"
#include <iostream>

BitFunction bit;

#define NUM0_BITS 4
#define NUM1_BITS 1
#define NUM2_BITS 5
#define NUM3_BITS 1

int main(void)
{
	int range[] = { 4, 1, 5, 1 };

	bit.m_data = bit.num0;
	bit.m_data = bit.m_data << 1;

	bit.m_data |= bit.num1;
	bit.m_data = bit.m_data << 5;

	bit.m_data |= bit.num2;
	bit.m_data = bit.m_data << 1;

	bit.m_data |= bit.num3;
	std::cout << bit.m_data << std::endl;

	// Pack num0, num1, num2 into data variable.
	// Unpack from "data" variable.
	unsigned int retrieveNum0;
	// std::cout << retrieveNum0 << std::endl;

	system("PAUSE");
};