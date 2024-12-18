//--------------------------------------------------------------------
//
//                            listlnk.h
//
//--------------------------------------------------------------------
// #pragma warning( disable : 4290 )
#pragma once
#include <stdexcept>
#include <new>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

template < class T >         // Forward declaration of the List class
class List;

template < class T >
class ListNode                // Facilitator class for the List class
{
private:

    ListNode(const T &nodeData, ListNode *nextPtr);
    T dataItem;      // List data item
    ListNode *next;   // Pointer to the next list node

    friend class List<T>;
};

//--------------------------------------------------------------------

template < class T >
class List
{
public:

    List(int ignored = 0);
    ~List();
    void insert(const T &newData);        // Insert after cursor
    void remove();                      // Remove data item
    void replace(const T &newData);    // Replace data item
    void clear();

    bool isEmpty() const;
    bool isFull() const;          

    // List iteration operations
    void gotoBeginning();          
    void gotoEnd();    
    bool gotoNext();                      
    bool gotoPrior();                  
    T getCursor() const;                   // Return item
    void showStructure() const;
    void moveToBeginning();                    // Move to beginning
    void insertBefore(const T &newElement);  // Insert before cursor

private:
    ListNode<T> *head,     // Pointer to the beginning of the list
        *cursor;   // Cursor pointer
};

template < class T >
ListNode<T>::ListNode(const T &nodeDataItem, ListNode<T> *nextPtr) : dataItem(nodeDataItem), next(nextPtr)
{}

//--------------------------------------------------------------------

template < class T >
List<T>::List(int ignored) : head(0), cursor(0)
{}

//--------------------------------------------------------------------

template < class T >
List<T>:: ~List()
{
    clear();
}

//--------------------------------------------------------------------

template < class T >
void List<T>::insert(const T &newDataItem) 
{
    if (head == 0)             // Empty list
    {
        head = new ListNode<T>(newDataItem, 0);
        cursor = head;
    }
    else                         // After cursor
    {
        cursor->next = new ListNode<T>(newDataItem, cursor->next);
        cursor = cursor->next;
    }
}

//--------------------------------------------------------------------

template < class T >
void List<T>::remove() 
{
    ListNode<T> *p,   // Pointer to removed node
        *q;   // Pointer to prior node

     // Requires that the list is not empty
    if (head == 0)
        throw logic_error("list is empty");

    if (cursor == head)             // Remove first item
    {
        p = head;
        head = head->next;
        cursor = head;
    }
    else if (cursor->next != 0)     // Remove middle item
    {
        p = cursor->next;
        cursor->dataItem = p->dataItem;
        cursor->next = p->next;
    }
    else                              // Remove last item
    {
        p = cursor;
        for (q = head; q->next != cursor; q = q->next)
            ;
        q->next = 0;
        cursor = head;
    }

    delete p;
}

//--------------------------------------------------------------------

template < class T >
void List<T>::replace(const T &newDataItem) 
{
    if (head == 0)
        throw logic_error("list is empty");

    cursor->dataItem = newDataItem;
}

//--------------------------------------------------------------------

template < class T >
void List<T>::clear()
{
    ListNode<T> *p,      // Points to successive nodes
    *nextP;                  // Points to next node
    p = head;
    while (p != 0)
    {
        nextP = p->next;
        delete p;
        p = nextP;
    }

    head = 0;
    cursor = 0;
}

//--------------------------------------------------------------------

template < class T >
bool List<T>::isEmpty() const
{
    return (head == 0);
}
//--------------------------------------------------------------------

template < class T >
bool List<T>::isFull() const
{
    T testDataItem;
    ListNode<T> *p;

    try
    {
        p = new ListNode<T>(testDataItem, 0);
    }
    catch (bad_alloc)
    {
        return true;
    }

    delete p;
    return false;
}

//--------------------------------------------------------------------

template < class T >
void List<T>::gotoBeginning()
{
    if (head != 0)
        cursor = head;
    else
        throw logic_error("list is empty");
}

//--------------------------------------------------------------------

template < class T >
void List<T>::gotoEnd() 
{
    if (head != 0)
        for (; cursor->next != 0; cursor = cursor->next)
            ;
    else
        throw logic_error("list is empty");
}

//--------------------------------------------------------------------

template < class T >
bool List<T>::gotoNext()
{
    bool result;   // Result returned

    if (cursor->next != 0)
    {
        cursor = cursor->next;
        result = true;
    }
    else
        result = false;

    return result;
}

//--------------------------------------------------------------------

template < class T >
bool List<T>::gotoPrior()

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding item in the list and returns 1.
// Otherwise, returns 0.

{
    ListNode<T> *p;   // Pointer to prior node
    int result;        // Result returned

    if (cursor != head)
    {
        for (p = head; p->next != cursor; p = p->next)
            ;
        cursor = p;
        result = true;
    }
    else
        result = false;

    return result;
}

//--------------------------------------------------------------------

template < class T >
T List<T>::getCursor() const
{
    if (head == 0)
        throw logic_error("list is empty");

    return cursor->dataItem;
}

//--------------------------------------------------------------------

template < class T >
void List<T>::showStructure() const
{
    ListNode<T> *p;   // Iterates through the list

    if (head == 0)
        cout << "Empty list" << endl;
    else
    {
        for (p = head; p != 0; p = p->next)
            if (p == cursor)
                cout << "[" << p->dataItem << "] ";
            else
                cout << p->dataItem << " ";
        cout << endl;
    }
}

//--------------------------------------------------------------------

template < class T >
void List<T>::moveToBeginning()

// Removes the item marked by the cursor from a list and
// reinserts it at the beginning of the list. Moves the cursor to the
// beginning of the list.
{
    ListNode<T> *p;   //  Pointer to prior node
                       // Requires that the list is not empty
    if (head == 0)
        throw logic_error("list is empty");

    if (cursor != head)
    {
        for (p = head; p->next != cursor; p = p->next)
            ;
        p->next = cursor->next;
        cursor->next = head;
        head = cursor;
    }
}

//--------------------------------------------------------------------

template < class T >
void List<T>::insertBefore(const T &newDataItem)

// Inserts newDataItem before the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) item in the list.
// In either case, moves the cursor to newDataItem.

{
    if (head == 0)             // Empty list
    {
        head = new ListNode<T>(newDataItem, 0);
        cursor = head;
    }
    else                         // Before cursor
    {
        cursor->next = new ListNode<T>(cursor->dataItem, cursor->next);
        cursor->dataItem = newDataItem;
    }
}