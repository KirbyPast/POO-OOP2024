#include <iostream>
#include "Array.hpp"
#include <exception>
using namespace std;

class Comparator: public Compare
{
public:
	int CompareElements(void* e1, void* e2)  {
		if (*(int*)e1 == *(int*)e2) return 0;
		else if (*(int*)e1 > *(int*)e2) return 1;
		else return -1;
	}
};

int comparer(const int& e1,const int& e2) {
	if (e1 == e2) return 0;
	else if (e1 > e2) return 1;
	else return -1;
}


int main() {
	Comparator c;
	Array<int> arr1(2);
	arr1 += 2;
	arr1 += 4;
	arr1 += 3;
	arr1 += 5;

	arr1.Print();

	arr1.Sort();

	arr1.Print();

	arr1.Clear();
	arr1 += 2;
	arr1 += 4;
	arr1 += 3;
	arr1 += 5;

	arr1.Sort(&comparer);

	arr1.Print();

	arr1.Clear();
	arr1 += 2;
	arr1 += 4;
	arr1 += 3;
	arr1 += 5;

	arr1.Sort(&c);

	arr1.Print();

	arr1.Insert(1, 10);

	arr1.Print();

	Array<int> arr2(arr1);
	arr2.Delete(2);

	arr2.Print();

	printf("%d\n",arr2.Find(10));
	printf("%d\n", arr2.Find(2, &comparer));
	printf("%d\n", arr2.Find(5, &c));

	arr2.Sort();

	arr2.Print();

	printf("%d\n", arr2.BinarySearch(10));
	printf("%d\n", arr2.BinarySearch(2, &comparer));
	printf("%d\n", arr2.BinarySearch(5, &c));

	/*for (ArrayIterator<int> it = arr1.GetBeginIterator(); it != arr1.GetEndIterator(); it++) {
		printf("%d ", *it.GetElement());
	}*/

	try {
		arr2.Insert(100, 5);
	}
	catch (exception& e) {
		cout << "Exceptie: " << e.what() << endl;
	}

	try {
		arr2[100];
	}
	catch (exception& e) {
		cout << "Exceptie: " << e.what() << endl;
	}
	arr1.Print();

	arr2.Print();
	arr2.Insert(1, arr1);

	arr2.Print();
	try {
		arr2.Insert(111, arr1);
	}

	catch (exception& e) {
		cout << "Exceptie: " << e.what() << endl;
	}
	try {
		arr2.Delete(111);
	}
	catch (exception& e) {
		cout << "Exceptie: " << e.what() << endl;
	}

	for (auto it = arr2.GetBeginIterator(); it != arr2.GetEndIterator(); it++) {
		cout << *it.GetElement() <<' ';
	}
	cout << '\n';

	arr2 = arr1;
	arr2.Print();

	return 0;
}