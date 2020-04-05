#include "Person.h"
#include <iostream>

Person::Person()
{
	name = "Unknown";
}

Person::Person(std::string _name)
{
	name = _name;
}

Person::~Person()
{
	std::cout << "Person Destructor for " << name << std::endl;
}

void Person::PrintName()
{
	std::cout << name << std::endl;
}
