/*************************************************************
* Author: Dillon Wall
* Filename: String.cpp
* Date Created: 10/10/18
* Modifications:
**************************************************************/

#include "Fight.h"



Fight::Fight(Game * g) : GameState(g), m_monster(nullptr), m_character(nullptr), m_inDialog(true), m_currentDialog(ENCOUNTER), m_currentSelection(ATTACK), 
								m_currentListSelection(0), m_currentMenu(M_FIGHT), m_lastDmgDealtToChar(0), m_lastDmgDealtToEnemy(0), m_isBlocking(false), m_isBerserking(false), 
								m_listElementSelected(false), m_inspectingListElement(false)
{
}

Fight::~Fight()
{
	m_monsterList.purge();
}

void Fight::Update(char key)
{
	if (m_inDialog)
	{
		if (key == GameState::KEYS::J || key == GameState::KEYS::Z)
		{
			if (m_currentDialog == ENCOUNTER)
			{
				m_currentDialog = SELECT_CHOICE;
				m_inDialog = false;
			}
			else if (m_currentDialog == CHAR_ATTACK)
			{
				//check dead
				if (m_monster->GetHealth() <= 0)
				{
					m_currentDialog = END_BATTLE;
				}
				else if (m_character->GetSpeed() >= m_monster->GetSpeed())
				{
					//damage player
					m_character->Hit(m_lastDmgDealtToChar);

					m_currentDialog = ENEMY_ATTACK;
				}
				else
				{
					m_currentDialog = SELECT_CHOICE;
					m_inDialog = false;
				}
			}
			else if (m_currentDialog == ENEMY_ATTACK)
			{
				//check dead
				if (m_character->GetHealth() <= 0)
				{
					m_currentDialog = END_BATTLE;
				}
				else if (m_character->GetSpeed() >= m_monster->GetSpeed())
				{
					m_currentDialog = SELECT_CHOICE;
					m_inDialog = false;
				}
				else
				{
					//damage enemy
					m_monster->Hit(m_lastDmgDealtToEnemy);
					m_currentDialog = CHAR_ATTACK;
				}
			}
			else if (m_currentDialog == END_BATTLE)
			{
				if (m_character->GetHealth() <= 0) //player dead
				{

				}
				else //monster dead
				{
					m_character->GetCoinpouch()->GainMoney(m_monster->GetMoney());
					if (m_character->GetMonsterNum() < Monster::NUM_MONSTERS) m_character->SetMonsterNum(m_character->GetMonsterNum() + 1); //goes from 1 to 10
				}

				GameState::SetGameState(GameState::STATES::SHOP);
				dynamic_cast<Shop*>(GameState::GetCurrentState())->Init();
				GameState::GetCurrentState()->Display();
			}
		}
	}
	else
	{
		if (m_currentMenu == M_FIGHT)
		{
			if (key == GameState::KEYS::J || key == GameState::KEYS::Z)
			{
				if (m_currentSelection == ATTACK)
				{
					m_isBerserking = false;
					m_isBlocking = false;

					m_lastDmgDealtToEnemy = m_character->GetTotalAttack() + Rand::GetRand(m_character->GetTotalAttack() / 3) - m_monster->GetDefense();
					m_lastDmgDealtToChar = m_monster->GetAttack() + Rand::GetRand(m_monster->GetAttack() / 3) - m_character->GetTotalDefense();
					//do crits
					if (m_lastDmgDealtToEnemy < 0) m_lastDmgDealtToEnemy = 0;
					if (m_lastDmgDealtToChar < 0) m_lastDmgDealtToChar = 0;

					//Set next dialog and attack
					if (m_character->GetSpeed() >= m_monster->GetSpeed()) {
						//damage enemy
						m_monster->Hit(m_lastDmgDealtToEnemy);
						m_currentDialog = CHAR_ATTACK;
					}
					else
					{
						//damage character
						m_character->Hit(m_lastDmgDealtToChar);
						m_currentDialog = ENEMY_ATTACK;
					}

					m_inDialog = true;
				}
				else if (m_currentSelection == MAGIC)
				{
					m_currentMenu = M_MAGIC;
					m_currentSelection = 0;
				}
				else if (m_currentSelection == BLOCK)
				{
					m_isBerserking = false;
					m_isBlocking = true;

					m_lastDmgDealtToEnemy = m_character->GetTotalAttack()*.75 + Rand::GetRand(m_character->GetTotalAttack()*.75 / 3) - m_monster->GetDefense();
					m_lastDmgDealtToChar = m_monster->GetAttack() + Rand::GetRand(m_monster->GetAttack() / 3) - m_character->GetTotalDefense()*1.5;
					//do crits
					if (m_lastDmgDealtToEnemy < 0) m_lastDmgDealtToEnemy = 0;
					if (m_lastDmgDealtToChar < 0) m_lastDmgDealtToChar = 0;

					//Set next dialog and attack
					if (m_character->GetSpeed() >= m_monster->GetSpeed()) {
						//damage enemy
						m_monster->Hit(m_lastDmgDealtToEnemy);
						m_currentDialog = CHAR_ATTACK;
					}
					else
					{
						//damage character
						m_character->Hit(m_lastDmgDealtToChar);
						m_currentDialog = ENEMY_ATTACK;
					}

					m_inDialog = true;
				}
				else if (m_currentSelection == BERSERK)
				{
					m_isBlocking = false;
					m_isBerserking = true;

					m_lastDmgDealtToEnemy = m_character->GetTotalAttack()*1.5 + Rand::GetRand(m_character->GetTotalAttack()*1.5 / 3) - m_monster->GetDefense();
					m_lastDmgDealtToChar = m_monster->GetAttack() + Rand::GetRand(m_monster->GetAttack() / 3) - m_character->GetTotalDefense()*.75;
					//do crits
					if (m_lastDmgDealtToEnemy < 0) m_lastDmgDealtToEnemy = 0;
					if (m_lastDmgDealtToChar < 0) m_lastDmgDealtToChar = 0;

					//Set next dialog and attack
					if (m_character->GetSpeed() >= m_monster->GetSpeed()) {
						//damage enemy
						m_monster->Hit(m_lastDmgDealtToEnemy);
						m_currentDialog = CHAR_ATTACK;
					}
					else
					{
						//damage character
						m_character->Hit(m_lastDmgDealtToChar);
						m_currentDialog = ENEMY_ATTACK;
					}

					m_inDialog = true;
				}
				else if (m_currentSelection == ITEMS)
				{
					m_currentMenu = M_ITEMS;
					m_currentSelection = 0;
				}
				else if (m_currentSelection == STATS)
				{
					m_currentMenu = M_STATS;
				}
			}
			else if (key == GameState::KEYS::A || key == GameState::KEYS::LEFT)
			{
				--m_currentSelection;
				if (m_currentSelection < ATTACK)
				{
					m_currentSelection = STATS;
				}
			}
			else if (key == GameState::KEYS::D || key == GameState::KEYS::RIGHT)
			{
				++m_currentSelection;
				if (m_currentSelection > STATS)
				{
					m_currentSelection = ATTACK;
				}
			}			
		}
		else if (m_currentMenu == M_MAGIC)
		{
			if (m_inspectingListElement)
			{
				if (key == GameState::KEYS::J || key == GameState::KEYS::Z || key == GameState::KEYS::K || key == GameState::KEYS::X)
				{
					m_inspectingListElement = false;
				}
			}
			else if (m_listElementSelected)
			{
				if (key == GameState::KEYS::J || key == GameState::KEYS::Z)
				{
					if (m_currentSelection == MAG_CAST)
					{
						//use that magic if mana allows
						Spell * spellToCast = (*(m_character->GetSpellsArr()))[m_currentListSelection];
						if (m_character->GetMana() >= spellToCast->GetMana())
						{
							m_character->ModMana(-spellToCast->GetMana());

							m_lastDmgDealtToEnemy = spellToCast->GetDamage() + Rand::GetRand(spellToCast->GetDamage() / 10) - (2 * m_monster->GetDefense() / 3);
							m_lastDmgDealtToChar = m_monster->GetAttack() + Rand::GetRand(m_monster->GetAttack() / 3) - m_character->GetTotalDefense();
							if (m_lastDmgDealtToEnemy < 0) m_lastDmgDealtToEnemy = 0;
							if (m_lastDmgDealtToChar < 0) m_lastDmgDealtToChar = 0;

							//Set next dialog and attack
							if (m_character->GetSpeed() >= m_monster->GetSpeed()) {
								//damage enemy
								m_monster->Hit(m_lastDmgDealtToEnemy);
								m_currentDialog = CHAR_ATTACK;
							}
							else
							{
								//damage character
								m_character->Hit(m_lastDmgDealtToChar);
								m_currentDialog = ENEMY_ATTACK;
							}

							m_inDialog = true;

							m_currentMenu = M_FIGHT;
							m_currentSelection = MAGIC;
							m_listElementSelected = false;
						}
					}
					else if (m_currentSelection == MAG_INSPECT)
					{
						m_inspectingListElement = true;
					}
				}
				else if (key == GameState::KEYS::K || key == GameState::KEYS::X)
				{
					m_currentSelection = m_currentListSelection;
					m_listElementSelected = false;
				}
				else if (key == GameState::KEYS::A || key == GameState::KEYS::LEFT)
				{
					--m_currentSelection;
					if (m_currentSelection < MAG_CAST)
					{
						m_currentSelection = MAG_INSPECT;
					}
				}
				else if (key == GameState::KEYS::D || key == GameState::KEYS::RIGHT)
				{
					++m_currentSelection;
					if (m_currentSelection > MAG_CAST)
					{
						m_currentSelection = MAG_INSPECT;
					}
				}				
			}
			else
			{
				if (key == GameState::KEYS::J || key == GameState::KEYS::Z)
				{
					if (m_character->GetSpellsArr()->GetElements() > 0)
					{
						m_currentListSelection = m_currentSelection;
						m_listElementSelected = true;
						m_currentSelection = MAG_CAST;
					}
				}
				else if (key == GameState::KEYS::K || key == GameState::KEYS::X)
				{
					m_currentMenu = M_FIGHT;

					m_currentSelection = MAGIC;
				}
				else if (key == GameState::KEYS::W || key == GameState::KEYS::UP)
				{
					--m_currentSelection;
					if (m_currentSelection < 0)
					{
						m_currentSelection = m_character->GetSpellsArr()->GetElements() - 1;
					}
				}
				else if (key == GameState::KEYS::S || key == GameState::KEYS::DOWN)
				{
					++m_currentSelection;
					if (m_currentSelection > m_character->GetSpellsArr()->GetElements() - 1)
					{
						m_currentSelection = 0;
					}
				}
			}
		}
		else if (m_currentMenu == M_ITEMS)
		{
			if (m_inspectingListElement)
			{
				if (key == GameState::KEYS::J || key == GameState::KEYS::Z || key == GameState::KEYS::K || key == GameState::KEYS::X)
				{
					m_inspectingListElement = false;
				}
			}
			else if (m_listElementSelected)
			{
				if (key == GameState::KEYS::J || key == GameState::KEYS::Z)
				{
					if (m_currentSelection == I_USE)
					{
						//use the item
						Item * itemToUse = m_character->GetBackpack()->GetItemArray()[m_currentListSelection];
						switch (itemToUse->GetType())
						{
						case Item::HEALING:
						{
							Potion * potHeal = dynamic_cast<Potion *>(itemToUse);
							m_character->ModHealth(potHeal->GetPotency());
							if (m_character->GetHealth() > m_character->GetMaxHealth()) m_character->SetHealth(m_character->GetMaxHealth());
							m_character->GetBackpack()->RemoveItem(itemToUse);
						}
						break;
						case Item::MANA_RECOVER:
						{
							Potion * potMana = dynamic_cast<Potion *>(itemToUse);
							m_character->ModMana(potMana->GetPotency());
							if (m_character->GetMana() > m_character->GetMaxMana()) m_character->SetMana(m_character->GetMaxMana());
							m_character->GetBackpack()->RemoveItem(itemToUse);
						}
						break;
						default:
							break;
						}

						m_listElementSelected = false;
						m_currentMenu = M_FIGHT;
						m_currentSelection = ITEMS;
					}
					else if (m_currentSelection == I_INSPECT)
					{
						m_inspectingListElement = true;
					}
					else if (m_currentSelection == I_TOSS)
					{
						Item * itemToToss = m_character->GetBackpack()->GetItemArray()[m_currentListSelection];
						m_character->GetBackpack()->RemoveItem(itemToToss);

						m_listElementSelected = false;
						m_currentMenu = M_FIGHT;
						m_currentSelection = ITEMS;
					}
				}
				else if (key == GameState::KEYS::K || key == GameState::KEYS::X)
				{
					m_currentSelection = m_currentListSelection;
					m_listElementSelected = false;
				}
				else if (key == GameState::KEYS::A || key == GameState::KEYS::LEFT)
				{
					--m_currentSelection;
					if (m_currentSelection < I_USE)
					{
						m_currentSelection = I_TOSS;
					}
				}
				else if (key == GameState::KEYS::D || key == GameState::KEYS::RIGHT)
				{
					++m_currentSelection;
					if (m_currentSelection > I_TOSS)
					{
						m_currentSelection = I_USE;
					}
				}
			}
			else
			{
				if (key == GameState::KEYS::J || key == GameState::KEYS::Z)
				{
					if (m_character->GetBackpack()->GetItemArray().GetElements() > 0)
					{
						m_currentListSelection = m_currentSelection;
						m_listElementSelected = true;
						m_currentSelection = I_USE;

					}
				}
				else if (key == GameState::KEYS::K || key == GameState::KEYS::X)
				{
					m_currentMenu = M_FIGHT;

					m_currentSelection = ITEMS;
				}
				else if (key == GameState::KEYS::W || key == GameState::KEYS::UP)
				{
					--m_currentSelection;
					if (m_currentSelection < 0)
					{
						m_currentSelection = m_character->GetBackpack()->GetItemArray().GetElements() - 1;
					}
				}
				else if (key == GameState::KEYS::S || key == GameState::KEYS::DOWN)
				{
					++m_currentSelection;
					if (m_currentSelection > m_character->GetBackpack()->GetItemArray().GetElements() - 1)
					{
						m_currentSelection = 0;
					}
				}
			}
		}
		else if (m_currentMenu == M_STATS)
		{
			if (key == GameState::KEYS::J || key == GameState::KEYS::Z || key == GameState::KEYS::K || key == GameState::KEYS::X)
			{
				m_currentMenu = M_FIGHT;
			}
		}
	}
}

