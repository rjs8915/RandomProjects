#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ofstream outFile = ofstream("text.txt");

	if (outFile.is_open())
	{
		outFile << "Hello File IO World" << endl;
		outFile << "Hello New Line! ";
		outFile << "Hello Same Line!";
	}

	outFile.close();


	ifstream inFile("text.txt");
	string fileAsString = string(istreambuf_iterator<char>(inFile), istreambuf_iterator<char>());
	inFile.close();
	cout << fileAsString << endl;


	const int OBSFUSCATION_KEY = 58205934059;
	string saveData = "Lives: 5, Position: (10, 14), Level: 3";

	for (int i = 0, length = saveData.length(); i < length; i++)
	{
		saveData[i] ^= OBSFUSCATION_KEY;
	}

	outFile.open("saveData.txt");
	if (outFile.is_open())
	{
		outFile << saveData;
	}
	outFile.close();



	inFile.open("saveData.txt");
	fileAsString = string(istreambuf_iterator<char>(inFile), istreambuf_iterator<char>());
	inFile.close();

	for (int i = 0, length = fileAsString.length(); i < length; i++)
	{
		fileAsString[i] ^= OBSFUSCATION_KEY;
	}

	cout << fileAsString << endl;



	ifstream mapFileIn = ifstream("level1.map", ios::binary);

	string line;
	while (mapFileIn.good())
	{
		getline(mapFileIn, line);
		cout << line << endl;
	}

	mapFileIn.close();
}