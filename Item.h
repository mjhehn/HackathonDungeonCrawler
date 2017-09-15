/*
Matt Hehn
5/11/14
Final Project Spring 2014 CSC 161

Items class
*/
#pragma once
#include <string>
using namespace std;



/************************
Class item is for later inheriting
of basic item traits for all
storable objects in the game
**************************/
class Item
{
private:
	string name;				//name of item
	string type;				//weapon, potion armor
	string subtype;				//Health type of potion, sword, spear weapon, etc.

	int quantity;				//number of item(s)
	int value;					//value of item in currency


public:
	Item();
	~Item();

	/*get and set item's name*/
	string getName();
	void setName(string input);

	/*get and set item's type- potion, weapon, etc.*/
	string getType();
	void setType(string input);

	/*get and set item's subtype*/
	string getSubtype();
	void setSubtype(string inputType);

	/*get and set quantity*/
	int getQuant();
	void setQuant(int input);

	/*get and set value*/
	int getValue();
	void setValue(int input);
};


