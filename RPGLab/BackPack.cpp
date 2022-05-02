/*************************************************************
* Author: Dillon Wall
* Filename: BackPack.cpp
* Date Created: 11/13/18
* Modifications:
**************************************************************/

#include "BackPack.h"



BackPack::BackPack() : m_items(DynamicArray<Item>())
{
}

BackPack::BackPack(DynamicArray<Item> potions) : m_items(potions)
{
}


BackPack::~BackPack()
{
}

BackPack::BackPack(const BackPack & other) : m_items(DynamicArray<Item>(other.m_items))
{
}

BackPack & BackPack::operator=(const BackPack & rhs)
{
	if (this != &rhs)
	{
		//purge

		m_items = DynamicArray<Item>(rhs.m_items);
	}

	return *this;
}

void BackPack::AddItem(Item * p)
{
	m_items.Insert(p);
}

void BackPack::RemoveItem(Item * p)
{
	m_items.Delete(p);
}

DynamicArray<Item> BackPack::GetItemArray() const
{
	return m_items;
}

void BackPack::Display() const
{
	m_items.Display();
}
