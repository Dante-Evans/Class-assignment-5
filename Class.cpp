#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Class.h"

using namespace std;

Character::Character(const string& name) : c_Name(name)
{
	
	strength = Strength; //sets the strength of the character
	dexterity = Dexterity; //sets the dexterity of the character
	constitution = Constitution; //sets the constitution of the character
	agility = Agility; //sets the agility of the character
	perception = Perception; //sets the perception of the character
	endurance = Endurance; //sets the endurance of the character
	intelligence = Intelligence; //sets the intelligence of the character
	luck = Luck; //sets the luck of the character

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

Enemy::Enemy(string Name, int Strength, int Dexterity, int Constitution, int Agility, int Perception, int Endurance, int Intelligence, int Luck, int Health, int Stamina) : Character(Name, Strength, Dexterity, Constitution, Agility, Perception, Endurance, Intelligence, Luck)
{
	Character::Character(Name, Strength, Dexterity, Constitution, Agility, Perception, Endurance, Intelligence, Luck);

	health = Health;
	stamina = Stamina;

	health = (Strength + Dexterity + Endurance) - Agility;
	stamina = (Constitution + Agility + Endurance) - Dexterity;
	cout << "Enemy's name is: " << Name << "\n";
	cout << "Enemy's Health is: " << Health << "\n";
	cout << "Enemy's Stamina is: " << Stamina << "\n";
	cout << "Strength: " << Strength << "\n";
	cout << "Dexterity: " << Dexterity << "\n";
	cout << "Constitution: " << Constitution << "\n";
	cout << "Agility: " << Agility << "\n";
	cout << "Perception: " << Perception << "\n";
	cout << "Endurance: " << Endurance << "\n";
	cout << "Intelligence: " << Intelligence << "\n";
	cout << "Luck: " << Luck << "\n";
}

Player::Player(string Name, int Strength, int Dexterity, int Constitution, int Agility, int Perception, int Endurance, int Intelligence, int Luck, int Health, int Stamina) : Character(Name, Strength, Dexterity, Constitution, Agility, Perception, Endurance, Intelligence, Luck)
{
	Character::Character(Name, Strength, Dexterity, Constitution, Agility, Perception, Endurance, Intelligence, Luck);

	health = Health;
	stamina = Stamina;

	health = (Strength + Dexterity + Endurance) - Agility;
	stamina = (Constitution + Agility + Endurance) - Dexterity;
	cout << "Your name is: " << Name << "\n";
	cout << "Your Health is: " << Health << "\n";
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