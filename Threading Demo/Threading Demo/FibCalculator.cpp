#include "FibCalculator.h"
#include <iostream>

using namespace std;

void FibCalculator::PrintFibNumber(int _number)
{
	cout << _number << " = " << CalculateFibNumber(_number) << endl;
}

int FibCalculator::CalculateFibNumber(int _number)
{
	if (_number <= 2)
	{
		return 1;
	}

	return CalculateFibNumber(_number - 1) + CalculateFibNumber(_number - 2);
}
