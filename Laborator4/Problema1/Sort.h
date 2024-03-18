#pragma once
#include <vector>
class Sort
{
	int count;
	int* list;
public:
	Sort(std::initializer_list<int> x);
	Sort(int count, int mini, int maxi);
	Sort(int count, ...);
	Sort(int* vector, int count);
	Sort(char* string);
	Sort();
	~Sort();
	void Print();
	void InsertSort(bool ascendent = false);
	void BubbleSort(bool ascendent = false);
	int GetElementsCount();
	void QuickSort(int st, int dr, bool ascendent = false);
	int GetElementFromIndex(int index);
};

