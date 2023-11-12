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

	T GetItem(int Index)
	{
		return _MyList.GetItems(Index);
	}

	void Reverse( )
	{
		_MyList.Reverse( );
	}

	void UpdateItems(int Index, T Value )
	{
		_MyList.UpdateItems( Index, Value);
	}

	void InsertAfter(int Index , T Value)
	{
		_MyList.InsertAfter(Index , Value);
	}

	void InsertAtFront(T Value)
	{
		_MyList.InsertAtBeginning(Value);
	}

	void InsertAtBack(T Value)
	{
		_MyList.InsertAtEnd(Value);
	}

	void Clear( )
	{
		_MyList.Clear( );
	}
};

