#include "queue.h"

template <typename T>
arrQueue<T>::arrQueue():
    qfront(0), qback(0), count(0)
{}

template <typename T>
void arrQueue<T>::push(const T& item)
{
    if (count == MAXQSIZE)
        throw baseException("arrQueue push(): queue full");
    // perform a circular queue insertion
    queueArray[qback] = item;
    qback = (qback+1) % MAXQSIZE;
    count++;
}

template <typename T>
void arrQueue<T>::pop()
{
    if (count == 0)
        throw baseException("arrQueue pop(): empty queue");
    // perform a circular queue deletion
    qfront = (qfront+1) % MAXQSIZE;
    count--;
}

template <typename T>
T& arrQueue<T>::front()
{
    if (count == 0)
        throw baseException("arrQueue front(): empty queue");
    return queueArray[qfront];
}

template <typename T>
const T& arrQueue<T>::front() const
{
    if (count == 0)
        throw baseException("arrQueue front(): empty queue");
    return queueArray[qfront];
}

template <typename T>
int arrQueue<T>::size() const
{
    return count;
}

template <typename T>
bool arrQueue<T>::empty() const
{
    return count == 0;
}

template <typename T>
bool arrQueue<T>::full() const
{
    return count == MAXQSIZE;
}