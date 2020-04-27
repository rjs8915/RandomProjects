#include <iostream>
#include <thread>
#include <vector>

#include "FibCalculator.h"

using namespace std;

void PrintHello()
{
	cout << "Hello" << endl;
}

void PrintGoodbye()
{
	cout << "Goodbye!" << endl;
}

int main()
{
	thread helloThread(PrintHello);
	thread goodbyeThread(PrintGoodbye);

	helloThread.join();
	cout << "Finished Joining Hello" << endl;
	goodbyeThread.join();


	FibCalculator fibCalc;
	vector<thread*> fibThreads;
	
	for (int i = 0; i < 45; i++)
	{
		fibThreads.push_back(new thread(&FibCalculator::PrintFibNumber, fibCalc, i));
	}

	for (int i = 0; i < fibThreads.size(); i++)
	{
		fibThreads[i]->join();
		delete fibThreads[i];
	}

	cout << "Bottom of Main" << endl;
}