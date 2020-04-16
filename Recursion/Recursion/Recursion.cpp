#include <iostream>

using namespace std;

int factorial(int number);
int facRecursive(int number);

int fibonacci(int number);
int fibRecursive(int number);

int main()
{
	//cout << factorial(6) << endl;
	//cout << facRecursive(6) << endl;
    
	for (int i = 0; i < 40; i++)
	{
		cout << i << ": " << fibRecursive(i) << endl;
	}
}

int factorial(int number) 
{
	int product = 1; 

	while (number > 1)
	{
		product *= number;
		number--;
	}

	return product;
}

int facRecursive(int number)
{
	if (number <= 1)
	{
		return 1;
	}

	return number * facRecursive(number - 1);
}

int fibonacci(int number)
{
	if (number < 2) 
	{
		return number;
	}

	int twoBack = 0;
	int oneBack = 1;
	int current;

	for (int i = 1; i < number; i++)
	{
		current = twoBack + oneBack;
		twoBack = oneBack;
		oneBack = current;
	}

	return current;
}

int fibRecursive(int number)
{
	if (number < 2)
	{
		return number;
	}

	return fibRecursive(number - 1) + fibRecursive(number - 2);
}
