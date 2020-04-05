#pragma once
class Player
{
public:
	Player(int item1, int item2, int item3);

	Player(const Player& other); //Copy Constructor
	Player& operator=(const Player& other); //Copy Assignment Operator
	~Player(); //Destructor

	void PrintInventory();

	int* inventory;
	int inventorySize;
};

