/*************************************************************
* Author: Dillon Wall
* Filename: "Weapon.cpp"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#include "Weapon.h"

#include <iostream>
using std::cout;
using std::endl;

Weapon ** Weapon::weaponList;

Weapon::Weapon() : Item(), m_attack(0)
{
}

Weapon::Weapon(String name, String description, int attack, String cost, int itemID) : Item(name, description, cost, WEAPON, itemID), m_attack(attack)
{
}

Weapon::Weapon(const Weapon & other) : Item(other), m_attack(other.m_attack)
{
}


Weapon::~Weapon()
{
}

Weapon & Weapon::operator=(const Weapon & rhs)
{
	Item::operator=(rhs);

	if (this != &rhs) {
		//purge

		m_attack = rhs.m_attack;
	}

	return *this;
}

bool Weapon::operator==(const Weapon & rhs) const
{
	return (Item::operator==(rhs) && m_attack == rhs.m_attack);
}

int Weapon::GetAttack() const
{
	return m_attack;
}

void Weapon::SetAttack(int attack)
{
	m_attack = attack;
}

void Weapon::Display()
{
	String * costDString = Item::CostToDisplayString(m_cost);

	cout << "      /| ________________   " << "Name: "; m_name.Display();
	cout << "O|===|* >________________>  " << "Attack: " << m_attack << endl;
	cout << "      \\|                    " << "Cost: "; costDString->Display();
	cout << "                            " << endl <<
	"Description: "; m_description.Display();

	delete costDString;
}

void Weapon::Init()
{
	weaponList = new Weapon*[NUM_WEAPONS];
	weaponList[RUSTED] = new Weapon("Rusted Shortsword", "A rusty shortened sword made of copper; however, anything is better than nothing.", 2, "0.0.10.0", ID_RUSTED);
	weaponList[IRON] = new Weapon("Iron Longsword", "Your standard and traditional battle-ready sword; this will help a fair amount.", 5, "0.1.50.0", ID_IRON);
	weaponList[SILVER] = new Weapon("Silver Broadsword", "A sword with a widened blade commonly seen wielded by knights of the Silver Rose; its attack is considerably strong.", 10, "0.25.0.0", ID_SILVER);
	weaponList[EXCALIBUR] = new Weapon("Excalibur", "The legendary sword orginally wielded by King Arthur; its power radiates within you.", 20, "1.15.0.0", ID_EXCALIBUR);
}

void Weapon::Purge()
{
	for (int i = 0; i < NUM_WEAPONS; ++i)
	{
		delete weaponList[i];
	}

	delete[] weaponList;
}
