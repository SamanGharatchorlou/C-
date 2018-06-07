#include <iostream>

//base warrior class
class Warrior
{
protected:
	std::string m_name;
	int m_strength;
	int m_health;
	int m_armour;

public:
	Warrior();
	Warrior(std::string name, int str, int hp, int armour);

	//name
	std::string GetName() { return m_name; }
	void SetName(std::string name) { m_name = name; }

	//health
	int GetHp() { return m_health; }
	void SetHp(int health) { m_health = health; }

	//strength
	int GetStr() { return m_strength; }

	//Armour
	int GetArmour() { return m_armour; }
	void SetArmour(int armour) { m_armour = armour; }

	void PrintHp();
	void ReduceHp(int damage);

	virtual void Attack(Warrior& warrior) = 0;
	virtual void BasicAttack(Warrior& warrior);
	virtual void Battle(Warrior& warrior1, Warrior& warrior2) { std::cout << "nope\n"; }
};


class Bruiser : public Warrior
{
public:
	float m_blockChance;

	Bruiser(std::string name, int str, int hp, int armour, float blockChance);

	void Attack(Warrior& warrior) override;
	void Battle(Warrior& thisBruiser, Warrior& warrior) override;
};

class Mage : public Warrior
{
public:
	int m_spellPower;

	Mage(std::string name, int str, int hp, int armour, int spellPower);

	void Attack(Warrior& warrior) override;
	void SpellAttack(Warrior&);

	void Battle(Warrior& thisMage, Warrior& warrior) override;

};


