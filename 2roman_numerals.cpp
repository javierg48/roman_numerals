// author: Javier Garcia Ramirez
// create date: Sunday, January 12th, 2020
// last modified: Saturday, January 18th, 2020
// filename: 2roman_numerals.cpp
// description: receives input from user then outputs the roman numeral value of the input
// runtime: n/a

#include <iostream>
#include <cstring>
using namespace std;

int numLength, newNumber, adjust = 0;;
string strNumber;
// declares values for 1, 10, 100, 1.000, and 10.000
string oneDigit = "I", twoDigit = "X", threeDigit = "C", fourDigit = "M", fiveDigit = ".X_.";
// declares values for 5, 50, 500, 5.000, 50.000, 500.000, 5.000.000, and 50.000.000
string vDigit = "V", lDigit = "L", dDigit = "D", v_Digit = ".V_.", l_Digit = ".L_.", d_Digit = ".D_.", _v_Digit = "._V_.", _l_Digit = "._L_.", _d_Digit = "._D_.";
// declares values for 100.000, 1.000.000, 10.000.000, 100.000.000, and 1.000.000.000
string sixDigit = ".C_.", sevenDigit = ".M_.", eightDigit = "._X_.", nineDigit = "._C_.", tenDigit = "._M_.";

int numList[100];
string digitList[10] = {oneDigit, twoDigit, threeDigit, fourDigit, fiveDigit, sixDigit, sevenDigit, eightDigit, nineDigit, tenDigit};
string d2List[10] = {vDigit, lDigit, dDigit, v_Digit, l_Digit, d_Digit, _v_Digit, _l_Digit, _d_Digit};


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
                cout << digitList[numLength-1];
            }
        }
        // prints if numList[adjust] is 4
        if (numList[adjust] == 4){
            cout << digitList[numLength-1] + d2List[numLength-1];
        }
        // prints 5 value automatically if number is equal to or greater than 5 but less than 9. Then prints digit for each number over 5
        if (numList[adjust] >= 5 && numList[adjust] < 9){
            cout << d2List[numLength-1];
            // x = 5 because if numList[adjust] = 5, it will not run the for loop which means it will not print unneeded digits
            for(int x = 5; x < numList[adjust] ;x++){
                cout << digitList[numLength-1];
            }
        }
        // prints if numList[adjust] is 9
        if (numList[adjust] == 9){
            cout << digitList[numLength-1] + digitList[numLength];
        }

        adjust = adjust + 1;        // in numList, it moves the index to the element on the right 
        // keeps s the same value of 0 because if we increase s and keep numLength, then printint from digitList or d2List becomes more difficult.
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
