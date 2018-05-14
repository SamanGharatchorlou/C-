// TestTwo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "warrior.h"

#include <iostream>
#include <string>

//comment

int main()
{
	//name, str, hp, block
	Warrior saman("Saman", 10, 100, 50);
	Warrior ross("Ross", 4, 12, 200);

	std::cout << saman.GetName() << " has " << saman.GetHp() << "hp\n";
	std::cout << ross.GetName() << " has " << ross.GetHp() << "hp\n";

	Battle(saman, ross);

	std::cout << saman.GetName() << " has " << saman.GetHp() << "hp\n";
	std::cout << ross.GetName() << " has " << ross.GetHp() << "hp\n";

    return 0;
}

