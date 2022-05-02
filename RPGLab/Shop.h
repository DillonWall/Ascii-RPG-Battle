/*************************************************************
* Author: Dillon Wall
* Filename: "Shop.h"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#pragma once
#include "GameState.h"
#include "Game.h"
#include "Character.h"

/************************************************************************
* Class: Shop
*
* Purpose: Shop gamestate, controls functionality of the shop and is entered after a fight (whether win or lose)
*
* Manager functions:
* 	Shop(Game * g);
*	~Shop();
*
* Methods:
* 	virtual void Update(char key) override;
*	virtual void Display() override;
*
*	void Init();
*		initializes variables
*
*************************************************************************/

class Shop :
	public GameState
{
public:
	enum MENUS : int {MAIN = 0, BUY = 1, TRAIN = 2};
	enum MAIN_SELECTIONS : int {M_BUY = 0, M_TRAIN = 1, M_CONTINUE = 2};
	enum BUY_SELECTIONS : int {B_WEAPONS = 0, B_ARMOR = 1, B_POTIONS = 2};
	enum ACTIONS : int {A_BUY = 0, A_INSPECT = 1};

	Shop(Game * g);
	~Shop();

	// Inherited via GameState
	virtual void Update(char key) override;
	virtual void Display() override;

	void Init();

	const int BACKPACK_SPACE = 9;

private:
	
	Character * m_character;

	int m_currentMainSelection, m_currentTabSelection, m_currentListSelection, m_currentAction;
	int m_currentMenu;
	bool m_inList, m_inActions, m_isInspecting;
};

