#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <cstring>
#include <stdio.h>
#include <algorithm>

char valInBaseChar(int num);
// CONSTRUCTORS

Number::Number(int value) {
	this->numBase = 10;
	
	int copy = value;
	int len = 0;
	while (copy) {
		len++;
		copy /= 10;
	}

	this->value = new char[len + 1];
	this->value[len] = '\0';

	for (int i = 0; i < len; i++) {
		this->value[i] = valInBaseChar(value%10);
		value /= 10;
	}

	for (int i = 0; i < len/2; i++) {
		char temp = this->value[i];
		this->value[i] = this->value[len - i - 1];
		this->value[len - i - 1] = temp;
	}
}

Number::Number(Number& i) {
	this->numBase = i.GetBase();
	int len = i.GetDigitsCount();
	this->value = new char[len+1];
	for (int j = 0; j <= len; j++) {
		this->value[j] = i.value[j];
	}
}

Number::Number(const char* value, int base) : numBase(base) {

	int len = 0;
	while (value[len] != 0) {
		len++;
	}
	this->value = new char[len+1];
	for (int i = 0; i <= len; i++) {
		this->value[i] = value[i];
	}
}

Number::Number(char* value, int base) : numBase(base) {

	int len = 0;
	while (value[len] != 0) {
		len++;
	}
	this->value = new char[len + 1];
	for (int i = 0; i <= len; i++) {
		this->value[i] = value[i];
	}
}

// DESTRUCTORS

Number::~Number() {
	delete[] this->value;
}

// GET/SHOW FUNCTIONS

void Number::Print() {
	printf("%s, in base: %d, length: %d \n", this->value, this->numBase, this->GetDigitsCount());
}

int Number::GetDigitsCount() {
	int i = 0;
	while (this->value[i]!=NULL) {
		i++;
	}
	return i;
}

int Number::GetBase() { 
	return this->numBase; 
}

// FUNCTIONS

int valInBase(char num) {
	if (num >= '0' && num <= '9') {
		return num - '0';
	}
	else {
		return num - 'A' + 10;
	}
}

char valInBaseChar(int num) {
	if (num >= 0 && num <= 9) {
		return char('0' + num);
	}
	else {
		return char('A' + num - 10);
	}
}

int Number::NumberInDeca() {
	int newNum = 0, len = this->GetDigitsCount();
	int i;
	for (i = len - 1; i >= 0; i--) {
		newNum += pow(this->GetBase(), len - i - 1) * valInBase(this->value[i]);
	}
	return newNum;
}
void Number::SwitchBase(int newBase) {
	int newNum = 0, len = this->GetDigitsCount();
	int i;
	for (i = len - 1; i >= 0; i--) {
		newNum += pow(this->GetBase(), len - i - 1) * valInBase(this->value[i]);
	}

	int tempNum = newNum;
	int newLen = 0;
	while (tempNum) {
		tempNum /= newBase;
		newLen++;
	}

	delete[] this->value;
	this->value = new char[newLen+1];
	this->value[newLen] = '\0';
	this->numBase = newBase;
	i = 0;
	while (newNum) {
		this->value[i] = valInBaseChar(newNum % newBase);
		i++;
		newNum /= newBase;
	}
	for (i = 0; i < newLen / 2; i++) {
		char temp = this->value[i];
		this->value[i] = this->value[newLen - i - 1];
		this->value[newLen - i - 1] = temp;
	}
}


// OPERATORS

bool Number::operator>(Number& i) {
	if (this->NumberInDeca() > i.NumberInDeca()) return 1;
	else return 0;
}

bool Number::operator<(Number& i) {
	if (this->NumberInDeca() < i.NumberInDeca()) return 1;
	else return 0;
}

bool Number::operator>=(Number& i) {
	if (this->NumberInDeca() >= i.NumberInDeca()) return 1;
	else return 0;
}

bool Number::operator<=(Number& i) {
	if (this->NumberInDeca() <= i.NumberInDeca()) return 1;
	else return 0;
}

bool Number::operator==(Number& i) {
	if (this->NumberInDeca() == i.NumberInDeca()) return 1;
	else return 0;
}

char Number::operator[](int i) {
	if (i >= 0 && i <= this->GetDigitsCount()) {
		return this->value[i];
	}
	else return -1;
}

