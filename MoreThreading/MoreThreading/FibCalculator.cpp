#include "FibCalculator.h"
#include <iostream>
using namespace std;

void FibCalculator::PrintFibNumber(int _number, mutex* mtx)
{
	int calculated = CalculateFibNumber(_number);

	mtx->lock();
	cout << _number << " = " << calculated << endl;
	mtx->unlock();
}

int FibCalculator::CalculateFibNumber(int _number)
{
	if (_number <= 2)
	{
		return 1;
	}
	return CalculateFibNumber(_number - 1) + CalculateFibNumber(_number - 2);
}
