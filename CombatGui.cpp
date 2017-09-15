/*
Matt Hehn
5/11/14
Final Project Spring 2014 CSC 161

Functions to enact and print battle in-game.
*/
#include "CombatGUI.h"
using namespace std;

/********************
generates a line of stars on-screen as long as passed in
parameters: length of line in characters
returns: n/a
*********************/
void solidline(int numStars)
{

	for (int count = 0; count<numStars; count++)
	{
		cout << "*";
	}
	cout << endl;
}


/********************
outputs HP, AP, and name of player/enemy currently in combat
Parameters: pointer to a character which will have their info output
Returns: n/a
*********************/
void statsline(Character *player)
{
	cout << "\n*";
	cout << setw(10);
	cout << player->getName(); //player's name
	cout << setw(9);
	cout << "*";
	cout << endl;

	cout << "*";
	cout << setw(7);
	cout << "HP:" << (int)player->HP; //number should be hp variable
	cout << setw(10);
	cout << "*";
	cout << endl;

	cout << "*";
	cout << setw(7);
	cout << "AP:" << (int)player->AP;	//number should be ap variable
	cout << setw(10);
	cout << "*";
	cout << endl;
}

/********************
outputs the basic options for combat in a box
Parameters: n/a
Returns: n/a
*********************/
void actionsline()
{
	string optionsarray[4] = { "Attack", "Specials", "Items", "Flee" };
	
	for (int i = 0; i < 4; i++)
	{
	cout << "*";
	cout << setw(4);
	cout << (i + 1) << ". " << setw(10) << optionsarray[i];
	cout << setw(5);
	cout << "*";
	cout << endl;
	}
	
}

/********************
outputs the non-armor/weapon items of a player onscren
Parameters: pointer to the player whose items will be output
Returns: n/a
*********************/
void itemsline(Character *player)
{
	InventoryList * current;
	current = player->getHead();
	int index = 1;
	while (current != nullptr)
	{
		if (current->object.getType() != "Weapon" && current->object.getType() != "Armor")
		{
			cout << "*";
			cout << setw(4);
			cout << index << ". " << setw(10) << current->object.getName();
			cout << setw(5);
			cout << "*";
			cout << endl;
		}
		else{ ; }
		
		current = current->nextItem;
		index++;
	}
}

/********************
outputs the names of the specials for a particular player
Parameters: array of strings containing the names of the specials
Returns: n/a
*********************/
void specialsline(string specialsarray[MAXSPECIALS])
{
	

	for (int i = 0; i < MAXSPECIALS; i++)
	{
		cout << "*";
		cout << setw(4);
		cout << (i + 1) << ". " << setw(12) << specialsarray[i];
		
		cout << setw(8);
		cout << "*";
		cout << endl;
	}

}

/********************
calls other functions to generate basic UI of the combat screens
Parameters: pointers  player and opponent
Returns: n/a
*********************/
void maincombatscreen(Character *player, Character *enemy)
{
	solidline(STATSLENGTH);
	cout<<"Enemy stats";
	statsline(enemy);
	solidline(STATSLENGTH);
	cout << endl;
	solidline(STATSLENGTH);
	cout<<"Player stats";
	statsline(player);
	solidline(STATSLENGTH);
	cout << endl;
	solidline(ACTIONSLENGTH);
	actionsline();
	solidline(ACTIONSLENGTH);
}

/********************
generate the box/screen UI for items 
Parameters: pointer to player whose items are output
Returns: n/a
*********************/
void itemsscreen(Character *player)
{
	cout << endl;
	solidline(ACTIONSLENGTH);
	itemsline(player);
	solidline(ACTIONSLENGTH);
	cout << endl;
}

/********************
outputs the box/ui for specials arrays
Parameters: array of specials
Returns: n/a
*********************/
void specialsscreen(string specialsArray[MAXSPECIALS])
{
	system("cls");
	cout << endl;
	solidline(ACTIONSLENGTH);
	specialsline(specialsArray);
	solidline(ACTIONSLENGTH);
	cout << endl;
}


/********************
get good input from the players and check against valid inputs
Parameters: n/a
Returns: number chosen by player
*********************/
int getChoice()
{
	bool good;		//is input acceptable?
	string choice;	//string version of input
	char oneChoice; //char representation of input
	do
	{
		do
		{
			getline(cin, choice);
		} while (choice.size() < 1);		//while input does not exist, loop.
		good = true;						
		oneChoice = choice[0]; 
		if ( oneChoice < '1' || oneChoice > '5')
		{
			cout<<"Invalid choice";
			good = false;
		}
	}while (!good);
	choice = oneChoice;
	return atoi(choice.c_str());		//return character/string converted to integer
	
}


