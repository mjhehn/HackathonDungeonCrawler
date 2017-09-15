/*
Matt Hehn
5/11/14
Final Project Spring 2014 CSC 161

Functions to enact and print battle in-game.
*/

#pragma once

#include "All.h"
using namespace std;



const int STATSLENGTH = 25;		//constant for stats box length
const int ACTIONSLENGTH = 27;	//constant for actions box length

void solidline(int numStars);	//creates a solid line of stars
void statsline();				//creates the lines for player and enemey hp and ap
void actionsline();				//creates the box for the main screen combat with main choices
void itemsline(Character *player);				//creates the box for the items in inventory
void specialsline(string specialsArray[MAXSPECIALS]);			//creates the box for the special abilities
void maincombatscreen(Character *player, Character *enemy);		//displays the UI for main battle screen
void itemsscreen(Character *player);				//displays the UI for the selection of the items menu in the main screen
void specialsscreen(string specialsArray[MAXSPECIALS]);			//displays the UI for the selection of the specials menu in the main screen

void combat(Character *player, Character *enemy, bool &playerIsAlive, bool &playersTurn, bool &enemyIsAlive);		//do battle!
void playerAttack(Character *player, Character *enemy);	//attack in battle
int getChoice();	//take in choice