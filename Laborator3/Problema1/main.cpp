#include <iostream>
#include "Math.h"
using namespace std;
int main() {
	cout << Math::Add(3, 5) << '\n'; //8
	cout << Math::Add(3, 5, 6) << '\n'; //14
	cout << Math::Add(3.0, 4.0) << '\n'; //7
	cout << Math::Add(3.0, 4.0, 5.0) << '\n'; //12
	cout << Math::Add(4, 12, 13, 14, 69) << '\n'; //108
	cout << Math::Mul(2, 3) << '\n'; //6
	cout << Math::Mul(2, 3, 4) << '\n'; //24
	cout << Math::Mul(2.0, 4.0) << '\n'; //8
	cout << Math::Mul(2.0, 4.0, 5.0) << '\n'; //40
	cout << Math::Add("23456787654", "11234543244") << '\n';  //34.691.330.898
	return 0;
}