/*************************************************************
* Author: Dillon Wall
* Filename: "Goblin.h"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#pragma once
#include "Monster.h"

/************************************************************************
* Class: Goblin
*
* Purpose: A type of monster object the play can fight
*
* Manager functions:
*	Goblin();
*	~Goblin();
*
* Methods:
* 	virtual void Display() override;
*
*************************************************************************/

class Goblin :
	public Monster
{
public:
	Goblin();
	~Goblin();

	// Inherited via Monster
	virtual void Display() override;
};

