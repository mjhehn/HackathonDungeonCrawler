/*
Matt Hehn
5/11/14
Final Project Spring 2014 CSC 161
*/

#include "Goblin.h"


Goblin::Goblin(int level)		//setup goblin, and setup to do basic scaling once levels are integrated
{
	name = "Goblin";
	HP = 40 + (level*.7);
	AP = 16 + (level*.5);
	setStr(8 + (level*.6));
	setDef(14 + (level*.6));
	setAcc(10 + (level*.6));
	setLuck(9 + (level*.6));
	speed = 1.0;
	expGain = 18 * (level*.8);
	goldLooted = 12 * (level*.3);
}


Goblin::~Goblin()
{
}