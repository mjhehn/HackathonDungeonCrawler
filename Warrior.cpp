/*
Matt Hehn
5/11/14
Final Project Spring 2014 CSC 161

Playable warrior class
*/
#include "Warrior.h"


Warrior::Warrior()
{
	MAXHP = HP = 80;
	MAXAP = AP = 20;
	className = "Warrior";
	acc = 16;		//mid acc
	str = 20;		//high str
	def = 14;		//mied def
	luck = 10;		//base luck

	speed = .75;

	Item sword, armor;				//generate basic  warrior gear
	sword.setName("Heirloom sword");
	sword.setType("Weapon");
	sword.setSubtype("Sword");
	sword.setValue(10);

	armor.setName("Old suit of Armor");
	armor.setType("Armor");
	armor.setSubtype("Metal");
	armor.setValue(20);

	addItem(sword);
	addItem(armor);

	specialNames[0] = "Strong Slash";
	specialNames[1] = "Iron Skin";
	specialNames[2] = "Clear Sight";
}


Warrior::~Warrior()
{
}


/********************
checkitem will check if the item passed in is a valid item
to be used by the character. Utility is not yet implemented.
Parameters: the item to be checked
Returns: a true if it's useable, a false if it cannot be used by this class.
*********************/
bool Warrior::checkItem(Item input)
{
	if (input.getSubtype() != "Sword" || input.getSubtype() != "Metal")
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
int Warrior::strongSlash()
{
	int temp = getStr();		//original value
	setStr(getStr()*1.2);
	return (temp - getStr());	//return difference
}

/********************
special ability #2, which inceases defense for a time
Parameters: n/a
Returns: increased defense
*********************/
int Warrior::ironSkin()
{
	int temp = getDef();		//orignal value
	setDef(getDef()*1.2);
	return (temp - getDef());					//return difference
}

/********************
special ability #3, which inceases accuracy for a time
Parameters: n/a
Returns: increased accuracy
*********************/
int Warrior::clearSight()
{
	int temp = getAcc();		//original value
	setAcc(getAcc()* 1.2);
	return (temp - getAcc());		//return difference
}

/********************
Warrior class's special abilities function
Parameters : integer selecting a skill
Returns : n / a
*********************/
void Warrior::specialAbilities(int input)
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
				strBuff = strongSlash();
			}

			strBuffTurn = 4;
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
			if (defBuff == 0)
			{
				defBuff = ironSkin();
			}

			defBuffTurn = 4;
			AP = AP - 8;
		}
		else
		{
			//cout << "Not enough AP";
			success = false;
		}

		break;
	case 3:
		if (AP > 8)
		{
			if (accBuff == 0)
			{
				accBuff = clearSight();
			}

			accBuffTurn = 4;
			AP = AP - 8;
		}
		else
		{
			//cout << "not enough AP";
			success = false;
		}
		break;
	default:
		;	//if what is tried is not a special
	}
	decrementTurnBuff(strBuffTurn, 'S', strBuff);
	decrementTurnBuff(defBuffTurn, 'D', defBuff);
	decrementTurnBuff(accBuffTurn, 'A', accBuff);
	decrementTurnBuff(luckBuffTurn, 'L', luckBuff);
}
