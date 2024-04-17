#include "Fractie.h"
#include <stdio.h>
#include <cmath>
int getStringLength(const char* string) {
	int i = 0, len = 0;
	while (string[i] != 0) {
		len++;
		i++;
	}
	return len;
}

int euclid(int a, int b) {
	int r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

Fractie::Fractie(int numerator, int denominator):numerator(numerator)
, denominator(denominator){}

Fractie::Fractie(const char* fraction) {
	int len = getStringLength(fraction);
	this->numerator = 0;
	this->denominator = 0;
	int flag = 0;
	int p = 1;
	for (int i = 0; i < len; i++) {
		if (fraction[i] == '/') {
			flag = 1;
			p = 1;
			continue;
		}
		if (flag == 0) {
			this->numerator = this->numerator*10 + (fraction[i] - 48);
			p *= 10;
		}
		else {
			this->denominator = this->denominator *10+ (fraction[i] - 48);
			p *= 10;
		}
	}
	if (flag == 0) this->denominator = 1;
}

Fractie Fractie::simplify() {
	int gcd = euclid(this->numerator, this->denominator);
	Fractie f3(this->numerator / gcd, this->denominator / gcd);
	return f3;
}

void Fractie::print() {
	printf("%d / %d \n ", this->numerator, this->denominator);
}

Fractie operator+(Fractie f1, Fractie f2) {
	int gcd = euclid(f1.denominator, f2.denominator);
	int scm = abs((f1.denominator * f2.denominator)) / gcd;
	f1.numerator = f1.numerator * (scm / f1.denominator);
	f2.numerator = f2.numerator * (scm / f2.denominator);
	f1.denominator = scm;
	f2.denominator = scm;
	Fractie f3(f1.numerator + f2.numerator, scm);
	return f3;
}

Fractie operator-(Fractie f1, Fractie f2) {
	int gcd = euclid(f1.denominator, f2.denominator);
	int scm = abs((f1.denominator * f2.denominator)) / gcd;
	f1.numerator = f1.numerator * (scm / f1.denominator);
	f2.numerator = f2.numerator * (scm / f2.denominator);
	f1.denominator = scm;
	f2.denominator = scm;
	Fractie f3(f1.numerator - f2.numerator, scm);
	return f3;
}

Fractie::Fractie(const Fractie& f1) {
	this->numerator = f1.numerator;
	this->denominator = f1.denominator;
}

void Fractie::operator=(Fractie& f1) {
	this->numerator = f1.numerator;
	this->denominator = f1.denominator;
}

bool Fractie::operator==(Fractie f1) {
	Fractie f2(this->numerator, this->denominator);
	int gcd = euclid(f1.denominator, f2.denominator);
	int scm = abs((f1.denominator * f2.denominator)) / gcd;
	f1.numerator = f1.numerator * (scm / f1.denominator);
	f2.numerator = f2.numerator * (scm / f2.denominator);
	f1.denominator = scm;
	f2.denominator = scm;
	return (f1.numerator == f2.numerator);
}

Fractie operator*(Fractie f1, Fractie f2) {
	Fractie f3(f1.numerator * f2.numerator, f1.denominator * f2.denominator);
	return f3;
}

int Fractie::operator[](const char* input) {
	char numVerif[] = { "numerator" };
	char denVerif[] = { "denominator" };
	int num = 1, den = 1;
	int len = getStringLength(input);
	for (int i = 0; i < len; i++) {
		if (input[i] != numVerif[i]) {
			num = 0;
		}
		if (input[i] != denVerif[i]) {
			den = 0;
		}
	}
	if (num) return this->numerator;
	else return this->denominator;
}