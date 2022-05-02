/*************************************************************
* Author: Dillon Wall
* Filename: "Armor.cpp"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#include "Armor.h"

#include <iostream>
using std::cout;
using std::endl;

Armor ** Armor::armorList;

Armor::Armor() : Item(), m_defense(0)
{
}

Armor::Armor(String name, String description, int defense, String cost, int itemID) : Item(name, description, cost, ARMOR, itemID), m_defense(defense)
{
}

Armor::Armor(const Armor & other) : Item(other), m_defense(other.m_defense)
{
}


Armor::~Armor()
{
}

Armor & Armor::operator=(const Armor & rhs)
{
	Item::operator=(rhs);

	if (this != &rhs) {
		//purge

		m_defense = rhs.m_defense;
	}

	return *this;
}

bool Armor::operator==(const Armor & rhs) const
{
	return (Item::operator==(rhs) && m_defense == rhs.m_defense);
}

int Armor::GetDefense() const
{
	return m_defense;
}

void Armor::SetDefense(int defense)
{
	m_defense = defense;
}

void Armor::Display()
{
	String * costDString = Item::CostToDisplayString(m_cost);

	cout << "  |`-._/\\_.-`|  " << "Name: "; m_name.Display();
	cout << "  |    ||    |  " << "Defense: " << m_defense << endl; 
	cout << "  |___o()o___|  " << "Cost: "; costDString->Display();
	cout << "  |__((<>))__|  " << endl;
	cout << "  \\   o\\/o   /" << endl <<
			"   \\   ||   /" << endl <<
			"    \\  ||  /" << endl <<
			"     '.||.'" << endl <<
			"       ``" << endl << endl <<
			"Description: "; m_description.Display();

	delete costDString;
}

void Armor::Init()
{
	armorList = new Armor*[NUM_ARMORS];
	armorList[BUCKLER] = new Armor("Leather Buckler", "A small shield made of leather, with a small amount of protection; however, anything is better than nothing.", 2, "0.0.10.0", ID_BUCKLER);
	armorList[HEATER] = new Armor("Heather Shield", "A more standard shield; this will protect for a fair amount.", 5, "0.1.50.0", ID_HEATER);
	armorList[KITE] = new Armor("Kite Shield", "An elongated shield, commonly seen wielded by knights; its defense is considerably strong.", 10, "0.25.0.0", ID_KITE);
	armorList[WYNEBERG] = new Armor("Wyneberg", "The legendary shield orginally wielded by King Arthur; its power radiates within you", 25, "1.15.0.0", ID_WYNEBERG);
}

void Armor::Purge()
{
	for (int i = 0; i < NUM_ARMORS; ++i)
	{
		delete armorList[i];
	}

	delete[] armorList;
}
