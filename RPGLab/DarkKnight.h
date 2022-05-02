/*************************************************************
* Author: Dillon Wall
* Filename: "DarkKnight.h"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#pragma once
#include "Monster.h"

/************************************************************************
* Class: DarkKnight
*
* Purpose: A type of monster object the play can fight
*
* Manager functions:
*	DarkKnight();
*	~DarkKnight();
*
* Methods:
* 	virtual void Display() override;
*
*************************************************************************/

class DarkKnight :
	public Monster
{
public:
	DarkKnight();
	~DarkKnight();

	// Inherited via Monster
	virtual void Display() override;
};

