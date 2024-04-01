#include <iostream>
#include <string>
using namespace std;

//Initialize the size of an array as a constant
const int SIZE = 20;

//Funtion prototypes
void build_array(char arr[], int SIZE);
void check(const char answers[], const char correctAnswers[]);


int main() {
	//Initialize the array with the correct answers
	char correctAnswers[SIZE] { 'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B', 'C', 'D', 'A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 'D', 'B'};
	//Initialize the array with the student's answers
	char answers[SIZE];

	//Ask the user to enter the student's answers
	cout << "Please enter the student's answer to each question." << endl;
	cout << "Please press enter after each question." << endl;

	//Create an array with the student's answers
	build_array(answers, SIZE);
	
	//Prints if the student passed or failded the exam, number of incorrect and correct, and questions incorrect
	check(answers, correctAnswers);
}

//Makes the student's answers as an array
void build_array(char arr[], int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		cout << "Question " << i + 1 << ": ";
		cin >> arr[i];
		if (arr[i] != 'A' && arr[i] != 'B' && arr[i] != 'C' && arr[i] != 'D') {
			cout << "Please enter A, B, C, or D." << endl;
			i -= 1;
		}
	}
}

//Checks if the student passed or failded the exam, number of incorrect and correct, and questions incorrect
void check(const char answers[], const char correctAnswers[]) {
	int correct;
	int incorrect = 0;
	string incorrectQuestion;
	for (int i = 0; i < SIZE; i++) {
		if (answers[i] != correctAnswers[i]) {
			incorrect ++;
			incorrectQuestion += to_string(i) += "\n";
		}
	}
	correct = SIZE - incorrect;
	
	//Prints if student passed or failed exam
	if (correct >= 15) {
		cout << "The student passed the exam." << endl;
	}
	else {
		cout << "The student failed the exam." << endl;
	}
	
	//Prints how many correct and incorrect answers and the incorrect questions
	cout << "Correct Answers : " << correct << endl << "Incorrect Answers: " << incorrect << endl
		<< "Questions answered incorrectly :" << endl << incorrectQuestion << endl;
}
