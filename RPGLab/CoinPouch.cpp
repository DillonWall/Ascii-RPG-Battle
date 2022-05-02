/*************************************************************
* Author: Dillon Wall
* Filename: CoinPouch.cpp
* Date Created: 11/13/18
* Modifications:
**************************************************************/

#include "CoinPouch.h"



CoinPouch::CoinPouch() : m_money(String("0.0.0.0"))
{
}

CoinPouch::CoinPouch(String money) : m_money(money)
{
}


CoinPouch::~CoinPouch()
{
}

CoinPouch::CoinPouch(const CoinPouch & other) : m_money(String(other.m_money))
{
}

CoinPouch & CoinPouch::operator=(const CoinPouch & rhs)
{
	if (this != &rhs)
	{
		//purge

		m_money = String(rhs.m_money);
	}

	return *this;
}

void CoinPouch::GainMoney(const String & money)
{
	ModMoney(money, 1);
}

void CoinPouch::SpendMoney(const String & money)
{
	ModMoney(money, -1);
}

String CoinPouch::GetMoney() const
{
	return m_money;
}

void CoinPouch::Display() const
{
	m_money.Display();
}

bool CoinPouch::operator>=(const String & rhs)
{
	String coins[4] = { String('0'), String('0'), String('0'), String('0') };
	int costs1[4] = { 0,0,0,0 };
	int costs2[4] = { 0,0,0,0 };

	//split both costs
	String temp = String(m_money); //copy so cost1 isnt tampered
	char * pch = strtok(temp.GetCharArr(), ".");
	costs1[0] = std::atoi(pch);
	for (int i = 1; i < 4; ++i)
	{
		pch = strtok(NULL, ".");
		costs1[i] = std::atoi(pch);
	}

	temp = String(rhs); //copy so cost2 isnt tampered
	pch = strtok(temp.GetCharArr(), ".");
	costs2[0] = std::atoi(pch);
	for (int i = 1; i < 4; ++i)
	{
		pch = strtok(NULL, ".");
		costs2[i] = std::atoi(pch);
	}

	bool retVal = true;
	if (costs1[0] < costs2[0]) retVal = false;
	else if (costs1[0] == costs2[0])
	{
		if (costs1[1] < costs2[1]) retVal = false;
		else if (costs1[1] == costs2[1])
		{
			if (costs1[2] < costs2[2]) retVal = false;
			else if (costs1[3] == costs2[3])
			{
				if (costs1[3] < costs2[3]) retVal = false;
			}
		}
	}


	return retVal;
}

void CoinPouch::ModMoney(const String & money, int polarity)
{
	String coins[4] = { String('0'), String('0'), String('0'), String('0') };
	int costs1[4] = { 0,0,0,0 };
	int costs2[4] = { 0,0,0,0 };

	//split both costs
	String temp = String(m_money); //copy so cost1 isnt tampered
	char * pch = strtok(temp.GetCharArr(), ".");
	costs1[0] = std::atoi(pch);
	for (int i = 1; i < 4; ++i)
	{
		pch = strtok(NULL, ".");
		costs1[i] = std::atoi(pch);
	}

	temp = String(money); //copy so cost2 isnt tampered
	pch = strtok(temp.GetCharArr(), ".");
	costs2[0] = std::atoi(pch);
	for (int i = 1; i < 4; ++i)
	{
		pch = strtok(NULL, ".");
		costs2[i] = std::atoi(pch);
	}

	for (int i = 0; i < 4; ++i) {

		int amt1 = costs1[i];

		int amt2 = costs2[i];

		//check for correction
		int total = amt1 + (polarity * amt2);
		if (i > 0) {
			while (total > 99 || total < 0) { //while instead of if in case the user want to do something like 300 copper + 200 copper
				//carry the 1
				if (total > 99)
				{
					coins[i - 1] = String::itos(std::atoi(coins[i - 1].GetCharArr()) + 1);
					total -= 100;
				}
				else if (total < 0)
				{
					coins[i - 1] = String::itos(std::atoi(coins[i - 1].GetCharArr()) - 1);
					total += 100;
				}
			}
		}

		coins[i] = String(String::itos(total));
	}

	m_money = coins[0] + "." + coins[1] + "." + coins[2] + "." + coins[3];
}
