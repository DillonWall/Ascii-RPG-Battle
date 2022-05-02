/*************************************************************
* Author: Dillon Wall
* Filename: "LinkedList.h"
* Date Created: 2018/11/29
* Modifications: 
*			- 
**************************************************************/

#pragma once

#include "Node.h"

/************************************************************************
* Class: LinkedList
*
* Purpose: LinkedList to manage data
*
* Manager functions:
* 	LinkedList();
*	LinkedList(const LinkedList<T>& other);
*	~LinkedList();
*	LinkedList<T>& operator=(const LinkedList<T>& other);
*
* Methods:
* 	void prepend(T data);
*	void append(T data);
*	void insertOrdered(T data);
*		Insert based on < operator of data
*	void purge();
*
*************************************************************************/

template <typename T>
class LinkedList
{
public:
	LinkedList();
	LinkedList(const LinkedList<T>& other);
	~LinkedList();
	LinkedList<T>& operator=(const LinkedList<T>& other);

	void prepend(T data);
	void append(T data);
	void insertOrdered(T data);
	void purge();

	T operator[](int pos);
private:
	Node<T> * m_head;
};

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
inline LinkedList<T>::LinkedList() : m_head(nullptr)
{
}

template <typename T>
inline LinkedList<T>::LinkedList(const LinkedList<T> & other) : m_head(nullptr)
{
	Node<T> * travel = other.m_head;
	Node<T> * new_travel = m_head;

	if (other.m_head != nullptr)
	{
		m_head = new Node<T>(travel->getData());
		new_travel = m_head;
		travel = travel->getNext();

		while (travel != nullptr)
		{
			new_travel->setNext(new Node<T>(travel->getData()));
			new_travel = new_travel->getNext();
			travel = travel->getNext();
		}
	}
}

template <typename T>
inline LinkedList<T>::~LinkedList()
{
	purge();
}

template <typename T>
inline LinkedList<T> & LinkedList<T>::operator=(const LinkedList<T> & other)
{
	if (this != &other) {
		purge();

		//DEEP COPY
		Node<T> * travel = other.m_head;
		Node<T> * new_travel = m_head;

		if (other.m_head != nullptr)
		{
			m_head = new Node<T>(travel->getData());
			new_travel = m_head;
			travel = travel->getNext();

			while (travel != nullptr)
			{
				new_travel->setNext(new Node<T>(travel->getData()));
				new_travel = new_travel->getNext();
				travel = travel->getNext();
			}
		}
	}

	return *this;
}

template <typename T>
inline void LinkedList<T>::prepend(T data)
{
	Node<T> * nn = new Node<T>(data);

	nn->setNext(m_head);
	m_head = nn;
}

template <typename T>
inline void LinkedList<T>::append(T data)
{
	Node<T> * nn = new Node<T>(data);

	if (m_head == nullptr)
	{
		m_head = nn;
	}
	else
	{
		Node<T> * travel = m_head;
		while (travel->getNext() != nullptr)
		{
			travel = travel->getNext();
		}
		travel->setNext(nn);
	}
}

template <typename T>
inline void LinkedList<T>::insertOrdered(T data)
{
	Node<T> * nn = new Node<T>(data);

	if ((m_head == nullptr) || (nn->getData() < m_head->getData()))
	{
		nn->setNext(m_head);
		m_head = nn;
	}
	else
	{
		Node<T> * travel = m_head;
		Node<T> * trail = nullptr;

		while ((travel != nullptr) && (travel->getData() < nn->getData()))
		{
			trail = travel;
			travel = travel->getNext();
		}
		trail->setNext(nn);
		nn->setNext(travel);
	}
}

template <typename T>
inline void LinkedList<T>::purge()
{
	Node<T> * trail = m_head;

	while (m_head != nullptr) {
		m_head = m_head->getNext();
		delete trail;
		trail = m_head;
	}
}

template<typename T>
inline T LinkedList<T>::operator[](int pos)
{
	Node<T> * travel = m_head;

	for (int i = 0; i < pos; ++i)
	{
		if (travel != nullptr)
		{
			travel = travel->getNext();
		}
	}

	return travel->getData();
}
