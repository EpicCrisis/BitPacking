
#pragma once

#define DATACOUNT 4

typedef unsigned short _bitdata;

class BitFunction
{
private:
	unsigned int _value[DATACOUNT];
	unsigned int _bit[DATACOUNT];

public:
	BitFunction();
	BitFunction(unsigned int num0, unsigned int num1, unsigned int num2, unsigned int num3);
	virtual ~BitFunction();

	void InitializeBitRange();

	_bitdata Pack();
	void UnPack(_bitdata data);
	void Print();
};

