/*************************************************************
* Author: Dillon Wall
* Filename: String.h
* Date Created: 10/10/18
* Modifications:
*			- 10/16/18 - Added operator== and renamed functions to fit standard
*			- 11/11/18 - Added both operator<< 
*			- 11/29/18 - Fixed memory leak in operator+
**************************************************************/

#pragma once

#include <iostream>
using std::ostream;

/************************************************************************
* Class: Potion
*
* Purpose: This class represents a potion object to be used in an RPG
*
* Manager functions:
*	String();
*		default constructor initialized m_str to ""
*	String(char in_ch);
*		constructor that initialized m_str to a char
*	String(const char * in_str);
*		constructor that deep copies a char array to m_str
*	~String();
*	String(const String& other);
*	String& operator=(const String& rhs);
*	bool operator==(const String& rhs);
*
* Methods:
*
*	void Display();
*		displays the string to the console and goes to the next line
*	void Upper();
*		converts the string to uppercase
*	void Lower();
*		converts the string to lowercase
*	char * GetCharArr();
*		return m_str*
*
*	static String itos(int i);
*		converts an integer into a string and returns the result
*
*************************************************************************/
class String
{
public:
	String();
	String(char in_ch);
	String(const char * in_str);
	~String();
	String(const String& other);
	String& operator=(const String& rhs);
	bool operator==(const String& rhs) const;

	void Display() const;
	void Upper();
	void Lower();
	char * GetCharArr();

	static String itos(int i);

	String operator+(const char* rhs);
	String operator+(const String& rhs);
	friend ostream& operator<<(ostream& os, const String& rhs);
private:
	char * m_str;
};

