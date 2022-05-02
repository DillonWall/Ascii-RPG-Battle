/*************************************************************
* Author: Dillon Wall
* Filename: "Game.cpp"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#include "Game.h"

#include <iostream>
#include <fstream>
#include <vector>
using std::ios;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::cout;
using std::endl;

const char * Game::FILE_NAME = "characters.bin";
const int Game::NUM_CHARS = 4;
const int Game::ERR_FILE_NOT_FOUND = -1;
const int Game::NUM_CONSOLE_LINES = 22;

Game::Game() : m_currentChar(0), m_characters(nullptr), m_shouldExit(false)
{
	Rand::Init();	
	Potion::Init();
	Weapon::Init();
	Armor::Init();
	Spell::Init();

	try
	{
		m_characters = LoadChars(NUM_CHARS);
	}
	catch (int excep)
	{
		if (excep == ERR_FILE_NOT_FOUND)
		{
			cout << "File name: '" << FILE_NAME << "' not found when loading... exiting program..." << endl;
			exit(0);
		}
	}

	GameState::Init(new MainMenu(this), new LoadMenu(this), new NewGame(this), new Fight(this), new Shop(this));


	GameState::GetCurrentState()->Display();
}


Game::~Game()
{
	GameState::Purge();
	Potion::Purge();
	Armor::Purge();
	Weapon::Purge();
	Spell::Purge();

	for (int i=0; i<NUM_CHARS; ++i)
	{
		delete m_characters[i];
	}
	delete[] m_characters;
}

bool Game::Update(char key)
{
	if (key == 27) //Esc
	{
		ExitGame();
	}
	else
	{
		GameState::GetCurrentState()->Update(key);
	}

	return m_shouldExit;
}

void Game::Display()
{
	GameState::GetCurrentState()->Display();
}

void Game::SetCurrentCharPos(int pos)
{
	m_currentChar = pos;
}

void Game::SetChar(Character * c, int pos)
{
	if (pos == -1)
	{
		pos = m_currentChar;
	}

	delete m_characters[pos];
	m_characters[pos] = c;
}

void Game::Save()
{
	if (m_characters[m_currentChar] != nullptr)
	{
		m_characters[m_currentChar]->SetHealth(m_characters[m_currentChar]->GetMaxHealth());
		m_characters[m_currentChar]->SetMana(m_characters[m_currentChar]->GetMaxMana());
	}

	try
	{
		SaveChars(m_characters, NUM_CHARS);
	}
	catch (int excep)
	{
		if (excep == ERR_FILE_NOT_FOUND)
		{
			cout << "File name: '" << FILE_NAME << "' not found when saving... exiting program..." << endl;
			exit(0);
		}
	}
}

Character * Game::GetChar(int pos) const
{
	return m_characters[pos];
}

Character * Game::GetCurrentChar() const
{
	return m_characters[m_currentChar];
}

void Game::ExitGame()
{
	Save();

	m_shouldExit = true;
}

Character ** Game::LoadChars(int numChars)
{
	Character ** retVal = new Character*[NUM_CHARS];
	int temp = 0;
	char * tempStr;

	ifstream myFile(FILE_NAME, ios::in | ios::binary);

	if (myFile.is_open())
	{
		for (int i = 0; i < numChars; i++)
		{
			//read name size
			myFile.read(reinterpret_cast<char *>(&temp), sizeof(int));
			if (temp > strlen(""))
			{
				Character * tempChar = new Character();

				//read name
				tempStr = new char[temp + 1];
				myFile.read(reinterpret_cast<char *>(tempStr), temp);
				tempStr[temp] = '\0';
				tempChar->SetName(String(tempStr));
				delete[] tempStr;

				//read items in backpack
				DynamicArray<Item> items;

				//read how many items
				myFile.read(reinterpret_cast<char *>(&temp), sizeof(int));

				int numItems = temp;
				for (int j = 0; j < numItems; ++j)
				{
					//read item id
					myFile.read(reinterpret_cast<char *>(&temp), sizeof(int));
					switch (temp / 10)
					{
					case 0:
						//potion
						items.Insert(Potion::potionList[temp % 10]);
						break;
					case 1:
						//weapon
						items.Insert(Weapon::weaponList[temp % 10]);
						break;
					case 2:
						//armor
						items.Insert(Armor::armorList[temp % 10]);
						break;
					default:
						break;
					}
				}

				//assign backpack to character
				tempChar->SetBackpack(new BackPack(items));

				//read spells in spell list
				DynamicArray<Spell> * spells = new DynamicArray<Spell>();

				//read how many spells
				myFile.read(reinterpret_cast<char *>(&temp), sizeof(int));

				int numSpells = temp;
				for (int j = 0; j < numSpells; ++j)
				{
					//read spell id
					myFile.read(reinterpret_cast<char *>(&temp), sizeof(int));
					spells->Insert(Spell::spellList[temp]);
				}
				
				//assign spells to character and pass the data on so no deleting needed
				tempChar->SetSpellsArr(spells);

				//read string in coinpouch
				myFile.read(reinterpret_cast<char *>(&temp), sizeof(int));
				tempStr = new char[temp + 1];
				myFile.read(reinterpret_cast<char *>(tempStr), temp);
				tempStr[temp] = '\0';
				tempChar->SetCoinpouch(new CoinPouch(String(tempStr)));
				delete[] tempStr;

				//read weapon equipped
				myFile.read(reinterpret_cast<char *>(&temp), sizeof(int));
				if (temp != -1) tempChar->EquipWeapon(Weapon::weaponList[temp % 10]);				

				//read armor equipped
				myFile.read(reinterpret_cast<char *>(&temp), sizeof(int));
				if (temp != -1) tempChar->EquipArmor(Armor::armorList[temp % 10]);

				//write all int vals in character
				myFile.read(reinterpret_cast<char *>(&temp), sizeof(int));
				tempChar->SetMonsterNum(temp);
				myFile.read(reinterpret_cast<char *>(&temp), sizeof(int));
				tempChar->SetMaxHealth(temp);
				myFile.read(reinterpret_cast<char *>(&temp), sizeof(int));
				tempChar->SetHealth(temp);
				myFile.read(reinterpret_cast<char *>(&temp), sizeof(int));
				tempChar->SetMaxMana(temp);
				myFile.read(reinterpret_cast<char *>(&temp), sizeof(int));
				tempChar->SetMana(temp);
				myFile.read(reinterpret_cast<char *>(&temp), sizeof(int));
				tempChar->SetAttack(temp);
				myFile.read(reinterpret_cast<char *>(&temp), sizeof(int));
				tempChar->SetDefense(temp);
				myFile.read(reinterpret_cast<char *>(&temp), sizeof(int));
				tempChar->SetSpeed(temp);

				retVal[i] = tempChar;
			}
			else
			{
				retVal[i] = nullptr;
			}
		}

		myFile.close();
	}
	else
	{
		throw ERR_FILE_NOT_FOUND;
	}

	return retVal;
}

void Game::SaveChars(Character ** c, int numChars)
{
	ofstream myFile(FILE_NAME, ios::out | ios::binary | ios::ate);

	int temp = 0;

	if (myFile.is_open())
	{

		for (int i = 0; i < numChars; i++)
		{
			if (c[i] != nullptr)
			{
				//write name
				char * name = new char[strlen(c[i]->GetName().GetCharArr()) + 1];				
				strcpy(name, c[i]->GetName().GetCharArr());
				temp = strlen(name);
				myFile.write(reinterpret_cast<char *>(&temp), sizeof(int));
				myFile.write(reinterpret_cast<char *>(name), temp);
				delete[] name;

				//write items in backpack
				DynamicArray<Item> items = c[i]->GetBackpack()->GetItemArray();

				//write how many items
				temp = items.GetElements();
				myFile.write(reinterpret_cast<char *>(&temp), sizeof(int));

				for (int j = 0; j < items.GetElements(); ++j)
				{
					//write item id
					temp = items[j]->GetItemID();
					myFile.write(reinterpret_cast<char *>(&temp), sizeof(int));
				}

				//write spells in spell list
				DynamicArray<Spell> spells = *(c[i]->GetSpellsArr());

				//write how many spells
				temp = spells.GetElements();
				myFile.write(reinterpret_cast<char *>(&temp), sizeof(int));

				for (int j = 0; j < spells.GetElements(); ++j)
				{
					//write spell id
					temp = spells[j]->GetSpellID();
					myFile.write(reinterpret_cast<char *>(&temp), sizeof(int));
				}

				//write string in coinpouch
				char * moneyStr = new char[strlen(c[i]->GetCoinpouch()->GetMoney().GetCharArr()) + 1];
				strcpy(moneyStr, c[i]->GetCoinpouch()->GetMoney().GetCharArr());
				temp = strlen(moneyStr);
				myFile.write(reinterpret_cast<char *>(&temp), sizeof(int));
				myFile.write(reinterpret_cast<char *>(moneyStr), temp);
				delete[] moneyStr;

				//write weapon equipped
				if (c[i]->GetWeapon() == nullptr) temp = -1;
				else temp = c[i]->GetWeapon()->GetItemID();
				myFile.write(reinterpret_cast<char *>(&temp), sizeof(int));

				//write armor equipped
				if (c[i]->GetArmor() == nullptr) temp = -1;
				else temp = c[i]->GetArmor()->GetItemID();
				myFile.write(reinterpret_cast<char *>(&temp), sizeof(int));
				
				//write all int vals in character
				temp = c[i]->GetMonsterNum();
				myFile.write(reinterpret_cast<char *>(&temp), sizeof(int));
				temp = c[i]->GetMaxHealth();
				myFile.write(reinterpret_cast<char *>(&temp), sizeof(int));
				temp = c[i]->GetHealth();
				myFile.write(reinterpret_cast<char *>(&temp), sizeof(int));
				temp = c[i]->GetMaxMana();
				myFile.write(reinterpret_cast<char *>(&temp), sizeof(int));
				temp = c[i]->GetMana();
				myFile.write(reinterpret_cast<char *>(&temp), sizeof(int));
				temp = c[i]->GetAttack();
				myFile.write(reinterpret_cast<char *>(&temp), sizeof(int));
				temp = c[i]->GetDefense();
				myFile.write(reinterpret_cast<char *>(&temp), sizeof(int));
				temp = c[i]->GetSpeed();
				myFile.write(reinterpret_cast<char *>(&temp), sizeof(int));
			}
			else
			{
				//write 0 indicating empty name and thus no char
				int empty = 0;
				myFile.write(reinterpret_cast<char *>(&empty), sizeof(int));
			}
		}

		myFile.close();
	}
	else
	{
		throw ERR_FILE_NOT_FOUND;
	}
}