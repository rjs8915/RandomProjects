#include "Animal.h"
#include <iostream>

Animal::Animal(std::string _name, std::string _species)
{
	name = _name;
	species = _species;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor for " << name << std::endl;
}

void Animal::PrintInfo()
{
	std::cout << name << " is a " << species << std::endl;
}
