/*************************************************************
* Author: Dillon Wall
* Filename: "Rand.h"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#pragma once

#include <cstdlib>
#include <time.h>

/************************************************************************
* Class: Rand
*
* Purpose: Static class for getting a random number
*
* Manager functions:
*
* Methods:
* 	static void Init();
* 		needs to be called to initialize random seed based on time
*	static int GetRand(int range, int low = 0);
*		returns random number with a range and starting value (default 0)
*
*************************************************************************/

class Rand
{
public:
	static void Init();
	static int GetRand(int range, int low = 0);
private:
	Rand() {}
};

