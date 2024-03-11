#include "Math.h"
#include <stdarg.h>
#include <cstring>
#include <algorithm>
int Math::Add(int x, int y) {
	return x + y;
}
int Math::Add(int x, int y, int z) {
	return x + y + z;
}
int Math::Add(double x, double y) {
	return x + y;
}
int Math::Add(double x, double y, double z) {
	return x + y + z;
}
int Math::Mul(int x, int y) {
	return x * y;
}
int Math::Mul(int x, int y, int z) {
	return x * y * z;
}
int Math::Mul(double x, double y) {
	return x * y;
}
int Math::Mul(double x, double y, double z) {
	return x * y * z;
}
int Math::Add(int count, ...) {
	int result = 0;
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++) {
		result += va_arg(args, int);
	}
	va_end(args);
	return result;
}

char* Math::Add(const char* number1, const char* number2) {
	if (number1 == nullptr || number2 == nullptr) {
		return nullptr;
	}
	int len1 = strlen(number1), len2 = strlen(number2);
	char* resString = new char[std::max(len1,len2)+2];//1 in plus ptr null si 1 in plus ptr overflow
	int i = 1;
	int carry = 0;
	while (i <= len1 && i <= len2) {
		char addRes = (number1[len1 - i] - '0') + (number2[len2 - i] - '0') + carry;
		carry = addRes / 10;
		addRes = addRes % 10;
		resString[i - 1] = addRes + '0';
		i++;
	}
	while (i <= len1) {
		char addRes = number1[len1 - i] - '0' +carry;
		carry = addRes / 10;
		addRes = addRes % 10;
		resString[i - 1] = addRes + '0';
		i++;
	}
	while (i <= len2) {
		char addRes = number2[len2 - i] - '0' + carry;
		carry = addRes / 10;
		addRes = addRes % 10;
		resString[i - 1] = addRes + '0';
		i++;
	}
	if (carry) resString[i - 1] = carry + '0';
	else resString[i - 1] = '\0';
	resString[i] = '\0';
	for (int i = 0; i <= strlen(resString)/2; i++) {
		std::swap(resString[i], resString[strlen(resString) - i - 1]);
	}
	return resString;
}
