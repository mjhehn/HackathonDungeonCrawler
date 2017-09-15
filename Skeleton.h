/*
Matt Hehn
5/11/14
Final Project Spring 2014 CSC 161

Skeleton warrior monster class
*/

#pragma once
#include "Monster.h"
#include "Warrior.h"

/*********************
Skeleton warrior is the generateable
warrior based monster class, with function to define individual AI behavior
**********************/
class SkeletonWarrior :
	public Warrior, public Monster
{
public:
	SkeletonWarrior(int level);
	~SkeletonWarrior();
};

