#include "stdafx.h"
#include "warrior.h"

#include <iostream>
#include <string>

Warrior::Warrior()
{
	this->name = "";
	this->strength = 0;
	this->health = 0;
	this->block = 0;
}

Warrior::Warrior(std::string name, int strength, int health, float block)
{
	this->name = name;
	this->strength = strength;
	this->health = health;
	this->block = block;
}

Warrior::~Warrior()
{
}


void Attack(Warrior& warrior1, Warrior& warrior2) {

	warrior2.SetHp(warrior2.GetHp() - warrior1.GetStr());

	std::cout << warrior1.GetName() << " attacked " << warrior2.GetName() << "\n";

	PrintHp(warrior2);
}


void Battle(Warrior& warrior1, Warrior& warrior2) {

	Attack(warrior1, warrior2);


	if (warrior2.GetHp() > 0)
		Battle(warrior2, warrior1);
	else
		std::cout << warrior2.GetName() << " died!\n";

}

void PrintHp(Warrior& warrior) {

	std::cout << warrior.GetName() << " has " << warrior.GetHp() << "\n";

}
