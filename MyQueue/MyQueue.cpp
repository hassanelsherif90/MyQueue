
#include <iostream>
#include "clsMyQueue.h"

using namespace std;

int main()
{
    clsMyQueue <int> MyQueue;

    MyQueue.push(10);
    MyQueue.push(20);
    MyQueue.push(30);
    MyQueue.push(40);
    MyQueue.push(50);


    cout << "\nQueue: \n";
    MyQueue.Print( );

    cout << "\nQueue Size: " << MyQueue.Size( );
    cout << "\nQueue Front: " << MyQueue.front( );
    cout << "\nQueue Back: " << MyQueue.back( );

    MyQueue.pop( );

    cout << "\n\nQueue after pop() : \n";
    MyQueue.Print( );

    //Extension #1
    cout << "\n\nItem (2) : " << MyQueue.GetItem(2);

    //Exteinsion #2
    MyQueue.Reverse( );
    cout << "\n\nQueue after revese() : \n";
    MyQueue.Print( );

    
    //Exteinsion #3
    MyQueue.UpdateItems(2, 600 );
    cout << "\n\nQueue after Updating Item(2) : \n";
    MyQueue.Print( );

    
    
    //Exteinsion #4
    MyQueue.InsertAfter(2, 800 );
    cout << "\n\nQueue after Inserting  800 : \n";
    MyQueue.Print( );
    
    
    //Exteinsion #5
    MyQueue.InsertAtFront(1000 );
    cout << "\n\nQueue after Inserting  1000 : \n";
    MyQueue.Print( );
    
    //Exteinsion #6
    MyQueue.InsertAtBack(2000 );
    cout << "\n\nQueue after Inserting  2000 : \n";
    MyQueue.Print( );


    //Exteinsion #7
    MyQueue.Clear( );
    cout << "\n\nQueue after Clear : \n";
    MyQueue.Print( );





    system("pause>0");
}

