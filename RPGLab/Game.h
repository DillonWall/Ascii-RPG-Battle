/*************************************************************
* Author: Dillon Wall
* Filename: "Game.h"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#pragma once

#include "GameState.h"
#include "MainMenu.h"
#include "LoadMenu.h"
#include "NewGame.h"
#include "Fight.h"
#include "Shop.h"
#include "Character.h"
#include "Spell.h"
#include "Potion.h"

/************************************************************************
* Class: Game
*
* Purpose: Game object which manages the other classes and gamestates
*
* Manager functions:
* 	Game();
*	~Game();
*
* Methods:
* 	bool Update(char key);
* 		calls the current gamestate's update function
*	void Display();
*		calls the current gamestate's display function
*	void SetCurrentCharPos(int pos);
*	void SetChar(Character * c, int pos = -1);
*		sets the character at the desired position to the passed character pointer, when pos is -1 (default val) it will replace current char
*	void Save();
*		saves the game
*	Character * GetChar(int pos) const;
*	Character * GetCurrentChar() const;
*	void ExitGame();
*		signals flag to exit game
*
*************************************************************************/

class Game
{
public:
	Game();
	~Game();

	bool Update(char key);
	void Display();

	void SetCurrentCharPos(int pos);
	void SetChar(Character * c, int pos = -1);
	void Save();
	Character * GetChar(int pos) const;
	Character * GetCurrentChar() const;	
	void ExitGame();

	static const char * FILE_NAME;
	static const int NUM_CHARS;
	static const int ERR_FILE_NOT_FOUND;
	static const int NUM_CONSOLE_LINES;
private:
	Character ** LoadChars(int numChars);
	void SaveChars(Character ** c, int numChars);

	int m_currentChar;
	Character ** m_characters;

	bool m_shouldExit;
};

