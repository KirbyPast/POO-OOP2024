#include <stdio.h>
//float operator"" _Kelvin(long double x)
//{
//	return x - 273.15;
//}
//
//float operator"" _Fahrenheit(long double x)
//{
//	return (x - 32) * 5 / 9;
//}

float operator"" _Kelvin(unsigned long long int x)
{
	return x - 273.15;
}

float operator"" _Fahrenheit(unsigned long long int x)
{
	return (x - 32.0) * 5 / 9;
}

int main()
{
	float a = 300_Kelvin;	
	float b = 120_Fahrenheit;


	printf("%f, %f", a, b);
	return 0;
}