/*************************************************************
* Author: Dillon Wall
* Filename: "Dragon.h"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#pragma once
#include "Monster.h"

/************************************************************************
* Class: Dragon
*
* Purpose: A type of monster object the play can fight
*
* Manager functions:
*	Dragon();
*	~Dragon();
*
* Methods:
* 	virtual void Display() override;
*
*************************************************************************/

class Dragon :
	public Monster
{
public:
	Dragon();
	~Dragon();

	// Inherited via Monster
	virtual void Display() override;
};

