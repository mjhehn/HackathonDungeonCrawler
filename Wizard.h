/*
Matt Hehn
5/11/14
Final Project Spring 2014 CSC 161

Playable wizard class
*/

#pragma once
#include "Character.h"

/****************
Wizard is a basic player class with lesser stats
and general use skills.
******************/
class Wizard :
	public Character
{
public:
	Wizard();
	~Wizard();

	bool checkItem(Item input);//check if it's a wizard useable item

	//Apply one turn str buff for an attack
	int fireball();

	//3 turn defense buff
	int stoneWall();

	//3 turn acc buff
	int phaseShift();

	void specialAbilities(int input);		//choose special ability to apply
};

