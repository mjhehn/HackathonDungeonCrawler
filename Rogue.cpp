/*
Matt Hehn
5/11/14
Final Project Spring 2014 CSC 161

rogue class functions
*/

#include "Rogue.h"


Rogue::Rogue()
{
	MAXHP = HP = 60;
	MAXAP = AP = 30;
	className = "Rogue";
	acc = 18;		//high base acc
	str = 11;		//low str
	def = 11;		//low def
	luck = 20;		//high luck

	speed = 1.25;

	Item dagger, cloak;				//generate basic wizard gear
	dagger.setName("Basic Dagger");
	dagger.setType("Weapon");
	dagger.setSubtype("Dagger");
	dagger.setValue(10);

	cloak.setName("Scrap Armor");
	cloak.setType("Armor");
	cloak.setSubtype("Metal");
	cloak.setValue(20);

	addItem(dagger);
	addItem(cloak);

	specialNames[0] = "Backstab";
	specialNames[1] = "Dark shroud";
	specialNames[2] = "Poisoned blade";
}


Rogue::~Rogue()
{
}

/********************
checkitem will check if the item passed in is a valid item
to be used by the character. Utility is not yet implemented.
Parameters: the item to be checked
Returns: a true if it's useable, a false if it cannot be used by this class.
*********************/
bool Rogue:: checkItem(Item input)
{
	if (input.getSubtype() != "Dagger" || input.getSubtype() != "Metal")
	{
		return false;
	}
	return true;
}

/********************
special ability #1, which increases damage for a brief time
Parameters: n/a
Returns: increased strength
*********************/
int Rogue:: backStab()
{
	int temp = getStr();		//original value
	setStr(getStr()*1.75);
	return (temp - getStr());	//return difference
}

/********************
special ability #2, which inceases accuracy for a time
Parameters: n/a
Returns: increased accuracy
*********************/
int Rogue:: darkShroud()
{
	int temp = getAcc();		//original value
	setAcc(getAcc()* 1.3);
	return (temp - getAcc());		//return difference
}
/*not implemented*/
//int Rogue:: poisonBlade()
//{
//	//apply poison ailment
//}


/********************
Rogue class's special abilities function
Parameters: integer selecting a skill
Returns: n/a
*********************/
void Rogue:: specialAbilities(int input)
{
	bool success;					//did it work? t/f
	static int strBuff = 0;			//amount strength is boosted
	static int defBuff = 0;		//amount defense is boosted
	static int accBuff = 0;			//ammount accuracy is boosted
	static int luckBuff = 0;		//ammount luck is boosted

	static int strBuffTurn = 0;		//how long strength is boosted
	static int defBuffTurn = 0;		//how long def is boosted
	static int accBuffTurn = 0;		//how long accuracy is boosted
	static int luckBuffTurn = 0;	//how long luck is boosted


	switch (input)
	{
	case 1:
		if (AP > 8)
		{
			if (strBuff == 0)
			{
				strBuff = backStab();
			}

			strBuffTurn = 1;
			AP = AP - 8;
		}
		else
		{
			//cout << "Not enough AP";
			success = false;
		}

		break;
	case 2:
		if (AP > 8)
		{
			if (accBuff == 0)
			{
				defBuff = darkShroud();
			}

			accBuffTurn = 4;
			AP = AP - 8;
		}
		else
		{
			//cout << "Not enough AP";
			success = false;
		}

		break;
	case 3:		//not implemented
		//if (AP > 8)
		//{
		//	if (accBuff == 0)
		//	{
		//		accBuff = poisonBlade();
		//	}

		//	accBuffTurn = 4;
		//	AP = AP - 8;
		//}
		//else
		//{
		//	//cout << "not enough AP";
		//	success = false;
		//}
		break;
	default:
		;	//if what is tried is not a special
	}
	decrementTurnBuff(strBuffTurn, 'S', strBuff);	//only these two as they're the only ones that can change
	decrementTurnBuff(accBuffTurn, 'A', accBuff);
}