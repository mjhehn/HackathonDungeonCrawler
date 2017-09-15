/*
Matt Hehn
5/11/14
Final Project Spring 2014 CSC 161

*/

#pragma once
#include "Monster.h"
#include "Warrior.h"

/**************
Boss monster. Has warrior base stats, but has unique special abilities function.
**************/
class Vicki :
	public Monster, public Warrior
{
public:

	Vicki();
	~Vicki();
	void specialAbilities(int input); //selects the ability to be used. 
	//Overloads the base case version and ignores the input put in, using its own "AI"
};

