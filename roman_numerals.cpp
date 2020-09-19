// author: Javier Garcia Ramirez
// create date: Sunday, January 12th, 2020
// last modified: Friday, September 18, 2020
// filename: roman_numerals.cpp
// description: receives input from user then outputs the roman numeral value of the input
// runtime: n/a

#include <iostream>
#include <cstring>
using namespace std;

int numLength, newNumber, adjust = 0;


string strNumber; // Input by user will be received as string.
// Declare values for numbers leading/starting with the number 1.
string one = "I", ten = "X", hundred = "C", thousand = "M", tenThousand = "X̅";
// Declare values for numbers leading/starting with the number 5.
string five = "V", fifty = "L", fiveHundred = "D", fiveThousand = "V̅", fiftyThousand = "L̅"
, fiveHundredThousand = "D̅", fiveMillion = "V̿", fiftyMillion = "L̿", fiveHundredMillion = "D̿";
// Declare values for numbers leading/starting with the number 1.
string oneHundredThousand = "C̅", oneMillion = "M̅", tenMillion = "X̿", hundredMillion = "C̿", oneBillion = "M̿";


int numList[10]; // 10 is the most amount of digits the user's input can have.
string leadingOneList[10] = {one, ten, hundred, thousand, tenThousand, 
oneHundredThousand, oneMillion, tenMillion, hundredMillion, oneBillion};
string leadingFiveList[9] = {five, fifty, fiveHundred, fiveThousand, 
fiftyThousand, fiveHundredThousand, fiveMillion, fiftyMillion, fiveHundredMillion};


void stringToInteger();
void printRomanNumeral();


int main() {   
    cout << "\nEnter a number to see the Roman Numeral value: ";
    cin >> strNumber;
    numLength = strNumber.length();

    stringToInteger();
    cout << strNumber << " as a Roman Numeral: ";

    printRomanNumeral();
    cout << endl << endl;
    return 0;
}


void stringToInteger() {
   char charArray[numLength + 1];
   int intNumber;
   for (unsigned i= 0; i < numLength; i++) {
        strcpy(charArray, strNumber.c_str());   // copy string strNumber into charArray
        intNumber = charArray[i] - '0'; // convert char  value to int value by subracting ascii value of charArray[i] from the ascii value of 0 to get int value
        numList[i] = intNumber;         // save the int value into the int array
      
   }
}

void printRomanNumeral() {
    int placeholder;
    for (int s = 0; s <= numLength ;s++) {
	placeholder = numList[adjust]; // adjust makes sure the index is going through each element in numList
        // prints digit for numbers equal to or smaller than 3.
	switch(placeholder) {
		case 1: case 2: case 3: 
			for(int x = 0; x < placeholder ;x++) {
				cout << leadingOneList[numLength-1];
			}
			break;
        	// prints if numList[adjust] is 4
		case 4: 
			cout << leadingOneList[numLength-1] + leadingFiveList[numLength-1];
			break;
        	// prints 5 value automatically if number is equal to or greater than 5 but less than 9. Then prints digit for each number over 5
		case 5: case 6: case 7: case 8:
			cout << leadingFiveList[numLength-1];
			// x = 5 because if numList[adjust] = 5, it will not run the for loop which means it will not print unneeded digits
			for(int x = 5; x < placeholder ;x++){
				cout << leadingOneList[numLength-1];
		    	}
			break;
        	// prints if numList[adjust] is 9
		case 9:
			cout << leadingOneList[numLength-1] + leadingOneList[numLength];
			break;
	}
        adjust = adjust + 1;        // in numList, it moves the index to the element on the right 
        // keeps s the same value of 0 because if we increase s and keep numLength, then printint from leadingOneList or leadingFiveList becomes more difficult.
        s = s-1;    
        numLength = numLength -1;   // since s is staying the same, we are decreasing numLength to eventually end the for loop
    }
}
