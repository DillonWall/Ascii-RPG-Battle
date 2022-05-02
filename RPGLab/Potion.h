/*************************************************************
* Author: Dillon Wall
* Filename: Potion.h
* Date Created: 10/1/18
* Modifications:
*			- 10/10/18 - Updated to account for new String class
*			- 10/16/18 - Added operator== and renamed functions to fit standard
*			- 11/29/18 - Made it a derived class of item
**************************************************************/

#pragma once

#include "Item.h"

/************************************************************************
* Class: Potion
*
* Purpose: This class represents a potion object to be used in an RPG
*
* Manager functions:
* Potion()
*		Creates default Potion where are strings are "".
* Potion(String name, String description, String potency, String cost)
*		Creates a Potion where m_name = name, m_description = description,
*       m_potency = potency, and m_cost = cost.
* Potion(const Potion& other)
* Potion& operator=(const Potion& rhs);
* bool operator==(const Postion& rhs);
* ~Potion()
*
* Methods:
* string GetPotency()
*		returns m_potency
* void SetPotency(String potency)
*		sets m_potency to potency
* void Display()
*		outputs the Potion to the console in the format:
*		   |~|   Name: Minor Healing Potion
*		   | |   Description: A potion that heals for a small amount
*		 .'   `. Potency: I
*		 `.___.' Cost: 1 platinum, 2 gold, 2 silver, 50 copper
* static void Init();
*		initialize static variables
* static void Purge();
*		purge static variables
*
*************************************************************************/
class Potion :
	public Item
{
public:
	enum POTIONS : int {MINOR_HEAL = 0, MINOR_MANA = 1, HEAL = 2, MANA = 3};

	Potion();
	Potion(String name, String description, int potency, String cost, int type, int itemID);
	Potion(const Potion& other);
	~Potion();
	Potion& operator=(const Potion& rhs);
	bool operator==(const Potion& rhs) const;

	int GetPotency() const;
	void SetPotency(int potency);

	virtual void Display() override;

	static void Init();
	static void Purge();

	static Potion ** potionList;
	static const int NUM_POTIONS = 4;

private:
	int m_potency;
};

