#include <iostream>
using namespace std;

const int COLS = 5;


//Function Prototypes

int getTotal(int array[][COLS], int rows);
double getAverage(int array[][COLS], int rows);
int getRowTotal(int array[][COLS], int rowToTotal);
int getColumnTotal(int array[][COLS], int colToTotal, int rows);
int getHighestInRow(int array[][COLS], int rowToSearch);
int getLowestInRow(int array[][COLS], int rowToSearch);


int main()
{
	const int ROWS = 4;


	int testArray[ROWS][COLS] =
	{ { 91,   12,  33,  91,  5 },
	{   61,   21,  52,  42, 12 },
	{  9,  15, 22, 11, 13 },
	{  26,  17, 14, 19, 24 } };


	cout << "The total of the array elements is "
		<< getTotal(testArray, ROWS)
		<< endl;


	cout << "The average value of an element is "
		<< getAverage(testArray, ROWS)
		<< endl;


	cout << "The total of row 0 is "
		<< getRowTotal(testArray, 0)
		<< endl;


	cout << "The total of col 2 is "
		<< getColumnTotal(testArray, 2, ROWS)
		<< endl;


	cout << "The highest value in row 2 is "
		<< getHighestInRow(testArray, 2)
		<< endl;


	cout << "The lowest value in row 2 is "
		<< getLowestInRow(testArray, 2)
		<< endl;

	//system("PAUSE");
	return 0;
}

// Implement the six (6) functions here

//Finds the total of all elements in the array
int getTotal(int array[][COLS], int rows) {
	int sum = 0;
	//Goes through entire array
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < COLS; j++) {
			sum += array[i][j];
		}
	}
	return sum;
}

//Returns the average of all elements in the array
double getAverage(int array[][COLS], int rows) {
	return getTotal(array, rows) / (COLS * rows);
}

//Returns the total of all elements in a row
int getRowTotal(int array[][COLS], int rowToTotal) {
	int sum = 0;
	//Traverse through row
	for (int i = 0; i < COLS; i++) {
		sum += array[rowToTotal][i];
	}
	return sum;
}

//Returns the total of all elements in a column
int getColumnTotal(int array[][COLS], int colToTotal, int rows) {
	int sum = 0;
	//Traverse through column
	for (int i = 0; i < 4; i++) {
		sum += array[i][colToTotal];
	}
	return sum;
}

//Returns the highest value of an element in an row
int getHighestInRow(int array[][COLS], int rowToSearch) {
	int highest = array[rowToSearch][0];
	//traverse through row
	for (int i = 0; i < COLS - 1; i++) {
		if (array[rowToSearch][i + 1] > highest) {
			array[rowToSearch][i + 1] = highest;
		}
	}
	return highest;
}

//Returns the lowest value of an element in a row
int getLowestInRow(int array[][COLS], int rowToSearch) {
	int lowest = array[rowToSearch][0];
	//traverse through row
	for (int i = 0; i < COLS - 1; i++) {
		if (array[rowToSearch][i + 1] < lowest) {
			array[rowToSearch][i + 1] = lowest;
		}
	}
	return lowest;
}