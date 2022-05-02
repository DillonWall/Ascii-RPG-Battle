/*************************************************************
* Author: Dillon Wall
* Filename: "Gryphon.h"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#pragma once
#include "Monster.h"

/************************************************************************
* Class: Gryphon
*
* Purpose: A type of monster object the play can fight
*
* Manager functions:
*	Gryphon();
*	~Gryphon();
*
* Methods:
* 	virtual void Display() override;
*
*************************************************************************/

class Gryphon :
	public Monster
{
public:
	Gryphon();
	~Gryphon();

	// Inherited via Monster
	virtual void Display() override;
};

