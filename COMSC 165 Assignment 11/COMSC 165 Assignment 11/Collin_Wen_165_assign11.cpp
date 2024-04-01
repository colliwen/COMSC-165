#include <iostream>
#include <string>
using namespace std;

//Structure for type of drink
struct Drink {
	string name;
	double price;
	int numCans;
};

//Function prototypes
void display(Drink[]);
int getChoice(Drink []);
void purchase(Drink [], int, double &);


int main() {

	//Initialize earnings number
	double earnings = 0;
	
	//Create array with Drinks
	Drink drinks[5] = { {"1) Cola      ", .75, 20}, {"2) Root Beer ", .75, 20},
						{"3) Lemon-Lime", .75, 20}, {"4) Grape Soda", 0.80, 20},
						{"5) Cream Soda", .80, 20} };

	//Initialize choice by using function get choice
	int choice = getChoice(drinks);
	
	//Continue loop until user exits
	while (choice >= 0 && choice < 5) {
		purchase(drinks, choice, earnings);
		choice = getChoice(drinks);

	}
	
	//Return the earnings
	cout << "Bye." << endl << "Money earned: $" << earnings;

	return 0;
}

//Displays menu with drink data
void display(Drink arr[]) {
	for (int i = 0; i < 5; i++) {
		cout << arr[i].name << "     " << arr[i].price << endl;
	}
	cout << "6) Leave";
}

//Gets the users choice
int getChoice(Drink arr[]) {
	int num;
	display(arr);
	cout << endl << "choose one: ";
	cin >> num;

	//Check if choice is valid
	while (num < 0 || num > 6) {
		cout << "Enter a number between 1 and 6: ";
		cin >> num;
	}

	return num - 1;
}

//Using choice, allows purchase and gives change
void purchase(Drink arr[], int choice, double& earnings) {
	double moneyEntered;
	
	//Check if drink type out of stock
	if (arr[choice].numCans == 0) {
		cout << "Sold out" << endl;
		return;
	}
	
	//Gets users money
	cout << "The price is: $" << arr[choice].price << endl << "Please enter money: ";
	cin >> moneyEntered;

	//Checks if money amount valid
	while (moneyEntered < arr[choice].price || moneyEntered > 1) {
		cout << "Please enter more than $" << arr[choice].price << " and greater than $1: ";
		cin >> moneyEntered;
	}
	
	//Returns change and adds to earnings
	if (moneyEntered > arr[choice].price && moneyEntered <= 1) {
		arr[choice].numCans--;
		cout << "Thanyou, enjoy! " << "Your change is $" << moneyEntered - arr[choice].price << endl << "There are "
			<< arr[choice].numCans << " of this soda left" << endl << endl;
		earnings += arr[choice].price;
	}
}



