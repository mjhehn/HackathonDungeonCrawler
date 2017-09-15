/*
Matt Hehn
5/11/14
Final Project Spring 2014 CSC 161

functions to operate the inventory linked list.
*/
#include "InventoryList.h"


InventoryList::InventoryList()
{
	nextItem = nullptr;
}


InventoryList::~InventoryList()
{
	delete nextItem;
	void deleteList();
}

/********************
output weight will output the index location
and weight of the object in this location of the linklist
Parameters: n/a
Returns: n/a
*********************/

void InventoryList:: output()
{
	int index = 1;					//for organization of output
	InventoryList *current;			// pointer for manipulation and output
	current = this;
	while (current != nullptr)
	{
		cout << "\t" << index << ". " << current->object.getName();
		cout<<"\n\t\tQuant:"<<current->object.getQuant()<<endl;
		cout << "\t\t"<< "Gold: "<< current->object.getValue() <<endl;
		current = current->nextItem;
		index++;
	}
}



/***********************
adds a new node to weight list containing the object
passed in as parameter.
Parameter: an Item class object.
Returns: nothing
***********************/
InventoryList* InventoryList::addFront(Item newItem)
{
	/*Set head pointer = to this function's expression*/
	InventoryList * newNode;				//create bag entry
	newNode = new InventoryList;

	newNode->nextItem = this;				//put on front of list
	newNode->object = newItem;				//assign object to the newly created node

	return newNode;
}

/***************
Used to delete the entire set of lists.
called in the destructor.
***************/
void InventoryList::deleteList()
{
	InventoryList *current;			//pointer to help cycle through link nodes
	InventoryList *previous;		//" "
	current = this;

	while (current != nullptr)
	{
		previous = current;
		current = current->nextItem;
		delete previous;
	}
	cout << "\nfinished deleting";
}


/********************
deleteItem will remove one item matching the parameter
from the linked list.
Parameters: item to be found and removed
Returns: n/a
*********************/
void InventoryList::deleteItem(Item input)
{
	InventoryList *current;			//pointer to help cycle through link nodes
	InventoryList *previous;		//" "
	previous = current = this;
	bool found = false;				//if the item is the current node
	while (found == false && current != nullptr)
	{
		previous = current;
		current = current->nextItem;

		if (input.getName() == current->object.getName())
		{
			found = true;
		}
		else{ ; }
	}

	if (found == true)
	{
		previous->nextItem = current->nextItem;
		delete current;
	}
	else{ cout << "No item found.\n"; }
	
}

/********************
find item will take in a number and return a pointer in the inventorylist
to the item associated with that number. (two types of potions)
Parameters: the number
Returns: pointer to associated item, if any exists.
*********************/
InventoryList* InventoryList::findItem(int num)
{
	InventoryList *current;			//pointer to help cycle through link nodes
	current = this;
	bool found = false;				//if the item is the current node

	string input;
	switch (num)
	{
	case 4:
		input = "Health Potion";
		break;
	case 3: 
		input = "Ability Potion";
		break;
	default:
		input = " ";
	}



	while (found == false && current != nullptr)
	{	
		current = current->nextItem;
		if (current != nullptr && input == current->object.getName())
		{
			found = true;
		}
		else{ ; }
	}

	return current;
}


