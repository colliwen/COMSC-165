#include <iostream>
using namespace std;

//Function prototypes
int getMode(int*, int);
int* makeArray(int);

// main has been completed for you

int main()
{
	const int SIZE = 11;
	int test[SIZE] = { 12, 3, 9, 2, 8, 12, 7, 3, 12, 31, 42 };
	int mode;

	mode = getMode(test, SIZE);

	if (mode == -1)
		cout << "The test set has no mode.\n";
	else
		cout << "\nThe mode of the test set is: "
		<< mode << endl;

	system("PAUSE");
	return 0;
}

int getMode(int* array, int size)
{

	// frequencies will point at a dynamically allocated array
	// in this assignment pointer notation (i.e., using the *) should always be used instead of
	// bracket/subscript notation (i.e., using the []).

	int* frequencies = makeArray(size);

	for (int i = 0; i < (size - 1); i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (*(array + i) == *(array + j))
				*(frequencies + i) = *(frequencies + i) + 1;
		}
	}

	//Initialize variables
	//Where the max number in frequencies array is
	int position = 0;
	//The max number in frequencies array
	int	max = *frequencies;
	//The mode
	int mode = *array;

	//Finds the max of frequencies array
	for (int a = 1; a < size; a++)
	{
		//Checks if current max is less than next max
		if (max < *(frequencies + a))
		{
			//If current max is less then switch
			max = *(frequencies + a);
			//Goes back to array to find mode
			mode = *(array + a);
			//The position of the max/mode
			position = a;
		}
	}

	//Deletes frequencies array to save space
	delete[] frequencies; // Do NOT remove this -- this needs to be at the end of the function
						   // to remove the dynamically allocated frequencies array from memory
						   // when it is no longer needed.

	//Returns the mode of the array
	return mode;

}



// makeArray has been completed for you

int* makeArray(int size)
{
	return new int[size];
}





