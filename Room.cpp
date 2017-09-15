/*
Matt Hehn
5/11/14
Final Project Spring 2014 CSC 161

Room/navigation functions and map output
*/
#include "Room.h"

/**********************
	Tile Functions
************************/
Tile::Tile()
{
	solid = false;
	appearance = ' ';
	door = false;
	encounterChance = 0;
	boss = false;
}
Tile::~Tile()
{

};
/*Tile setters/getters and setup as written for Hackathon Spring 2014*/
void Tile::setAppearance(char app)
{
	appearance = app;
}
void Tile::setDoorLoc(int x, int y)
{
	doorLoc.X = x;
	doorLoc.Y = y;
}

void Tile::setSolid(bool sol)
{
	solid = sol;
}

void Tile::setDoor(bool d)
{
	door = d;
}

void Tile::setEncounterChance(int c)
{
	encounterChance = c;
}

void Tile::setBoss(bool b)
{
	boss = b;
}

char Tile::getAppearance()
{
	return appearance;
}

bool Tile::getSolid()
{
	return solid;
}

bool Tile::isDoor()
{
	return door;
}

int Tile::getEncounterChance()
{
	return encounterChance;
}

COORD Tile::getDoorLoc()
{
	return doorLoc;
}

void Tile::setDestRoom(int room, int door)
{
	destRoomDoor.X = room;
	destRoomDoor.Y = door;
}

COORD Tile::getDestRoomDoor()
{
	return destRoomDoor;
}

bool Tile::isBoss()
{
	return boss;
}



/**********************
	Room Functions
************************/

Room::Room(void)
{

	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd = GetStdHandle(STD_INPUT_HANDLE);

	SMALL_RECT windowSize = {0, 0, SCREEN_WIDTH - 1 , SCREEN_HEIGHT - 1};
	COORD bufferSize = {SCREEN_WIDTH, SCREEN_HEIGHT};

	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);

	numDoors = 0;
	needsChange = false;
	playerLoc.X = 0;
	playerLoc.Y = 0;
}
Room::~Room(void)
{
}

/*Room getters/setters*/
COORD Room::getDoorLoc(int door)
{
	return doors[door]->getDoorLoc();
}

bool Room::needsChangeRoom()
{
	return needsChange;
}

COORD Room::getDestinationRoom()
{
	needsChange = false;
	return destRoomDoor;
}

void Room::setPlayerLoc(COORD loc)
{
	playerLoc = loc;
}



/********************
Generate a room from the ifstream passed in
Parameters: ifstream associated with room text file
Returns: a true/false if the file open succeeds.
*********************/
bool Room::loadRoom(ifstream &ifs)
{
	
	if(!ifs.is_open())
	{
		cout << "Could not open file." << endl;
		return false;
	}

	ifs >> roomWidth;
	ifs >> roomHeight;
	
	ifs.get();
	string temp;
	for(int y = 0; y < roomHeight; y++)
	{
		getline(ifs, temp);
		for(int x = 0; x < roomWidth; x++)
		{
			room[x][y].setAppearance(temp[x]);


			if(temp[x] == '#')
			{
				room[x][y].setDoor(false);
				room[x][y].setSolid(true);
				room[x][y].setBoss(false);
			}
			else if(temp[x] == 'D')
			{
				room[x][y].setDoor(true);
				room[x][y].setSolid(false);
				room[x][y].setBoss(false);
				room[x][y].setDoorLoc(x, y);

				if(numDoors < MAX_DOORS)
				{
					doors[numDoors] = &room[x][y];
					numDoors++;
				}
			}
			else if(temp[x] == 'S')
			{
				room[x][y].setAppearance(' ');
				room[x][y].setDoor(false);
				room[x][y].setSolid(false);
				room[x][y].setBoss(false);
				playerLoc.X = x-1;
				playerLoc.Y = y;
			}
			else if(temp[x] >= '0' && temp[x] <= '8')
			{
				room[x][y].setAppearance(' ');
				room[x][y].setDoor(false);
				room[x][y].setSolid(false);
				room[x][y].setBoss(false);
				room[x][y].setEncounterChance((temp[x] - 48)*10);
			}
			else if(temp[x] == '9')
			{
				room[x][y].setAppearance(' ');
				room[x][y].setDoor(false);
				room[x][y].setSolid(false);
				room[x][y].setBoss(false);
				room[x][y].setEncounterChance(100);
			}
			else if(temp[x] == 'B')
			{
				room[x][y].setAppearance(234);
				room[x][y].setDoor(false);
				room[x][y].setBoss(true);
				room[x][y].setSolid(false);
				room[x][y].setEncounterChance(0);
			}
		}
	}
	for(int i = 0; i < numDoors; i++)
	{
		int r, d;
		ifs >> r ;
		ifs >> d;
		doors[i]->setDestRoom(r, d);
	}
	
	return true;
}
/********************
Draws/outputs the room currently stored
Parameters:  n/a
Returns:  n/a
*********************/
void Room::draw()
{

	for(int y = 0; y < roomHeight; y++)
	{
		for(int x = 0; x < roomWidth; x++)
		{
			if(playerLoc.X == x && playerLoc.Y == y)
			{
				cout << (char)1; //:)
			}
			else
			{
				cout << room[x][y].getAppearance();
			}
		}
		cout << endl;
	}

}

