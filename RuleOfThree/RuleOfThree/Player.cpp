#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(int item1, int item2, int item3)
{
	cout << "Constructor Called!" << endl;

	inventorySize = 3;
	inventory = new int[inventorySize] {item1, item2, item3};
}

Player::Player(const Player& other)
{
	cout << "Copy Constructor Called" << endl;
	inventorySize = other.inventorySize;
	inventory = new int[inventorySize];

	copy(other.inventory, other.inventory + other.inventorySize, inventory);
}

Player& Player::operator=(const Player& other)
{
	cout << "Copy Assignment Called" << endl;

	if (this == &other) 
	{
		return *this;
	}

	if (inventory != nullptr)
	{
		delete[] inventory;
		inventory = nullptr;
		inventorySize = 0;
	}

	inventorySize = other.inventorySize;
	inventory = new int[inventorySize];

	copy(other.inventory, other.inventory + other.inventorySize, inventory);

	return *this;
}

Player::~Player()
{
	delete[] inventory;
	inventory = nullptr;
	inventorySize = 0;
}

void Player::PrintInventory()
{
	for (int i = 0; i < inventorySize; i++)
	{
		cout << inventory[i] << " ";
	}
	cout << "which is stored at: " << inventory << endl;
}
