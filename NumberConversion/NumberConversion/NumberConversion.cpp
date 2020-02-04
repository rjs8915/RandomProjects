#include <iostream>
#include <string>
#include <cstring>
#include "Functions.h"
using namespace std;

char values[36] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
int result;
char resultString[25];

int main()
{
	char input[100];
	int inputBase;
	int desiredBase;

	cout << "What base would you like to start with? ";
	cin >> inputBase;

	if (inputBase > 36) {
		cout << "\nThat number is currently too high" << endl;
		return 3;
	}

	cout << "\nWhat number would you like to convert? ";
	cin >> input;

	int length = strlen(input);

	for (int i = 0; i < length; i++) {
		for (int j = inputBase; j < 36; j++) {
			if (input[i] == values[j]) {
				cout << "The number has invalid characters" << endl;
				return 4;
			}

		}
	}

	cout << "What base would you like to convert to? ";
	cin >> desiredBase;

	if (desiredBase > 36) {
		cout << "\nThat number is currently too high" << endl;
		return 3;
	}

	result = convertToDecimal(input, inputBase, values);

	cout << "Your number in decimal is: " << result << endl;

	if (result < 0) {
		cout << "Your number is too large!" << endl;
		return 5;
	}

	if (desiredBase != 10) {
		int i = 0;
		while (result != 0) {
			resultString[i] = convertToBase(result, desiredBase, values);
			i++;
			result /= desiredBase;
		}


		cout << "Your number in base " << desiredBase << " is " << _strrev(resultString) << endl;
	}
}