/*************************************************************
* Author: Dillon Wall
* Filename: "Node.h"
* Date Created: 2018/11/29
* Modifications: 
*			- 11/29/18 -
**************************************************************/

#pragma once

/************************************************************************
* Class: Node
*
* Purpose: Node of data for LinkedList
*
* Manager functions:
* 	Node(T data);
*	~Node();
*
* Methods:
* 	Node<T> * getNext();
*	void setNext(Node<T> * next);
*	const T getData();
*	void setData(T data);
*
*************************************************************************/

template <typename T>
class Node
{
public:
	Node(T data);
	~Node();

	Node<T> * getNext();
	void setNext(Node<T> * next);
	const T getData();
	void setData(T data);
private:
	T m_data;
	Node<T> * m_next;
};

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
Node<T>::Node(T data) : m_data(data), m_next(nullptr)
{
}

template <typename T>
Node<T>::~Node()
{
	delete m_data;
}

template <typename T>
Node<T> * Node<T>::getNext()
{
	return m_next;
}

template <typename T>
void Node<T>::setNext(Node<T> * next)
{
	m_next = next;
}

template <typename T>
const T Node<T>::getData()
{
	return m_data;
}

template <typename T>
void Node<T>::setData(T data)
{
	m_data = data;
}