/*************************************************************
* Author: Dillon Wall
* Filename: "Skeleton.cpp"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#include "Skeleton.h"

#include <iostream>
using std::cout;
using std::endl;

Skeleton::Skeleton() : Monster("Skeleton", 15, 15, 5, 5, 4, 2, 4, "0.1.0.0")
{
}


Skeleton::~Skeleton()
{
}

void Skeleton::Display()
{
	cout <<
		"                 .-\"```\"-." << endl <<
		"                /         \\" << endl <<
		"                |  _   _  |" << endl <<
		"                | (_\ /_) |" << endl <<
		"                (_   A   _)" << endl <<
		"                 | _____ |" << endl <<
		"                 \\`\"\"\"\"\"`/" << endl <<
		"                  '-.-.-'" << endl <<
		"                   _:=:_                   \\\\|" << endl <<
		"            .-\"\"\"\"`_'='_`\"\"\"\"-.           \\///" << endl <<
		"           (`,-- -`\\   /`- --,`)          (`/" << endl <<
		"           / //`-_--| |--_-`\\\\ \\         .//" << endl <<
		"          / /(_-_  _| |_  _-_)\\ \\       ///" << endl <<
		"         / / (_- __ \\ / __ -_) \\ \\     ///" << endl <<
		"        / /  (_ -_ - ^ - _- _)  \\ \\   ///" << endl <<
		"       / /   (_-  _ /=\\ _ - _)   \\ \\ '//" << endl;
}
