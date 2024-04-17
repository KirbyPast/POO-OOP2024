#pragma once
class Fractie
{
	int numerator, denominator;
public:
	Fractie(int numerator, int denominator);
	Fractie(const char* fraction);
	Fractie(const Fractie& f1);
	Fractie simplify();
	void print();
	friend Fractie operator+(Fractie f1, Fractie f2);
	void operator=(Fractie& f1);
	friend Fractie operator-(Fractie f1, Fractie f2);
	bool operator==(Fractie f1);
	int operator[](const char* input);
	friend Fractie operator*(Fractie f1, Fractie f2);
};

