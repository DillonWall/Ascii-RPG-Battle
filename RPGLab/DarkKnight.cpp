/*************************************************************
* Author: Dillon Wall
* Filename: "DarkKnight.cpp"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#include "DarkKnight.h"

#include <iostream>
using std::cout;
using std::endl;

DarkKnight::DarkKnight() : Monster("Dark Knight", 100, 100, 50, 50, 15, 8, 12, "1.0.25.0")
{
}


DarkKnight::~DarkKnight()
{
}

void DarkKnight::Display()
{
	cout <<
		"     |  |" << endl <<
		"     |--|" << endl <<
		"     |  |" << endl <<
		"   _.+  +._" << endl <<
		"  /\\,)    /\\" << endl <<
		" :  `-._.'  ;" << endl <<
		" |      \"*--|" << endl <<
		" | \\        |" << endl <<
		" |  `.      ;" << endl <<
		" :         /|" << endl <<
		" |\\      -' |" << endl <<
		" | `.       |" << endl <<
		" :          |" << endl <<
		"  ;         |" << endl <<
		"  |      /  |" << endl <<
		"  :    .'   :" << endl;
}
