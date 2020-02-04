#include <cstring>
#include <cctype>
#include <string>
#include "Functions.h"
using namespace std;

int convertToDecimal(char input[100], int inputBase, char values[36]) {
	int length = strlen(input);
	int Digits[100];
	int Powers[100];
	int result = 0;
	for (int i = 0; i < length; i++)
	{
		Digits[i] = convertToDigit(input[i], values);
		Powers[i] = Pow(inputBase, length - (i + 1));
	}
	for (int j = 0; j < length; j++) {
		result += (Powers[j] * Digits[j]);
	}
	return result;
}

int convertToDigit(char value, char values[36]) {
	value = toupper(value);
	for (int y = 0; y < 36; y++)
	{
		if (value == values[y]) {
			return y;
		}
	}
	return -1;
}

int Pow(int base, int power) {
	int currentNum = 1;
	if (power == 0) {
		return currentNum;
	} else {
		for (int i = 0; i < power; i++) {
			currentNum *= base;
		}
		return currentNum;
	}
}

char convertToBase(int num, int desiredBase, char values[36]) {
	char results;
	if (num != 0) {
		results = convertToChar(num % desiredBase, values);
	}

	return results;
}

char convertToChar(int digit, char values[36])
{
	return values[digit];
}