/********************
trymove will attempt to move the character in a given direction
if permitted, and will enact functions as the new space designates
Parameters: pointer to the player, and the attmempted coordinates
Returns: a true/false if successful in moving to the cell
*********************/
bool Room::tryMove(int dx, int dy, Character *player)
{
	if( playerLoc.X + dx >= 0 && playerLoc.X + dx < roomWidth
		&& !room[playerLoc.X + dx][playerLoc.Y + dy].getSolid())
	{
		playerLoc.X += dx;
	}
	if(playerLoc.Y + dy >= 0 && playerLoc.Y + dy < roomHeight
		&& !room[playerLoc.X + dx][playerLoc.Y + dy].getSolid())
	{
		playerLoc.Y += dy;
	}
	else
	{
		return false;
	}

	if(room[playerLoc.X][playerLoc.Y].getEncounterChance() > (rand()%50 + player->getLuck()))
	{

		cout << "You have encountered a monster!" << endl; 
		Sleep(2500);
		Character *enemy1;
		int monsterType = rand() % 3 +1;
		switch (monsterType)
		{
		case 1:
			enemy1 = new Zubat(player->level);
			break;
		case 2:
			enemy1 = new SkeletonWarrior(player->level);
			break;
		case 3:
			enemy1 = new Goblin(player->level);
		default:
			enemy1 = new Zubat(player->level);
		}
		bool playerIsAlive = true;
		bool playersTurn = true;
		bool enemyIsAlive = true;
		combat(player, enemy1, playerIsAlive, playersTurn, enemyIsAlive);
	}

	return true;
}

/********************
doaction takes the player and their location and then
allows them to interact with their tile. (currently only allowing entry to boss)
Parameters: pointer to the player
Returns: n/a
*********************/
void Room::doAction(Character *player)
{
	if(room[playerLoc.X][playerLoc.Y].isDoor())
	{
		destRoomDoor = room[playerLoc.X][playerLoc.Y].getDestRoomDoor();
		needsChange = true;
	}
	else if(room[playerLoc.X][playerLoc.Y].isBoss())
	{
		cout << "You chose to fight the Boss!" << endl; 
		Sleep(2500);
		while(_kbhit()) _getch();

		Vicki *boss;		//generate the boss to be fought
		boss = new Vicki;

		bool playerIsAlive = true;
		bool playersTurn = true;
		bool enemyIsAlive = true;
		combat(player, boss, playerIsAlive, playersTurn, enemyIsAlive);
		system("cls");
		if(playerIsAlive == true)
		{
			cout<<"WHAT??? YOU WON?!?!?!";
		}
		else
		{
			;
		}
		system("pause");
		player->setWon(true);
	}
}