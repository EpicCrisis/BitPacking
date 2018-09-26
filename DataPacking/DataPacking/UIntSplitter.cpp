
#include "UIntSplitter.h"
#include <iostream>
#include <bitset>

UIntSplitter::UIntSplitter()
{
}


UIntSplitter::~UIntSplitter()
{
}

void UIntSplitter::StoreUInt(unsigned int value)
{
	for (int i = 0; i < 4; ++i)
	{
		m_bytes[3 - i] = (value >> (i * 8) & 0xff);
		std::string binary = std::bitset<8>(m_bytes[i]).to_string();
	}
}

unsigned int UIntSplitter::GetInt(void)
{
	unsigned int value = 0;

	for (int i = 0; i < 4; ++i)
	{
		value = (value << 8) | m_bytes[i];
	}
	return value;
}
