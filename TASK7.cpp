
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>

using namespace std;

// Reads an integer within [minVal, maxVal], re-prompting on bad input.
int readIntInRange(const string &prompt, int minVal, int maxVal)
{
	int value;
	while (true)
	{
		cout << prompt;
		cin >> value;

		if (cin.fail())
		{
			if (cin.eof())
			{
				cerr << "\nInput stream ended unexpectedly. Exiting." << endl;
				exit(1);
			}
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a whole number." << endl;
			continue;
		}

		if (value < minVal || value > maxVal)
		{
			cout << "Value must be between " << minVal << " and " << maxVal
				<< ". Please try again." << endl;
			continue;
		}

		return value;
	}
}

int main()
{
	
	int n = readIntInRange("Enter number of existing students (1-10): ", 1, 10);

	// Allocate the original block of n marks
	int *marks = new int[n];

	cout << "\nEnter " << n << " mark(s) (0-100):" << endl;
	for (int i = 0; i < n; i++)
	{
		string prompt = "Mark " + to_string(i + 1) + ": ";
		*(marks + i) = readIntInRange(prompt, 0, 100);
	}

	// Allocate a second, bigger block; copy old values across 
	int *newMarks = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		*(newMarks + i) = *(marks + i);   // copy using pointer notation
	}

	// Read the new student's mark into the final position
	int newMark = readIntInRange("\nEnter the new student's mark (0-100): ", 0, 100);
	*(newMarks + n) = newMark;

	//  Release the old block, repoint 'marks', update size 
	delete[] marks;      
	marks = newMarks;    
	newMarks = nullptr;  
	n = n + 1;           

	
	cout << "\nUpdated marks list (" << n << " values): ";
	for (int i = 0; i < n; i++)
	{
		cout << *(marks + i) << " ";
	}
	cout << endl;

	//  Release the final block exactly once 
	delete[] marks;
	marks = nullptr;

	return 0;
}