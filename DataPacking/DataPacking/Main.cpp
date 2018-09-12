
#include "BitFunction.h"
#include <iostream>

int main(void)
{
	std::cout << "[SERVER] " << std::endl;
	std::cout << "[SERVER] Server initialized" << std::endl;
	std::cout << "[SERVER] " << std::endl;

	BitFunction* clientA = new BitFunction(3, 1, 30, 0);
	std::cout << "[SERVER] Client A initialized with values" << std::endl;
	std::cout << "{" << std::endl;
	clientA->Print();
	std::cout << "}" << std::endl;
	std::cout << "[SERVER] " << std::endl;

	std::cout << "[SERVER] Packaging..." << std::endl;
	unsigned short clientData = clientA->Pack();
	std::cout << "[SERVER] Packed Data: " << clientData << std::endl;
	std::cout << "[SERVER] " << std::endl;

	BitFunction* clientB = new BitFunction();
	std::cout << "[SERVER] Client B initialized with values" << std::endl;
	std::cout << "{" << std::endl;
	clientB->Print();
	std::cout << "}" << std::endl;
	std::cout << "[SERVER] " << std::endl;

	std::cout << "[SERVER] Sent packed data from Client A to Client B..." << std::endl;
	std::cout << "[SERVER] " << std::endl;

	std::cout << "[SERVER] Unpackaging..." << std::endl;
	clientB->UnPack(clientData);
	std::cout << "[SERVER] Unpacked Data:" << std::endl;
	std::cout << "{" << std::endl;
	clientB->Print();
	std::cout << "}" << std::endl;
	std::cout << "[SERVER] " << std::endl;

	std::cout << "[SERVER] " << std::endl;
	std::cout << "[SERVER] End of operation" << std::endl;
	std::cout << std::endl;
	system("PAUSE");

	delete clientA;
	delete clientB;

	return 0;
};