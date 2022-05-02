/*************************************************************
* Author: Dillon Wall
* Filename: "Minotaur.cpp"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#include "Minotaur.h"

#include <iostream>
using std::cout;
using std::endl;

Minotaur::Minotaur() : Monster("Minotaur", 20, 20, 0, 0, 6, 3, 5, "0.5.0.0")
{
}


Minotaur::~Minotaur()
{
}

void Minotaur::Display()
{
	cout <<
		"         ,     ." << endl <<
		"        /(     )\\               A" << endl <<
		"   .--.( `.___.' ).--.         /_\\" << endl <<
		"   `._ `%_&%#%$_ ' _.'     /| <___> |\\" << endl <<
		"      `|(@\\*%%/@)|'       / (  |L|  ) \\" << endl <<
		"       |  |%%#|  |       J d8bo|=|od8b L" << endl <<
		"        \\ \\$#%/ /        | 8888|=|8888 |" << endl <<
		"        |\\|%%#|/|        J Y8P\"|=|\"Y8P F" << endl <<
		"        | (.\".)%|         \\ (  |L|  ) /" << endl <<
		"    ___.'  `-'  `.___      \\|  |L|  |/" << endl <<
		"  .'#*#`-       -'$#*`.       / )|" << endl <<
		" /#%^#%*_ *%^%_  #  %$%\\    .J (__)" << endl <<
		" #&  . %%%#% ###%*.   *%\\.-'&# (__)" << endl <<
		" %*  J %.%#_|_#$.\\J* \\ %'#%*^   (__)" << endl <<
		" *#% J %$%%#|#$#$ J\\%   *   .--|(_)" << endl <<
		" |%  J\\ `%%#|#%%' / `.   _.'   |L|" << endl <<
		" |#$%||` %%%$### '|   `-'      |L|" << endl;
}
