#pragma once
class Number
{
	char* value;
	int numBase;
public:
	Number(Number& i);
	Number(const char* value, int base); //where base is between 2 and 16
	Number(char* value, int base);
	Number(int value);
	~Number();

	////add operators and copy/move constructor
	bool operator>(Number& i);
	bool operator<(Number& i);
	bool operator<=(Number& i);
	bool operator>=(Number& i);
	bool operator==(Number& i);
	void operator=(Number& i);
	void operator=(Number&& i);
	void operator=(const char* i);
	void operator=(const int i);
	void operator+=(Number& num2);
	Number operator--(int);
	Number& operator--();
	friend Number operator+(Number& num1, Number& num2);
	friend Number operator-(Number& num1, Number& num2);

	char operator[](int i);


	void SwitchBase(int newBase);
	void Print();
	int NumberInDeca();
	int GetDigitsCount(); // returns the number of digits for the current number
	int GetBase(); // returns the current base
};

