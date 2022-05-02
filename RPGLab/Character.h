/*************************************************************
* Author: Dillon Wall
* Filename: Character.h
* Date Created: 11/13/18
* Modifications:
*			- 11/29/18 - Added stats, equipment, and spells, and added getters and setters
**************************************************************/

#pragma once

#include "BackPack.h"
#include "CoinPouch.h"
#include "String.h"
#include "Armor.h"
#include "Weapon.h"
#include "Spell.h"

/************************************************************************
* Class: Character
*
* Purpose: This class is used to represent a game character
*
* Manager functions:
*	Character();
*		Default ctor calls each member variable's default ctor
*	Character(String name, BackPack backpack, CoinPouch coinpouch);
*	~Character();
*	Character(const Character& other);
*	Character& operator=(const Character& rhs);
*
* Methods:
*
*	void EquipWeapon(Weapon * weapon);
*		Setter for m_weapon
*	void EquipArmor(Armor * armor);
*		Setter for m_armor
*	void Display() const;
*		Calls Display function for name, coinpouch, and backpack with better formatting
*	int GetTotalAttack() const;
*		Gets attack + weapon attack
*	int GetTotalDefense() const;
*		Gets defense + armor defense
*	void ModMana(int modVal);
*		changes mana by some val
*	void ModHealth(int modVal);
*		changes health by some val
*	void Hit(int damage);
*		subtracts damage from health
*		
*
*************************************************************************/

class Character
{
public:
	Character();
	Character(String name);
	Character(String name, BackPack * backpack, CoinPouch * coinpouch);
	~Character();
	Character(const Character& other);
	Character& operator=(const Character& rhs);

	String GetName() const;
	BackPack * GetBackpack() const;
	CoinPouch * GetCoinpouch() const;
	Weapon * GetWeapon() const;
	Armor * GetArmor() const;
	DynamicArray<Spell> * GetSpellsArr() const;
	int GetMonsterNum() const;
	int GetHealth() const;
	int GetMaxHealth() const;
	int GetMana() const;
	int GetMaxMana() const;
	int GetAttack() const;
	int GetDefense() const;
	int GetSpeed() const;
	void SetName(String name);
	void SetBackpack(BackPack * bp);
	void SetCoinpouch(CoinPouch * cp);
	void EquipWeapon(Weapon * weapon);
	void EquipArmor(Armor * armor);
	void SetSpellsArr(DynamicArray<Spell> * spells);
	void SetMonsterNum(int num);
	void SetHealth(int health);
	void SetMaxHealth(int health);
	void SetMana(int mana);
	void SetMaxMana(int mana);
	void SetAttack(int attack);
	void SetDefense(int defense);
	void SetSpeed(int speed);

	int GetTotalAttack() const;
	int GetTotalDefense() const;
	void ModMana(int modVal);
	void ModHealth(int modVal);
	void Hit(int damage);

	void Display() const;
private:
	String m_name;
	BackPack * m_backpack;
	CoinPouch * m_coinpouch;
	Weapon * m_weapon;
	Armor * m_armor;
	DynamicArray<Spell> * m_spells;
	int m_monsterNum;
	int m_maxHealth, m_health, m_maxMana, m_mana, m_attack, m_defense, m_speed;
};

