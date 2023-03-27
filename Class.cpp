#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Class.h"

using namespace std;

Building::Building(Player pPlayer)
{
	player = pPlayer;
}

void Building::emptyRoom(Room *room)
{
	cout << "\n\nAs you enter the room the floor boards creak with your foot steps.\n";
	cout << "You look around and see piles of clothes in one corner but nothing else\n";
	cout << "of interest in this room.\n";
	cout << "Please type 'Move' in order to move to the next room.\n";
	string actions[] = { "Move to another room.\n\n" };
	while (true)
	{
		actionSequence(1 , actions);
		string input;
		cin >> input;
		if (input == "Move")
		{
			return;
		}
		else
		{
			cout << "Please try again.\n";
		}
	}
}
void Building::actionSequence(int numActions, string actions[])
{
	cout << "As you look around you see ";
	for (int i; i < numActions; i++)
	{
		cout << actions[i] << " door(s). What would you like to do?\n";
	}
}

void Building::looting(Room *room)
{
	Item item = room->items.front();
	int size = room->items.size();
	player.lootRoom(room);
	room->loot();
	for (int i = 0; i < room->items.size(); i++)
	{
		cout << "You open the chest. A puff of dust blinds you for a moment as you wave your hands to clear\n";
		cout << "the dust. You cough a few times to clear the dust from your lungs. As the dust clears you see\n";
		cout << item.name << "sitting on top of some old clothes.\n";		
	}	
}

void Building::chestRoom(Room *room)
{
	cout << "\n\nAs you enter the room the floor boards creak with your foot steps.\n";
	cout << "You look around and see a chest up against the wall directly infront of you.\n";	
	cout << "Please type 'Move' in order to move to the next room.\n";
	cout << "Or type 'Open' to open the chest.\n";
	string actions[] = { "Move to another room.\n", "Open the chest.\n\n"};
	while (true)
	{
		actionSequence(2, actions);
		string input;
		cin >> input;
		if (input == "Open")
		{
			looting(room);
			return;
		}
		else if (input == "Move")
		{
			return;
		}
		else
		{
			cout << "Please try again.\n";
		}
	}
}

void Building::fighting(Character *enemy)
{
	string actions[] = { "Fight", "Move to another room.\n\n" };
	while (true)
	{
		actionSequence(2, actions);
		string input;
		cin >> input;

		//player actions
		if (input == "Fight")
		{
			int damage = enemy->damageTaken(player.attack);
			cout << "You hit the " << enemy->name << " for " << damage << ".\n";
		}
		else if (input == "Move")
		{
			player.roomChange(player.previousRoom);
			enterRoom(player.currentRoom);
			return;
		}
		else
		{
			cout << "Please try again.\n";
		}
		//Check the enemy is dead
		if (enemy->isDead())
		{ 
			cout << "Your sword sinks into the head of the " << enemy->name << ", it collapses on the floor and doesn't move.\n";
			player.stats(10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0);
			player.currentRoom->clearEnemy();
		}
		//Enemy's move
		int damage = player.damageTaken(enemy->attack);
		cout << enemy->name << "'s attack hits you for " << damage << ".\n";
		cout << "Your health fell to " << player.currentHealth << ".\n";
		if (player.isDead())
		{
			return;
		}		
	}
}

void Building::enemyRoom(Room *room)
{
	Character enemy = room->enemy.front();
	cout << "\n\nAs you enter the room the floor boards creak with your foot steps.\n";
	cout << "You hear a noise coming from the shadows of one corner of the room. As you are watching\n";
	cout << "the area. A " << enemy.name << " standing infront of you.\n";
	cout << "Please type 'Fight' in order to fight the " << enemy.name << ".\n";
	cout << "Please type 'Move' to return to the previous room and regroup.\n";
	string actions[] = { "Fight the " + enemy.name, "Move to another room.\n\n"};
	while (true)
	{
		actionSequence(2, actions);
		string input;
		cin >> input;
		
		while (true)
		{
			if (input == "Fight")
			{
				fighting(&enemy);
				return;
			}
			else if (input == "Move")
			{
				player.roomChange(player.previousRoom);
				enterRoom(player.currentRoom);
				return;
			}
			else
			{
				cout << "Please try again.\n";
			}
		}		
	}
}

void Building::enterRoom(Room* room)
{
	if (room->enemy.size() != 0)
	{
		enemyRoom(room);
	}
	else if (room->items.size() != 0)
	{
		chestRoom(room);
	}
	else
	{
		emptyRoom(room);
	}
}

