#pragma once
#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

template<class T>
class clsMyQueue 
{
	protected:

	clsDblLinkedList <T> _MyList;
	public:

	void push( T Value)
	{
		
		_MyList.InsertAtEnd(Value);
	}

	void Print( )
	{
		_MyList.PrintList( );
	}

	int Size( )
	{
		return _MyList.Size( );
	}

	int front( )
	{
		return _MyList.GetItems(0);
	}

	int back( )
	{
		return _MyList.GetItems(Size( ) - 1);
	}

	void pop( )
	{
		_MyList.DeleteFirstNode( );
	}
};

