/*************************************************************
* Author: Dillon Wall
* Filename: "GameState.cpp"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#include "GameState.h"

GameState ** GameState::gameStates;
GameState * GameState::currentState;


GameState::GameState(Game * g) : m_gameRef(g)
{
}

GameState::~GameState()
{
}

void GameState::Init(GameState * mainMenu, GameState * loadMenu, GameState * newGame, GameState * fight, GameState * shop)
{
	gameStates = new GameState*[NUM_STATES];
	gameStates[MAIN_MENU] = mainMenu;
	gameStates[LOAD_MENU] = loadMenu;
	gameStates[NEW_GAME] = newGame;
	gameStates[FIGHT] = fight;
	gameStates[SHOP] = shop;

	currentState = gameStates[MAIN_MENU];
}

void GameState::Purge()
{
	delete gameStates[MAIN_MENU];
	delete gameStates[LOAD_MENU];
	delete gameStates[NEW_GAME];
	delete gameStates[FIGHT];
	delete gameStates[SHOP];
	delete[] gameStates;
}

void GameState::SetGameState(int state)
{
	currentState = gameStates[state];
}

GameState * GameState::GetCurrentState()
{
	return currentState;
}

GameState * GameState::GetState(int state)
{
	return gameStates[state];
}
