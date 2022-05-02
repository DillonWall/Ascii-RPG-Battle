/*************************************************************
* Author: Dillon Wall
* Filename: "Medusa.h"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#pragma once
#include "Monster.h"

/************************************************************************
* Class: Medusa
*
* Purpose: A type of monster object the play can fight
*
* Manager functions:
*	Medusa();
*	~Medusa();
*
* Methods:
* 	virtual void Display() override;
*
*************************************************************************/

class Medusa :
	public Monster
{
public:
	Medusa();
	~Medusa();

	// Inherited via Monster
	virtual void Display() override;
};

