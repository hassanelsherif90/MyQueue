#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDblLinkedList
{
protected:
    int _Size = 0;

public:
    class Node
    {
    public:
        T value;
        Node *next;
        Node *prev;
    };

    Node *head = NULL;

    void InsertAtBeginning(T value)
    {

        Node *newNode = new Node();
        newNode->value = value;
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL)
        {
            head->prev = newNode;
        }

        head = newNode;
        _Size++;
    }

    void PrintNodeDetails()
    {

        if (head->prev != NULL)
            cout << head->prev->value;
        else
            cout << "NULL";

        cout << " <--> " << head->value << " <--> ";

        if (head->next != NULL)
            cout << head->next->value << "\n";
        else
            cout << "NULL";
    }

    void PrintListDetails()
    {
        cout << "\n\n";
        while (head != NULL)
        {
            PrintNodeDetails(head);
            head = head->next;
        }
    }

    void PrintList()
    {
        Node *Current = head;

        while (Current != NULL)
        {
            cout << Current->value << " ";
            Current = Current->next;
        }
        cout << "\n";
    }

    Node *Find(T Value)
    {
        Node *Current = head;
        while (Current != NULL)
        {

            if (Current->value == Value)
                return Current;

            Current = Current->next;
        }

        return NULL;
    }

    void InsertAtAfter(Node *current, T value)
    {
        Node *newNode = new Node();
        newNode->value = value;
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL)
        {
            current->next->prev = newNode;
        }
        current->next = newNode;
        _Size++;
    }

    void InsertAtEnd(T value)
    {

        Node *newNode = new Node();
        newNode->value = value;
        newNode->next = NULL;
        if (head == NULL)
        {
            newNode->prev = NULL;
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
        _Size++;
    }

    void DeleteNode(Node *&NodeToDelete)
    {
        if (head == NULL || NodeToDelete == NULL)
        {
            return;
        }

        if (head == NodeToDelete)
        {
            head = NodeToDelete->next;
        }

        if (NodeToDelete->next != NULL)
        {
            NodeToDelete->next->prev = NodeToDelete->prev;
        }

        if (NodeToDelete->prev != NULL)
        {
            NodeToDelete->prev->next = NodeToDelete->next;
        }

        delete NodeToDelete;

        _Size--;
    }

    void DeleteFirstNode()
    {

        if (head == NULL)
        {
            return;
        }

        Node *temp = head;
        head = head->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }

        delete temp;
        _Size--;
    }

    void DeleteLastNode()
    {
        if (head == NULL)
        {
            return;
        }

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node *current = head;
        while (current->next->next != NULL)
        {
            current = current->next;
        }

        Node *temp = current->next;
        current->next = NULL;
        delete temp;
        _Size--;
    }

    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return (_Size == 0 ? true : false);
    }

    void Clear()
    {
        while (_Size > 0)
        {
            DeleteFirstNode();
        }
    }

    void Reverse()
    {
        Node *Current = head;
        Node *temp = nullptr;

        while (Current != nullptr)
        {
            temp = Current->prev;
            Current->prev = Current->next;
            Current->next = temp;
            Current = Current->prev;
        }

        if (temp != nullptr)
        {
            head = temp->prev;
        }
    }

    Node* GetNode(int Index)
    {
        int Counter = 0;
        if (Index < 0 || Index > _Size - 1)
            return NULL;

        Node* Current = head;

        while (Current != NULL && (Current->next != NULL))
        {
            if (Index == Counter)
            {
                break;
            }

            Current = Current->next;
            Counter++;
        }

        return Current;
    }

    T GetItems(int Index)
    {
        Node* ItemNode = GetNode(Index);

        if (ItemNode == NULL)
            return NULL;
        return ItemNode->value;
    }

    bool UpdateItems(int Index, T Value)
    {
        Node* ItemNode = GetNode(Index);

        if (ItemNode != NULL)
        {
            ItemNode->value = Value;
            return true;

        }
        else
        {
            return false;
        }

    }

    bool InsertAfter(int Index, T Value)
    {
        Node* ItemNode = GetNode(Index);

        if (ItemNode != NULL)
        {
            InsertAtAfter(ItemNode, Value);
            return true;
        }
        else
        {
            return false;
        }
    }

};
