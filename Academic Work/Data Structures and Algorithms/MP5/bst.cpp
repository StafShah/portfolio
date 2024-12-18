#include "bst.h"

template <typename T>
void BST<T>::deleteNode(const T& item)
{
    nodeType<T> *curr;
    nodeType<T> *trail;
    bool found = false;
    if (this->root == nullptr)
        cout << "Nothing to delete" << endl;
    else
    {
        curr = this->root;
        trail = curr;
        while (curr != nullptr && !found)
        {
            if (curr->info == item)
                found = true;
            else
            {
                trail = curr;
                if (curr->info > item)
                    curr = curr->lLink;
                else
                    curr = curr->rLink;
            }
        }
        if (found)
        {
            if (curr == this->root)
                deleteFromTree(this->root);
            else if (trail->info > item)
                deleteFromTree(trail->lLink);
            else
                deleteFromTree(trail->rLink);
        }
        else
            cout << "Item is not found" << endl;
    }
}
template <typename T>
void BST<T>::deleteFromTree(nodeType<T> * &p)
{
    nodeType<T> *curr;
    nodeType<T> *trail;
    nodeType<T> *temp;
    if (p == nullptr)
        cout << "Nothing to delete" << endl;
    else if (p->lLink == nullptr && p->rLink == nullptr)
    {
        temp = p;
        p = nullptr;
        delete temp;
    } 
    else if (p->lLink == nullptr)
    {
        temp = p;
        p = temp->rLink;
        delete temp;
    }
    else if (p->rLink == nullptr)
    {
        temp = p;
        p = temp->lLink;
        delete temp;
    }
    else
    {
        curr = p->lLink;
        trail = nullptr;
        while (curr->rLink != nullptr)
        {
            trail = curr;
            curr = curr->rLink;
        }
        p->info = curr->info;
        if (trail == nullptr) // curr didnot move
            p->lLink = curr->lLink;
        else
            trail->rLink = curr->lLink;
        delete curr;
    }
}
template <typename T>
void BST<T>::insert(const T& item)
{
    nodeType<T> *newNode;
    nodeType<T> *current;
    nodeType<T> *trail;
    newNode = new nodeType<T>;
    newNode->info = item;
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;
    if (this->root == nullptr)
        this->root = newNode;
    else
    {
        current = this->root;
        trail = nullptr;
        while (current != nullptr)
        {
            trail = current;
            if (current->info == item)
            {
                cout << "No duplicates allowed" << endl;
                return;
            }
            else if (current->info > item)
                current = current->lLink;
            else
                current = current->rLink;
        }
        if (trail->info > item)
            trail->lLink = newNode;
        else
            trail->rLink = newNode;
    }
}
template <typename T>
vector<T> BST<T>::getPreOrderTraversal() const {
    std::vector<T> result;
    preOrderCapture(this->root, result);
    return result;
}
template <typename T>
void BST<T>::preOrderCapture(nodeType<T> *p, vector<T>& result) const {
    if (p != nullptr) {
        result.push_back(p->info);
        postOrderCapture(p->lLink, result);
        postOrderCapture(p->rLink, result);
    }
}
template <typename T>
vector<T> BST<T>::getPostOrderTraversal() const {
    std::vector<T> result;
    postOrderCapture(this->root, result);
    return result;
}
template <typename T>
void BST<T>::postOrderCapture(nodeType<T> *p, vector<T>& result) const {
    if (p != nullptr) {
        postOrderCapture(p->lLink, result);
        postOrderCapture(p->rLink, result);
        result.push_back(p->info);
    }
}