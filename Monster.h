/*
Matt Hehn
5/11/14
Final Project Spring 2014 CSC 161

holds generic monster data members and functions
*/


#pragma once

/*
The monster class is to give all of its children unified 
functions for returning the gold or experience their defeat gives.

However, allocation of exp, gold, shopping/equipping, and levelling up are not currently implemented
in the game engine as a whole, so this is largely for future expansion.*/
class Monster
	
{
public:
	Monster();
	~Monster();

	int getExp();			//return exp gained by defeating
	int getGold();			//return gold dropped by monster

protected:
	int expGain;			//experience gained by killing the monster
	int goldLooted;			//gold gained by killing the monster

	
};

