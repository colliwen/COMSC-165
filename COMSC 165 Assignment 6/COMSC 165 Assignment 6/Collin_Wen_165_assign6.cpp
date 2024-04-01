#include<iostream>
using namespace std;

//Constant variables for the number of rows, columns, and the maximum and minimum number allowed for magic square
const int ROWS = 3;
const int COLS = 3;
const int MIN = 1;
const int MAX = 9;

//Function prototypes
void showResult(int[][COLS]);
void showArray(int[][COLS]);
bool isMagicSquare(int[][COLS]);
bool checkRange(int[][COLS]);
bool checkUnique(int[][COLS]);
bool checkRowSum(int[][COLS]);
bool checkColSum(int[][COLS]);
bool checkDiagSum(int[][COLS]);

int main()
{

    int magicArray[ROWS][COLS] = { {4, 9, 2},
                                   {3, 5, 7},
                                   {8, 1, 6} };


    int normalArray[ROWS][COLS] = { {1, 21, 3},
                                    {0, 0, 2},
                                    {9, 181, 1} };

    //Prints out the normal array and if it is a magic square
    showArray(normalArray);
    showResult(normalArray);

    //Prints out the magic array and if it is a magic square
    showArray(magicArray);
    showResult(magicArray);

    // system("PAUSE");
    return 0;
}

//Function that prints out if an array is a magic square
void showResult(int values[][COLS])
{

    if (isMagicSquare(values))
    {
       cout << "This is a Lo Shu magic square.\n\n";
    }
    else
    {
        cout << "This is not a Lo Shu magic square.\n\n";
    }
}

//Prints out the elements of an array
void showArray(int values[][COLS])
{

    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            cout << values[row][col] << " ";
        }
        cout << endl;
    }
}

//Checks if an array is a magic square
bool isMagicSquare(int arr[][COLS]) {
    if (checkRange(arr) == false
        || checkUnique(arr) == false
        || checkRowSum(arr) == false
        || checkColSum(arr) == false
        || checkDiagSum(arr) == false) {
        return false;
    };
}

//Checks an array if it has nine elements and there are only numbers 1 - 9
bool checkRange(int arr[][COLS]) {
    //Checks if the array is a 3 by 3
    if (sizeof(arr) / sizeof arr[0] != 3 && sizeof arr[0] / sizeof(int) != 3) {
        return false;
    }
    
    //Checks if elements are 1 - 9
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] < MIN || arr[i][j] > MAX)
                return false;
        }
    }
    return true;
}

//Checks for duplicates in the array
bool checkUnique(int arr[][COLS]) {
    int count = 0;
    for (int l = 1; l <= 9; l++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (arr[i][j] == l) {
                    count += 1;
                    if (count > 1) {
                        return false;
                    }
                }
                if (arr[i][j] == arr[2][2]) {
                    count = 0;
                }
            }
        }
    }
    return true;
}

//Checks to make sure all rows of the array are equal to 15
bool checkRowSum(int arr[][COLS]) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += arr[i][j];
            if (arr[i][j] == arr[i][2]) {
                if (sum != 15) {
                    return false;
                }
                sum = 0;
            }
        }
    }
    return true;
}

//Checks if all columns of the array are equal to 15
bool checkColSum(int arr[][COLS]) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += arr[j][i];
            if (arr[j][i] == arr[2][i]) {
                if (sum != 15) {
                    return false;
                }
                sum = 0;
            }
        }
    }
    return true;
}

//Checks if all diagnals of an array are equal to 15
bool checkDiagSum(int arr[][COLS]) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += arr[i][i];
        if (arr[i][i] == arr[2][2]) {
            if (sum != 15) {
                return false;
            }
        }
    }
    sum = 0;
    for (int j = 2; j > -1; j--) {
        sum += arr[j][j];
        if (arr[j][j] == arr[0][0]) {
            if (sum != 15) {
                return false;
            }
        }
    }
    return true;
}

