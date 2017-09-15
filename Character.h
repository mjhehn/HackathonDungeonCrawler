/*
Matt Hehn
5/11/14
Final Project Spring 2014 CSC 161

holds generic character datamembers and functions
*/

#pragma once
#include "Item.h"
#include "InventoryList.h"
#include <iomanip>

using namespace std;

const int MAPWIDTH = 100;	//temp max values
const int MAPHEIGHT= 100;	//temp max values
const int MAXSPECIALS = 3;	//max number of specials a class can have


/*****************
The basic character class, upon which all players are based.
This class has the basic stats used, as well as a polymorphic virtual combat function
to allow for child classes to have their respective combat skills called.
*******************/
class Character
{
public:
	double MAXHP;	//max hp possible for class
	double HP;		//hitpoints

	double MAXAP;	//max ap possible for class
	double AP;		//ability points 
	
	double speed;	//movement speed
	
	int level;		//to setup scaling for future iteration


	string specialNames[MAXSPECIALS];		//names of each classes specials

	virtual void specialAbilities(int choice);	//virtual version of the special abilities function

	Character(void);
	~Character(void);

	/*STR setters and getters*/
	void setStr(int strNum);
	int getStr();

	//accuracy setters and getters
	void setAcc(int accNum);
	int getAcc();

	//defense setters and getters
	void setDef(double defNum);
	double getDef();

	/*set the gain/loss of def for a combat function*/
	void setGainDef(double gainDef);
	void setLossDef(double lossDef);

	//luck setters and getters
	void setLuck(int luckNum);
	int getLuck();

	//race setters and getters
	void setRace(string inputRace);
	string getRace();

	//class setters and getters
	void setClass(string inputType);
	string getClass();

	//name setters/getters
	void setName(string inputName);
	string getName();

	//won getter/setter
	void setWon(bool input);
	bool getWon();

	//add an item to linked list in alphabetical order
	void addItem(Item currentItem);

	/*return the head of the inventory list*/
	InventoryList* getHead();

	/*uses a potion item designated by num*/
	void usePotion(int num);

protected:
	string name;		//name chosen by player
	string className;	//warrior, mage, etc.
	string race;		//fantasy race: Goblin, human, elf, etc. Typed in by player


	int str;		//strength
	int acc;		//accuracy
	double def;		//defense
	int luck;		//luck for escapes/encounters
	
	bool won;		//defeated boss/ended level

	InventoryList *head;		//front of the inventory list

	/*************
	when buff has expired, revert stat to previous value
	Parameters: length of buff, current stat value, size of buff
	***************/
	void decrementTurnBuff(int &num, char stat, int &buffSize);

private:
	/*using an item(potion) in combat*/
	void useItem(Item* input);
};

