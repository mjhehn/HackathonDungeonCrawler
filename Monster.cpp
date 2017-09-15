/*
Matt Hehn
5/11/14
Final Project Spring 2014 CSC 161

holds generic monster data members and functions
*/
#include "Monster.h"


Monster::Monster()
{
}


Monster::~Monster()
{
}

/*get exp and gold -> not implemented in overall code*/
int Monster::getExp()
{
	return expGain;
}

int Monster::getGold()
{
	return goldLooted;
}