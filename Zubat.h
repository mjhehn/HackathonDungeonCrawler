/*
Matt Hehn
5/11/14
Final Project Spring 2014 CSC 161

zubat wizard monster class
*/

#pragma once
#include "Monster.h"
#include "Wizard.h"

/****************
Zubat is the wizard based
generateable monster.
***************/
class Zubat :
	public Wizard,	public Monster
{
public:
	Zubat(int level);
	~Zubat();
};

