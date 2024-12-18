#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct NodeType
{
    T info;
    NodeType<T> *nextPtr;
    NodeType<T> *prevPtr;
};
template <typename T>
class LinkedListIterator
{
public:
    LinkedListIterator() { currPtr = nullptr; }
    LinkedListIterator(NodeType<T> *ptr) { currPtr = ptr; }
    T operator* () { return currPtr->info; }
    LinkedListIterator<T> operator++()
    {
        currPtr = currPtr->nextPtr;
        return *this;
    }
    bool operator!=(const LinkedListIterator<T>& rhs)
    {
        return (currPtr != rhs.currPtr);
    }
    bool operator==(const LinkedListIterator<T>& rhs)
    {
        return (currPtr == rhs.currPtr);
    }
private:
    NodeType<T> *currPtr;
};
template <typename T>
class doublyLinkedList
{
public:
    doublyLinkedList();
    void initialize();
    bool isEmpty() const;
    void destroy();
    void print() const;
    int length() const;
    void reversePrint() const;
    void reversePrintUsingRecursion(NodeType<T>* curr) const;
    void reversePrintUsingRecursion() const;
    T front() const;
    T back() const;
    NodeType<T>* search(const T& item) const;
    void insert(const T& item);
    void deleteNode(const T& item);
    LinkedListIterator<T> begin();
    LinkedListIterator<T> end();
protected:
    NodeType<T> *frontPtr;
    NodeType<T> *lastPtr;
    int count;
};
// template <typename T>
// LinkedListIterator<T> doublyLinkedList<T>::begin()
// {
//     LinkedListIterator<T> temp(frontPtr);
//     return temp;
// }
// template <typename T>
// LinkedListIterator<T> doublyLinkedList<T>::end()
// {
//     return nullptr;
// }

// template <typename T>
// NodeType<T>* doublyLinkedList<T>::search(const T& item) const
// {
//     NodeType<T> *curr = frontPtr;
//     for (int i = 0; i < count; i++)
//     {
//         if (curr->info == item)
//         {
//             // cout << "returning " << curr->info << endl;
//             return curr;
//         }
//         else if (curr->info > item)
//             return nullptr;
//         curr = curr->nextPtr;
//     }
//     return nullptr;
// }
// template <typename T>
// void doublyLinkedList<T>::deleteNode(const T& item)
// {
//     NodeType<T> *curr = search(item);
//     if (curr == nullptr)
//         // cout << "Nothing to delete or not match" << endl;
//         ;
//     else
//     {
//         if (curr == frontPtr && curr == lastPtr)    // only one node
//             initialize();
//         else if (curr == frontPtr)
//         {
//             frontPtr = curr->nextPtr;
//             frontPtr->prevPtr = nullptr;
//             count--;
//             delete curr;
//         }
//         else if (curr == lastPtr)
//         {
//             // cout << "Deleting the last node" << endl;
//             lastPtr = curr->prevPtr;
//             lastPtr->nextPtr = nullptr;
//             count--;
//             delete curr;
//         }
//         else
//         {
//             curr->nextPtr->prevPtr = curr->prevPtr;
//             curr->prevPtr->nextPtr = curr->nextPtr;
//             count--;
//             delete curr;
//         }
//     }
// }
// template <typename T>
// doublyLinkedList<T>::doublyLinkedList()
// {
//     frontPtr = nullptr;
//     lastPtr = nullptr;
//     count = 0;
// }
// template <typename T>
// void doublyLinkedList<T>::destroy()
// {
//     NodeType<T> *temp;
//     while (frontPtr != nullptr)
//     {
//         temp = frontPtr;
//         frontPtr = frontPtr->nextPtr;
//         delete temp;
//     }
//     lastPtr = nullptr;
//     count = 0;
// }
// template <typename T>
// void doublyLinkedList<T>::initialize()
// {
//     destroy();
// }
// template <typename T>
// bool doublyLinkedList<T>::isEmpty() const
// {
//     return frontPtr == nullptr;
// }
// template <typename T>
// int doublyLinkedList<T>::length() const
// {
//     return count;
// }
// template <typename T>
// void doublyLinkedList<T>::print() const
// {
//     NodeType<T> *temp = frontPtr;
//     while (temp != nullptr)
//     {
//         cout << temp->info << ", ";
//         temp = temp->nextPtr;
//     }
//     cout << endl;
// }
// template <typename T>
// void doublyLinkedList<T>::reversePrintUsingRecursion(NodeType<T>* curr) const
// {
//     if (curr != nullptr)
//     {
//         reversePrintUsingRecursion(curr->nextPtr);
//         cout << curr->info << ", ";
//     }
// }
// template <typename T>
// void doublyLinkedList<T>::reversePrintUsingRecursion() const
// {
//     reversePrintUsingRecursion(frontPtr);
// }
// template <typename T>
// void doublyLinkedList<T>::reversePrint() const
// {
//     NodeType<T> *temp = lastPtr;
//     while (temp != nullptr)
//     {
//         cout << temp->info << ", ";
//         temp = temp->prevPtr;
//     }
//     cout << endl;
// }
// template <typename T>
// T doublyLinkedList<T>::front() const
// {
//     return frontPtr->info;
// }
// template <typename T>
// T doublyLinkedList<T>::back() const
// {
//     return lastPtr->info;
// }
// template <typename T>
// void doublyLinkedList<T>::insert(const T& item)
// {
//     NodeType<T> *curr;
//     NodeType<T> *newNode = new NodeType<T>;
//     newNode->info = item;
//     newNode->nextPtr = nullptr;
//     newNode->prevPtr = nullptr;
//     if (isEmpty())
//     {
//         frontPtr = newNode;
//         lastPtr = newNode;
//         count++;
//         return;
//     }
//     curr = frontPtr;
//     while (curr != nullptr)        // search
//     {
//         if (curr->info >= item)
//             break;
//         curr = curr->nextPtr;
//     }
//     if (curr == frontPtr)            // insert before first
//     {
//         newNode->nextPtr = frontPtr;
//         frontPtr->prevPtr = newNode;
//         frontPtr = newNode;
//         count++;
//     }
//     else
//     {
//         // insert in the middle
//         if (curr != nullptr)
//         {
//             newNode->nextPtr = curr;
//             newNode->prevPtr = curr->prevPtr;
//             curr->prevPtr = newNode;
//             newNode->prevPtr->nextPtr = newNode;
//         }
//         else
//         {
//             newNode->prevPtr = lastPtr;
//             lastPtr->nextPtr = newNode;
//             lastPtr = newNode;
//         }
//         count++;
//     }
// }