void Building::movingAround(Room* room)
{
	while (true)
	{
		if (room->position == 0)
		{
			string actions[] = { "Move Down" };
			actionSequence(1, actions);
			string input;
			cin >> input;
			if (input == "Move")
			{
				player.roomChange(&room[1]);
				cout << "\n\nYou notice a door on the south side of the room. Carefully you walk toward the door and open \n";
				cout << "the door entering the next room.\n";
				return;
			}
			else
			{
				cout << "You did not make a correct choice. Please try again.";				
			}
		}
		else if (room->position == 1)
		{
			string actions[] = { "Move Left", "Move Right", "Move Back"};
			actionSequence(3, actions);
			cout << "\nType 'Left', 'Right', or 'Back' to move to the next room.\n";
			string input;
			cin >> input;
			if (input == "Left")
			{
				player.roomChange(&room[2]);
				cout << "\n\nYou notice a door on the west side of the room. Carefully you walk toward the door and open \n";
				cout << "the door entering the next room.\n";
				return;
			}
			else if (input == "Right")
			{
				player.roomChange(&room[3]);
				cout << "\n\nYou notice a door on the east side of the room. Carefully you walk toward the door and open \n";
				cout << "the door entering the next room.\n";
				return;
			}
			else if (input == "Back")
			{
				player.roomChange(&room[0]);
				cout << "\n\nYou decided to go back into the room you just came from thinking you might have left something in there.\n";
				cout << "You walk back into the room you just left.\n";
				return;
			}
			else
			{
				cout << "\nYou did not make a correct choice. Please try again.\n";
			}
		}
		else if (room->position == 2)
		{
			string actions[] = { "Move Right" };
			actionSequence(1, actions);
			cout << "\nPlease type 'Right' to move.\n";
			string input;
			cin >> input;
			if (input == "Right")
			{
				player.roomChange(&room[1]);
				cout << "\n\nYou notice a door on the east side of the room. Carefully you walk toward the door and open \n";
				cout << "the door entering the next room.\n";
				return;
			}
			else
			{
				cout << "\nYou did not make a correct choice. Please try again.\n";
			}
		}
		else if (room->position == 3)
		{
			string actions[] = { "Move Down", "Back"};
			actionSequence(2, actions);
			cout << "\nPlease type 'Down' or 'Back' to move.";
			string input;
			cin >> input;
			if (input == "Down")
			{
				player.roomChange(&room[4]);
				cout << "\n\nYou notice a door on the south side of the room. Carefully you walk toward the door and open \n";
				cout << "the door entering the next room.\n";
				return;
			}
			else if (input == "Back")
			{
				player.roomChange(&room[1]);
				cout << "\nYou decide you might want to check the previous room one more time.";
				return;
			}
			else
			{
				cout << "You did not make a correct choice. Please try again.";
			}
		}
		else if (room->position == 4)
		{
			string actions[] = { "Move Right", "Back" };
			actionSequence(2, actions);
			cout << "\nPlease type 'Right' or 'Back' to move.";
			string input;
			cin >> input;
			if (input == "Right")
			{
				player.roomChange(&room[5]);
				cout << "\n\nYou notice a door on the east side of the room. Carefully you walk toward the door and open \n";
				cout << "the door entering the next room.\n";
				return;
			}
			else if (input == "Back")
			{
				player.roomChange(&room[3]);
				cout << "\nYou decide you might want to check the previous room one more time.";
				return;
			}
			else
			{
				cout << "You did not make a correct choice. Please try again.";
			}

		}
		else if (room->position == 5)
		{
			string actions[] = { "Move Back" };
			actionSequence(1, actions);
			cout << "\nPlease type 'Back' to move.\n";
			string input;
			cin >> input;
			if (input == "Back")
			{
				player.roomChange(&room[4]);
				cout << "\n\nYou notice a door on the west side of the room. Carefully you walk toward the door and open \n";
				cout << "the door entering the next room.\n";
				return;
			}
			else
			{
				cout << "\nYou did not make a correct choice. Please try again.\n";
			}
		}
		else
		{
			cout << "You have not made a correct decision. Please try again.";
		}
	}
}

int Building::endGameLogic()
{
	string actions[] = { "Yes", "No" };
	
	while (true)
	{
		actionSequence(2, actions);
		string input;
		cin >> input;
		if (input == "Yes")
		{
			return 1;
		}
		else if (input == "No")
		{
			return 0;
		}
		else
		{
			cout << "You have entered an incorrect value.";
		}
	}
}

int Building::runBuilding()
{
	cout << "\t\tWelcome to the fun house. Riches are waiting however so is danger.\n\n\n";
	player.currentRoom = &rooms[0];
	player.previousRoom = &rooms[0];
	while (true)
	{
		enterRoom(player.currentRoom);
		if (player.isDead())
		{
			cout << "You have died!\n";
			return endGameLogic();
		}
		else
		{
			if (player.currentRoom->exit)
			{
				if (player.currentRoom->enemy.size() == 0)
				{
					cout << "YOu have conquered the building. Would you like to play again?\n";
					return endGameLogic();
				}
			}
		}
		movingAround(player.currentRoom);
	}
}

