#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//constant variables giving a number to a choice
const int ROCK = 1;
const int PAPER = 2;
const int SCISSORS = 3;
const int QUIT = 4;

//function prototypes
int getUserChoice();
int getComputerChoice();
void determineOutcome(int, int);
void displayChoice(int);

int main()
{
	//initialize variables for computer and user choice
	int userChoice;
	int computerChoice;

	//assign the computer's choice with the function getComputerChoice()
	computerChoice = getComputerChoice();

	//assign the user's choice with the function getUserChoice
	userChoice = getUserChoice();

	//when the user enters a valid choice, display what they chose, what the computer chose, and who won the game
	while (userChoice != QUIT)
	{

		cout << "\nYou selected: ";
		displayChoice(userChoice);
		cout << "The computer selected: ";
		displayChoice(computerChoice);

		determineOutcome(userChoice, computerChoice);
		cout << endl;

		computerChoice = getComputerChoice();

		userChoice = getUserChoice();
	}

	system("PAUSE");
	return 0;
}

//Create the function getUserChoice() that returns the choice of the user
int getUserChoice() {
	int choice;
	cout << "Game Menu\n---------------\n\n1) Rock\n\n2) Paper\n\n3) Scissors\n\n4) Quit\n" << endl;
	cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
		cout << "Pick a number between 1 and 4" << endl;
		cin >> choice;
	}
	return choice;
}

//Create the function getComputerChoice that returns the choice of the computer that is a random number
int getComputerChoice() {
	//seed the random number generator so the same sequence of numbers is given each time the program runs
	srand(time(0));
	//returns a random number between 1 and 4
	return rand() % 4 + 1;
}

//Create the function determineOutcom(int, int) that returns a statement saying who won the game
void determineOutcome(int userChoice, int compChoice) {
	//Goes through all the combinations of user choices and computer choices giving each of them a return statement on who won(or if there is a tie)
	if (userChoice == compChoice)
		cout << "You tied" << endl;
	else if (userChoice == ROCK && compChoice == SCISSORS)
		cout << "You Win(Rock smashes scissors)" << endl;
	else if (userChoice == ROCK)
		cout << "You lose(Paper wraps Rock)" << endl;
	else if (userChoice == SCISSORS && compChoice == PAPER)
		cout << "You win(Scissors cuts paper)" << endl;
	else if (userChoice == SCISSORS)
		cout << "You lose(Rock smashes scissors)" << endl;
	else if (userChoice == PAPER && compChoice == ROCK)
		cout << "You win(Paper wraps rock)" << endl;
	else if (userChoice == PAPER)
		cout << "You lose(Scissors cuts paper)" << endl;
}

//Create the function displayChoice(int) that returns a statement on what the number entered is as a choice of rock, paper, or scissors
void displayChoice(int choice) {
	if (choice == ROCK)
		cout << "rock" << endl;
	else if (choice == SCISSORS)
		cout << "scissors" << endl;
	else
		cout << "paper" << endl;
}

