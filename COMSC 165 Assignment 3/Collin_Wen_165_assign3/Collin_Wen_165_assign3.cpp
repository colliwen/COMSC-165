#include <iostream>
#include <iomanip>
using namespace std;

//prototype of functions
void getJudgeData(double &);
void calcScore(double, double, double, double, double);
double findLowest(double, double, double, double, double);
double findHighest(double, double, double, double, double);

int main()
{
	//Initialize judge's score variable
	double score1;	
	double score2;	
	double score3;	
	double score4;	
	double score5;	

	//Get and input for each judge's score and check if they are between 0.0 and 10.0

	cout << "Enter a judge's score: ";
	cin >> score1;
	getJudgeData(score1);
	cout << "Enter a judge's score: ";
	cin >> score2;
	getJudgeData(score2);

	cout << "Enter a judge's score: ";
	cin >> score3;
	getJudgeData(score3);

	cout << "Enter a judge's score: ";
	cin >> score4;
	getJudgeData(score4);

	cout << "Enter a judge's score: ";
	cin >> score5;
	getJudgeData(score5);

	//Get and print a line telling the average score
	calcScore(score1, score2, score3, score4, score5);

//	system("PAUSE");
    return 0;
}

//Make sure the score given in between 0.0 and 10.0
void getJudgeData(double &score) {
	if (score < 0.0 || score > 10.0) {
		//If score not between 0.0 and 10.0 then ask for a new score
		cout << "Please choose a number between 0 and 10." << endl;
		cout << "Enter a judge's score: ";
		cin >> score;
		getJudgeData(score);
		
	}
}

//Calculate and return the average score dropping the lowest and highest scores
void calcScore(double score1, double score2, double score3, double score4, double score5) {
	double highest = findHighest(score1, score2, score3, score4, score5);
	double lowest = findLowest(score1, score2, score3, score4, score5);
	double total = score1 + score2 + score3 + score4 + score5;
	
	//Drop the lowest and highest score
	if (score1 == highest || score1 == lowest)
		total - score1;
	if (score2 == highest || score2 == lowest)
		total - score2;
	if (score3 == highest || score3 == lowest)
		total - score3;
	if (score4 == highest || score4 == lowest)
		total - score4;
	if (score5 == highest || score5 == lowest)
		total - score5;
	cout << "After dropping both the highest and lowest scores the average score is " << total / 5 << endl;
}

//Finds teh lowest score
double findLowest(double score1, double score2, double score3, double score4, double score5) {
	double lowest = score1;
	if (score2 < lowest)
		lowest = score2;
	if (score3 < lowest)
		lowest = score3;
	if (score4 < lowest)
		lowest = score4;
	if (score5 < lowest)
		lowest = score5;
	return lowest;
}

//Finds the highest score
double findHighest(double score1, double score2, double score3, double score4, double score5) {
	double highest = score1;
	if (score2 > highest)
		highest = score2;
	if (score3 > highest)
		highest = score3;
	if (score4 > highest)
		highest = score4;
	if (score5 > highest)
		highest = score5;
	return highest;
}

