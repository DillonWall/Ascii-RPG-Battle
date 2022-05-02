/*************************************************************
* Author: Dillon Wall
* Filename: "LoadMenu.cpp"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#include "LoadMenu.h"

#include <iostream>
using std::cout;
using std::endl;

LoadMenu::LoadMenu(Game * g) : GameState(g), m_selection(0)
{
}

LoadMenu::~LoadMenu()
{
}

void LoadMenu::Update(char key)
{

	if (key == GameState::KEYS::J || key == GameState::KEYS::Z)
	{
		m_gameRef->SetCurrentCharPos(m_selection);

		GameState::SetGameState(GameState::STATES::FIGHT);
		dynamic_cast<Fight*>(GameState::GetCurrentState())->Init();
		GameState::GetCurrentState()->Display();

		m_selection = 0; //reset so it goes back to default if coming back to this menu
	}
	else if (key == GameState::KEYS::K || key == GameState::KEYS::X)
	{
		GameState::SetGameState(GameState::STATES::MAIN_MENU);

		m_selection = 0; //reset so it goes back to default if coming back to this menu
	}
	else if(key == GameState::KEYS::W || key == GameState::KEYS::UP)
	{
		--m_selection;
		if (m_selection < 0)
		{
			m_selection = Game::NUM_CHARS - 1;
		}
	}
	else if (key == GameState::KEYS::S || key == GameState::KEYS::DOWN)
	{
		++m_selection;
		if (m_selection > Game::NUM_CHARS - 1)
		{
			m_selection = 0;
		}
	}
}

void LoadMenu::Display()
{
	cout <<
		endl <<
		endl <<
		"                                   " << ((m_selection == 0) ? ">" : " ") << "  Save slot 1 || " << ((m_gameRef->GetChar(0) != nullptr) ? (m_gameRef->GetChar(0)->GetName()) : "--------") << endl <<
		endl <<
		endl <<
		"                                   " << ((m_selection == 1) ? ">" : " ") << "  Save slot 2 || " << ((m_gameRef->GetChar(1) != nullptr) ? (m_gameRef->GetChar(1)->GetName()) : "--------") << endl <<
		endl <<
		endl <<
		"                                   " << ((m_selection == 2) ? ">" : " ") << "  Save slot 3 || " << ((m_gameRef->GetChar(2) != nullptr) ? (m_gameRef->GetChar(2)->GetName()) : "--------") << endl <<
		endl <<
		endl <<
		"                                   " << ((m_selection == 3) ? ">" : " ") << "  Save slot 4 || " << ((m_gameRef->GetChar(3) != nullptr) ? (m_gameRef->GetChar(3)->GetName()) : "--------") << endl <<
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