/*
Matt Hehn
5/11/14
Final Project Spring 2014 CSC 161

goblin rogue monster class
*/

#pragma once
#include "Monster.h"
#include "Rogue.h"


/****************
The goblin class is a scaleable monster/NPC type which
is based on the rogue player class, and has its associated specials.
****************/
class Goblin :			
	public Monster, public Rogue
{
public:
	Goblin(int level);
	~Goblin();
};

