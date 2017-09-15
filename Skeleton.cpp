/*
Matt Hehn
5/11/14
Final Project Spring 2014 CSC 161

Skeleton warrior monster class
*/
#include "Skeleton.h"


SkeletonWarrior:: SkeletonWarrior(int level)
{
	name = "Skeleton";
	HP = 50 + (level*.8);
	AP = 25 + (level*.7);
	setStr(11 + (level*.6));
	setDef(11 + (level*.6));
	setAcc(9 + (level*.6));
	setLuck(15 + (level*.6));
	speed = .9;
	expGain = 20 * (level*.9);
	goldLooted = 5;
}


SkeletonWarrior::~SkeletonWarrior()
{
}

