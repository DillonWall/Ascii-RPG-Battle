/*************************************************************
* Author: Dillon Wall
* Filename: "Minotaur.h"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#pragma once
#include "Monster.h"

/************************************************************************
* Class: Minotaur
*
* Purpose: A type of monster object the play can fight
*
* Manager functions:
*	Minotaur();
*	~Minotaur();
*
* Methods:
* 	virtual void Display() override;
*
*************************************************************************/

class Minotaur :
	public Monster
{
public:
	Minotaur();
	~Minotaur();

	// Inherited via Monster
	virtual void Display() override;
};

