/*************************************************************
* Author: Dillon Wall
* Filename: String.cpp
* Date Created: 10/10/18
* Modifications:
*			- 10/16/18 - Added operator== and renamed functions to fit standard
**************************************************************/

#include "String.h"

#include <iostream>
using std::cout;
using std::endl;
using std::strcmp;

String::String() : m_str(nullptr)
{
	//cout << "String default ctor..." << endl;

	m_str = new char[strlen("") + 1];
	strcpy(m_str, "");
}

String::String(const char in_ch) : m_str(nullptr)
{
	//cout << "String 1 arg arr ctor..." << endl;

	m_str = new char[2];
	m_str[0] = in_ch;
	m_str[1] = '\0';
}

String::String(const char * in_str) : m_str(nullptr)
{
	//cout << "String 1 arg arr ctor..." << endl;

	m_str = new char[strlen(in_str) + 1];
	strcpy(m_str, in_str);
}

String::~String()
{
	//cout << "String dtor..." << endl;

	delete[] m_str;
}

String::String(const String & other) : m_str(nullptr)
{
	//cout << "String copy ctor..." << endl;

	m_str = new char[strlen(other.m_str) + 1];
	strcpy(m_str, other.m_str);
}

String & String::operator=(const String & other)
{
	//cout << "String op=..." << endl;

	if (this != &other) {
		delete[] m_str;

		m_str = new char[strlen(other.m_str) + 1];
		strcpy(m_str, other.m_str);
	}

	return *this;
}

bool String::operator==(const String & rhs) const
{
	return (strcmp(m_str, rhs.m_str) == 0 );
}

void String::Display() const
{
	cout << m_str << endl;
}

void String::Upper()
{
	for (int i = 0; i < strlen(m_str) + 1; ++i)
	{
		m_str[i] = toupper(m_str[i]);
	}
}

void String::Lower()
{
	for (int i = 0; i < strlen(m_str) + 1; ++i)
	{
		m_str[i] = tolower(m_str[i]);
	}
}

char * String::GetCharArr()
{
	return m_str;
}

String String::itos(int i)
{
	char * buffer = new char[100];
	// copy int to char
	snprintf(buffer, 100, "%d", i);

	String retStr(buffer);

	delete[] buffer;

	return retStr;
}

String String::operator+(const char * rhs)
{
	char* temp = new char[strlen(m_str) + strlen(rhs) + 1];
	strcpy(temp, m_str);
	strcat(temp, rhs);

	String retVal(temp);

	delete[] temp;

	return retVal;
}

String String::operator+(const String & rhs)
{
	char* temp = new char[strlen(m_str) + strlen(rhs.m_str) + 1];
	strcpy(temp, m_str);
	strcat(temp, rhs.m_str);

	String retVal(temp);

	delete[] temp;

	return retVal;
}

ostream & operator<<(ostream & os, const String & rhs)
{
	os << rhs.m_str;

	return os;
}
