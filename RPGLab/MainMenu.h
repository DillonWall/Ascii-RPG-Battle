/*************************************************************
* Author: Dillon Wall
* Filename: "MainMenu.h"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#pragma once
#include "GameState.h"
#include "Game.h"

/************************************************************************
* Class: MainMenu
*
* Purpose: Main menu gamestate, shows main menu options
*
* Manager functions:
* 	MainMenu(Game * g);
*	~MainMenu();
*
* Methods:
* 	virtual void Update(char key) override;
*	virtual void Display() override;
*
*************************************************************************/

class MainMenu :
	public GameState
{
public:
	enum SELECTION : int {NEW_GAME = 0, LOAD_GAME = 1, EXIT = 2};

	MainMenu(Game * g);
	~MainMenu();

	// Inherited via GameState
	virtual void Update(char key) override;
	virtual void Display() override;

private:
	int m_selection;
};

