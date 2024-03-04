#include "NumberList.h"
#include "stdio.h"

void NumberList::Init() {
	this->count = 0;
}

bool NumberList::Add(int x) {
	if (this->count >= 10) return false;
	this->count++;
	this->numbers[this->count - 1] = x;
	return true;
}

void NumberList::Sort() {
	for (int i = 0; i < this->count - 1; i++) {
		for (int j = i + 1; j < this->count; j++) {
			if (this->numbers[i] > this->numbers[j]) {
				int z = this->numbers[i];
				this->numbers[i] = this->numbers[j];
				this->numbers[j] = z;
			}
		}
	}
}

void NumberList::Print() {
	for (int i = 0; i < this->count; i++) {
		printf("%d ", this->numbers[i]);
	}
	printf("\n");
}
