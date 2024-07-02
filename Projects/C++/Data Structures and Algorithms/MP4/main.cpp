/*Mustafa Shah*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "linkedlist.h"

using namespace std;

void generateList(doublyLinkedList<int>& l1, int size) {
    for (int i = 0; i < size; i++) {
        int randInt1 = rand() % 101;
        while (l1.search(randInt1) != nullptr) {
            randInt1 = rand() % 101;
        }
        l1.insert(randInt1);
    }
}

template <typename T>
doublyLinkedList<T> mergeLists(doublyLinkedList<T>& l1, doublyLinkedList<T>& l2) {
    doublyLinkedList<T> result;
    LinkedListIterator<T> curr1 = l1.begin();
    LinkedListIterator<T> curr2 = l2.begin();
    
    while (curr1 != l1.end() && curr2 != l2.end()) {
        if (*curr1 == *curr2) {
            result.insert(*curr1);
            ++curr1;
            ++curr2;
        } else if (*curr1 < *curr2) {
            result.insert(*curr1);
            ++curr1;
        } else {
            result.insert(*curr2);
            ++curr2;
        }
    }
    
    while (curr1 != l1.end()) {
        result.insert(*curr1);
        ++curr1;
    }
    
    while (curr2 != l2.end()) {
        result.insert(*curr2);
        ++curr2;
    }
    
    return result;
}

void sumAndMean(doublyLinkedList<int>& l) {
    LinkedListIterator<int> curr = l.begin();
    float mean;
    int sum = 0;
    
    while (curr != l.end()) {
        sum += *curr;
        ++curr;
    }
    
    mean = static_cast<float>(sum) / l.length();
    
    cout << "\nThe sum of the final list's elements is: " << sum << endl;
    cout << "The average of the final list is: " << mean;
}

int main()
{
    srand(time(0));
    doublyLinkedList<int> list1, list2; 
    generateList(list1, 20);
    generateList(list2, 15);
    cout << "List 1: ";
    list1.print();
    cout << "List 2: ";
    list2.print();
    cout << "Merged List: ";
    doublyLinkedList<int> list3 = mergeLists(list1, list2);
    list3.print();
    sumAndMean(list3);
    
    return 0;
}