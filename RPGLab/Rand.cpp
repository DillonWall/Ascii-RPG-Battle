/*************************************************************
* Author: Dillon Wall
* Filename: "Rand.cpp"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#include "Rand.h"



void Rand::Init()
{
	srand(time(0));
}

int Rand::GetRand(int range, int low)
{
	if (range == 0) range = 1;
	return rand() % range + low;
}
