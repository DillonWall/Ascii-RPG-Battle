/*************************************************************
* Author: Dillon Wall
* Filename: "Shop.cpp"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#include "Shop.h"



Shop::Shop(Game * g) : GameState(g), m_character(nullptr), m_currentMainSelection(M_BUY), m_currentTabSelection(0), m_currentListSelection(0), m_currentAction(0), 
						m_currentMenu(MAIN), m_inList(false), m_inActions(false), m_isInspecting(false)
{
}


Shop::~Shop()
{
}

void Shop::Update(char key)
{
	switch (m_currentMenu)
	{
	case MAIN:
	{
		switch (m_currentMainSelection)
		{
		case M_BUY:
		{
			if (key == GameState::KEYS::J || key == GameState::KEYS::Z)
			{
				m_currentMenu = BUY;
				m_currentTabSelection = B_WEAPONS;
			}
		}
		break;

		case M_TRAIN:
		{
			if (key == GameState::KEYS::J || key == GameState::KEYS::Z)
			{
				m_currentMenu = TRAIN;
				m_inList = true;
				m_currentListSelection = 0;
			}
		}
		break;

		case M_CONTINUE:
		{
			if (key == GameState::KEYS::J || key == GameState::KEYS::Z)
			{
				//save, increment monster num, go to fight state
				m_gameRef->Save();

				GameState::SetGameState(GameState::STATES::FIGHT);
				dynamic_cast<Fight*>(GameState::GetCurrentState())->Reset();
				GameState::GetCurrentState()->Display();
			}
		}
		break;

		default:
			break;
		}

		if (key == GameState::KEYS::W || key == GameState::KEYS::UP)
		{
			--m_currentMainSelection;
			if (m_currentMainSelection < M_BUY)
			{
				m_currentMainSelection = M_CONTINUE;
			}
		}
		else if (key == GameState::KEYS::S || key == GameState::KEYS::DOWN)
		{
			++m_currentMainSelection;
			if (m_currentMainSelection > M_CONTINUE)
			{
				m_currentMainSelection = M_BUY;
			}
		}
	}
	break;

	case BUY:
	{
		switch (m_currentTabSelection)
		{
		case B_WEAPONS:
		{
			if (m_inList)
			{
				if (m_inActions) //decide what to do with selected item
				{
					if (m_isInspecting) {
						if (key == GameState::KEYS::J || key == GameState::KEYS::Z || key == GameState::KEYS::K || key == GameState::KEYS::X)
						{
							m_isInspecting = false;
						}
					}
					else {
						if (key == GameState::KEYS::J || key == GameState::KEYS::Z) //execute selection
						{
							switch (m_currentAction)
							{
							case A_BUY:
							{

								Weapon * toBuy = Weapon::weaponList[m_currentListSelection];
								if (*(m_character->GetCoinpouch()) >= toBuy->GetCost() && m_character->GetBackpack()->GetItemArray().GetElements() < BACKPACK_SPACE)
								{
									m_character->GetCoinpouch()->SpendMoney(toBuy->GetCost());
									if (m_character->GetWeapon() != nullptr) m_character->GetBackpack()->AddItem(m_character->GetWeapon());
									m_character->EquipWeapon(toBuy);

								}
							}
							break;

							case A_INSPECT:
							{
								m_isInspecting = true;
							}
							break;

							default:
								break;
							}
						}
						else if (key == GameState::KEYS::K || key == GameState::KEYS::X) //go back a level
						{
							m_currentAction = A_BUY;
							m_inActions = false;
						}
						else if (key == GameState::KEYS::A || key == GameState::KEYS::LEFT)
						{
							--m_currentAction;
							if (m_currentAction < A_BUY)
							{
								m_currentAction = A_INSPECT;
							}
						}
						else if (key == GameState::KEYS::D || key == GameState::KEYS::RIGHT)
						{
							++m_currentAction;
							if (m_currentAction > A_INSPECT)
							{
								m_currentAction = A_BUY;
							}
						}
					}
				}
				else //item selection
				{
					if (key == GameState::KEYS::J || key == GameState::KEYS::Z) //select item and go to action tabs
					{
						m_currentAction = A_BUY;
						m_inActions = true;
					}
					else if (key == GameState::KEYS::K || key == GameState::KEYS::X) //go back a level
					{
						m_currentListSelection = 0;
						m_inList = false;
					}
					else if (key == GameState::KEYS::W || key == GameState::KEYS::UP)
					{
						--m_currentListSelection;
						if (m_currentListSelection < 0)
						{
							m_currentListSelection = Weapon::NUM_WEAPONS - 1;
						}
					}
					else if (key == GameState::KEYS::S || key == GameState::KEYS::DOWN)
					{
						++m_currentListSelection;
						if (m_currentListSelection > Weapon::NUM_WEAPONS - 1)
						{
							m_currentListSelection = 0;
						}
					}
				}
			}
			else //tab selection
			{
				if (key == GameState::KEYS::J || key == GameState::KEYS::Z) //select tab and go to item selection
				{
					m_inList = true;
					m_currentListSelection = 0;
				}
				else if (key == GameState::KEYS::K || key == GameState::KEYS::X) //go back to main menu
				{
					m_currentMenu = MAIN;
					m_currentTabSelection = B_WEAPONS;
				}
				else if (key == GameState::KEYS::A || key == GameState::KEYS::LEFT)
				{
					--m_currentTabSelection;
					if (m_currentTabSelection < B_WEAPONS)
					{
						m_currentTabSelection = B_POTIONS;
					}					
				}
				else if (key == GameState::KEYS::D || key == GameState::KEYS::RIGHT)
				{
					++m_currentTabSelection;
					if (m_currentTabSelection > B_POTIONS)
					{
						m_currentTabSelection = B_WEAPONS;
					}
				}
			}
		}
		break;

		case B_ARMOR:
		{
			if (m_inList)
			{
				if (m_inActions) //decide what to do with selected item
				{
					if (m_isInspecting) {
						if (key == GameState::KEYS::J || key == GameState::KEYS::Z || key == GameState::KEYS::K || key == GameState::KEYS::X)
						{
							m_isInspecting = false;
						}
					}
					else {
						if (key == GameState::KEYS::J || key == GameState::KEYS::Z) //execute selection
						{
							switch (m_currentAction)
							{
							case A_BUY:
							{
								Armor * toBuy = Armor::armorList[m_currentListSelection];
								if (*(m_character->GetCoinpouch()) >= toBuy->GetCost() && m_character->GetBackpack()->GetItemArray().GetElements() < BACKPACK_SPACE)
								{
									m_character->GetCoinpouch()->SpendMoney(toBuy->GetCost());
									if (m_character->GetArmor() != nullptr) m_character->GetBackpack()->AddItem(m_character->GetArmor());
									m_character->EquipArmor(toBuy);
								}
							}
							break;

							case A_INSPECT:
							{
								m_isInspecting = true;
							}
							break;

							default:
								break;
							}
						}
						else if (key == GameState::KEYS::K || key == GameState::KEYS::X) //go back a level
						{
							m_currentAction = A_BUY;
							m_inActions = false;
						}
						else if (key == GameState::KEYS::A || key == GameState::KEYS::LEFT)
						{
							--m_currentAction;
							if (m_currentAction < A_BUY)
							{
								m_currentAction = A_INSPECT;
							}
						}
						else if (key == GameState::KEYS::D || key == GameState::KEYS::RIGHT)
						{
							++m_currentAction;
							if (m_currentAction > A_INSPECT)
							{
								m_currentAction = A_BUY;
							}
						}
					}
				}
				else //item selection
				{
					if (key == GameState::KEYS::J || key == GameState::KEYS::Z) //select item and go to action tabs
					{
						m_currentAction = A_BUY;
						m_inActions = true;
					}
					else if (key == GameState::KEYS::K || key == GameState::KEYS::X) //go back a level
					{
						m_currentListSelection = 0;
						m_inList = false;
					}
					else if (key == GameState::KEYS::W || key == GameState::KEYS::UP)
					{
						--m_currentListSelection;
						if (m_currentListSelection < 0)
						{
							m_currentListSelection = Armor::NUM_ARMORS - 1;
						}
					}
					else if (key == GameState::KEYS::S || key == GameState::KEYS::DOWN)
					{
						++m_currentListSelection;
						if (m_currentListSelection > Armor::NUM_ARMORS - 1)
						{
							m_currentListSelection = 0;
						}
					}
				}
			}
			else //tab selection
			{
				if (key == GameState::KEYS::J || key == GameState::KEYS::Z) //select tab and go to item selection
				{
					m_inList = true;
					m_currentListSelection = 0;
				}
				else if (key == GameState::KEYS::K || key == GameState::KEYS::X) //go back to main menu
				{
					m_currentMenu = MAIN;
					m_currentTabSelection = B_WEAPONS;
				}
				else if (key == GameState::KEYS::A || key == GameState::KEYS::LEFT)
				{
					--m_currentTabSelection;
					if (m_currentTabSelection < B_WEAPONS)
					{
						m_currentTabSelection = B_POTIONS;
					}
				}
				else if (key == GameState::KEYS::D || key == GameState::KEYS::RIGHT)
				{
					++m_currentTabSelection;
					if (m_currentTabSelection > B_POTIONS)
					{
						m_currentTabSelection = B_WEAPONS;
					}
				}
			}
		}
		break;

		case B_POTIONS:
		{
			if (m_inList)
			{
				if (m_inActions) //decide what to do with selected item
				{
					if (m_isInspecting) {
						if (key == GameState::KEYS::J || key == GameState::KEYS::Z || key == GameState::KEYS::K || key == GameState::KEYS::X)
						{
							m_isInspecting = false;
						}
					}
					else {
						if (key == GameState::KEYS::J || key == GameState::KEYS::Z) //execute selection
						{
							switch (m_currentAction)
							{
							case A_BUY:
							{								
								Potion * toBuy = Potion::potionList[m_currentListSelection];
								if (*(m_character->GetCoinpouch()) >= toBuy->GetCost() && m_character->GetBackpack()->GetItemArray().GetElements() < BACKPACK_SPACE)
								{
									m_character->GetCoinpouch()->SpendMoney(toBuy->GetCost());
									m_character->GetBackpack()->AddItem(toBuy);
								}
							}
							break;

							case A_INSPECT:
							{
								m_isInspecting = true;
							}
							break;

							default:
								break;
							}
						}
						else if (key == GameState::KEYS::K || key == GameState::KEYS::X) //go back a level
						{
							m_currentAction = A_BUY;
							m_inActions = false;
						}
						else if (key == GameState::KEYS::A || key == GameState::KEYS::LEFT)
						{
							--m_currentAction;
							if (m_currentAction < A_BUY)
							{
								m_currentAction = A_INSPECT;
							}
						}
						else if (key == GameState::KEYS::D || key == GameState::KEYS::RIGHT)
						{
							++m_currentAction;
							if (m_currentAction > A_INSPECT)
							{
								m_currentAction = A_BUY;
							}
						}
					}
				}
				else //item selection
				{
					if (key == GameState::KEYS::J || key == GameState::KEYS::Z) //select item and go to action tabs
					{
						m_currentAction = A_BUY;
						m_inActions = true;
					}
					else if (key == GameState::KEYS::K || key == GameState::KEYS::X) //go back a level
					{
						m_currentListSelection = 0;
						m_inList = false;
					}
					else if (key == GameState::KEYS::W || key == GameState::KEYS::UP)
					{
						--m_currentListSelection;
						if (m_currentListSelection < 0)
						{
							m_currentListSelection = Potion::NUM_POTIONS - 1;
						}
					}
					else if (key == GameState::KEYS::S || key == GameState::KEYS::DOWN)
					{
						++m_currentListSelection;
						if (m_currentListSelection > Potion::NUM_POTIONS - 1)
						{
							m_currentListSelection = 0;
						}
					}
				}
			}
			else //tab selection
			{
				if (key == GameState::KEYS::J || key == GameState::KEYS::Z) //select tab and go to item selection
				{
					m_inList = true;
					m_currentListSelection = 0;
				}
				else if (key == GameState::KEYS::K || key == GameState::KEYS::X) //go back to main menu
				{
					m_currentMenu = MAIN;
					m_currentTabSelection = B_WEAPONS;
				}
				else if (key == GameState::KEYS::A || key == GameState::KEYS::LEFT)
				{
					--m_currentTabSelection;
					if (m_currentTabSelection < B_WEAPONS)
					{
						m_currentTabSelection = B_POTIONS;
					}
				}
				else if (key == GameState::KEYS::D || key == GameState::KEYS::RIGHT)
				{
					++m_currentTabSelection;
					if (m_currentTabSelection > B_POTIONS)
					{
						m_currentTabSelection = B_WEAPONS;
					}
				}
			}
		}
		break;

		default:
			break;
		}
	}
	break;

	case TRAIN:
	{
		if (m_inActions) //decide what to do with selected spell
		{
			if (m_isInspecting) {
				if (key == GameState::KEYS::J || key == GameState::KEYS::Z || key == GameState::KEYS::K || key == GameState::KEYS::X)
				{
					m_isInspecting = false;
				}
			}
			else {
				if (key == GameState::KEYS::J || key == GameState::KEYS::Z) //execute selection
				{
					switch (m_currentAction)
					{
					case A_BUY:
					{
						Spell * toBuy = Spell::spellList[m_currentListSelection];
						if (*(m_character->GetCoinpouch()) >= toBuy->GetCost())
						{
							m_character->GetCoinpouch()->SpendMoney(toBuy->GetCost());
							m_character->GetSpellsArr()->Insert(toBuy);
						}
					}
					break;

					case A_INSPECT:
					{
						m_isInspecting = true;
					}
					break;

					default:
						break;
					}
				}
				else if (key == GameState::KEYS::K || key == GameState::KEYS::X) //go back a level
				{
					m_currentAction = A_BUY;
					m_inActions = false;
				}
				else if (key == GameState::KEYS::A || key == GameState::KEYS::LEFT)
				{
					--m_currentAction;
					if (m_currentAction < A_BUY)
					{
						m_currentAction = A_INSPECT;
					}
				}
				else if (key == GameState::KEYS::D || key == GameState::KEYS::RIGHT)
				{
					++m_currentAction;
					if (m_currentAction > A_INSPECT)
					{
						m_currentAction = A_BUY;
					}
				}
			}
		}
		else //spell selection
		{
			if (key == GameState::KEYS::J || key == GameState::KEYS::Z) //select spell and go to action tabs
			{
				m_currentAction = A_BUY;
				m_inActions = true;
			}
			else if (key == GameState::KEYS::K || key == GameState::KEYS::X) //go back a level
			{
				m_currentMenu = MAIN;
				m_currentListSelection = 0;
				m_inList = false;
			}
			else if (key == GameState::KEYS::W || key == GameState::KEYS::UP)
			{
				--m_currentListSelection;
				if (m_currentListSelection < 0)
				{
					m_currentListSelection = Spell::NUM_SPELLS - 1;
				}
			}
			else if (key == GameState::KEYS::S || key == GameState::KEYS::DOWN)
			{
				++m_currentListSelection;
				if (m_currentListSelection > Spell::NUM_SPELLS - 1)
				{
					m_currentListSelection = 0;
				}
			}
		}
	}
	break;

	default:
		break;
	}


}

void Shop::Display()
{
	if (m_currentMenu == MAIN)
	{
		cout <<
			"                                         .e$c\"*eee..." << endl <<
			"                                       z$$$$$$.  \"*$$$$$$$$$." << endl <<
			"                                   .z$$$$$$$$$$$e. \"$$$$$$$$$$c." << endl <<
			"                                .e$$P\"\"  $$  \"\"*$$$bc.\"$$$$$$$$$$$e." << endl <<
			"                            .e$*\"\"       $$         \"**be$$$***$   3" << endl <<
			"           (                $            $F              $    4$r  'F" << endl <<
			"            )               $           4$F              $    4$F   $" << endl <<
			"           (  (            4P   \\       4$F              $     $$   3r" << endl <<
			"               )           $\"    r      4$F              3     $$r   $" << endl <<
			"         (    (            $     '.     $$F              4F    4$$   'b" << endl <<
			"          ) /\\ (          dF      3     $$    ^           b     $$L   \"L" << endl <<
			"        (  // | (`'       $        .    $$   %            $     ^$$r   \"c" << endl <<
			"      _ -.;_/ \\\\--._     JF             $$  %             4r     '$$.   3L" << endl <<
			"     (_;-// | \\ \\-'.\\   .$              $$ \"               $      ^$$r\"\"" << endl <<
			"     ( `.__ _  ___,')   $%              $$P                3r  .e*\"" << endl <<
			"      `'(_ )_)(_)_)'    '*=*********************************$$P\"" << endl <<
			"----------------------------------------------------------------------------------------------" << endl <<
			"    " << ((m_currentMainSelection == M_BUY) ? ">" : " ") << " Buy" << endl <<
			endl <<
			"    " << ((m_currentMainSelection == M_TRAIN) ? ">" : " ") << " Train" << endl <<
			endl <<
			"    " << ((m_currentMainSelection == M_CONTINUE) ? ">" : " ") << " Save and Continue" << endl;
	}
	else
	{
		if (m_currentMenu == BUY) cout << "  |BUY ITEMS|                  Money: " << m_character->GetCoinpouch()->GetMoney() << "                [X/K Back]" << endl;
		else if (m_currentMenu == TRAIN) cout << "  |TRAIN SPELLS|               Money: " << m_character->GetCoinpouch()->GetMoney() << "                [X/K Back]" << endl;
		cout << "+--------------------------------------------------------------------------------------------+" << endl;
		if (!m_inList)
		{
			if (m_currentMenu == BUY)
			{
				cout << "                  " << ((m_currentTabSelection == B_WEAPONS) ? ">" : " ") << " Weapons | " <<
					((m_currentTabSelection == B_ARMOR) ? ">" : " ") << " Armor | " <<
					((m_currentTabSelection == B_POTIONS) ? ">" : " ") << " Potions " << endl;
			}
			else
			{
				cout << endl;
			}
		}
		else if (m_inActions)
		{
			cout << "                  " << ((m_currentAction == A_BUY) ? ">" : " ") << " Buy | " <<
				((m_currentAction == A_INSPECT) ? ">" : " ") << " Inspect" << endl;
		}
		else
		{
			cout << endl;
		}
		cout << "+--------------------------------------------------------------------------------------------+" << endl <<
			endl; //line 5
		if (!m_inActions && m_inList)
		{
			if (m_currentMenu == BUY)
			{
				if (m_currentTabSelection == B_WEAPONS)
				{
					int i = 0;
					for (i; i < Weapon::NUM_WEAPONS; ++i)
					{
						cout << ((m_currentListSelection == i) ? " > " : "   ") << Weapon::weaponList[i]->GetName() << " | " << Weapon::weaponList[i]->GetCost() << endl <<
							endl;
					}
					i *= 2; //2 lines per item
					for (i; i < Game::NUM_CONSOLE_LINES - 5; ++i)
					{
						cout << endl;
					}
				}
				else if (m_currentTabSelection == B_ARMOR)
				{
					int i = 0;
					for (i; i < Armor::NUM_ARMORS; ++i)
					{
						cout << ((m_currentListSelection == i) ? " > " : "   ") << Armor::armorList[i]->GetName() << " | " << Armor::armorList[i]->GetCost() << endl <<
							endl;
					}
					i *= 2; //2 lines per item
					for (i; i < Game::NUM_CONSOLE_LINES - 5; ++i)
					{
						cout << endl;
					}
				}
				else if (m_currentTabSelection == B_POTIONS)
				{
					int i = 0;
					for (i; i < Potion::NUM_POTIONS; ++i)
					{
						cout << ((m_currentListSelection == i) ? " > " : "   ") << Potion::potionList[i]->GetName() << " | " << Potion::potionList[i]->GetCost() << endl <<
							endl;
					}
					i *= 2; //2 lines per item
					for (i; i < Game::NUM_CONSOLE_LINES - 5; ++i)
					{
						cout << endl;
					}
				}
			}
			else if (m_currentMenu == TRAIN)
			{
				int i = 0;
				for (i; i < Spell::NUM_SPELLS; ++i)
				{
					cout << ((m_currentListSelection == i) ? " > " : "   ") << Spell::spellList[i]->GetName() << " | " << Spell::spellList[i]->GetCost() << endl <<
						endl;
				}
				i *= 2; //2 lines per item
				for (i; i < Game::NUM_CONSOLE_LINES - 5; ++i)
				{
					cout << endl;
				}
			}
		}	
		else if (m_isInspecting)
		{
			if (m_currentMenu == BUY)
			{
				if (m_currentTabSelection == B_WEAPONS)
				{
					Weapon::weaponList[m_currentListSelection]->Display();
					for (int i = 0; i < Game::NUM_CONSOLE_LINES - 5 - 7; ++i)
					{
						cout << endl;
					}
				}
				else if (m_currentTabSelection == B_ARMOR)
				{
					Armor::armorList[m_currentListSelection]->Display();
					for (int i = 0; i < Game::NUM_CONSOLE_LINES - 5 - 12; ++i)
					{
						cout << endl;
					}
				}
				else if (m_currentTabSelection == B_POTIONS)
				{
					Potion::potionList[m_currentListSelection]->Display();
					for (int i = 0; i < Game::NUM_CONSOLE_LINES - 5 - 7; ++i)
					{
						cout << endl;
					}
				}
			}
			else if (m_currentMenu == TRAIN)
			{
				Spell::spellList[m_currentListSelection]->Display();
				for (int i = 0; i < Game::NUM_CONSOLE_LINES - 5 - 9; ++i)
				{
					cout << endl;
				}
			}
		}
		else
		{
			for (int i = 0; i < Game::NUM_CONSOLE_LINES - 5; ++i)
			{
				cout << endl;
			}
		}
	}
}

void Shop::Init()
{
	m_character = m_gameRef->GetCurrentChar();
}
