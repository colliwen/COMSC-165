#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

//Function prototypes
void read(const string, vector<string> &);
void displayVector(const vector<string>);
string chooseTeam();
int totalWins(const vector<string>, const string);
void displayWins(const string, const int);

int main() {
	//Initialize vectors that will hold team names and the winners of world series
	vector<string> teams;
	vector<string> winners;

	//Copy the teams and winners of the world series into the vectors
	read("Teams.txt", teams);
	read("Winners.txt", winners);
	
	//Print all the teams onto the console
	displayVector(teams);

	//Ask user to choos a team
	string team = chooseTeam();

	//Print out how many wins the chosen team has
	displayWins(team, totalWins(winners, team));

	system("PAUSE");
	return 0;
}

//Goes through a file and puts each line into a vector element
void read(const string filename, vector<string> &vec) {
	ifstream input_obj;
	input_obj.open(filename);
	string value;
	if (!input_obj)
		cout << "error" << filename;
	while (getline(input_obj, value))
		vec.push_back(value);
	input_obj.close();
}

//Print out the elements of a vector
void displayVector(const vector<string> vec) {
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << endl;
}

//Asks the user to choose a team
string chooseTeam() {
	string team;
	cout << "Pick a team: ";
	getline(cin, team);
	return team;
}

//Calculates the world series wins of a team
int totalWins(const vector<string> vec, const string team) {
	int total = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (team == vec[i])
			total++;
	}
	return total;
}

//Prints out the number of world series wins the chosen team has
void displayWins(const string team, const int wins) {
	cout << team << " have " << wins << " world series wins.";
}