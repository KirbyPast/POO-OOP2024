#include "Map.h"
#include <iostream>

using namespace std;

int main()
{
	Map<int, const char*> m;
	m[10] = "C++";
	m[20] = "test";
	m[30] = "Poo";

	for (auto [index, key, value] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	printf("---------------------------------------\n");
	
	m.Set("ILoveOOP", 20);

	for (auto [index, key, value] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	printf("---------------------------------------\n");

	const char* v = nullptr;
	m.Get(20, v);

	cout << v << '\n';
	printf("---------------------------------------\n");
	m.Delete(10);

	for (auto [index, key, value] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	printf("---------------------------------------\n");
	m.Clear();

	for (auto [index, key, value] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	printf("---------------------------------------\n");

	return 0;
}