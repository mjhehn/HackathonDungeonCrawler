/*
Matt Hehn
5/11/14
Final Project Spring 2014 CSC 161


*/

#include "Vicki.h"


Vicki::Vicki()
{
	name = "Vicki";
	race = "Professor";
	className = "Computer Scientist";

	HP = 130;
	AP = 70;
	setStr(25);
	setDef(30);
	setAcc(20);
	setLuck(15);
	speed = 1.3;
}

Vicki::~Vicki()
{
	;
}

/***********
specialabilities for Vicki Boss character/monster
parameters: input that's not used
returns: n/a
************/
void Vicki:: specialAbilities(int input)
{
	input =rand() % 5;		//generate attack type
	static int strBuff = 0;			//amount strength is boosted
	static int defBuff = 0;		//amount defense is boosted
	static int accBuff = 0;			//ammount accuracy is boosted
	static int luckBuff = 0;		//ammount luck is boosted

	static int strBuffTurn = 0;		//how long strength is boosted
	static int defBuffTurn = 0;		//how long def is boosted
	static int accBuffTurn = 0;		//how long accuracy is boosted
	static int luckBuffTurn = 0;	//how long luck is boosted

	decrementTurnBuff(strBuffTurn, 'S', strBuff);
	decrementTurnBuff(defBuffTurn, 'D', defBuff);
	decrementTurnBuff(accBuffTurn, 'A', accBuff);
	decrementTurnBuff(luckBuffTurn, 'L', luckBuff);

	switch (input)
	{
	case 1:
		if (AP > 10)
		{
			strBuff = strongSlash();
			strBuffTurn = 3;
			AP = AP - 10;
		}
		else
		{
			//cout << "Not enough AP";
		}

		break;
	case 2:
		if (AP > 10)
		{
			defBuff = ironSkin();
			defBuffTurn = 3;
			AP = AP - 10;
		}
		else
		{
			//cout << "Not enough AP";
		}

		break;
	case 3:
		if (AP > 10)
		{
			accBuff = clearSight();
			accBuffTurn = 3;
			AP = AP - 10;
		}
		else
		{
			//cout << "not enough AP";
		}
		break;
	case 4:
		if (HP < 30)
		{
			system("cls");
			cout << "YOU HAVE ANGERED THE PROGRAMMING GODS (and Vicki) BY USING GLOBAL VARIABLES!\n\n\t May the internet have mercy on your soul.\n";
			setDef(100);
			setStr(100);
			setAcc(100);
			setLuck(100);
			speed = .75;
			HP = 150;
			cout << "\n\n\n\n\n\n\n\n\t\tLike a Boss.\n";
			//and death = true :D
		}
		else
		{
			specialAbilities(3);
		}
	default:
		specialAbilities(1);
	}

}

