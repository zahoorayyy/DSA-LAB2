

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>   // for exit()

using namespace std;

int readPositiveInt(const string &prompt)
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
				// Input stream has run out entirely; looping again would spin forever.
				cerr << "\nInput stream ended unexpectedly. Exiting." << endl;
				exit(1);
			}
			cin.clear();                                          // reset error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n');   // discard bad input
			cout << "Invalid input. Please enter a whole number." << endl;
			continue;
		}

		if (value <= 0)
		{
			cout << "Value must be greater than 0. Please try again." << endl;
			continue;
		}

		return value;
	}
}

int main()
{
	//  Read and validate rows and cols before allocation 
	int rows = readPositiveInt("Enter number of students: ");
	int cols = readPositiveInt("Enter number of subjects: ");

	// Allocate an array of row pointers, then allocate 'cols' integers for each row
	int **marks = new int *[rows];
	for (int r = 0; r < rows; r++)
	{
		marks[r] = new int[cols];
	}

	//  Read marks (0-100), validated, using pointer notation 
	cout << "\nEnter marks (0-100) for each student:" << endl;
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			while (true)
			{
				cout << "Student " << (r + 1) << ", Subject " << (c + 1) << ": ";
				cin >> *(*(marks + r) + c);   // required pointer notation

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

				int enteredMark = *(*(marks + r) + c);
				if (enteredMark < 0 || enteredMark > 100)
				{
					cout << "Mark must be between 0 and 100. Please try again." << endl;
					continue;
				}

				break;   // valid mark accepted
			}
		}
	}

	// Display the matrix using the same pointer notation
	cout << "\nMarks Matrix:" << endl;
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			cout << *(*(marks + r) + c) << "\t";
		}
		cout << endl;
	}

	//Calculate totals and find the topper
	int bestTotal = 0;
	int bestStudent = 1;

	for (int r = 0; r < rows; r++)
	{
		int total = 0;
		for (int c = 0; c < cols; c++)
		{
			total += *(*(marks + r) + c);
		}

		cout << "Student " << (r + 1) << " total: " << total << endl;

		if (r == 0)
		{
			bestTotal = total;
			bestStudent = 1;
		}
		else if (total > bestTotal)   // strictly greater keeps first student on a tie
		{
			bestTotal = total;
			bestStudent = r + 1;
		}
	}

	cout << "\nTop student: Student " << bestStudent
		<< " with total marks = " << bestTotal << endl;

	//  Free the memory correctly
	for (int r = 0; r < rows; r++)
	{
		delete[] marks[r];
	}
	delete[] marks;
	marks = nullptr;

	return 0;
}