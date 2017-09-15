/*
Matt Hehn
5/11/14
Final Project Spring 2014 CSC 161

Playable wizard class
*/
#include "Wizard.h"


Wizard::Wizard()
{
	MAXHP = HP = 50;
	MAXAP = AP = 50;
	className = "Wizard";
	acc = 20;		//high base acc
	str = 10;		//min str
	def = 12;		//low def
	luck = 18;		//mid-high luck

	speed = 1.1;

	Item staff, robes;				//generate basic wizard gear
	staff.setName("Basic Staff");
	staff.setType("Weapon");
	staff.setSubtype("Staff");
	staff.setValue(10);

	robes.setName("Worn Robes");
	robes.setType("Armor");
	robes.setSubtype("Cloth");
	robes.setValue(20);

	addItem(staff);
	addItem(robes);

	specialNames[0] = "Fireball";
	specialNames[1] = "Stonewall";
	specialNames[2] = "Phase shift";
}


Wizard::~Wizard()
{
	;
}


/********************
checkitem will check if the item passed in is a valid item
to be used by the character. Utility is not yet implemented.
Parameters: the item to be checked
Returns: a true if it's useable, a false if it cannot be used by this class.
*********************/
bool Wizard::checkItem(Item input)
{
	if (input.getSubtype() != "Staff" || input.getSubtype() != "Cloth")
	{
		return false;
	}
	return true;
}

/********************
special ability #1, which increases damage for a turn
Parameters: n/a
Returns: increased strength
*********************/
int Wizard::fireball()
{
	int temp = getStr();		//orignal value
	setDef(getStr()*2);
	return (temp - getStr());					//return difference
}

/********************
special ability #2, which inceases defense for a time
Parameters: n/a
Returns: increased defense
*********************/
int Wizard::stoneWall()
{
	int temp = getDef();		//original value
	setAcc(getDef()* 1.4);
	return (temp - getDef());		//return difference
}

/********************
special ability #3, which inceases accuracy for a time
Parameters: n/a
Returns: increased accuracy
*********************/
int Wizard::phaseShift()
{
	int temp = getAcc();		//original value
	setAcc(getAcc()* 1.3);
	return (temp - getAcc());		//return difference
}

/********************
Wizard class's special abilities function
Parameters: integer selecting a skill
Returns: n/a
*********************/
void Wizard::specialAbilities(int input)
{
	bool success = true;
	int strBuff = 0;
	int defBuff = 0;
	int accBuff = 0;
	int luckBuff = 0;

	static int strBuffTurn = 0;
	static int defBuffTurn = 0;
	static int accBuffTurn = 0;
	static int luckBuffTurn = 0;

	

	switch (input)
	{
	case 1:
		if (AP > 10)
		{
			if (strBuff == 0)
			{
				strBuff = fireball();
			}
			strBuffTurn = 2;
			AP = AP - 10;
		}
		else
		{
			//cout << "not enough AP";
			success = false;
		}

		break;
	case 2:
		if (AP > 10)
		{
			if (defBuff == 0)
			{
				defBuff = stoneWall();
			}
			defBuffTurn = 4;
			AP = AP - 10;
		}
		else
		{
			//cout << "Not enough AP";
			success = false;
		}

		break;
	case 3:

		if (AP > 10)
		{
			if (accBuff == 0)
			{
				accBuff = phaseShift();
			}
			
			accBuffTurn = 4;
			AP = AP - 10;
		}
		else
		{
			//cout << "Not enough AP";
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