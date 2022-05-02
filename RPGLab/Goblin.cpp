/*************************************************************
* Author: Dillon Wall
* Filename: "Goblin.cpp"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#include "Goblin.h"

#include <iostream>
using std::cout;
using std::endl;

Goblin::Goblin() : Monster(String("Goblin"), 10, 10, 0, 0, 4, 1, 2, "0.0.25.0")
{
}


Goblin::~Goblin()
{
}

void Goblin::Display()
{
	cout <<
		endl <<
		endl <<
		endl <<
		endl <<
		endl <<
		"                                            ,      ,   " << endl <<
		"                                           /(.-\"\"-.)\\" << endl <<
		"                                       |\\  \\/      \\/  /|" << endl <<
		"                                       | \\ / =.  .= \\ / |" << endl <<
		"                                       \\( \\   o\\/o   / )/" << endl <<
		"                                        \\_, '-/  \\-' ,_/" << endl <<
		"                                          /   \\__/   \\" << endl <<
		"                                          \\ \\__/\\__/ /" << endl <<
		"                                        ___\\ \\|--|/ /___" << endl <<
		"                                      /`    \\      /    `\\" << endl <<
		"                                     /       '----'       \\" << endl;
}
