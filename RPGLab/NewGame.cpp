/*************************************************************
* Author: Dillon Wall
* Filename: "NewGame.cpp"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#include "NewGame.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

NewGame::NewGame(Game * g) : GameState(g)
{
}

NewGame::~NewGame()
{
}

void NewGame::Update(char key)
{
	//Have to put in the Display funtion since this only fires after key stroke
}

void NewGame::Display()
{
	cout <<
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
		endl <<
		endl <<
		endl <<
		endl <<
		endl <<
		"                                 Enter the hero's name... (10 chars)" << endl <<
		endl <<
		endl <<
		endl;



	///UPDATE///
	char * name = new char[64];
	cin >> name;

	int newCharPos = -1;

	for (int i = 0; i < Game::NUM_CHARS; ++i)
	{
		if (m_gameRef->GetChar(i) == nullptr)
		{
			newCharPos = i;
		}
	}

	if (newCharPos == -1) //no slots are available, we should ask which file to override
	{
		cout <<
			endl <<
			endl <<
			endl <<
			endl <<
			endl <<
			endl <<
			endl <<
			endl <<
			"                                     No save slots are available," << endl <<
			"                                   which would you like to override?" << endl <<
			endl <<
			"                                          1 : " << ((m_gameRef->GetChar(0) != nullptr) ? (m_gameRef->GetChar(0)->GetName()) : "--------") << endl <<
			endl <<
			"                                          2 : " << ((m_gameRef->GetChar(0) != nullptr) ? (m_gameRef->GetChar(1)->GetName()) : "--------") << endl <<
			endl <<
			"                                          3 : " << ((m_gameRef->GetChar(0) != nullptr) ? (m_gameRef->GetChar(2)->GetName()) : "--------") << endl <<
			endl <<
			"                                          4 : " << ((m_gameRef->GetChar(0) != nullptr) ? (m_gameRef->GetChar(3)->GetName()) : "--------") << endl <<
			endl <<
			endl <<
			endl <<
			endl;

		int choice = -1;
		while (choice < 1 || choice > 4)
		{
			cin >> choice;
		}

		newCharPos = choice - 1;
	}

	m_gameRef->SetCurrentCharPos(newCharPos);

	Character * c = new Character(String(name));
	m_gameRef->SetChar(c);

	GameState::SetGameState(GameState::STATES::FIGHT);
	dynamic_cast<Fight*>(GameState::GetCurrentState())->Init();
	GameState::GetCurrentState()->Display();

	delete name;
}
