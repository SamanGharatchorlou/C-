#include <iostream>

class Warrior
{
private:
	std::string name;
	int strength;
	int health;
	float block;

public:
	Warrior();
	Warrior(std::string name, int str, int hp, float block);
	~Warrior();

	//name
	std::string GetName() {
		return this->name;
	}
	void SetName(std::string name) {
		this->name = name;
	}

	//health
	int GetHp() {
		return (this->health < 0) ? 0 : this->health;
	}
	void SetHp(int health) {
		this->health = health;
	}

	//strength
	int GetStr() {
		return this->strength;
	}

	//print health


};

void Attack(Warrior& warrior1, Warrior& warrior2);

void Battle(Warrior& warrior1, Warrior& warrior2);

void PrintHp(Warrior& warrior);
