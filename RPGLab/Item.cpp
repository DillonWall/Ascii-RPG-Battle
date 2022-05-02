/*************************************************************
* Author: Dillon Wall
* Filename: "Item.cpp"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#include "Item.h"



Item::Item() : m_name(""), m_description(""), m_cost("0.0.0.0"), m_type(0), m_itemID(00)
{
}

Item::Item(String name, String description, String cost, int type, int itemID) : m_name(name), m_description(description), m_cost(cost), m_type(type), m_itemID(itemID)
{
}


Item::~Item()
{
}

Item::Item(const Item & other) : m_name(other.m_name), m_description(other.m_description), m_cost(other.m_cost), m_type(other.m_type), m_itemID(other.m_itemID)
{
}

Item & Item::operator=(const Item & rhs)
{
	if (this != &rhs) {
		//purge

		m_name = rhs.m_name;
		m_description = rhs.m_description;
		m_cost = rhs.m_cost;
		m_type = rhs.m_type;
		m_itemID = rhs.m_itemID;
	}

	return *this;
}

bool Item::operator==(const Item & rhs) const
{
	//I could also just check itemID
	return (m_cost == rhs.m_cost &&
			m_description == rhs.m_description &&
			m_name == rhs.m_name &&
			m_type == rhs.m_type &&
			m_itemID == rhs.m_itemID);
}

String Item::GetName() const
{
	return m_name;
}

void Item::SetName(String name)
{
	m_name = name;
}

String Item::GetDescription() const
{
	return m_description;
}

void Item::SetDescription(String description)
{
	m_description = description;
}

String Item::GetCost() const
{
	return m_cost;
}

void Item::SetCost(String cost)
{
	m_cost = cost;
}

int Item::GetType() const
{
	return m_type;
}

int Item::GetItemID() const
{
	return m_itemID;
}

String * Item::CostToDisplayString(String cost)
{

	String money[4] = { String('0'), String('0'), String('0'), String('0') };

	String temp = String(cost); //copy so cost isnt tampered
	char * pch = strtok(temp.GetCharArr(), ".");
	money[0] = String(pch);
	for (int i = 1; i < 4; ++i)
	{
		pch = strtok(NULL, ".");
		money[i] = String(pch);
	}

	char * outChrBuffer = new char[255];
	strcpy(outChrBuffer, money[0].GetCharArr());
	strcat(outChrBuffer, " platinum, ");
	strcat(outChrBuffer, money[1].GetCharArr());
	strcat(outChrBuffer, " gold, ");
	strcat(outChrBuffer, money[2].GetCharArr());
	strcat(outChrBuffer, " silver, ");
	strcat(outChrBuffer, money[3].GetCharArr());
	strcat(outChrBuffer, " copper");
	String * output = new String(outChrBuffer);

	//release memory created
	delete[] outChrBuffer;

	return output;
}