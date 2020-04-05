#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>

#include "Player.h"

using namespace std;

void begoneFakeMemoryLeaks()
{
	Player* p1 = new Player(1, 2, 3);
	cout << "Creating p1 with this inventory: ";
	p1->PrintInventory();

	cout << "Creating p2 by using new Player(*p1);" << endl;
	Player* p2 = new Player(*p1);
	cout << endl;

	cout << "Changing p1's inventory" << endl;
	p1->inventory[2] = 5;

	cout << "p1's inventory: ";
	p1->PrintInventory();

	cout << "p2's inventory: ";
	p2->PrintInventory();

	Player p3 = *p1;
	cout << "p3's inventory: ";
	p3.PrintInventory();

	cout << "Setting p3 = *p2" << endl;
	p3 = *p2;

	cout << "p3's inventory: ";
	p3.PrintInventory();
	cout << endl;

	cout << "Changing p3's inventory" << endl;
	p3.inventory[2] = 7;
	
	cout << "p2's inventory: ";
	p2->PrintInventory();

	cout << "p3's inventory: ";
	p3.PrintInventory();
	cout << endl;


	delete p1;
	p1 = nullptr;

	delete p2;
	p2 = nullptr;
}

int main()
{
	begoneFakeMemoryLeaks();
	_CrtDumpMemoryLeaks();
}