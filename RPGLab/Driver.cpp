/*************************************************************
*
* Lab / Assignment: RPG Lab (Lab8)
*
* Overview:
*		This program is a turn based RPG where you try to slay 10 monsters, 
*		getting money along the way to buy stronger items and spells in order
*		to beat the harder enemies. Upon beating the last enemy the player has won
*		and is left to continue fight the last enemy and getting more money if they wish
*
* Input:
*		W, A, S, D or Arrow keys are used to navigate menus
*		J,K or Z,X for select (J,Z) and back (K,X) buttons
*		Esc is used to exit the game and save. The game should not be exited in any other
*			way except from the "Exit Game" option in the main menu. If the game is exited
*			in an incorrect way it may result in memory leaks and progress not being saved
*
* Output:
*		Depending on the current game state, the output is a different menu where
*		the player can navigate and see their cursor indicated by a ">"
*
**************************************************************/

/*************************************************************
* Author: Dillon Wall
* Filename: Driver.cpp
* Date Created: 10/1/18
* Modifications: 
*			- 10/10/18 - Updated main and addCosts to account for
*						 new String class
*			- 11/13/18 - Removed addCosts function and reimplemented in CoinPouch,
*					   - Added LoadChars() and SaveChars(c,numChars) functions,
*					   - Modified main to load, display, then save chars
*			- 11/29/18 - Modified to work with game object and run game correctly, taking in inputs to update and display
**************************************************************/

#include "Game.h"

#include <conio.h>
#include <Windows.h>

int main() 
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	///Resize Console Window///
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, 800, 19 * Game::NUM_CONSOLE_LINES, TRUE); //22 lines on screen, plus 1 for bottom line

	///Set Console Font///
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = 32;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	
	///Main Game Loop///
	Game game;

	bool shouldExit = false;

	while (!shouldExit)
	{
		char input = getch();
		//cout << static_cast<int>(input);

		shouldExit = game.Update(input);
		game.Display();
	}

	return 0;
}