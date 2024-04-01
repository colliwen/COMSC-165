#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//Function prototpes
void read(char*);
string rainyDays(const char*);
void display(const char*);


const int NUM_OF_MONTHS = 3;
const int NUM_OF_DAYS = 30;


int main()
{

	// this 2D array stores the 90 values from the RainOrShine.txt text file
	char weather[NUM_OF_MONTHS][NUM_OF_DAYS];

	char* ptr = &weather[0][0]; // this pointer points to the beginning of the 2D array
								// Remember -- no using the brackets/subscripts ([]'s)! 
								// Everything should be handled with pointer offset notation
								// and/or pointer arithmetic

	//implement the rest of main
	read(ptr);
	display(ptr);


//	system("PAUSE");
	return 0;
}

// implement your functions

//Reads file into array
void read(char* array) {
	ifstream input_obj;
	input_obj.open("RainorShine.txt");
	string value;
	if (!input_obj)
		cout << "error";
	int i = 0;
	//Go through file and put info into array
	while (getline(input_obj, value)) {
		if (i <= 29)
			*(array + 0) + i;
		if (i > 29 && i <= 59)
			*(array + 1) + i - 29;
		if (i > 59)
			*(array + 2) + i - 58;
	}
	input_obj.close();


}

//Calculate which month has most rainy days
string rainyDays(const char* array) {
	int june = 0;
	int july = 0;
	int august = 0;
	//Go through array
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 90; j++) {
			//Find when index is equal to r
			if (*(array + i) + j == 'r') {
				//For june
				if (i == 0) 
					june += 1;
				//For july
				else if (i == 1)
					july += 1;
				//For august
				else if (i == 2)
					august += 1;
			}		
		}
	}
	//Return which month has most rainy days
	if (june > july && june > august)
		return "June";
	if (july > august && july > june)
		return "July";
	else
		return "August";
}




//Display the weather for every month
void display(const char* array) {
	//Go through the months and find the weather
	int juneR = 0;
	int julyR = 0;
	int augustR = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 90; j++) {
			if (*(array + i) + j == 'R') {
				if (i == 0)
					juneR += 1;
				else if (i == 1)
					julyR += 1;
				else if (i == 2)
					augustR += 1;
			}
		}
	}

	int juneC = 0;
	int julyC = 0;
	int augustC = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 90; j++) {
			if (*(array + i) + j == 'C') {
				if (i == 0)
					juneC += 1;
				else if (i == 1)
					julyC += 1;
				else if (i == 2)
					augustC += 1;
			}
		}
	}

	int juneS = 0;
	int julyS = 0;
	int augustS = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 90; j++) {
			if (*(array + i) + j == 'S') {
				if (i == 0)
					juneS += 1;
				else if (i == 1)
					julyS += 1;
				else if (i == 2)
					augustS += 1;
			}
		}
	}

	//Print out all the weather for each month
	cout << "June had " << juneR << " rainy days, " << juneC << " cloudy days, and " << juneS << " sunny days" << endl;
	cout << "July had " << julyR << " rainy days, " << julyC << " cloudy days, and " << julyS << " sunny days" << endl;
	cout << "August had " << augustR << " rainy days, " << augustC << " cloudy days, and " << augustS << " sunny days" << endl;
	cout << rainyDays(array) << " had the most rainy days" << endl;
}
