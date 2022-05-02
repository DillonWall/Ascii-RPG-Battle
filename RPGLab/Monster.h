/*************************************************************
* Author: Dillon Wall
* Filename: "Monster.h"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#pragma once

#include "String.h"

/************************************************************************
* Class: Monster
*
* Purpose: A base class for monsters that handles basic monster functionality
*
* Manager functions:
*	Monster(String name, int maxHealth, int health, int maxMana, int mana, int attack, int defense, int speed, String money);
*	virtual ~Monster();
*
* Methods:
* 	virtual void Display() = 0;
*		displays the monster (must be 16 lines)
* 	void Hit(int damage);
* 		subtracts damage from health
*
*************************************************************************/

class Monster
{
public:
	Monster(String name, int maxHealth, int health, int maxMana, int mana, int attack, int defense, int speed, String money);
	virtual ~Monster();

	virtual void Display() = 0;

	String GetName() const;
	int GetHealth() const;
	int GetMaxHealth() const;
	int GetMana() const;
	int GetMaxMana() const;
	int GetAttack() const;
	int GetDefense() const;
	int GetSpeed() const;
	String GetMoney() const;
	void SetHealth(int health);
	void SetMana(int mana);
	void Hit(int damage);

	static const int NUM_MONSTERS = 10;

protected:
	String m_name, m_money;
	int m_maxHealth, m_health, m_maxMana, m_mana, m_attack, m_defense, m_speed;
};

