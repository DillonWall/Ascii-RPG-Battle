/*************************************************************
* Author: Dillon Wall
* Filename: "Enchantress.cpp"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#include "Enchantress.h"

#include <iostream>
using std::cout;
using std::endl;

Enchantress::Enchantress() : Monster("Enchantress", 25, 25, 100, 100, 10, 2, 10, "0.8.0.0")
{
}


Enchantress::~Enchantress()
{
}

void Enchantress::Display()
{
	cout <<
		"                      \\'/" << endl <<
		"                    -= * =-" << endl <<
		"                .-\"-. / #,_" << endl <<
		"               / /\\_ \\  `#|\\" << endl <<
		"              / /')'\\ \\  /#/" << endl <<
		"             (  \\ = /  )/\\/#" << endl <<
		"              )  ) (  (/  \\" << endl <<
		"             (_.;`\"`;._)  |" << endl <<
		"            / (  \\|/  )   |" << endl <<
		"           /  /\\-'^'-/\\   |" << endl <<
		"          |  \\| )=@=(  \\_/" << endl <<
		"          |  /\\/     \\" << endl <<
		"          | /\\ \\      ;" << endl <<
		"          \\(// /'     |" << endl <<
		"             \\/       |" << endl <<
		"              |       |" << endl;
}