void Fight::Display()
{
	if (m_currentMenu == M_FIGHT)
	{
		m_monster->Display();
		cout << "----------------------------------------------------------------------------------------------" << endl;
		DisplayDialog();
		cout << "----------------------------------------------------------------------------------------------" << endl;
		if (!m_inDialog) cout << "                  " << ((m_currentSelection == ATTACK) ? ">" : " ") << " Attack | " <<
			((m_currentSelection == MAGIC) ? ">" : " ") << " Magic | " <<
			((m_currentSelection == BLOCK) ? ">" : " ") << " Block | " <<
			((m_currentSelection == BERSERK) ? ">" : " ") << " Berserk | " <<
			((m_currentSelection == ITEMS) ? ">" : " ") << " Items | " <<
			((m_currentSelection == STATS) ? ">" : " ") << " Stats" << endl;
		else cout << endl;
	}
	else if (m_currentMenu == M_MAGIC)
	{
		cout << "   Magic:                                                                        [X/K Back]" << endl <<
			"+--------------------------------------------------------------------------------------------+" << endl;
		if (m_listElementSelected && !m_inspectingListElement) cout << "                                " << ((m_currentSelection == MAG_CAST) ? " > " : "   ") << "CAST              " << ((m_currentSelection == MAG_INSPECT) ? " > " : "   ") << "INSPECT            " << endl;
		else cout << endl;
		cout << "+--------------------------------------------------------------------------------------------+" << endl;
		if (m_inspectingListElement)
		{
			(*(m_character->GetSpellsArr()))[m_currentListSelection]->Display();
			for (int i = 0; i < Game::NUM_CONSOLE_LINES - 5 - 9; ++i)
			{
				cout << endl;
			}
		}
		else
		{
			DynamicArray<Spell> * charSpells = m_character->GetSpellsArr();
			int i = 0;
			for (i; i < charSpells->GetElements(); ++i)
			{
				cout << ((m_currentSelection == i && !m_listElementSelected) ? " > " : "   ") << (*charSpells)[i]->GetName() << "   " << (*charSpells)[i]->GetMana() << endl <<
					endl;
			}
			i *= 2;
			for (i; i < Game::NUM_CONSOLE_LINES - 4; ++i)
			{
				cout << endl;
			}
		}
	}
	else if (m_currentMenu == M_ITEMS)
	{
		cout << "   Items:                                                                        [X/K Back]" << endl <<
			"+--------------------------------------------------------------------------------------------+" << endl;
		if (m_listElementSelected && !m_inspectingListElement) cout << "                      " << ((m_currentSelection == I_USE) ? " > " : "   ") << "USE            " << ((m_currentSelection == I_INSPECT) ? " > " : "   ") << "INSPECT            " << ((m_currentSelection == I_TOSS) ? " > " : "   ") << "TOSS            " << endl;
		else cout << endl;
		cout << "+--------------------------------------------------------------------------------------------+" << endl;
		if (m_inspectingListElement)
		{
			Item * itemToDisplay = m_character->GetBackpack()->GetItemArray()[m_currentListSelection];
			int itemType = m_character->GetBackpack()->GetItemArray()[m_currentListSelection]->GetType();
			if(itemType == Item::TYPES::WEAPON)
			{
				dynamic_cast<Weapon *>(itemToDisplay)->Display();
				for (int i = 0; i < Game::NUM_CONSOLE_LINES - 5 - 7; ++i)
				{
					cout << endl;
				}
			}
			else if (itemType == Item::TYPES::ARMOR)
			{
				dynamic_cast<Armor *>(itemToDisplay)->Display();
				for (int i = 0; i < Game::NUM_CONSOLE_LINES - 5 - 12; ++i)
				{
					cout << endl;
				}
			}
			else if (itemType == Item::TYPES::HEALING || itemType == Item::TYPES::MANA_RECOVER)
			{
				dynamic_cast<Potion *>(itemToDisplay)->Display();
				for (int i = 0; i < Game::NUM_CONSOLE_LINES - 5 - 7; ++i)
				{
					cout << endl;
				}
			}
		}
		else
		{
			DynamicArray<Item> charItems = m_character->GetBackpack()->GetItemArray();
			int i = 0;
			for (i; i < charItems.GetElements(); ++i)
			{
				cout << ((m_currentSelection == i && !m_listElementSelected) ? " > " : "   ") << charItems[i]->GetName() << endl <<
					endl;
			}
			i *= 2;
			for (i; i < Game::NUM_CONSOLE_LINES - 4; ++i)
			{
				cout << endl;
			}
		}

	}
	else if (m_currentMenu == M_STATS)
	{
		cout << "   Stats:                                                                        [X/K Back]" << endl <<
			"+--------------------------------------------------------------------------------------------+" << endl <<
			m_character->GetName() << ":" << endl <<
			"    HP: " << m_character->GetHealth() << "/" << m_character->GetMaxHealth() << endl <<
			"    Mana: " << m_character->GetMana() << "/" << m_character->GetMaxMana() << endl <<
			"    Attack: " << m_character->GetTotalAttack() << endl <<
			"    Defense: " << m_character->GetTotalDefense() << endl <<
			"    Speed: " << m_character->GetSpeed() << endl <<
			endl <<
			m_monster->GetName() << ":" << endl <<
			"    HP: " << m_monster->GetHealth() << "/" << m_monster->GetMaxHealth() << endl <<
			"    Mana: " << m_monster->GetMana() << "/" << m_monster->GetMaxMana() << endl <<
			"    Attack: " << m_monster->GetAttack() << endl <<
			"    Defense: " << m_monster->GetDefense() << endl <<
			"    Speed: " << m_monster->GetSpeed() << endl <<
			endl <<
			endl <<
			endl <<
			endl <<
			endl <<
			endl <<
			endl;

	}
}

