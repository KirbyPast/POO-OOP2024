#include <iostream>
#include "sort.h"
using namespace std;

int main() {
	Sort vectBase(  10, 0, 5 );
	vectBase.Print();

	Sort vectVariadic( 5, 10, 12, 13, 14, 15 );
	vectVariadic.Print();

	Sort vectInit={3,4,5,6,7,8};
	vectInit.Print();

	int vector[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	Sort vectVect{ vector,15 };
	vectVect.Print();

	char string[] = { "10,40,100,5,70" };
	Sort vectString{ string };
	vectString.Print();


	vectString.QuickSort(0,vectString.GetElementsCount()-1, true);
	vectString.Print();

	vectString.QuickSort(0,vectString.GetElementsCount()-1, false);
	vectString.Print();

	vectString.BubbleSort(true);
	vectString.Print();

	vectString.BubbleSort(false);
	vectString.Print();

	vectString.InsertSort(true);
	vectString.Print();

	vectString.InsertSort(false);
	vectString.Print();

	return 0;
}