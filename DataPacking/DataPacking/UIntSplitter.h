#pragma once

// The purpose of this class is to test your understanding of bit operations.
// It's less common we need to split the int into smaller data type, but there are few cases you will need to do this.
// For example, you are sending(or storing) byte arrays(byte stream), in order to store the date type larger than byte.
// You will need to split it.
class UIntSplitter
{
public:
	UIntSplitter();
	~UIntSplitter();

	unsigned char m_bytes[4];

	void StoreUInt(unsigned int value); // Store "1 unsigned int" value into "4 unsigned char".
	unsigned int GetInt(void); // Merge the bytes(unsigned char) and return the unsigned int value.
};

