
#pragma once
#define DATACOUNT 4

typedef unsigned short __DATA;

class BitPackage
{
public:
	BitPackage();
	BitPackage(unsigned int _num0, unsigned int _num1, unsigned int _num2, unsigned int _num3);
	virtual ~BitPackage();

	// Set the values for the bit to be stored.
	void InitializeBit();

	// Pack and unpack bit functions.
	__DATA Pack();
	void UnPack(__DATA _data);
	void PrintValue();

	// One to store the "value" and one to store the "bit of value".
	unsigned int value[DATACOUNT];
	unsigned int bit[DATACOUNT];
};

