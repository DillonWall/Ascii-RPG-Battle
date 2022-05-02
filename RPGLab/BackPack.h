/*************************************************************
* Author: Dillon Wall
* Filename: BackPack.h
* Date Created: 11/13/18
* Modifications:
*			- 11/29/18 - Changed to use items instead of just potions
**************************************************************/

#pragma once
#include "DynamicArray.h"
#include "Item.h"

/************************************************************************
* Class: BackPack
*
* Purpose: This class is used to represent a backpack which contains other items
*
* Manager functions:
*	BackPack();
*	BackPack(DynamicArray potions);
*	~BackPack();
*	BackPack(const BackPack& other);
*	BackPack& operator=(const BackPack& rhs);
*
* Methods:
*
*	void AddItem(Item * p);
*		Adds an item to the dynamic array of items
*	void RemoveItem(Item * p);
*		Removes a item from the dynamic array of items
*	DynamicArray<Item> GetItemArray() const;
*		Returns m_items
*	void Display() const;
*		Calls Display function of DynamicArray<Item>
*
*************************************************************************/

class BackPack
{
public:
	BackPack();
	BackPack(DynamicArray<Item> items);
	~BackPack();
	BackPack(const BackPack& other);
	BackPack& operator=(const BackPack& rhs);

	void AddItem(Item * p);
	void RemoveItem(Item * p);
	DynamicArray<Item> GetItemArray() const;
	void Display() const;
private:
	DynamicArray<Item> m_items;
};

