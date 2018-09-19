
#include <iostream>

int main(void)
{
	// Value for the bit.
	unsigned int number[4];
	number[0] = 3; // 0~15 bits
	number[1] = 1; // 0~1 bits
	number[2] = 30; // 0~31 bits
	number[3] = 0; // 0~1 bits

	// Needed to count the amount of "shifting" to reach a specific bit.
	unsigned int bitRequired[4];
	bitRequired[0] = 4;
	bitRequired[1] = 1;
	bitRequired[2] = 5;
	bitRequired[3] = 1;

	// Store the values.
	unsigned int DATA;

	// ====== DATA PACKING ====== //
	// Without using a "for loop", just increment index.
	// After storing the initial bit, the DATA needs to be shifted for an extra space to store the next bit(s).
	int i = 0;
	DATA = DATA | number[i];
	++i;

	DATA = DATA << bitRequired[i];
	DATA = DATA | number[i];
	++i;

	DATA = DATA << bitRequired[i];
	DATA = DATA | number[i];
	++i;

	DATA = DATA << bitRequired[i];
	DATA = DATA | number[i];
	++i;
	// ====== DATA PACKING ====== //

	// ====== DATA UNPACKING ====== //
	// Using the "AND" operator to extract the bit.
	// Using "power of" operation in order to obtain the necessary bit to compare and extract.
	// 2^5=32 : 32-bits
	i = 3;
	unsigned int enum3 = DATA & (1 << bitRequired[i] - 1);
	//unsigned int enum3 = DATA & (2 ^ bitRequired[i] - 1);
	DATA = DATA >> bitRequired[i];

	--i;
	unsigned int enum2 = DATA & (2 ^ bitRequired[i] - 1);
	DATA = DATA >> bitRequired[i];

	--i;
	unsigned int enum1 = DATA & (2 ^ bitRequired[i] - 1);
	DATA = DATA >> bitRequired[i];

	--i;
	unsigned int enum0 = DATA & (2 ^ bitRequired[i] - 1);
	DATA = DATA >> bitRequired[i];
	// ====== DATA UNPACKING ====== //

	system("PAUSE");
};