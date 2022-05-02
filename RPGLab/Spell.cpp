/*************************************************************
* Author: Dillon Wall
* Filename: "Spell.cpp"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#include "Spell.h"

#include <iostream>
#include "Item.h"
using std::cout;
using std::endl;

Spell ** Spell::spellList;

Spell::Spell() : m_name(""), m_description(""), m_cost("0.0.0.0"), m_mana(0), m_damage(0)
{
}

Spell::Spell(String name, String description, String cost, int mana, int damage, int spellID) : m_name(name), m_description(description), m_cost(cost), m_mana(mana), m_damage(damage), m_spellID(spellID)
{
}


Spell::~Spell()
{
}

Spell::Spell(const Spell & other) : m_name(other.m_name), m_description(other.m_description), m_cost(other.m_cost), m_mana(other.m_mana), m_damage(other.m_damage)
{
}

Spell & Spell::operator=(const Spell & rhs)
{
	if (this != &rhs) {
		//purge

		m_name = rhs.m_name;
		m_description = rhs.m_description;
		m_cost = rhs.m_cost;
		m_mana = rhs.m_mana;
		m_damage = rhs.m_damage;
	}

	return *this;
}

bool Spell::operator==(const Spell & rhs) const
{
	return (m_cost == rhs.m_cost &&
		m_description == rhs.m_description &&
		m_name == rhs.m_name &&
		m_mana == rhs.m_mana &&
		m_damage == rhs.m_damage);
}

String Spell::GetName() const
{
	return m_name;
}

void Spell::SetName(String name)
{
	m_name = name;
}

String Spell::GetDescription() const
{
	return m_description;
}

void Spell::SetDescription(String description)
{
	m_description = description;
}

String Spell::GetCost() const
{
	return m_cost;
}

void Spell::SetCost(String cost)
{
	m_cost = cost;
}

int Spell::GetMana() const
{
	return m_mana;
}

void Spell::SetMana(int mana)
{
	m_mana = mana;
}

int Spell::GetDamage() const
{
	return m_damage;
}

void Spell::SetDamage(int damage)
{
	m_damage = damage;
}

int Spell::GetSpellID() const
{
	return m_spellID;
}

void Spell::Display()
{
	String * costDString = Item::CostToDisplayString(m_cost);

	cout << "   _____________      " << "Name: "; m_name.Display();
	cout << " / \\            \\.    " << "Mana Cost: " << m_mana << endl;
	cout << "|   | ~~ ~  ~~~ |.    " << "Damage: " << m_damage << endl;
	cout << " \\_ |   ~~   ~~ |.    " << "Cost: "; costDString->Display();
	cout << "    |   ________|___  " << endl;
	cout << "    |  /           /. " << endl;
	cout << "    \\_/___________/. " << endl << endl <<
			"Description: "; m_description.Display();

	delete costDString;
}

void Spell::Init()
{
	spellList = new Spell*[NUM_SPELLS];
	spellList[FIREBOLT] = new Spell("FireBolt", "You cast the elements of fire to burn your foe.", "0.1.0.0", 4, 7, FIREBOLT);
	spellList[FIREBALL] = new Spell("FireBall", "You store the elements of fire into a large gaseous ball and hurl it at your foe.", "0.10.0.0", 10, 15, FIREBALL);
	spellList[METEOR] = new Spell("Meteor", "You summon meteors from the heavens to strike your foe.", "1.0.0.0", 20, 30, METEOR);
	spellList[SHOCK] = new Spell("Shock", "You cast the elements of lightning to shock your foe.", "0.2.0.0", 5, 10, SHOCK);
	spellList[THUNDER] = new Spell("Thunder", "You summon a cloud of thunder to strike your foe.", "0.20.0.0", 12, 18, THUNDER);
	spellList[FREEZE] = new Spell("Freeze", "You cast the elements of ice to freeze your foe.", "0.5.0.0", 7, 12, FREEZE);
	spellList[JUDGEMENT] = new Spell("Judgement", "An illuminating sword plummets from the heavens to vanquish your foe.", "8.0.0.0", 20, 50, JUDGEMENT);
}

void Spell::Purge()
{
	for (int i = 0; i < NUM_SPELLS; ++i)
	{
		delete spellList[i];
	}

	delete[] spellList;
}