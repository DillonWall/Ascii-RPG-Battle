/*************************************************************
* Author: Dillon Wall
* Filename: Potion.cpp
* Date Created: 10/1/18
* Modifications:
*			- 10/10/18 - Updated to account for new String class
						 and made potency alway go to uppcase
*			- 10/16/18 - Added operator== and renamed functions to fit standard
**************************************************************/

#include "Potion.h"

#include <iostream>
using std::cout;
using std::endl;

Potion ** Potion::potionList;

Potion::Potion() : Item(), m_potency(0)
{
}

Potion::Potion(String name, String description, int potency, String cost, int type, int itemID) : Item(name, description, cost, type, itemID), m_potency(potency)
{
}

Potion::Potion(const Potion & other) : Item(other), m_potency(other.m_potency)
{
}


Potion::~Potion()
{
}

Potion & Potion::operator=(const Potion & rhs)
{
	Item::operator=(rhs);

	if (this != &rhs) {
		//purge

		m_potency = rhs.m_potency;
	}

	return *this;
}

bool Potion::operator==(const Potion & rhs) const
{
	return (Item::operator==(rhs) && m_potency == rhs.m_potency);
}

int Potion::GetPotency() const
{
	return m_potency;
}

void Potion::SetPotency(int potency)
{
	m_potency = potency;
}

void Potion::Display()
{
	String * costDString = Item::CostToDisplayString(m_cost);

	cout << "   |~|   " << "Name: "; m_name.Display();
	cout << "   | |   " << "Potency: " << m_potency << endl;
	cout << " .'   `. " << "Cost: "; costDString->Display();
	cout << " `.___.' " << endl << endl <<
			"Description: "; m_description.Display();

	delete costDString;
}

void Potion::Init()
{
	potionList = new Potion*[NUM_POTIONS];
	potionList[MINOR_HEAL] = new Potion("Minor Healing Potion", "A small vial of a strange red liquid; the liquid is tasty and makes you feel warm.", 5, "0.0.25.0", HEALING, ID_MINOR_HEAL);
	potionList[MINOR_MANA] = new Potion("Minor Mana Potion", "A small vial of a strange blue liquid; the liquid invigorates you and makes you feel powerful.", 5, "0.0.25.0", MANA_RECOVER, ID_MINOR_MANA);
	potionList[HEAL] = new Potion("Healing Potion", "A flask of red liquid; the liquid is tasty and makes you feel warm.", 10, "0.1.0.0", HEALING, ID_HEAL);
	potionList[MANA] = new Potion("Mana Potion", "A flask of blue liquid; the liquid invigorates you and makes you feel powerful", 10, "0.1.0.0", MANA_RECOVER, ID_MANA);
}

void Potion::Purge()
{
	for (int i = 0; i < NUM_POTIONS; ++i)
	{
		delete potionList[i];
	}

	delete[] potionList;
}