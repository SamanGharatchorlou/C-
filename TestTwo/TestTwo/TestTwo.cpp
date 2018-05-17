// TestTwo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "warrior.h"

#include <iostream>
#include <string>
#include <ctime>

//comment two

int main()
{
	srand(time(NULL));

	//name, str, hp, block
	Bruiser saman("Saman", 25, 150, 3, 0.2);
	Bruiser ross("Ross", 16, 300, 10, 0.3);
	Mage adrian("Adrian", 8, 100, 0, 50);

	saman.PrintHp();

	adrian.Battle(adrian, saman);

    return 0;
}

