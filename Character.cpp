/*
Matt Hehn
5/11/14
Final Project Spring 2014 CSC 161

holds generic character datamembers and functions
*/
#include "Character.h"

Character::Character(void)
{
	Item HPpot, APpot;		//give all players two health and two ability potions
	HPpot.setName("Health Potion");
	HPpot.setQuant(2);
	HPpot.setType("Potion");
	HPpot.setSubtype("Health");
	HPpot.setValue(25);

	APpot.setName("Ability Potion");
	APpot.setQuant(2);
	APpot.setType("Potion");
	APpot.setSubtype("Ability");
	APpot.setValue(25);

	addItem(HPpot);
	addItem(APpot);

	won = false;
}


Character::~Character(void)
{
}

/***********
Placeholder that should be overwritten by child classes.
************/
void Character::specialAbilities(int choice)
{
	cout << "Shouldn't happen. virtual character function.";
}

/***********
use the item(potion) passed into the function
parameters: pointer to item to use
returns: n/a
************/
void Character::useItem(Item* input)
{
	if (input->getType() == "Potion")
	{
		if (input->getSubtype() == "Health")
		{
			HP += 25;
			if (HP > MAXHP)
			{
				HP = MAXHP;
			}
			else{ ; }

			input->setQuant(input->getQuant() - 1);
			if (input->getQuant() == 0)		//remove potion type if out of potions
			{
				cout << "You used the last of the " << input->getName() << "s\n";
				head->deleteItem(*input);
			}
			else
			{
				cout << input->getQuant() << " " << input->getName() << " left.\n";
			}
		}
		else if (input->getSubtype() == "Ability")
		{
			AP += 20;
			if (AP > MAXAP)
			{
				AP = MAXAP;
			}
			else{ ; }
			input->setQuant(input->getQuant() - 1);
			if (input->getQuant() == 0)			//remove potions if used up
			{
				cout << "You used the last of the " << input->getName() << "s\n";
				head->deleteItem(*input);
			}
			else
			{
				cout << input->getQuant() << " " << input->getName() << " left.\n";
			}
		}
	}
	else
	{
		cout << "You can't use this item right now.\n";
	}
}

/**********************
Setter and getters
*********************/

void Character:: setStr(int strNum)
{
	str = strNum;
}
int Character::getStr()
{
	return str;
}

void Character::setAcc(int accNum)
{
	acc = accNum;
}
int Character::getAcc()
{
	return acc;
}

void Character::setDef(double defNum)
{
	def = defNum;
}
double Character::getDef()
{
	return def;
}

/* modify base defense by an amount */
void Character::setLossDef(double lossDef)
{
	def = def - (def / lossDef);
}
void Character::setGainDef(double gainDef)
{
	def = (def * gainDef) + def;
}


void Character::setLuck(int luckNum)
{
	luck = luckNum;
}
int Character::getLuck()
{
	return luck;
}

void Character::setRace(string inputRace)
{
	race = inputRace;
}
string Character::getRace()
{
	return race;
}

void Character::setClass(string inputType)
{
	className = inputType;
}
string Character::getClass()
{
	return className;
}

void Character::setName(string inputName)
{
	name = inputName;
}
string Character::getName()
{
	return name;
}

bool Character:: getWon()
{
	return won;
}
void Character:: setWon(bool input)
{
	won = input;
}
InventoryList* Character::getHead()
{
	InventoryList * current;
	current = head;
	return current;
}
/********************
END SETTERS/GETTERS
*********************/


/*****************
add item in parameter to the weight linklist
parameter: item to be added
returns: n/a
****************/
void Character::addItem(Item currentItem)
{
	head = head->addFront(currentItem);
}

/***************
Decrements or reverts the buffs applied to a stat
parameters: the length of time the buff is working, the stat buffed, and the size of the buff
returns: n/a
*****************/
void Character::decrementTurnBuff(int &num, char stat, int &buffSize)
{
	if (num > 0)		//if buff isn't 0, decrement it
	{
		num--;
	}
	else
	{
		switch (stat)
		{
		case 'S':
			str = str - buffSize;
			break;
		case 'D':
			def = def - buffSize;
			break;
		case 'A':
			acc = acc - buffSize;
			break;
		case 'L':
			luck = luck - buffSize;
			break;
		default:
			;//cout << "Invalid stat\n";
		}
		buffSize = 0;		//return buffsize to 0
	}
	
}

/********************
Takes in number and will enact functions to 
use a potion from the inventory
parameters: the "index" from the combatGui of the item
returns: n/a
*********************/
void Character:: usePotion(int num)
{
	InventoryList* temp;
	temp = nullptr;

	do{
		temp = head->findItem(num);
		if (temp == nullptr)
		{
			cout << "\n\t Invalid item. Try again. \n";
			cin>>num;
		}
		else{ ; }
	} while (temp == nullptr);
	
	useItem(&temp->object);
}