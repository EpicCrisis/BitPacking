
#include "UIntPacker.h"

UIntPacker::UIntPacker()
{
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
	m_data = m_data & (1 << bitCount - 1);
	m_data = m_data >> bitCount;

	return m_data;
}
