/*************************************************************
* Author: Dillon Wall
* Filename: "Vampire.h"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#pragma once
#include "Monster.h"

/************************************************************************
* Class: Vampire
*
* Purpose: A type of monster object the play can fight
*
* Manager functions:
*	Vampire();
*	~Vampire();
*
* Methods:
* 	virtual void Display() override;
*
*************************************************************************/

class Vampire :
	public Monster
{
public:
	Vampire();
	~Vampire();

	// Inherited via Monster
	virtual void Display() override;
};

