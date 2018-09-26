
#pragma once

class UIntPacker
{
private:
	unsigned int m_data;
	unsigned int m_bitCount; // To count how many bits are used.

public:
	UIntPacker();
	~UIntPacker();

	// Pack the "value" into m_data, it returns true if there are enough bits available 
	// BitCount : the bit count of "value"
	bool Pack(unsigned int value, unsigned int bitCount);
	unsigned int Extract(unsigned int bitCount);

	unsigned int GetData();
};