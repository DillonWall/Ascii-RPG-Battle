/*************************************************************
* Author: Dillon Wall
* Filename: CoinPouch.h
* Date Created: 11/13/18
* Modifications:
*				- 11/29/18 - Added >= operator and fixed memory leak issues
**************************************************************/

#pragma once
#include "String.h"

/************************************************************************
* Class: CoinPouch
*
* Purpose: This class is used to hold a String representing an amount of money
*
* Manager functions:
*	CoinPouch();
*		Default ctor initializes m_money to "0.0.0.0"
*	CoinPouch(String money);
*	~CoinPouch();
*	CoinPouch(const CoinPouch& other);
*	CoinPouch& operator=(const CoinPouch& rhs);
*
* Methods:
*
*	void GainMoney(const String& money);
*		This function adds a String of money to m_money, by calling ModMoney and adding 
*	void SpendMoney(const String& money);
*		This function subtracts a String of money from m_money, by calling ModMoney and subtracting
*	String GetMoney() const;
*		Returns m_money
*	void Display() const;
*		Calls DynamicArray's Display function
*
*	void ModMoney(const String& money, int polarity);
*		Either adds or subtracts from m_money based on an int polarity (1 = add, -1 = sub)
*		Note: If polarity is not 1 or -1 it will multiply the amount it adds/subtracts by
*
*************************************************************************/

class CoinPouch
{
public:
	CoinPouch();
	CoinPouch(String money);
	~CoinPouch();
	CoinPouch(const CoinPouch& other);
	CoinPouch& operator=(const CoinPouch& rhs);
	
	void GainMoney(const String& money);
	void SpendMoney(const String& money);
	String GetMoney() const;
	void Display() const;

	bool operator>=(const String& rhs);
private:
	void ModMoney(const String& money, int polarity);

	String m_money;
};

