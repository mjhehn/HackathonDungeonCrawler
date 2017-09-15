//COMMENT THISSSSSSSSSSSSSSSSSSSSSSSSSSSS


/*
Matt Hehn
5/11/14
Final Project Spring 2014 CSC 161

Room/navigation functions and map output
*/

#pragma once
#include "All.h"


using namespace std;

const int ROOM_SIZE = 64;		//????
const int SCREEN_WIDTH =100;	//width in characters of map
const int SCREEN_HEIGHT = 70;	//height in characters of map
const int MAX_DOORS = 16;		//maximum number of entrance/exits
class Tile

{
public:
	Tile();
	~Tile();

	void setAppearance(char app);
	void setDoorLoc(int x, int y);
	void setSolid(bool sol);
	void setDoor(bool d);
	void setDestRoom(int x, int y);
	void setEncounterChance(int chance);

	char getAppearance();
	bool getSolid();
	bool isDoor();
	COORD getDoorLoc();
	COORD getDestRoomDoor();
	int getEncounterChance();

	void setBoss(bool b);
	bool isBoss();

private:
	char appearance;
	bool solid;

	COORD destRoomDoor;
	COORD doorLoc;
	bool door;
	bool boss;


	int encounterChance;
	//more later
};


class Room
{
public:

	Room(void);

	bool loadRoom(ifstream &ifs);

	void draw();
	bool tryMove(int dx, int dy, Character *player);

	void setPlayerLoc(COORD loc);
	COORD getDoorLoc(int door);

	void doAction(Character *player);

	bool needsChangeRoom();
	COORD getDestinationRoom();

	~Room(void);

private:
	Tile room[ROOM_SIZE][ROOM_SIZE];

	char screenBuffer[SCREEN_WIDTH][SCREEN_HEIGHT];

	string roomName;

	int roomWidth;
	int roomHeight;

	int numDoors;
	Tile* doors[MAX_DOORS];


	//thanks to http://www.benryves.com/tutorials/winconsole/
	// for the win console stuff
	HANDLE wHnd;
	HANDLE rHnd;

	bool needsChange;
	COORD destRoomDoor;

	COORD playerLoc;
};

