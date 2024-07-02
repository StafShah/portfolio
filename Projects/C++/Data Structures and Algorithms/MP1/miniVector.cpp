#include "miniVector.h"

using namespace std;

template <typename T>
miniVector<T>::miniVector(size_t size) : vSize(0), capacity(0), ptr(NULL)
{
    if (size == 0)
        return ;
    ptr = new T[size];
    vSize = size;
    for (size_t i = 0; i < vSize; i++)
        ptr[i] = T();
}
template <typename T>
miniVector<T>::miniVector(const miniVector<T>& obj)
{
    ptr = new T[obj.vSize];
    this->vSize = obj.vSize;
    for (size_t i = 0; i < obj.vSize; i++)
        ptr[i] = obj.ptr[i];
}
template <typename T>
miniVector<T>::~miniVector()
{
    if (ptr != NULL)
    {
        delete [] ptr;
    }
}
template <typename T>
miniVector<T>& miniVector<T>::operator= (const miniVector<T>& rhs)
{
    this->vSize = rhs.vSize;
    for (size_t i = 0; i < vSize; ++i)
        ptr[i] = rhs.ptr[i];
    return *this;
}
template <typename T>
T& miniVector<T>::operator[] (size_t i)
{
    if (i < 0 || i >= vSize)
        throw out_of_range("Index out of range");
    return ptr[i];
}
template <typename T>
void miniVector<T>::push_back(const T& obj)
{
    if (vSize == capacity)
    {
        if(capacity == 0)
        {
            capacity = 1;
            ptr = new T[1];
        }
        else
        {
            T *temp;
            temp = new T[2 * capacity];
            for (size_t i = 0; i < vSize; i++)            
                temp[i] = ptr[i];
            capacity *= 2;
            if (ptr != NULL)
                delete [] ptr;
            ptr = temp;            
        }
    }
    ptr[vSize] = obj;
    vSize++;
}
template <typename T>
void miniVector<T>::pop_back()
{
    if (vSize == 0)
        throw out_of_range("Vector is empty");
    vSize--;
}
template <typename T>
T& miniVector<T>::back()
{
    if (vSize == 0)
        throw out_of_range("Vector is empty");
    return ptr[vSize - 1];
}
template <typename T>
size_t miniVector<T>::size() const
{
    return vSize;
}
template <typename T>
bool miniVector<T>::empty() const
{
    return (vSize == 0);
}