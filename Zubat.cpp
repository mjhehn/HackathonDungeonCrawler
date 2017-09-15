/*
Final Project Spring 2014 CSC 161

zubat wizard monster class
*/
#include "Zubat.h"


Zubat::Zubat(int level)
{
	name = "Zubat";
	HP = 30 + (level*.6);
	AP = 20 + (level*.6);
	setStr(10);
	setDef(8 + (level*.6));
	setAcc(14 + (level*.6));
	setLuck(5 + (level*.6));
	speed = 1.2;
	expGain = 15 * (level*.6);
	goldLooted = 10 * (level*.4);
}


Zubat::~Zubat()
{
}
