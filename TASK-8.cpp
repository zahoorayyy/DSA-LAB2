#include <iostream>

using namespace std;

int main()
{
	int n = 3;
	int *values = new int[n];   // allocate exactly n integers

	cout << "Enter " << n << " integers: " << endl;
	for (int i = 0; i < n; i++)   // FIX 1: loop only over valid indices 0..n-1
	{
		cin >> values[i];
	}

	cout << "You entered: ";
	for (int i = 0; i < n; i++)   // display all three values, not just the first
	{
		cout << values[i] << " ";
	}
	cout << endl;

	delete[] values;   // FIX 2: use delete[] to match new[] (array delete)
	values = nullptr;  // FIX 3: reset the pointer after freeing it

	return 0;
}