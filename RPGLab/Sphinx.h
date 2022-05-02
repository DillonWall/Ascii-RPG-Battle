/*************************************************************
* Author: Dillon Wall
* Filename: "Sphinx.h"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#pragma once
#include "Monster.h"

/************************************************************************
* Class: Sphinx
*
* Purpose: A type of monster object the play can fight
*
* Manager functions:
*	Sphinx();
*	~Sphinx();
*
* Methods:
* 	virtual void Display() override;
*
*************************************************************************/

class Sphinx :
	public Monster
{
public:
	Sphinx();
	~Sphinx();

	// Inherited via Monster
	virtual void Display() override;
};

