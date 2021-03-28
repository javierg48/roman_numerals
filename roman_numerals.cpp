// author: Javier Garcia Ramirez
// create date: Sunday, January 12, 2020
// last modified: Saturday, March 27, 2021
// filename: roman_numerals.cpp
// description: receives input from user then outputs the roman numeral value of the input
// runtime: n/a

#include <iostream>
#include <string>


void printRomanNumeral(std::string userInput, int inputLength);
void traverse(std::string *array, int inputLength, int currentNum, int x);


int main() {
    // receive input as string because it makes it easier to get it's length
    std::string userInput;
    std::cout << "\nEnter a number between 1 and 1 billion: "; // should be less than 10 digits
    std::cin >> userInput;

    int inputLength = userInput.length(); 
    int userNum = stoi(userInput); // convert userInput string to integer

    std::cout << userNum << " as a Roman Numeral: ";
    printRomanNumeral(userInput, inputLength);
    std::cout << std::endl << std::endl;
    return 0;
}


void printRomanNumeral(std::string userInput, int inputLength) {
    std::string onesList[] = { "I", "X", "C", "M", "X̅",  "C̅", "M̅", "X̿", "C̿", "M̿" };
    std::string fivesList[] = {"V", "L", "D", "V̅", "L̅", "D̅", "V̿", "L̿", "D̿"};

    int currentNum = 0;
    for(int i = 0; 0 <= inputLength; i++) {
        currentNum = userInput[i] - '0'; // convert character within string of userInput to an int
        inputLength -= 1;

        if (1 <= currentNum && currentNum <= 3) { // num between 1 and 3 (inclusive)
            traverse(onesList, inputLength, currentNum, 0);
        } else if (currentNum == 4) {
            std::cout << onesList[inputLength] + fivesList[inputLength];
        } else if (5 <= currentNum && currentNum <= 8) { // num between 5 and 8 (inclusive)
            std::cout << fivesList[inputLength];
            traverse(onesList, inputLength, currentNum, 5);
        } else if (currentNum == 9) {
            std::cout << onesList[inputLength] + onesList[inputLength+1];        
        }
    }
}


void traverse(std::string *array, int inputLength, int currentNum, int x) {
    for(int i = x; i < currentNum; i++) // x will be either 0 or 5
        std::cout << array[inputLength];
}