Number operator+(Number& num1, Number& num2) {
	int newNum10 = num1.NumberInDeca() + num2.NumberInDeca();
	int numCopy = newNum10;
	int len = 0;
	while (numCopy) {
		len++;
		numCopy /= 10;
	}

	int resultBase;
	if (num1.GetBase() > num2.GetBase()) resultBase = num1.GetBase();
	else resultBase = num2.GetBase();

	char* resultInChar = new char[len + 1];
	resultInChar[len] = '\0';
	int i = 0;
	while (newNum10) {
		resultInChar[i] = valInBaseChar(newNum10 % 10);
		i++;
		newNum10 /= 10;
	}

	for (i = 0; i < len / 2; i++) {
		char temp = resultInChar[i];
		resultInChar[i] = resultInChar[len - i - 1];
		resultInChar[len - i - 1] = temp;
	}

	Number result(resultInChar, 10);
	result.SwitchBase(resultBase);
	delete[] resultInChar;
	return result;
}

Number operator-(Number& num1, Number& num2) {
	int newNum10 = num1.NumberInDeca() - num2.NumberInDeca();

	int numCopy = newNum10;
	int len = 0;
	while (numCopy) {
		len++;
		numCopy /= 10;
	}

	int resultBase;
	if (num1.GetBase() > num2.GetBase()) resultBase = num1.GetBase();
	else resultBase = num2.GetBase();

	char* resultInChar = new char[len + 1];
	resultInChar[len] = '\0';
	int i = 0;
	while (newNum10) {
		resultInChar[i] = valInBaseChar(newNum10 % 10);
		i++;
		newNum10 /= 10;
	}

	for (i = 0; i < len / 2; i++) {
		char temp = resultInChar[i];
		resultInChar[i] = resultInChar[len - i - 1];
		resultInChar[len - i - 1] = temp;
	}

	Number result(resultInChar, 10);
	result.SwitchBase(resultBase);
	delete[] resultInChar;
	return result;
}

void Number::operator+=(Number& num2) {
	int newNum10 = this->NumberInDeca() + num2.NumberInDeca();
	int numCopy = newNum10;
	int len = 0;
	while (numCopy) {
		len++;
		numCopy /= 10;
	}

	int resultBase;
	if (this->GetBase() > num2.GetBase()) resultBase = this->GetBase();
	else resultBase = num2.GetBase();

	char* resultInChar = new char[len + 1];
	resultInChar[len] = '\0';
	int i = 0;
	while (newNum10) {
		resultInChar[i] = valInBaseChar(newNum10 % 10);
		i++;
		newNum10 /= 10;
	}

	for (i = 0; i < len / 2; i++) {
		char temp = resultInChar[i];
		resultInChar[i] = resultInChar[len - i - 1];
		resultInChar[len - i - 1] = temp;
	}
	delete[] this->value;
	this->value = new char[len + 1];
	for (i = 0; i <= len; i++) {
		this->value[i] = resultInChar[i];
	}
	this->SwitchBase(resultBase);
	delete[] resultInChar;
}

void Number::operator=(Number& i) {
	delete[] this->value;
	this->numBase = i.GetBase();
	int len = i.GetDigitsCount();
	this->value = new char[len + 1];
	for (int j = 0; j <= len; j++) {
		this->value[j] = i.value[j];
	}
}

void Number::operator=(Number&& i) {
	delete[] this->value;
	this->numBase = i.GetBase();
	int len = i.GetDigitsCount();
	this->value = new char[len + 1];
	for (int j = 0; j <= len; j++) {
		this->value[j] = i.value[j];
	}
}

void Number::operator=(const int i) {
	Number temp = i;
	temp.SwitchBase(this->numBase);
	*this = temp;
}

void Number::operator=(const char* i) {
	delete[] this->value;

	int len = 0;
	while (i[len] != 0) {
		len++;
	}

	this->value = new char[len + 1];
	this->value[len] = '\0';

	for (int j = 0; j < len; j++) {
		this->value[j] = i[j];
	}
}

Number& Number::operator--() {
	int len = this->GetDigitsCount();
	char* temp = new char[len];
	temp[len - 1] = '\0';
	for (int i = 1; i < len; i++) {
		temp[i-1] = this->value[i];
	}
	delete[] this->value;
	this->value = new char[len];
	this->value[len - 1] = '\0';
	for (int i = 0; i < len; i++) {
		this->value[i] = temp[i];
	}
	delete[] temp;
	return (*this);
}

Number Number::operator--(int) {
	int len = this->GetDigitsCount();
	char* temp = new char[len];
	temp[len - 1] = '\0';
	for (int i = 0; i < len - 1; i++) {
		temp[i] = this->value[i];
	}
	delete[] this->value;
	this->value = new char[len];
	this->value[len - 1] = '\0';
	for (int i = 0; i < len - 1; i++) {
		this->value[i] = temp[i];
	}
	delete[] temp;
	return (*this);
}