
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
	m_data = m_data << bitCount;
	m_data = m_data | value;

	return m_data;
}

unsigned int UIntPacker::Extract(unsigned int bitCount)
{
	unsigned int value;
	value = m_data & ((1 << bitCount) - 1);
	m_data = m_data >> bitCount;

	return value;
}

unsigned int UIntPacker::GetData()
{
	return m_data;
}
