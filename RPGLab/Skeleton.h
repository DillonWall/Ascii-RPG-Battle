/*************************************************************
* Author: Dillon Wall
* Filename: "Skeleton.h"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#pragma once
#include "Monster.h"

/************************************************************************
* Class: Skeleton
*
* Purpose: A type of monster object the play can fight
*
* Manager functions:
*	Skeleton();
*	~Skeleton();
*
* Methods:
* 	virtual void Display() override;
*
*************************************************************************/

class Skeleton :
	public Monster
{
public:
	Skeleton();
	~Skeleton();

	// Inherited via Monster
	virtual void Display() override;
};

