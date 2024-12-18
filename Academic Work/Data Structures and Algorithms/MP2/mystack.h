#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class myStack
{
private:
    T *ptr;
    int length;
    int first;
public:
    myStack();
    myStack(int s);
    bool empty() const;
    bool full() const;
    int size() const;
    void pop();
    void push(const T& item);
    T& top();
    const myStack<T>& operator=(const myStack<T>& rhs);
};

// template <typename T>
// myStack<T>::myStack()
// {
//     length = 10;
//     first = -1;
//     ptr = new T[length];
// }

// template <typename T>
// myStack<T>::myStack(int s)
// {
//     if (s > 0)
//         length = s;
//     else
//         length = 10;
//     first = -1;
//     ptr = new T[length];
// }

// template <typename T>
// bool myStack<T>::empty() const
// {
//     return first == -1;
// }

// template <typename T>
// bool myStack<T>::full() const
// {
//     return first == length - 1;
// }

// template <typename T>
// int myStack<T>::size() const
// {
//     return first + 1;
// }

// template <typename T>
// void myStack<T>::pop()
// {
//     if (empty())
//         throw invalid_argument("Stack is empty");
//     first--;
// }

// template <typename T>
// void myStack<T>::push(const T& item)
// {
//     if (full())
//         throw invalid_argument("Stack is full");
//     first++;
//     ptr[first] = item;
// }

// template <typename T>
// T& myStack<T>::top()
// {
//     if (empty())
//         throw invalid_argument("Stack is empty");
//     return ptr[first];
// }

// template <typename T>
// const myStack<T>& myStack<T>::operator=(const myStack<T>& rhs)
// {
//     if (rhs.empty())
//         this->first = -1;
//     delete [] this->ptr;
//     this->length = rhs.length;
//     this->ptr = new T[length];
//     this->first = rhs.first;
//     for (int i = 0; i <= first; i++)
//         this->ptr[i] = rhs.ptr[i];
//     return *this;
// }