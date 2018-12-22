
#include "BitPackage.h"
#include "UIntPacker.h"
#include "UIntSplitter.h"
#include <iostream>
#include <bitset>

// Assignment1 : Implement UIntPacker and UIntSplitter classes, the headers of the classes are shown as following

// Predetermined bit count for a very specific set of numbers within a certain bit range.
// Absolute and should not be changed.
#define bitCount0 4
#define bitCount1 1
#define bitCount2 5
#define bitCount3 1

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

	std::cout << "\n" << "=== Pack & Extract ===" << "\n" << std::endl;

	// Similarly predetermined, but must adhere to a certain range of bits.
	unsigned int value0 = 3;
	unsigned int value1 = 1;
	unsigned int value2 = 20;
	unsigned int value3 = 0;

	UIntPacker* packer = new UIntPacker;
	packer->Pack(value0, bitCount0);
	packer->Pack(value1, bitCount1);
	packer->Pack(value2, bitCount2);
	packer->Pack(value3, bitCount3);

	std::cout << "Pack Value " << packer->GetData() << std::endl;

	// Extract in reverse order (from left to right) to preserve unextracted binaries.
	unsigned int value3T = packer->Extract(bitCount3);
	unsigned int value2T = packer->Extract(bitCount2);
	unsigned int value1T = packer->Extract(bitCount1);
	unsigned int value0T = packer->Extract(bitCount0);

	std::cout << "Extract Value " << value0T << std::endl;
	std::cout << "Extract Value " << value1T << std::endl;
	std::cout << "Extract Value " << value2T << std::endl;
	std::cout << "Extract Value " << value3T << std::endl;
	
	std::cout << "\n" << "=== Split & Merge ===" << "\n" << std::endl;
	
	// Storing the integer value that will be split.
	UIntSplitter* splitter = new UIntSplitter;
	splitter->StoreUInt(44556677);

	unsigned char aChar0 = splitter->m_bytes[0];
	unsigned char aChar1 = splitter->m_bytes[1];
	unsigned char aChar2 = splitter->m_bytes[2];
	unsigned char aChar3 = splitter->m_bytes[3];

	std::cout << "Split Symbol " << aChar0 << " || " <<
	"Binary " << std::bitset<8>(aChar0).to_string() << std::endl;
	std::cout << "Split Symbol " << aChar1 << " || " <<
	"Binary " << std::bitset<8>(aChar1).to_string() << std::endl;
	std::cout << "Split Symbol " << aChar2 << " || " <<
	"Binary " << std::bitset<8>(aChar2).to_string() << std::endl;
	std::cout << "Split Symbol " << aChar3 << " || " <<
	"Binary " << std::bitset<8>(aChar3).to_string() << std::endl;
	std::cout << "Merge Value " << splitter->GetInt() << std::endl;
	
	std::cout << "\n";
	system("PAUSE");
};