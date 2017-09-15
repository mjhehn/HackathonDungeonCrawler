/*
Matt Hehn
5/11/14
Final Project Spring 2014 CSC 161

*/
#include "Item.h"


Item::Item()
{
	value = 0;						//value in currency
	quantity = 1;
	name = "";						//name of the item
	type = "";
	subtype = "";

}


Item::~Item()
{
	;
}

/*****************************
getters and setters for value
*****************************/
void Item::setValue(int input)
{
	value = input;
}
int Item::getValue()
{
	return value;
}


/*get and set item's type- potion, weapon, etc.*/
void Item::setType(string input)
{
	type = input;
}
string Item::getType()
{
	return type;
}


/*get and set item's subtype*/
string Item::getSubtype()
{
	return subtype;
}
void Item::setSubtype(string input)
{
	subtype = input;
}

/*get and set quantity*/
int Item:: getQuant()
{
	return quantity;
}
void Item:: setQuant(int input)
{
	quantity = input;
}


string Item:: getName()
{
	return name;
}
void Item:: setName(string input)
{
	name = input;
}
