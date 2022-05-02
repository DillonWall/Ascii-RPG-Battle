/*************************************************************
* Author: Dillon Wall
* Filename: "Item.h"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#pragma once

#include "String.h"

/************************************************************************
* Class: Item
*
* Purpose: Base abstract class for items
*
* Manager functions:
* 	Item();
*	Item(String name, String description, String cost, int type, int itemID);
*	~Item();
*	Item(const Item& other);
*	Item& operator=(const Item& rhs);
*	bool operator==(const Item& rhs) const;
*
* Methods:
* 	virtual void Display() = 0;
* 		displays the item
*	static String * CostToDisplayString(String cost);
*		converts cost string to a more user friendly reading
*
*************************************************************************/

class Item
{
public:
	enum TYPES : int {HEALING = 0, MANA_RECOVER = 1, WEAPON = 2, ARMOR = 3};
	enum IDS : int { ID_MINOR_HEAL = 00, ID_MINOR_MANA = 01, ID_HEAL = 02, ID_MANA = 03, ID_RUSTED = 10, ID_IRON = 11, ID_SILVER = 12, ID_EXCALIBUR = 13, ID_BUCKLER = 20, ID_HEATER = 21, ID_KITE = 22, ID_WYNEBERG = 23 };

	Item();
	Item(String name, String description, String cost, int type, int itemID);
	~Item();
	Item(const Item& other);
	Item& operator=(const Item& rhs);
	bool operator==(const Item& rhs) const;

	String GetName() const;
	void SetName(String name);
	String GetDescription() const;
	void SetDescription(String description);
	String GetCost() const;
	void SetCost(String cost);
	int GetType() const;
	int GetItemID() const;

	virtual void Display() = 0;

	static String * CostToDisplayString(String cost);
protected:
	String m_name;
	String m_description;
	String m_cost;
	int m_type, m_itemID;
};

