
#include "BitPackage.h"
#include "UIntPacker.h"
#include "UIntSplitter.h"
#include <iostream>
#include <bitset>

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

	std::cout << "\n" << "=== Pack & Extract ===" << "\n" << std::endl;

	unsigned int value0 = 3;
	unsigned int value1 = 1;
	unsigned int value2 = 20;
	unsigned int value3 = 0;

	UIntPacker* packer = new UIntPacker;
	packer->Pack(value0, 4);
	packer->Pack(value1, 1);
	packer->Pack(value2, 5);
	packer->Pack(value3, 1);

	std::cout << "Pack Value " << packer->GetData() << std::endl;

	// Extract in reverse order (from left to right) to preserve unextracted binaries.
	unsigned int value3T = packer->Extract(1);
	unsigned int value2T = packer->Extract(5);
	unsigned int value1T = packer->Extract(1);
	unsigned int value0T = packer->Extract(4);

	std::cout << "Extract Value " << value0T << std::endl;
	std::cout << "Extract Value " << value1T << std::endl;
	std::cout << "Extract Value " << value2T << std::endl;
	std::cout << "Extract Value " << value3T << std::endl;
	
	std::cout << "\n" << "=== Split & Merge ===" << "\n" << std::endl;

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