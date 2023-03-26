#pragma once
#include <iostream>
#include <string>

using namespace std;

class Character
{
public:
	Character(const string& name = "");
	virtual ~Character();

protected:
	string c_Name; 
	int c_Strength; 
	int c_Dexterity; 
	int c_Constitution; 
	int c_Agility; 
	int c_Perception; 
	int c_Endurance; 
	int c_Intelligence; 
	int c_Luck;
};

class Enemy : public Character
{
private:
	int health;
	int stamina;
public:
	Enemy(string Name, int Strength, int Dexterity, int Constitution, int Agility, int Perception, int Endurance, int Intelligence, int Luck, int Health, int Stamina);

};

class Player : public Character
{
private:
	int health;
	int stamina;
public:
	Player(string Name, int Strength, int Dexterity, int Constitution, int Agility, int Perception, int Endurance, int Intelligence, int Luck, int Health, int Stamina);
};