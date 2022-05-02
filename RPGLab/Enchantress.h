/*************************************************************
* Author: Dillon Wall
* Filename: "Enchantress.h"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#pragma once
#include "Monster.h"

/************************************************************************
* Class: Enchantress
*
* Purpose: A type of monster object the play can fight
*
* Manager functions:
*	Enchantress();
*	~Enchantress();
*
* Methods:
* 	virtual void Display() override;
*
*************************************************************************/

class Enchantress :
	public Monster
{
public:
	Enchantress();
	~Enchantress();

	// Inherited via Monster
	virtual void Display() override;
};

