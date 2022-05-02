/*************************************************************
* Author: Dillon Wall
* Filename: DynamicArray.h
* Date Created: 10/16/18
* Modifications:
*			- 11/12/18 - Added operator [] and Display()
*			- 11/29/18 - template-ed class
*			
**************************************************************/

#pragma once

#include <iostream>
using std::cout;
using std::endl;

/************************************************************************
* Class: DynamicArray
*
* Purpose: This class is used to manage a dynamic array for the Potion class
*
* Manager functions:
*	DynamicArray();
*		default constructor initialized m_array to nullptr (default when empty)
*		and m_elements to 0
*	~DynamicArray();
*	DynamicArray(const DynamicArray<T>& other);
*	DynamicArray<T>& operator=(const DynamicArray<T>& rhs);
*
* Methods:
*
*	int GetElements();
*		returns m_elements
*	void Insert(T * to_add);
*		inserts a T object onto the end of the m_array, reallocating for 
*		more memory, and increases m_elements by 1
*	void Delete(T * to_delete);
*		deletes an equivalent (==) T object from m_array, reallocating for 
*		less memory, and decreases m_elements by 1
*	void Display() const;
*		Iterates over each T and calls its Display function
*	Potion operator[](int pos);
*		Returns the T at a position pos
*
*	int Find(T * target);
*		searches through m_array and returns the index of a T equivalent (==)
*		to target. Throws EXCEPTION_OBJECT_NOT_FOUND when object is not found
*
*************************************************************************/

template <typename T>
class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();
	DynamicArray(const DynamicArray<T>& other);
	DynamicArray<T>& operator=(const DynamicArray<T>& rhs);
	
	int GetElements();
	void Insert(T * to_add);
	void Delete(T * to_delete);
	void Display() const;

	T * operator[](int pos);

	static const int EXCEPTION_INDEX_OUT_OF_BOUNDS = -2;
private:
	int Find(T * target);

	T ** m_array;
	int m_elements;
};

#include <new>

const int EXCEPTION_OBJECT_NOT_FOUND = -1;

template <typename T>
inline DynamicArray<T>::DynamicArray() : m_array(nullptr), m_elements(0)
{
}

template <typename T>
inline DynamicArray<T>::~DynamicArray()
{
	//Dont want to delete objects themselves since they are shared and are pointers. Delete on a per use basis

	//for (int i = 0; i < m_elements; ++i)
	//{
	//	delete m_array[i];
	//}

	delete[] m_array;
}

template <typename T>
inline DynamicArray<T>::DynamicArray(const DynamicArray<T> & other) : m_array(nullptr), m_elements(0)
{
	m_elements = other.m_elements;
	m_array = new T*[other.m_elements];
	for (int i = 0; i < other.m_elements; ++i)
	{
		m_array[i] = other.m_array[i];
	}
}

template <typename T>
inline DynamicArray<T> & DynamicArray<T>::operator=(const DynamicArray<T> & rhs)
{
	if (this != &rhs)
	{
		delete[] m_array;

		m_elements = rhs.m_elements;
		m_array = new T*[rhs.m_elements];
		for (int i = 0; i < rhs.m_elements; ++i)
		{
			m_array[i] = rhs.m_array[i];
		}
	}

	return *this;
}

template <typename T>
inline int DynamicArray<T>::GetElements()
{
	return m_elements;
}

template <typename T>
inline void DynamicArray<T>::Insert(T * to_add)
{
	//make temp copy with one extra memory location
	T ** temp = nullptr;
	try
	{
		temp = new T*[m_elements + 1];
	}
	catch (...)
	{
		cout << "Error creating new dynamic array of size: " << (m_elements + 1) << ", exiting program..." << endl;
		exit(-1);
	}
	for (int i = 0; i < m_elements; ++i)
	{
		temp[i] = m_array[i];
	}

	//insert the item at the end
	temp[m_elements] = to_add;

	//release old memory and store new memory
	//for (int i = 0; i < m_elements; ++i)
	//{
	//	delete m_array[i];
	//}
	delete[] m_array;
	m_array = temp;

	//modify num elements
	++m_elements;
}

template <typename T>
inline void DynamicArray<T>::Delete(T * to_delete)
{
	if (m_array != nullptr)
	{
		int loc = 0;
		try
		{
			loc = Find(to_delete);
		}
		catch (int except)
		{
			if (except == EXCEPTION_OBJECT_NOT_FOUND)
				cout << "DynamicArray.cpp :: Object not found in array" << endl;
			return; //No need to keep deleting now
		}

		//make temp copy with one less memory location
		T ** temp = nullptr;
		try
		{
			temp = new T*[m_elements - 1];
		}
		catch (...)
		{
			cout << "Error creating new potion array of size: " << (m_elements + 1) << ", exiting program..." << endl;
			exit(-1);
		}

		//only copy elements before and after loc
		int pos = 0;
		for (int i = 0; i < loc; ++i)
		{
			temp[pos] = m_array[i];
			++pos;
		}
		for (int i = loc + 1; i < m_elements; ++i)
		{
			temp[pos] = m_array[i];
			++pos;
		}

		//release old memory and store new memory
		//for (int i = 0; i < m_elements; ++i)
		//{
		//	delete m_array[i];
		//}
		delete[] m_array;
		m_array = temp;

		//modify num elements
		--m_elements;
	}
}

template <typename T>
inline void DynamicArray<T>::Display() const
{
	for (int i = 0; i < m_elements; ++i)
	{
		m_array[i]->Display();
	}
}

template <typename T>
inline T * DynamicArray<T>::operator[](int pos)
{
	if (pos >= m_elements) throw EXCEPTION_INDEX_OUT_OF_BOUNDS;
	return m_array[pos];
}

template <typename T>
inline int DynamicArray<T>::Find(T * target)
{
	int retVal = 0;

	if (m_array != nullptr)
	{
		for (int i = 0; i < m_elements; ++i)
		{
			if (m_array[i] == target)
			{
				retVal = i;
				return retVal;
			}
		}

		throw EXCEPTION_OBJECT_NOT_FOUND;
	}

	return retVal;
}
