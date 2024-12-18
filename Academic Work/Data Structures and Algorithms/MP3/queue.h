#pragma once
#include <stdexcept>

using namespace std;

const int MAXQSIZE = 50;

template <typename T>
class arrQueue
{
    public:
        arrQueue();
        void push(const T& item);
        void pop();
        T& front();
        const T& front() const;
        int size() const;
        bool empty() const;
        bool full() const;
    private:
        T queueArray[MAXQSIZE];
        int qfront, qback;
        int count;
};

// template <typename T>
// arrQueue<T>::arrQueue():
//     qfront(0), qback(0), count(0)
// {}

// template <typename T>
// void arrQueue<T>::push(const T& item)
// {
//     if (count == MAXQSIZE)
//         throw invalid_argument("arrQueue push(): queue full");
//     // perform a circular queue insertion
//     queueArray[qback] = item;
//     qback = (qback+1) % MAXQSIZE;
//     count++;
// }

// template <typename T>
// void arrQueue<T>::pop()
// {
//     if (count == 0)
//         throw invalid_argument("arrQueue pop(): empty queue");
//     // perform a circular queue deletion
//     qfront = (qfront+1) % MAXQSIZE;
//     count--;
// }

// template <typename T>
// T& arrQueue<T>::front()
// {
//     if (count == 0)
//         throw invalid_argument("arrQueue front(): empty queue");
//     return queueArray[qfront];
// }

// template <typename T>
// const T& arrQueue<T>::front() const
// {
//     if (count == 0)
//         throw invalid_argument("arrQueue front(): empty queue");
//     return queueArray[qfront];
// }

// template <typename T>
// int arrQueue<T>::size() const
// {
//     return count;
// }

// template <typename T>
// bool arrQueue<T>::empty() const
// {
//     return count == 0;
// }

// template <typename T>
// bool arrQueue<T>::full() const
// {
//     return count == MAXQSIZE;
// }