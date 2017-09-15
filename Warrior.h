/*
Matt Hehn
5/11/14
Final Project Spring 2014 CSC 161

Playable warrior class
*/

#pragma once
#include "Character.h"

/****************
Warrior is a basic player class with average stats overall
and simplistic general use skills.
******************/
class Warrior :
	public Character
{
public:
	Warrior();
	~Warrior();	
	bool checkItem(Item input);		//check for if it's a warrior approved item
	int strongSlash();		//attack ability
	int ironSkin();			//defense ability
	int clearSight();		//accuracy ability
	void specialAbilities(int input);	//call special abilities
};

