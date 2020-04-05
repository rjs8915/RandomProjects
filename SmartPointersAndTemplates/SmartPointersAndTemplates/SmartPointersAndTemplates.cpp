#include <iostream>
#include <vector>
#include <memory>

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include "Person.h"
#include "SmartPersonPointer.h"
#include "Animal.h"
#include "SmartPointer.h"

using namespace std;

void begoneFakeMemoryLeaks() 
{
	Person* personPtr = new Person("Cody");
	personPtr->PrintName();

	delete personPtr;
	personPtr = nullptr;

	SmartPersonPointer smartPersonPtr(new Person("Jane"));
	smartPersonPtr->PrintName();

	//SmartPersonPointer smartAnimalPtr(new Animal("Meow", "Cat"));
	SmartPointer<Animal> smartAnimalPtr(new Animal("Meow", "Cat"));
	smartAnimalPtr->PrintInfo();

	SmartPointer<Person> smarterPersonPtr(new Person("Austin"));
	smarterPersonPtr->PrintName();

	SmartPointer<int> smartIntPtr(new int(50));

	unique_ptr<Animal> bestAnimalPtr(new Animal("Meowington", "Cat"));
	bestAnimalPtr->PrintInfo();
}

int main()
{
	begoneFakeMemoryLeaks();

	_CrtDumpMemoryLeaks();
}