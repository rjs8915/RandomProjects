#pragma once
#include <string>
class Animal
{
public:
	Animal(std::string _name, std::string _species);
	~Animal();

	void PrintInfo();

private:
	std::string name;
	std::string species;
};

