/*************************************************************
* Author: Dillon Wall
* Filename: "Monster.cpp"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#include "Monster.h"



Monster::Monster(String name, int maxHealth, int health, int maxMana, int mana, int attack, int defense, int speed, String money) : m_name(name), m_maxHealth(maxHealth), 
					m_health(health), m_maxMana(maxMana), m_mana(mana), m_attack(attack), m_defense(defense), m_speed(speed), m_money(money)
{
}


Monster::~Monster()
{
}

String Monster::GetName() const
{
	return m_name;
}

int Monster::GetHealth() const
{
	return m_health;
}

int Monster::GetMaxHealth() const
{
	return m_maxHealth;
}

int Monster::GetMana() const
{
	return m_mana;
}

int Monster::GetMaxMana() const
{
	return m_maxMana;
}

int Monster::GetAttack() const
{
	return m_attack;
}

int Monster::GetDefense() const
{
	return m_defense;
}

int Monster::GetSpeed() const
{
	return m_speed;
}

String Monster::GetMoney() const
{
	return m_money;
}

void Monster::SetHealth(int health)
{
	m_health = health;
}

void Monster::SetMana(int mana)
{
	m_mana = mana;
}

void Monster::Hit(int damage)
{
	m_health -= damage;
}