void Fight::DisplayDialog()
{
	switch (m_currentDialog)
	{
	case ENCOUNTER:
	{
		cout << "                       You encounter " << m_monster->GetName() << "..." << endl <<
			endl <<
			"                                                                                 [Z/J]..." << endl;
	}
	break;
	case SELECT_CHOICE:
	{
		cout << "                       What will " << m_character->GetName() << " do?" << endl <<
			endl <<
			endl;
	}
	break;
	case CHAR_ATTACK:
	{
		cout << "                       You hit the " << m_monster->GetName() << " for " << m_lastDmgDealtToEnemy << " damage," << endl <<
			"                       it has " << m_monster->GetHealth() << "/" << m_monster->GetMaxHealth() << " HP remaining..." << endl <<
			"                                                                                 [Z/J]..." << endl;
	}
	break;
	case ENEMY_ATTACK:
	{
		cout << "                       The " << m_monster->GetName() << " hit you for " << m_lastDmgDealtToChar << " damage," << endl <<
			"                       you have " << m_character->GetHealth() << "/" << m_character->GetMaxHealth() << " HP remaining..." << endl <<
			"                                                                                 [Z/J]..." << endl;
	}
	break;
	case END_BATTLE:
	{
		String * gainedMoney = Item::CostToDisplayString(m_monster->GetMoney());
		cout << "                       " << ((m_character->GetHealth() <= 0) ? "You have been slain by " : "You have slain ") << m_monster->GetName() << "!" << endl;
		if (m_character->GetHealth() <= 0) cout << endl;
		else cout << "                       You gained " << *gainedMoney << endl;
		cout << "                                                                                 [Z/J]..." << endl;

		delete gainedMoney;
	}
	break;
	default:
		break;
	}
}

