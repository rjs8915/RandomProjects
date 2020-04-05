#pragma once
#include <string>

class Person
{
public:
	Person();
	Person(std::string _name);

	~Person();

	void PrintName();

private:
	std::string name;
};

