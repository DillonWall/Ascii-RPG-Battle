/*************************************************************
* Author: Dillon Wall
* Filename: "Armor.h"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#pragma once
#include "Item.h"

/************************************************************************
* Class: Armor
*
* Purpose: Represents an armor item
*
* Manager functions:
*	Armor();
*	Armor(String name, String description, int defense, String cost, int itemID);
*	Armor(const Armor& other);
*	~Armor();
*	Armor& operator=(const Armor& rhs);
*	bool operator==(const Armor& rhs) const;
*
* Methods:
* 	int GetDefense() const;
*	void SetDefense(int defense);
*	virtual void Display() override;
*	static void Init();
*		initialize static variables
*	static void Purge();
*		purge static variables
*
*************************************************************************/

class Armor :
	public Item
{
public:
	enum ARMORS : int {BUCKLER = 0, HEATER = 1, KITE = 2, WYNEBERG = 3};

	Armor();
	Armor(String name, String description, int defense, String cost, int itemID);
	Armor(const Armor& other);
	~Armor();
	Armor& operator=(const Armor& rhs);
	bool operator==(const Armor& rhs) const;

	int GetDefense() const;
	void SetDefense(int defense);

	virtual void Display() override;

	static void Init();
	static void Purge();
	
	static Armor ** armorList;
	static const int NUM_ARMORS = 4;

private:
	int m_defense;
};