/********************
do a basic attack by a character, doing damage to their opponent
Parameters: pointers to a character and their opponent
Returns: n/a
*********************/
void playerAttack(Character *player, Character *enemy)
{
	double damage = 0;
	
	//if the number generated plus the difference between the attacker's
	//accuracy stat and enemy luck is > 95, critical hit.
	if ((rand() % 100 + (player->getAcc() -enemy->getLuck())/ 2) > 95)
	{
		cout << player->getName()<<" got a Critical hit!\n";
		Sleep(1500);
		damage = (player->getStr()*1.3)*(1 - (double)enemy->getDef() / 100);
	}
	else if (player->getStr() > enemy->getDef())		//general attack, modified by enemy def percentage
	{
		damage = player->getStr()* (1 - (double)enemy->getDef() / 100);
	}
	else
	{
		damage = 2;									//default damage if str is too low to do damage
	}

	if (damage < 0)
	{
		damage = 0;				//just in case something wierd happens
	}
	else{ ; }
	enemy->HP = enemy->HP - damage;
	//cout << "\nDamage was: " << damage << endl;
	player->AP += 2;			//regen a little AP

}

/********************
combat functions all call here and battle is done until 
player or monster flees, or one of them dies.
Parameters: pointers to the player, enemy, and three bools (player alive, player's turn, and enemy alive)
Returns: returns nothing
*********************/
void combat(Character *player, Character *enemy, bool &playerIsAlive, bool &playersTurn, bool &enemyIsAlive)
{
	bool escape = false;	//the player isn't escaping

	if ( player->getLuck() > enemy->getLuck() )		//determind who goes first based on luck stat
	{
		playersTurn = true;
	}

	while(  (playerIsAlive==true) && (enemyIsAlive == true) && escape == false ) 
	{
		if( playersTurn == true && player->HP > 0 )
		{
			Sleep(1500);
			system("cls");
			maincombatscreen(player, enemy);
			int choice = getChoice();
			
			switch(choice)
			{
				//Attack
			case 1:
				playerAttack(player, enemy);	//standard attack
				player->specialAbilities(4);	//decrement buffs/check buffs
				break;

				//Special abilities
			case 2:
				specialsscreen(player->specialNames);	//output specials
				choice = getChoice();
				player->specialAbilities(choice);		//Need to figure out how to access class specific functions.
				if (choice == 1)
				{
					playerAttack(player, enemy);
				}
				system("cls");
				maincombatscreen(player, enemy);
				break;
				
				
			case 3:
				cout << endl;
				itemsscreen(player);
				choice = getChoice();
				player->usePotion(choice);
				player->specialAbilities(4);
				break;

			case 4:
				player->specialAbilities(4);
				if (player->speed * 100 + rand() % player->getLuck() > enemy->speed * 100 + rand() % 100)
				//if player's speed+ rand num(size determinded by luck) is > random number with enemy speed added, escape
				{
					escape = true;
				}
				break;

			//Should never happen
			default:
				cerr<<"Error contact support->";
				break;
			}
			
			playersTurn = false;
		}

		if(playersTurn == false && enemy->HP > 0)
		{
			/*Begin enemy "AI"*/
			int choice = rand() % 100;		//generate/select enemy move

			if (player->level > enemy->level + 2 && choice <= 50)
			{
				choice = 3;
			}
			else if (choice < 50 && enemy->HP > 20)
			{
				choice = 1;
			}
			else if (choice < 50 && enemy->HP <=20)
			{
				choice = 2;
			}
			else if (choice < 75 && choice >=50)
			{
				choice = 1;
			}
			else if (choice >= 75 && enemy->AP > 10)
			{
				choice = 2;
			}
			else
			{
				choice = 1;
			}
			/*End enemy "AI" setup*/

			switch (choice)
			{
				//Attack
			case 1:
				cout << enemy->getName() << " Attacked!\n";
				playerAttack(enemy, player);
				enemy->specialAbilities(4);
				break;

				//Special abilities
			case 2:
				cout << enemy->getName() << " used magic!\n";
				choice = rand() % 4;
				enemy->specialAbilities(choice);
				if (choice == 1)
				{
					playerAttack(enemy, player);
				}
				break;

			case 3:
				enemy->specialAbilities(4);
				cout << enemy->getName() << " is trying to escape!\n";
				if (enemy->speed*50 > rand() % 100 + player->getLuck() / 2)
				{
					escape = true;
				}
				break;

				//Should never happen
			default:
				cerr << "Error contact support->";
				break;
			}
			playersTurn = true;
		}

		if(enemy->HP < 1)
		{
			enemyIsAlive = false;
			//cout << "You killed it!\n";
			
		}

		if(player->HP <1)
		{
			playerIsAlive = false;
			//cout << "You are dead!\n";
			
		}
	}
	system("cls");
	if (escape == true)
	{
		cout << "You managed to escape!";
	}
	else if (playerIsAlive == false)
	{
		
		cout << "You are dead!";
	}
	else
	{
		cout << "You won the battle!";
	}
	cout << endl << endl;
	system("pause");
}