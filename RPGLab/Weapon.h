/*************************************************************
* Author: Dillon Wall
* Filename: "Weapon.h"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#pragma once
#include "Item.h"

/************************************************************************
* Class: Weapon
*
* Purpose: Represents a weapon item
*
* Manager functions:
* 	Weapon();
*	Weapon(String name, String description, int attack, String cost, int itemID);
*	Weapon(const Weapon& other);
*	~Weapon();
*	Weapon& operator=(const Weapon& rhs);
*	bool operator==(const Weapon& rhs) const;
*
* Methods:
* 	int GetAttack() const;
*	void SetAttack(int attack);
*	virtual void Display() override;
*	static void Init();
*		initialize static variables
*	static void Purge();
*		purge static variables
*
*************************************************************************/

class Weapon :
	public Item
{
public:
	enum WEAPONS : int { RUSTED = 0, IRON = 1, SILVER = 2, EXCALIBUR = 3 };

	Weapon();
	Weapon(String name, String description, int attack, String cost, int itemID);
	Weapon(const Weapon& other);
	~Weapon();
	Weapon& operator=(const Weapon& rhs);
	bool operator==(const Weapon& rhs) const;

	int GetAttack() const;
	void SetAttack(int attack);

	virtual void Display() override;

	static void Init();
	static void Purge();

	static Weapon ** weaponList;
	static const int NUM_WEAPONS = 4;

private:
	int m_attack;
};

