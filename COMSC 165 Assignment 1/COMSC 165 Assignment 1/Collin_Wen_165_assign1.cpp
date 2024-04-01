#include <iostream>
using namespace std;
#include <string>;

int main()
{
	//Initializing strings for the runner's names
	string runner1;
	string runner2;
	string runner3;
	
	//Initializing doubles for the runner's finishing times
	double run1Time;
	double run2Time;
	double run3Time;

	//Initializinig strings for which runner came in which position
	string firstPlace;
	string secondPlace;
	string thirdPlace;

	//Asks user for the first runners name and finishing time
	cout << "Who is the first runner?" << endl;
	getline(cin, runner1);
	cout << "What was their finishing time?" << endl;
	cin >> run1Time;
	cout << endl;
	
	//Makes the first runner be in first place
	firstPlace = runner1;

	//Asks user for second runners name and finishing time
	cout << "Who is the second runner?" << endl;
	cin.ignore();
	getline (cin, runner2);
	cout << "What was their finishing time?" << endl;
	cin >> run2Time;
	cout << endl;
	
	//If the second runner had a faster speed than the first runner they are in first place,
	//if not they are in second place
	if (run2Time < run1Time) {
		secondPlace = firstPlace;
		firstPlace = runner2;
	}
	else secondPlace = runner2;

	//Asks use for third runner name and finishing time
	cout << "Who is the third runner?" << endl;
	cin.ignore();
	getline (cin, runner3);
	cout << "What was their finishing time?" << endl;
	cin >> run3Time;
	cout << endl;
	
	//if runner 3's time is faster than all other runners, they are in first place and the other racers move down
	if (run3Time < run1Time && run3Time < run2Time) {
		thirdPlace = secondPlace;
		secondPlace = firstPlace;
		firstPlace = runner3;
	}
	//if runner 3's time is faster than one of the runners they are in second place, former second place racer moves to third
	else if (run3Time < run1Time || run3Time < run2Time) {
		thirdPlace = secondPlace;
		secondPlace = runner3;
	}
	//if runner 3's time is slower than both other runners then they are in third place
	else if (run3Time > run1Time && run3Time > run2Time) {
		thirdPlace = runner3;
	}

	//if one of the runner's times is less than 1 then an error message is displayed and the program ends
	if (run1Time < 0 || run2Time < 0 || run3Time < 0) {
		cout << "Error, 1 or more finishing times are negative.";
		return 0;
	}
	 //Prints out the positions of the racers
	cout << firstPlace << " came in first place." << endl;
	cout << secondPlace << " came in second place." << endl;
	cout << thirdPlace << " came in third place." << endl;

	//ends the program
	return 0;
	

}
