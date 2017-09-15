/*
Matt Hehn
5/11/14
Final Project Spring 2014 CSC 161

functions to operate the inventory linked list.
*/

#pragma once
#include "Item.h"
#include <iostream>
using namespace std;

/******************
Inventory list stores an object
and its location in regards to the
relevant sorting methods. (through multiple links)
*********************/

class InventoryList
{
public:
	InventoryList * nextItem;				//weight sorted list
	Item object;							//object/item being stored in the list

	InventoryList();
	~InventoryList();

	InventoryList * addFront(Item newItem);			//adds to front of weight list

	InventoryList* findItem(int num);
	
	void output();							//output weight in a numbered list

	void deleteList();								//deletes linklist
	void deleteItem(Item input);
	
};

