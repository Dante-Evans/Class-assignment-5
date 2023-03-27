#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Class.h"

using namespace std;

int main()
{	
	cout << "Please enter your desired name.\n\n";
	string name;
	cin >> name;
	Player player = Player(name, 20, 10, 10, 10, 10, 10, 10, 10, 25, 25, 250, 250, 10); //Actually sets up the player character

	//Time to set up the rooms...... yes all 6 of them. :)
	Room firstRoom = Room(0, false, vector<Item>(), vector<Character>()); //Sets up the first room to be empty.
	
	Item sword = Item("Short Sword", 100, 25, 3); //initializes the first item the player gets.
	vector<Item> secondRoomItems; //setups up the vector for the room.
	secondRoomItems.push_back(sword); //puts the item in that vector.
	Room secondRoom = Room(1, false, secondRoomItems, vector<Character>()); //Finally setting up the second room.

	Character spider = Character("Spider", 5, 1, 1, 1, 1, 1, 1, 1, 10, 15, 50, 50, 5); //Yay everyone loves spiders right? This is the first enemy the player will encounter.
	vector<Character> thirdRoomEnemies; //Create the character vector for this room.
	thirdRoomEnemies.push_back(spider); //put the character in the vector.
	Room thirdRoom = Room(2, false, vector<Item>(), thirdRoomEnemies); //Well thats three rooms down

	Item shield = Item("Wooden Shield", 50, 0, 25); //makes the second item for the player.
	vector<Item> fourthRoomItems; //setups up the vector for the items.
	fourthRoomItems.push_back(shield); //puts the item in the vector.
	Room fourthRoom = Room(3, false, fourthRoomItems, vector<Character>()); //And Finally initialize the room

	Room fifthRoom = Room(4, false, vector<Item>(), vector<Character>()); //Can't have enemies or items in every room right?

	Character boss = Character("Orge", 25, 5, 5, 5, 5, 5, 5, 5, 30, 25, 250, 250, 10); //This is the big bad boss
	vector<Character> sixthRoomEnemy; //enemy vector
	sixthRoomEnemy.push_back(boss); //puts into vector
	Room sixthRoom = Room(5, true, vector<Item>(), sixthRoomEnemy); //sets up the room

	Building building = Building(player);
	building.rooms[0] = firstRoom;
	building.rooms[1] = secondRoom;
	building.rooms[2] = thirdRoom;
	building.rooms[3] = fourthRoom;
	building.rooms[4] = fifthRoom;
	building.rooms[5] = sixthRoom;

	while (true)
	{
		int result = building.runBuilding();
		if (result == 0)
		{
			cout << "\nYou have failed to clear the building for your master.\n";
			cout << "Your master will not be pleased.\n";
			return false;
		}
	}
}