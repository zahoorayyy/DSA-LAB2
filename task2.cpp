//task 2 

#include <iostream>

using namespace std;


int main()
{
	int a, *pa;      // Statement 1
	pa = &a;           // Statement 2
	cout << "pa = &a --> pa = " << pa << endl << endl;
	pa = pa + 1;      // Statement 3
	cout << "pa = pa + 1 --> pa = " << pa << endl << endl;
	pa = pa + 3;      // Statement 4
	cout << "pa = pa + 3 --> pa = " << pa << endl << endl;
	pa = pa - 1;      // Statement 5
	cout << "pa = pa - 1 --> pa = " << pa << endl << endl;

	cout << "Trying to multiply pointer: " << (pa * 2) << endl;
}
