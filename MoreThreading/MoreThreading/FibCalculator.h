#pragma once

#include <mutex>
class FibCalculator
{
public:
	void PrintFibNumber(int _number, std::mutex* mtx);
private:
	int CalculateFibNumber(int _number);
};

