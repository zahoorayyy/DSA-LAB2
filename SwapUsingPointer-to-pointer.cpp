#include <iostream>
using namespace std;

void swapUsingDoublePointers(int **ppa, int **ppb)
{
	int temp = **ppa;   // dereference twice to reach the value of 'a'
	**ppa = **ppb;
	**ppb = temp;
}

int main()
{
	int a = 5, b = 10;
	int *pa = &a;              // pa and pb are pointer variables of type int
	int *pb = &b;

	int **ppa = &pa;           // ppa and ppb are pointers-to-pointers
	int **ppb = &pb;

	cout << "Before swap: a = " << a << ", b = " << b << endl;

	swapUsingDoublePointers(ppa, ppb);

	cout << "After swap:  a = " << a << ", b = " << b << endl;

	return 0;
}