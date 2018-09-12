
#pragma once

class BitFunction
{
public:
	BitFunction();

	void reset();
	void set(int _location, bool _flag);
	bool get(int _location);

	int getData();
	void setData(int value);

	unsigned int num0 = 3; //0~15, 4bits
	unsigned int num1 = 1; //0~1, 1bit
	unsigned int num2 = 20; //0~31, 5bits
	unsigned int num3 = 0; //0~1, 1bit

	unsigned int m_data = 0;
};

