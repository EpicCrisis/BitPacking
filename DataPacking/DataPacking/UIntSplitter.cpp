
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
	// Multiply in values of 8 because 1 "char" contains 4 bytes which equals 8 bits.
	// Can jump 4 times only because 1 "int" contains 16 bytes which equals 32 bits.
	for (int i = 0; i < 4; ++i)
	{
		// 0xff is used to "mask" the 32-bit binary which shortens them to 8 bits only.
		// Removing all the unnecessary 0.
		m_bytes[3 - i] = (value >> (i * 8) & 0xff);
		// Converting the binaries into string.
		std::string binary = std::bitset<8>(m_bytes[i]).to_string();
	}
}

unsigned int UIntSplitter::GetInt(void)
{
	unsigned int value = 0;

	// Loop all the splitted variables and combine them.
	for (int i = 0; i < 4; ++i)
	{
		// Get the merged value, which is why we use the combined "OR" operator.
		value = (value << 8) | m_bytes[i];
	}
	return value;
}
