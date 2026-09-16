
//task 3:

#include <iostream>

using namespace std;

int main()
{
	int list[5] = { 3, 6, 9, 12, 15 };
	int *pArr = list;  

	const int SIZE = 5;

	cout << "Values stored in array 'list' (accessed via pointer only):" << endl;

	// Dereference pArr
	for (int i = 0; i < SIZE; i++)
	{
		cout << *pArr << " ";   
		pArr++;                
	}
	cout << endl;

	return 0;
}