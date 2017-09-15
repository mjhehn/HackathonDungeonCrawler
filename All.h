/*
Matt Hehn
5/11/14
Final Project Spring 2014 CSC 161

has #include's for all the headers
*/

#pragma once
//Libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <Tchar.h>
#include <stdlib.h>
#include <fstream>



//Base Character
#include "Character.h"


//"Engine"  Code
#include "Room.h"
#include "CombatGUI.h"

//Playable classes
#include "Warrior.h"
#include "Wizard.h"
#include "Rogue.h"

//Enemy varieties
#include "Monster.h"
#include "Skeleton.h"	//Based on Warrior
#include "Zubat.h"		//Based on Wizard
#include "Goblin.h"		//based on rogue

//Need more than one, but currently hardcoded one
//#include "Boss.h"
#include "Vicki.h"