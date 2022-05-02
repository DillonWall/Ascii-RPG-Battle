/*************************************************************
* Author: Dillon Wall
* Filename: "MainMenu.cpp"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#include "MainMenu.h"

#include <iostream>
using std::cout;
using std::endl;

MainMenu::MainMenu(Game * g) : GameState(g), m_selection(NEW_GAME)
{
}


MainMenu::~MainMenu()
{
}

void MainMenu::Update(char key)
{
	if (key == GameState::KEYS::J || key == GameState::KEYS::Z)
	{
		if (m_selection == NEW_GAME)
		{
			GameState::SetGameState(GameState::STATES::NEW_GAME);
		}
		else if (m_selection == LOAD_GAME)
		{
			GameState::SetGameState(GameState::STATES::LOAD_MENU);
		}
		else if (m_selection == EXIT)
		{
			m_gameRef->ExitGame();
		}

		m_selection = 0; //reset so it goes back to default if coming back to this menu
	}
	else if (key == GameState::KEYS::W || key == GameState::KEYS::UP)
	{
		--m_selection;
		if (m_selection < NEW_GAME)
		{
			m_selection = EXIT;
		}
	}
	else if (key == GameState::KEYS::S || key == GameState::KEYS::DOWN)
	{
		++m_selection;
		if (m_selection > EXIT)
		{
			m_selection = NEW_GAME;
		}
	}
}

void MainMenu::Display()
{
	cout <<
		endl <<
		"                                     F I G H T   A R E N A" << endl <<
		endl <<
		"                                     " << ((m_selection == NEW_GAME) ? ">" : " ") << "  Start new game" << endl <<
		endl <<
		"                                        " << ((m_selection == LOAD_GAME) ? ">" : " ") << "  Load game" << endl <<
		endl <<
		"                                          " << ((m_selection == EXIT) ? ">" : " ") << "  Exit" << endl <<
		endl <<
		endl <<
		endl <<
		endl <<
		endl <<
		endl <<
		endl <<
		endl <<
		endl <<
		endl <<
		endl <<
		endl <<
		endl <<
		endl;
}
