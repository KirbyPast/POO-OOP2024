
#include "NumberList.h";

int main() {
	NumberList number1;
	number1.Init();
	number1.Print();
	number1.Add(5);
	number1.Add(6);
	number1.Add(3);
	number1.Add(10);
	number1.Print();
	number1.Sort();
	number1.Print();
	return 0;
}