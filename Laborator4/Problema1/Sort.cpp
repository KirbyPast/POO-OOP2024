#define _CRT_SECURE_NO_WARNINGS 0
#include "Sort.h"
#include <time.h>
#include "stdarg.h"
#include <cstring>
#include <iostream>
#include <vector>

Sort::Sort(std::initializer_list<int> x) {
	this->count = x.size();
	this->list = new int[this->count];
	std::copy(x.begin(), x.end(), this->list);
}

Sort::Sort(int count, int mini, int maxi) {
	srand(time(0));

	this->list = new int [count];
	this->count = count;

	for (int i = 0; i < count; i++) {
		this->list[i] = (rand() % (maxi - mini + 1)) + mini;
	}
}

Sort::Sort(int count, ...) {
	va_list args;
	va_start(args, count);

	this->list = new int [count];
	this->count = count;

	for (int i = 0; i < count; i++) {
		this->list[i] = va_arg(args, int);
	}

	va_end(args);
}

Sort::Sort(int* vector, int count) {
	this->count = count;
	this->list = new int [count];

	for (int i = 0; i < count; i++) {
		this->list[i] = vector[i];
	}
}

Sort::Sort(char* string) {
	int c = 1;
	for (int i = 0; i < strlen(string); i++) {
		if (string[i] == ',') c++;
	}

	this->count = c;
	this->list = new int[c];

	c = 0;
	int num = 0;

	char* p = strtok(string,",");
	while (p) {
		//this->list[c++] = atoi(p);
		for (int i = 0; i < strlen(p); i++) {
				num = num * 10 + (p[i] - '0');
			}
		this->list[c] = num;
		c++;
		num = 0;
		p = strtok(NULL, ",");
	}
}


Sort::~Sort() {
	delete[] this->list;
}

void Sort::Print() {
	for (int i = 0; i < this->count; i++) {
		printf("%d ", this->list[i]);
	}
	printf("\n");
}

void Sort::InsertSort(bool ascendent) {
	int temp,j;
	for (int i = 0; i < this->count; i++) {
		temp = this->list[i];
		j = i - 1;
		while (j >= 0 && ((this->list[j] < temp && !ascendent) || (this->list[j] > temp && ascendent))) {
			this->list[j + 1] = this->list[j];
			j--;
		}
		if (this->list[j + 1] != temp) {
			this->list[j + 1] = temp;
		}
	}
}

void Sort::BubbleSort(bool ascendent) {
	int i, n1, last = this->count - 1;
	
	while (last > 0) {
		n1 = last - 1;
		last = 0;
		for (i = 0; i <= n1; i++) {
			if ((this->list[i] > this->list[i + 1] && ascendent) || (this->list[i] < this->list[i+1] && !ascendent))
				std::swap(this->list[i], this->list[i + 1]);
				last = i;
			}
	}
}

void Sort::QuickSort(int st, int dr, bool ascendent) {
	int x = this->list[st];
	int i = st + 1;
	int j = dr;
	while (i <= j) {
		if ((this->list[i] <= x && ascendent) ||
			(this->list[i] >= x && !ascendent)) {
			i++;
		}
		if ((this->list[j] >= x && ascendent) ||
			(this->list[j] <= x && !ascendent)) {
			j--;
		}
		if ((i<j && this->list[i]>x && this->list[j] < x && ascendent) ||
			(i<j && this->list[i]<x && this->list[j] > x && !ascendent)) {
			std::swap(this->list[i], this->list[j]);
			i++;
			j--;
		}
	}
	int k = i - 1;
	this->list[st] = this->list[k];
	this->list[k] = x;
	if (st < dr) {
		QuickSort(st, k - 1, ascendent);
		QuickSort(k + 1, dr, ascendent);
	}
}

int Sort::GetElementsCount() {
	return this->count;
}

int Sort::GetElementFromIndex(int index) {
	if (index > -1 && index < this->count) {
		return this->list[index];
	}
	else return 0;
}

