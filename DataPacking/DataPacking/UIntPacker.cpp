
#include "UIntPacker.h"
#include <iostream>

UIntPacker::UIntPacker()
{
	m_data = 0;
	m_bitCount = 0;
}

UIntPacker::~UIntPacker()
{
}

bool UIntPacker::Pack(unsigned int value, unsigned int bitCount)
{
	// Shift it to the left (forward) because bits are counted from the right by computer.
	m_data = m_data << bitCount;
	// Use "OR" operator to maintain existing bits at the back.
	m_data = m_data | value;

	return m_data;
}

unsigned int UIntPacker::Extract(unsigned int bitCount)
{
	unsigned int value;
	// Reversing the shift count to get the values.
	// Must also be extracted from the reverse order or the back data will be lost.
	value = m_data & ((1 << bitCount) - 1);
	m_data = m_data >> bitCount;

	return value;
}

unsigned int UIntPacker::GetData()
{
	return m_data;
}
