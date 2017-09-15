/*
Final Project Spring 2014 CSC 161

generic boss class
*/


#pragma once
#include "Character.h"
#include "Warrior.h"
#include "Monster.h"
class Boss :
	public Warrior, Monster
{
public:
	Boss();
	~Boss();
	
};


