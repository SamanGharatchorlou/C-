#include "stdafx.h"
#include "warrior.h"

#include <iostream>
#include <string>

// ------------------- Warrior ---------------------
Warrior::Warrior()
{
	m_name = "";
	m_strength = 0;
	m_health = 0;
	m_armour = 0;
}

Warrior::Warrior(std::string name, int strength, int health, int armour)
{
	m_name = name;
	m_strength = strength;
	m_health = health;
	m_armour = armour;
}


//basic attack - reduced by warrior armour
void Warrior::BasicAttack(Warrior& warrior) {

	int damage = (rand() % m_strength) - warrior.GetArmour();

	if (damage <= 0) {
		damage = 0;
		std::cout << m_name << "s physical attack was too weak to get through " <<
			warrior.GetName() << "'s armour at " << warrior.GetArmour() << std::endl;
		return;
	}

	warrior.ReduceHp(damage);

	std::cout << m_name << " attacked " << warrior.GetName() <<
		" and dealt " << damage << " damage\n";
}

void Warrior::ReduceHp(int damage) {

	if (m_health - damage < 0)
		m_health = 0;
	else
		m_health = m_health - damage;
}

void Warrior::PrintHp() {
	std::cout << GetName() << " has " << GetHp() << " left\n";
}

// ------------------- Bruiser ---------------------
Bruiser::Bruiser(std::string name, int strength, int health, int armour, float blockchance) : Warrior(name, strength, health, armour) {
	m_name = name;
	m_strength = strength;
	m_health = health;
	m_armour = armour;
	m_blockChance = blockchance;
}

void Bruiser::Battle(Warrior& thisBruiser, Warrior& otherWarrior) {

	Attack(otherWarrior);

	if (otherWarrior.GetHp() > 0)
		otherWarrior.Battle(otherWarrior, thisBruiser);
	else
		std::cout << otherWarrior.GetName() << " died!\n";
}


//currently bruisers only have a basic attack
void Bruiser::Attack(Warrior& warrior) {
	BasicAttack(warrior);
}


// ------------------- Mage ---------------------

//spell attack ignors warrior armour
Mage::Mage(std::string name, int strength, int health, int armour, int spellPower) : Warrior(name, strength, health, armour) {
	m_name = name;
	m_strength = strength;
	m_health = health;
	m_armour = armour;
	m_spellPower = spellPower;
}


void Mage::Battle(Warrior& thisMage, Warrior& otherWarrior) {

	Attack(otherWarrior);

	if (otherWarrior.GetHp() > 0)
		otherWarrior.Battle(otherWarrior, thisMage);
	else
		std::cout << otherWarrior.GetName() << " died!\n";
}

//50/50 chance to call basic or spell attack
void Mage::Attack(Warrior& warrior) {

	if (rand() % 2)
		BasicAttack(warrior);
	else
		SpellAttack(warrior);

}

void Mage::SpellAttack(Warrior& warrior) {

	//min damage = 1
	int damage = (rand() % (m_spellPower - 1)) + 1;

	warrior.ReduceHp(damage);

	std::cout << m_name << " attacked " << warrior.GetName() <<
		" with a spell and dealt " << damage << " damage\n";
}