/*************************************************************
* Author: Dillon Wall
* Filename: "Dragon.cpp"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#include "Dragon.h"

#include <iostream>
using std::cout;
using std::endl;


Dragon::Dragon() : Monster("Dragon", 150, 150, 100, 100, 30, 20, 20, "10.53.75.99")
{
}


Dragon::~Dragon()
{
}

void Dragon::Display()
{
	cout <<
		endl <<
		"<~>" << endl <<
		" \\ \\,_____" << endl <<
		"       ___`\\" << endl <<
		"       \\('>\\`-__" << endl <<
		"         ~      ~~~--__            **              ***" << endl <<
		"               ______  (@\\   *******  ****    *******    ******" << endl <<
		"              /******~~~~\\|**********************************" << endl <<
		"      \\       `--____******************************************" << endl <<
		"     / ~~~--_____    ~~~/ ***************************************" << endl <<
		"                 `~~~~~         ******************************" << endl <<
		"                                      ****    **************" << endl <<
		"                                        ***       ***********" << endl <<
		"                                                        ********" << endl <<
		endl <<
		endl;
}
