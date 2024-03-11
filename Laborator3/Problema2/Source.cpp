#include <iostream>
#include "Canvas.h"
using namespace std;

int main() {
	Canvas test(32, 32);
	test.DrawCircle(10, 10, 5, '0');
	test.Print();
	test.Clear();

	test.FillCircle(10, 10, 5, '0');
	test.Print();
	test.Clear();

	test.DrawLine(1, 2, 16, 10, '0');
	test.Print();
	test.Clear();

	test.DrawRect(5, 10, 10, 5, '0');
	test.Print();
	test.Clear();

	test.FillRect(5, 10, 10, 5, '0');
	test.Print();
	test.Clear();

	test.SetPoint(5, 5, '0');
	test.Print();
	test.Clear();

	return 0;
}