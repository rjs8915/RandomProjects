#pragma once

#include "Person.h"

class SmartPersonPointer
{
public:
	SmartPersonPointer(Person* _ptr = NULL);
	~SmartPersonPointer();

	Person& operator *();
	Person* operator ->();

private:
	Person* ptr;
};

