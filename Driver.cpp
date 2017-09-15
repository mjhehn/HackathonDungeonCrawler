/*
Matt Hehn
5/13/14
Project Name: "Not-So-Final Fantasy"
Final Project Spring 2014 CSC 161

This project is a relatively simple dungeon crawling game with three playable classes.
Overall, this "engine" was originally intended to be modular and relatively easy to add upon or expand
at a later time.

Input files: Help.txt, Map.txt
Additional documentation to aid in understanding the RPG's "classes": Classes.txt
*/

#include "All.h"
#include "Room.h"
using namespace std;

Character* makeCharacter();		//Character creation w/player input and selection of their class to play as in the game
	

int main()
{
	srand(time(NULL));
	
	string helpOutput;

	ifstream ifs;
	ifs.open("Help.txt");		//output help file
	if(ifs.fail())
	{
		ifs.close();
		cout << "Help file didn't open correctly.";
	}
	else
	{
		while (!ifs.eof())
		{
			getline(ifs, helpOutput);
			if (helpOutput == "@")		//allows for better formatting of screen
			{
				cout << endl;
			}
			else
			{
				cout << helpOutput;
			}
		}
		ifs.close();
		cout << endl << endl;
		system("pause");
		system("cls");

		ifs.open("Map.txt");			//open level/map file
		if (ifs.fail())
		{
			ifs.close();
			cout << "Map file didn't open correctly.";
		}
		else
		{
			int numRooms;			//number of rooms in the level/game
			ifs >> numRooms;

			Room* level = new Room[numRooms];		//generate the map

			Character *player;						//the user's character for gameplay
			player = makeCharacter();

			for (int i = 0; i < numRooms; i++)
			{
				level[i].loadRoom(ifs);
			}
			ifs.close();
			int curRoom = 0;		//which room the player is in
			bool playing = true;	//as long as the player is alive/can play
			

			while (playing == true && player->getWon() == false)
			{
				system("cls");
				level[curRoom].draw();

				int in = _getch();
				switch (in)
				{
				case 'w':
					level[curRoom].tryMove(0, -1, player);
					break;
				case 'a':
					level[curRoom].tryMove(-1, 0, player);
					break;
				case 's':
					level[curRoom].tryMove(0, 1, player);
					break;
				case 'd':
					level[curRoom].tryMove(1, 0, player);
					break;
				case 'e':
					level[curRoom].doAction(player);
					break;
				default:
					break;
				}



				if (level[curRoom].needsChangeRoom())
				{
					COORD newRoom = level[curRoom].getDestinationRoom();
					curRoom = newRoom.X - 1;
					level[curRoom].setPlayerLoc(level[curRoom].getDoorLoc(newRoom.Y - 1));
				}

				if (player->HP <= 0)
				{
					cout << "You died!" << endl;
					playing = false;
					delete player;
				}
			}

			delete[] level;
		}
		
	}

	return 0;
}

/***************
makecharacter generates a new character
from the inputs made by the user
parameters: n/a
returns: the completed character for play.
*****************/
Character* makeCharacter()
{
	Character  *player;		//the player's character
	player = new Character;
	string input;			//generic string input for setting player information
	int inputNum = 0;		//numeric input from user


	while (inputNum <= 0)
	{
		system("cls");
		if (inputNum == -1)
		{
			cout << "Invalid class entry. Try again. \n\n";
		}
		else{ ; }


		cout << "--Select your class- Warrior(1), Wizard(2), or Rogue(3)--\n\t";
		getline(cin, input);

		for (int i = 0; i < input.size(); i++)
		{
			if (isdigit(input[i]))
			{
				inputNum = stoi(input, nullptr);		//changes string to int
			}
			else
			{
				inputNum = -1;
			}
		}
	}

	switch (inputNum)		//class selected, creating the correct class object.
	{
	case 1:
		player = new Warrior;
		break;
	case 2:
		player = new Wizard;
		break;
	case 3:
		player = new Rogue;
		break;

	default:
		cout << "Something went wrong in class selection during character creation\n";
		system("pause");
	}

	system("cls");
	cout << "Enter the name for your character\n\t";
	getline(cin, input);
	player->setName(input);

	system("cls");
	cout << "Choose your race:\n\t";
	getline(cin, input);
	player->setRace(input);

	system("cls");

	return player;
}
//Problems: None with current code that I've found. Some other features were removed or not used
//as their implementation required rebuilding a lot of code and a fair amount of time to ensure
//stability.