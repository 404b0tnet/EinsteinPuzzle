/*
file:	einsteinPuzzle
by:		Justin Smith
org:	COP 2001, Spring 2020
for:	Develop a puzzle that takes in 3 digits, doing string manipulation to them.
*/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


int main() {						// Start main
	   


	int inputNum;

	string numStr;

	char again;

	do {

		cout << "Enter a 3-digit number where the first and last digits differ by one or more: ";
		cin >> inputNum;



		// convert int to string
		numStr = to_string(inputNum);											



		// check to see if the first and last digit are different
		while ((numStr[0] == numStr[2]) || (numStr.length() > 3))				
		{
			cout << "Enter a 3-digit number where the first and last digits differ by one or more: ";
			cin >> inputNum;

			numStr = to_string(inputNum);
		}



		// reversing order of original number
		string stringReversed = "";

		for (int i = numStr.length() - 1; i >= 0; i--)
		{
			stringReversed += numStr[i];
		}


		// difference  between the original and the reversed number
		int diffNum = (inputNum - stoi(stringReversed));

		bool negative = false;

		// tests for a negative number
		if (diffNum < 0) {
			negative = true;
		}




		// reversing order of difference number
		string differenceReversed = "",
			diffStr = to_string(diffNum);

		if (negative) {		// if the difference was negative
			differenceReversed = "-";

			for (int i = diffStr.length() - 1; i > 0; i--)
				differenceReversed += diffStr[i];

		}
		else {

			for (int i = diffStr.length() - 1; i >= 0; i--)
				differenceReversed += diffStr[i];

		}

		


		// sum of diffNum and reverseDiff
		int sumDiff = (diffNum + stoi(differenceReversed));



		cout << inputNum << " -- original" << endl;
		cout << stringReversed << " -- reverse of the original" << endl;
		cout << diffNum << " -- difference between original and reversed" << endl;
		cout << differenceReversed << " -- reverse of the difference" << endl;
		cout << sumDiff << " -- sum of the difference and reverse of the difference" << endl;



		cout << "\nWould you like to go again? ";
		cin >> again;

		system("cls");

	} while (again == 'Y' || again == 'y');
	   

	return 0;
}									// End main