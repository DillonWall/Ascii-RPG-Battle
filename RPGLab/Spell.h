/*************************************************************
* Author: Dillon Wall
* Filename: "Spell.h"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#pragma once

#include "String.h"

/************************************************************************
* Class: Spell
*
* Purpose:	Represents a spell object
*
* Manager functions:
*	Spell();
*	Spell(String name, String description, String cost, int mana, int damage, int spellID);
*	~Spell();
*	Spell(const Spell& other);
*	Spell& operator=(const Spell& rhs);
*	bool operator==(const Spell& rhs) const;
*
* Methods:
* 	void Display();
*	static void Init();
*		Init static variables
*	static void Purge();
*		Purge static variables
*
*************************************************************************/

class Spell
{
public:
	enum SPELLS : int {FIREBOLT = 0, FIREBALL = 1, METEOR = 2, SHOCK = 3, THUNDER = 4, FREEZE = 5, JUDGEMENT = 6};

	Spell();
	Spell(String name, String description, String cost, int mana, int damage, int spellID);
	~Spell();
	Spell(const Spell& other);
	Spell& operator=(const Spell& rhs);
	bool operator==(const Spell& rhs) const;

	String GetName() const;
	void SetName(String name);
	String GetDescription() const;
	void SetDescription(String description);
	String GetCost() const;
	void SetCost(String cost);
	int GetMana() const;
	void SetMana(int mana);
	int GetDamage() const;
	void SetDamage(int damage);
	int GetSpellID() const;

	void Display();

	static void Init();
	static void Purge();

	static Spell ** spellList;
	static const int NUM_SPELLS = 7;

private:
	String m_name;
	String m_description;
	String m_cost;

	int m_mana;
	int m_damage;
	int m_spellID;
};

