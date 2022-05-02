/*************************************************************
* Author: Dillon Wall
* Filename: Character.cpp
* Date Created: 11/13/18
* Modifications:
**************************************************************/

#include "Character.h"
#include "Rand.h"


Character::Character() : m_name(String("")), m_backpack(new BackPack()), m_coinpouch(new CoinPouch()), m_weapon(nullptr), m_armor(nullptr), m_spells(new DynamicArray<Spell>()), m_monsterNum(1), m_maxHealth(20), m_health(20), 
								m_maxMana(20), m_mana(20), m_attack(0), m_defense(0), m_speed(0)
{
	m_attack = Rand::GetRand(2, 4);
	m_defense = Rand::GetRand(2, 2);
	m_speed = Rand::GetRand(5, 5);
}

Character::Character(String name) : m_name(name), m_backpack(new BackPack()), m_coinpouch(new CoinPouch()), m_weapon(nullptr), m_armor(nullptr), m_spells(new DynamicArray<Spell>()), m_monsterNum(1), m_maxHealth(20), m_health(20),
								m_maxMana(20), m_mana(20), m_attack(0), m_defense(0), m_speed(0)
{
	m_attack = Rand::GetRand(2, 4);
	m_defense = Rand::GetRand(2, 2);
	m_speed = Rand::GetRand(5, 5);
}

Character::Character(String name, BackPack * backpack, CoinPouch * coinpouch) : m_name(name), m_backpack(backpack), m_coinpouch(coinpouch), m_weapon(nullptr), m_armor(nullptr), m_spells(new DynamicArray<Spell>()),
								m_monsterNum(1), m_maxHealth(20), m_health(20), m_maxMana(20), m_mana(20), m_attack(0), m_defense(0), m_speed(0)
{
	m_attack = Rand::GetRand(2, 4);
	m_defense = Rand::GetRand(2, 2);
	m_speed = Rand::GetRand(5, 5);
}


Character::~Character()
{
	delete m_spells;
	delete m_coinpouch;
	delete m_backpack;
}

Character::Character(const Character & other) : m_name(String(other.m_name)), m_backpack(new BackPack(*other.m_backpack)), m_coinpouch(new CoinPouch(*other.m_coinpouch)), m_weapon(other.m_weapon), 
								m_armor(other.m_armor), m_spells(new DynamicArray<Spell>()), m_monsterNum(other.m_monsterNum), m_maxHealth(other.m_maxHealth), m_health(other.m_health), m_maxMana(other.m_maxMana),
								m_mana(other.m_mana), m_attack(other.m_attack),	m_defense(other.m_defense), m_speed(other.m_speed)
{
	for (int i = 0; i < other.m_spells->GetElements(); ++i)
	{
		m_spells->Insert((*other.m_spells)[i]); //dont deep copy since this refers to the general spell and that spell will be deleted with the game object
	}
}

Character & Character::operator=(const Character & rhs)
{
	if (this != &rhs)
	{
		//purge
		delete m_spells;
		delete m_coinpouch;
		delete m_backpack;

		m_name = String(rhs.m_name);
		m_backpack = new BackPack(*rhs.m_backpack);
		m_coinpouch = new CoinPouch(*rhs.m_coinpouch);
		m_weapon = rhs.m_weapon;
		m_armor = rhs.m_armor;
		m_monsterNum = rhs.m_monsterNum;
		m_maxHealth = rhs.m_maxHealth;
		m_health = rhs.m_health;
		m_maxMana = rhs.m_maxMana;
		m_mana = rhs.m_mana; 
		m_attack = rhs.m_attack; 
		m_defense = rhs.m_defense; 
		m_speed = rhs.m_speed;
		m_spells = new DynamicArray<Spell>();
		for (int i = 0; i < rhs.m_spells->GetElements(); ++i)
		{
			m_spells->Insert((*rhs.m_spells)[i]); //dont deep copy since this refers to the general spell and that spell will be deleted with the game object
		}
	}

	return *this;
}

String Character::GetName() const
{
	return m_name;
}

BackPack * Character::GetBackpack() const
{
	return m_backpack;
}

CoinPouch * Character::GetCoinpouch() const
{
	return m_coinpouch;
}

void Character::EquipWeapon(Weapon * weapon)
{
	m_weapon = weapon;
}

void Character::EquipArmor(Armor * armor)
{
	m_armor = armor;
}

void Character::SetSpellsArr(DynamicArray<Spell>* spells) 
{
	delete m_spells;
	m_spells = spells;
}

void Character::SetMonsterNum(int num) 
{
	m_monsterNum = num;
}

void Character::SetHealth(int health)
{
	m_health = health;
}

void Character::SetMaxHealth(int health) 
{
	m_maxHealth = health;
}

void Character::SetMana(int mana)
{
	m_mana = mana;
}

void Character::SetMaxMana(int mana)
{
	m_maxMana = mana;
}

void Character::SetAttack(int attack)
{
	m_attack = attack;
}

void Character::SetDefense(int defense)
{
	m_defense = defense;
}

void Character::SetSpeed(int speed)
{
	m_speed = speed;
}

Weapon * Character::GetWeapon() const
{
	return m_weapon;
}

Armor * Character::GetArmor() const
{
	return m_armor;
}

DynamicArray<Spell>* Character::GetSpellsArr() const
{
	return m_spells;
}

int Character::GetMonsterNum() const
{
	return m_monsterNum;
}

int Character::GetHealth() const
{
	return m_health;
}

int Character::GetMaxHealth() const
{
	return m_maxHealth;
}

int Character::GetMana() const
{
	return m_mana;
}

int Character::GetMaxMana() const
{
	return m_maxMana;
}

int Character::GetAttack() const
{
	return m_attack;
}

int Character::GetDefense() const
{
	return m_defense;
}

int Character::GetSpeed() const
{
	return m_speed;
}

void Character::SetName(String name)
{
	m_name = name;
}

void Character::SetBackpack(BackPack * bp)
{
	delete m_backpack;
	m_backpack = bp;
}

void Character::SetCoinpouch(CoinPouch * cp)
{
	delete m_coinpouch;
	m_coinpouch = cp;
}

int Character::GetTotalAttack() const
{
	return m_attack + (m_weapon != nullptr ? m_weapon->GetAttack() : 0);
}

int Character::GetTotalDefense() const
{
	return m_defense + (m_armor != nullptr ? m_armor->GetDefense() : 0);
}

void Character::ModMana(int modVal)
{
	m_mana += modVal;
}

void Character::ModHealth(int modVal)
{
	m_health += modVal;
}

void Character::Hit(int damage)
{
	m_health -= damage;
}

void Character::Display() const
{
	m_name.Display();
	m_coinpouch->Display();
	cout << "------------------------------------------------------------" << endl;
	m_backpack->Display();
	cout << "------------------------------------------------------------" << endl;
}