void Fight::Init()
{
	m_character = m_gameRef->GetCurrentChar();

	m_monsterList = LinkedList<Monster*>();
	m_monsterList.prepend(new Dragon());
	m_monsterList.prepend(new Sphinx());
	m_monsterList.prepend(new DarkKnight());
	m_monsterList.prepend(new Medusa());
	m_monsterList.prepend(new Gryphon());
	m_monsterList.prepend(new Vampire());
	m_monsterList.prepend(new Enchantress());
	m_monsterList.prepend(new Minotaur());
	m_monsterList.prepend(new Skeleton());
	m_monsterList.prepend(new Goblin());

	SetMonster();
}

void Fight::Reset()
{
	m_inDialog = true;
	m_currentDialog = ENCOUNTER;
	m_currentSelection = ATTACK;
	m_currentListSelection = 0;
	m_currentMenu = M_FIGHT;
	m_lastDmgDealtToChar = 0;
	m_lastDmgDealtToEnemy = 0;
	m_isBlocking = false;
	m_isBerserking = false;
	m_listElementSelected = false;
	m_inspectingListElement = false;

	SetMonster();

	m_monster->SetHealth(m_monster->GetMaxHealth());
	m_monster->SetMana(m_monster->GetMaxMana());
}

void Fight::SetMonster()
{
	m_monster = m_monsterList[m_character->GetMonsterNum() - 1];
}