Character::Character(string Name, int Strength, int Dexterity, int Constitution, int Agility, int Perception, int Endurance, int Intelligence, int Luck, int Attack, int Defense, int CurrentHealth, int MaxHealth, int Stamina)
{
	name = Name; //sets the name of the character
	strength = Strength; //sets the strength of the character
	dexterity = Dexterity; //sets the dexterity of the character
	constitution = Constitution; //sets the constitution of the character
	agility = Agility; //sets the agility of the character
	perception = Perception; //sets the perception of the character
	endurance = Endurance; //sets the endurance of the character
	intelligence = Intelligence; //sets the intelligence of the character
	luck = Luck; //sets the luck of the character
	attack = Attack;
	defense = Defense;
	currentHealth = CurrentHealth;
	maxHealth = MaxHealth;
	stamina = Stamina;

	//set the stats with values
	srand(static_cast<unsigned int>(time(0))); //random number generator to seed the time of the program
	strength = rand() % 100 + 1; //gets a number from 1 - 100 and sets it for the value of strength.
	dexterity = rand() % 100 + 1; //gets a number from 1 - 100 and sets it for the value of dexterity.
	constitution = rand() % 100 + 1; //gets a number from 1 - 100 and sets it for the value of constitution.
	agility = rand() % 100 + 1; //gets a number from 1 - 100 and sets it for the value of agility.
	perception = rand() % 100 + 1; //gets a number from 1 - 100 and sets it for the value of perception.
	endurance = rand() % 100 + 1; //gets a number from 1 - 100 and sets it for the value of endurance.
	intelligence = rand() % 100 + 1; //gets a number from 1 - 100 and sets it for the value of intelligence.
	luck = rand() % 100 + 1; //gets a number from 1 - 100 and sets it for the value of luck.	
}

int Character::damageTaken(int total)
{
	int damage = total - defense;
	if (damage < 0)
	{
		damage = 0;
	}

	currentHealth -= damage;
	return damage;
}

bool Character::isDead()
{
	return currentHealth <= 0; //checks to see if the character is dead.
}

Item::Item(string Name, int Durability, int Attack, int Defense) //The item constructor
{
	name = Name;
	durability = Durability;
	attack = Attack;
	defense = Defense;
}

Room::Room(int Position, bool Exit, vector<Item> Items, vector<Character> Enemy)
{
	position = Position;
	exit = Exit;
	items = Items;
	enemy = Enemy;
}

void Room::loot()
{
	items.clear(); //clears the items found int the rooms
}

void Room::clearEnemy()
{
	enemy.clear(); //clears the enemies that were defeated in the current room.
}

Player::Player(string Name, int Strength, int Dexterity, int Constitution, int Agility, int Perception, int Endurance, int Intelligence, int Luck, int Attack, int Defense, int CurrentHealth, int MaxHealth, int Stamina) : Character(Name, Strength, Dexterity, Constitution, Agility, Perception, Endurance, Intelligence, Luck, Attack, Defense, CurrentHealth, MaxHealth, Stamina)
{
	Item sword = Item("Short Sword", 100, 9, 3);
	addItem(sword);

	maxHealth = (Strength + Dexterity + Endurance) - Agility;
	currentHealth = maxHealth;
	stamina = (Constitution + Agility + Endurance) - Dexterity;
	cout << "Your name is: " << Name << "\n";
	cout << "Your Health is: " << currentHealth << "\n";
	cout << "Your Stamina is: " << Stamina << "\n";
	cout << "Strength: " << Strength << "\n";
	cout << "Dexterity: " << Dexterity << "\n";
	cout << "Constitution: " << Constitution << "\n";
	cout << "Agility: " << Agility << "\n";
	cout << "Perception: " << Perception << "\n";
	cout << "Endurance: " << Endurance << "\n";
	cout << "Intelligence: " << Intelligence << "\n";
	cout << "Luck: " << Luck << "\n";
}

void Player::addItem(Item item)
{
	inventory.push_back(item);	
}

void Player::stats(int, int, int, int, int, int, int, int, int, int, int, int, int)
{

}

void Player::lootRoom(Room* room)
{
	vector<Item> items = room->items;
	for (int i = 0; i < items.size(); i++)
	{
		addItem(items[i]);
	}
}

void Player::roomChange(Room* newRoom)
{
	previousRoom = currentRoom; //sets the previous room to the current room to show the player moved
	currentRoom = newRoom; //sets the current room to the new room to show the player moved.

}