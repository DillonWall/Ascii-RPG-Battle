/*************************************************************
* Author: Dillon Wall
* Filename: "LoadMenu.h"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#pragma once
#include "GameState.h"
#include "Game.h"

/************************************************************************
* Class: LoadMenu
*
* Purpose: Load menu gamestate, able to select and load files
*
* Manager functions:
* 	LoadMenu(Game * g);
*	~LoadMenu();
*
* Methods:
* 	virtual void Update(char key) override;
* 		updates menu
*	virtual void Display() override;
*		displays menu
*
*************************************************************************/

class LoadMenu :
	public GameState
{
public:
	LoadMenu(Game * g);
	~LoadMenu();

	// Inherited via GameState
	virtual void Update(char key) override;
	virtual void Display() override;

private:
	int m_selection;
};

