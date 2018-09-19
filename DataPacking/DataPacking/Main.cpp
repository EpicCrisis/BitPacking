
#include "BitPackage.h"
#include <iostream>

// Assignment1 : Implement UIntPacker and UIntSplitter classes, the headers of the classes are shown as following

int main(void)
{
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

	system("PAUSE");
};