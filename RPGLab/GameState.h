/*************************************************************
* Author: Dillon Wall
* Filename: "GameState.h"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#pragma once

class Game;

/************************************************************************
* Class: GameState
*
* Purpose: Base class for game states and also manager of gamestates
*
* Manager functions:
* 	GameState(Game * g);
*	virtual ~GameState();
*
* Methods:
* 	virtual void Update(char key) = 0;
* 		updates gamestate
*	virtual void Display() = 0;
*		displays gamestate
*
*	static void Init(GameState * mainMenu, GameState * loadMenu, GameState * newGame, GameState * fight, GameState * shop);
*		used to initialize the static variables
*	static void Purge();
*		used to purge the static variables
*	static void SetGameState(int state);
*		sets the current state
*	static GameState* GetCurrentState();
*	static GameState* GetState(int state);
*		get specified state (based on STATES enum)
*
*************************************************************************/

class GameState
{
public:
	enum KEYS : int {W = 'w', A = 'a', S = 's', D = 'd', J = 'j', K = 'k', UP = 72, LEFT = 75, DOWN = 80, RIGHT = 77, Z = 'z', X = 'x'};
	enum STATES : int { MAIN_MENU = 0, LOAD_MENU = 1, NEW_GAME = 2, FIGHT = 3, SHOP = 4 };

	GameState(Game * g);
	virtual ~GameState();

	virtual void Update(char key) = 0;
	virtual void Display() = 0;

	static void Init(GameState * mainMenu, GameState * loadMenu, GameState * newGame, GameState * fight, GameState * shop);
	static void Purge();
	static void SetGameState(int state);
	static GameState* GetCurrentState();
	static GameState* GetState(int state);

	static GameState ** gameStates;
	static GameState * currentState;
private:
	static const int NUM_STATES = 5;

protected:
	Game * m_gameRef;
};

