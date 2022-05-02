/*************************************************************
* Author: Dillon Wall
* Filename: "Fight.h"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#pragma once
#include "GameState.h"
#include "Game.h"
#include "Monster.h"
#include "Character.h"
#include "LinkedList.h"
#include "Rand.h"

#include "Dragon.h"
#include "DarkKnight.h"
#include "Minotaur.h"
#include "Vampire.h"
#include "Enchantress.h"
#include "Goblin.h"
#include "Gryphon.h"
#include "Medusa.h"
#include "Skeleton.h"
#include "Sphinx.h"

/************************************************************************
* Class: Fight
*
* Purpose: Functionality for fights, is a gamestate
*
* Manager functions:
* 	Fight(Game * g);
	~Fight();
*
* Methods:
* 	virtual void Update(char key) override;
* 		updates based on actions
*	virtual void Display() override;
*		displays fight to screen
*
*	void DisplayDialog();
*		helper function displays the current dialog
*	void Init();
*		initializes variables and makes ready for a fight
*	void Reset();
*		resets so new fight can be played
*
*************************************************************************/

class Fight :
	public GameState
{
public:
	enum DIALOGS : int {ENCOUNTER = 0, SELECT_CHOICE = 1, ENEMY_ATTACK = 2, CHAR_ATTACK = 3, END_BATTLE = 4};
	enum MENUS : int {M_FIGHT = 0, M_MAGIC = 1, M_ITEMS = 2, M_STATS = 3};
	enum FIGHT_SELECTIONS : int {ATTACK = 0, MAGIC = 1, BLOCK = 2, BERSERK = 3, ITEMS = 4, STATS = 5};
	enum ITEM_SELECTIONS : int { I_USE = 0, I_INSPECT = 1, I_TOSS = 2 };
	enum MAGIC_SELECTIONS : int { MAG_CAST = 0, MAG_INSPECT = 1 };

	Fight(Game * g);
	~Fight();

	// Inherited via GameState
	virtual void Update(char key) override;
	virtual void Display() override;

	void DisplayDialog();
	void Init();
	void Reset();

private:
	void SetMonster();

	LinkedList<Monster*> m_monsterList;
	Monster * m_monster;
	Character * m_character;
	bool m_inDialog;
	int m_currentDialog;
	int m_currentSelection, m_currentListSelection;
	int m_currentMenu;

	int m_lastDmgDealtToChar;
	int m_lastDmgDealtToEnemy;

	bool m_isBlocking, m_isBerserking, m_listElementSelected, m_inspectingListElement;
};

