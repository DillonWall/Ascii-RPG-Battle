/*************************************************************
* Author: Dillon Wall
* Filename: "NewGame.h"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#pragma once
#include "GameState.h"
#include "Game.h"

/************************************************************************
* Class: NewGame
*
* Purpose: New game gamestate, is entered upon selecting new game in the main menu and starts a fight after making character
*
* Manager functions:
* 	NewGame(Game * g);
*	~NewGame();
*
* Methods:
* 	virtual void Update(char key) override;
*	virtual void Display() override;
*
*************************************************************************/

class NewGame :
	public GameState
{
public:
	NewGame(Game * g);
	~NewGame();

	// Inherited via GameState
	virtual void Update(char key) override;
	virtual void Display() override;
};

