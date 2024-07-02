/*Mustafa Shah*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "bst.h"

using namespace std;

vector<string> phraseToVector(const string& s) {
    stringstream ss(s);
    string word;
    vector<string> result;
    
    while (ss >> word) {
        result.push_back(word);
    }
    
    return result;
}

void insertWordsToBST(BST<string>& bst, const vector<string>& s) {
    for (const string& word : s) {
        bst.insert(word);
    }
}

int main()
{
    string phrase = "This is Washtenaw Community College in Ann Arbor Michigan";
    BST<string> T1, T2, T3;
    insertWordsToBST(T1, phraseToVector(phrase));
    T1.postOrderTraversal();
    cout << "\nLeaves: " << T1.getLeafCount() << endl;
    cout << "Height: " << T1.getHeight() << endl;
    insertWordsToBST(T2, T1.getPostOrderTraversal());
    T2.preOrderTraversal();
    cout << "\nLeaves: " << T2.getLeafCount() << endl;
    cout << "Height: " << T2.getHeight() << endl;
    insertWordsToBST(T3, T2.getPreOrderTraversal());
    T3.inOrderTraversal();
    cout << "\nLeaves: " << T3.getLeafCount() << endl;
    cout << "Height: " << T3.getHeight() << endl;

    return 0;
}