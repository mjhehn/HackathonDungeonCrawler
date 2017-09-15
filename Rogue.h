/*
Matt Hehn
5/11/14
Final Project Spring 2014 CSC 161

Playable rogue class
*/

#pragma once
#include "Character.h"


/*******************
The rogue class is another player class
which has its respective special abilities, 
class specific constructor features, a checker
for ensuring proper item equips (when equippable items are implemented)
and an unimplemented poison skill.
********************/
class Rogue :
	public Character
{
public:
	Rogue();
	~Rogue();

	bool checkItem(Item input);		//check that it's a rogue-specific item

	int backStab();		//ability 1 -> increases strength

	int darkShroud();	//ability 2 -> increases accuracy

	//int poisonBlade();	//unimplemented. Apply poison counter to enemy

	void specialAbilities(int input);	//call special abilities.
};

