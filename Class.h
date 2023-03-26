#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Building
{
public:
	Player player;
	Room rooms[6];
	Building(Player);
	int runBuilding(); //gives me the ability to break out of the game loop incase the player loses.
	void enterRoom(Room*); //function to check for entering a room
	void emptyRoom(Room*); //function to check if the room is empty
	void chestRoom(Room*); //function to check to see if there is a chest to loot
	void enemyRoom(Room*); //function to check to see if there is an enemy in the room
	void looting(Room*); //function to loot the chest 
	void fighting(Character*); //function to fight the enemy	
	void movingAround(Room*); //function for moving around
	void actionSequence(int, string[]); //This will print the actions that are preformed byt both the player and the enemy
	int endGameLogic(); //Logic for the end game so there is an end and not getting stuck in an infinite loop... although.... no that would be cruel nevermind.
};

class Character
{
public:
	string name; //I don't believe I need to comment each of these.
	int strength;
	int dexterity;
	int constitution;
	int agility;
	int perception;
	int endurance;
	int intelligence;
	int luck;
	int attack;
	int defense;
	int currentHealth;
	int maxHealth;
	int stamina;
	Character(string, int, int, int, int, int, int, int, int, int, int, int, int, int);
	int damageTaken(int);
	bool isDead();	
};


class Room
{
public:
	int position;
	bool exit;
	vector<Item> items;
	vector<Character> enemy;
	Room(int=0, bool=false, vector<Item> = vector<Item>(), vector<Character> = vector<Character>());
	void loot();
	void clearEnemy();
};

class Player : public Character
{
public:
	Player(string=" ", int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0);
	void stats(int, int, int, int, int, int, int, int, int, int, int, int, int); //increases the stat for each enemy defeated.
	void lootRoom(Room *); //Pointer for a room the character is in.
	void roomChange(Room *); //Changes the room the player is in.
	void addItem(Item); //adds an item in the player's inventory.
	Room *currentRoom; //sets the current room the player is in by using a pointer for the room.
	Room *previousRoom; //sets the previous room the player just left by using a pointer for the room.
	vector<Item> inventory; //creates a vector for the items in the players inventory.
};

class Item
{
public:
	string name;
	int durability;
	int attack;
	int defense;

	Item(string, int, int, int);
};
