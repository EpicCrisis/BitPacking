
#include "BitPackage.h"
#include "UIntPacker.h"
#include <iostream>

// Assignment1 : Implement UIntPacker and UIntSplitter classes, the headers of the classes are shown as following

int main(void)
{
	/*
	// Create new package with hardcode values and print the correct values.
	BitPackage* a = new BitPackage(4, 1, 5, 1);
	a->PrintValue();
	// Storing the bit data.
	unsigned short packedData = a->Pack();
	std::cout << "Value of the packed data : " << packedData << std::endl;

	// Create new empty package and transfer first package to this package.
	BitPackage* b = new BitPackage();
	b->PrintValue();
	b = a;
	b->PrintValue();

	// Unpack the packed data in b.
	b->UnPack(packedData);
	b->PrintValue();
	*/

	unsigned int value0 = 3;
	unsigned int value1 = 1;
	unsigned int value2 = 30;
	unsigned int value3 = 0;

	UIntPacker* packer = new UIntPacker;
	packer->Pack(value0, 1);
	packer->Pack(value1, 4);
	packer->Pack(value2, 5);
	packer->Pack(value3, 2);

	unsigned int value3T = packer->Extract(2);
	unsigned int value2T = packer->Extract(5);
	unsigned int value1T = packer->Extract(4);
	unsigned int value0T = packer->Extract(1);

	system("PAUSE");
};