// author: Javier Garcia Ramirez
// create date: Sunday, January 12th, 2020
// last modified: Friday, September 18, 2020
// filename: roman_numerals.cpp
// description: receives input from user then outputs the roman numeral value of the input
// runtime: n/a

#include <iostream>
#include <cstring>
using namespace std;

int numLength, newNumber, adjust = 0;;
string strNumber;
           // 1          10            100            1.000             10.000
string one = "I", ten = "X", hundred = "C", thousand = "M", tenThousand = "X̅";
           //  5           50                 500                5.000                50.000                    500.000           5.000.000           50.000.000               500.000.000
string five = "V", fifty = "L", fiveHundred = "D", fiveThousand = "V̅", fiftyThousand = "L̅", fiveHundredThousand = "D̅", fiveMillion = "V̿", fiftyMillion = "L̿", fiveHundredMillion = "D̿";
           //              100.000,         1.000.000,        10.000.000,          100.000.000,     1.000.000.000
string oneHundredThousand = "C̅", oneMillion = "M̅", tenMillion = "X̿", hundredMillion = "C̿", oneBillion = "M̿";


int numList[100];
string leadingOneList[10] = {one, ten, hundred, thousand, tenThousand, oneHundredThousand, oneMillion, tenMillion, hundredMillion, oneBillion};
string leadingFiveList[10] = {five, fifty, fiveHundred, fiveThousand, fiftyThousand, fiveHundredThousand, fiveMillion, fiftyMillion, fiveHundredMillion};


void stringToInteger(){
   char charArray[numLength + 1];
   int intNumber;

    for (unsigned i= 0; i < numLength; i++){
        strcpy(charArray, strNumber.c_str());   // copy string strNumber into charArray
        // convert char  value to int value by subracting ascii value of charArray[i] from the ascii value of 0 to get int value
        intNumber = charArray[i] - '0';
        numList[i] = intNumber;        // save the int value into the int array
      
    }
}


void printRomanNumeral(){
    for (int s = 0; s <= numLength ;s++){
        // prints digit for numbers equal to or smaller than 3.
        if (numList[adjust] <= 3){      // adjust makes sure the index is going through each element in numList
            for(int x = 0; x < numList[adjust] ;x++){
                cout << leadingOneList[numLength-1];
            }
        }
        // prints if numList[adjust] is 4
        if (numList[adjust] == 4){
            cout << leadingOneList[numLength-1] + leadingFiveList[numLength-1];
        }
        // prints 5 value automatically if number is equal to or greater than 5 but less than 9. Then prints digit for each number over 5
        if (numList[adjust] >= 5 && numList[adjust] < 9){
            cout << leadingFiveList[numLength-1];
            // x = 5 because if numList[adjust] = 5, it will not run the for loop which means it will not print unneeded digits
            for(int x = 5; x < numList[adjust] ;x++){
                cout << leadingOneList[numLength-1];
            }
        }
        // prints if numList[adjust] is 9
        if (numList[adjust] == 9){
            cout << leadingOneList[numLength-1] + leadingOneList[numLength];
        }

        adjust = adjust + 1;        // in numList, it moves the index to the element on the right 
        // keeps s the same value of 0 because if we increase s and keep numLength, then printint from leadingOneList or leadingFiveList becomes more difficult.
        s = s-1;    
        numLength = numLength -1;   // since s is staying the same, we are decreasing numLength to eventually end the for loop
    }
}


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
