/*************************************************************
* Author: Dillon Wall
* Filename: "Vampire.cpp"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#include "Vampire.h"

#include <iostream>
using std::cout;
using std::endl;


Vampire::Vampire() : Monster("Vampire", 50, 50, 100, 100, 9, 5, 13, "0.20.0.0")
{
}


Vampire::~Vampire()
{
}

void Vampire::Display()
{
	cout <<
		endl <<
		endl <<
		endl <<
		"          _..._" << endl <<
		"        .'     '." << endl <<
		"       ; __   __ ;" << endl <<
		"       |/  \\ /  \\|" << endl <<
		"     |\\| -- ' -- |/|" << endl <<
		"     |(| \\o| |o/ |)|" << endl <<
		"     _\\|     >   |/_" << endl <<
		"  .-'  | ,.___., |  '-." << endl <<
		"  \\    ;  V'-'V  ;    /" << endl <<
		"   `\\   \\       /   /`" << endl <<
		"     `\\  '-...-'  /`" << endl <<
		"       `\\  / \\  /`" << endl <<
		"         `\\\\_//`" << endl;
}
