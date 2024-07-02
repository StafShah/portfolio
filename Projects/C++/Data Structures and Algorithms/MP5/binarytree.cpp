#include "binarytree.h"

template <typename T>
BinaryTreeType<T>::~BinaryTreeType()
{
    destroy(root);
}
template <typename T>
void BinaryTreeType<T>::destroy(nodeType<T> * &p)
{
    if (p != nullptr)
    {
        destroy(p->lLink);
        destroy(p->rLink);
        // cout << "Destroying " << p->info << endl;
        delete p;
        p = nullptr;
    }
}
template <typename T>
void BinaryTreeType<T>::postOrderTraversal() const
{
    postOrder(root);
}
template <typename T>
void BinaryTreeType<T>::postOrder(nodeType<T> *p) const
{
    if (p != nullptr)
    {
        postOrder(p->lLink);
        postOrder(p->rLink);
        cout << p->info << " ";
    }
}
template <typename T>
void BinaryTreeType<T>::preOrderTraversal() const
{
    preOrder(root);
}
template <typename T>
void BinaryTreeType<T>::preOrder(nodeType<T> *p) const
{
    if (p != nullptr)
    {
        cout << p->info << " ";
        preOrder(p->lLink);
        preOrder(p->rLink);
    }
}
template <typename T>
void BinaryTreeType<T>::inOrderTraversal() const
{
    inOrder(root);
}
template <typename T>
void BinaryTreeType<T>::inOrder(nodeType<T> *p) const
{
    if (p != nullptr)
    {
        inOrder(p->lLink);
        cout << p->info << " ";
        inOrder(p->rLink);
    }
}
template <typename T>
BinaryTreeType<T>::BinaryTreeType()
{
    root = nullptr;
}
template <typename T>
bool BinaryTreeType<T>::isEmpty() const
{
    return (root == nullptr);
}
template <typename T>
int BinaryTreeType<T>::getLeafCount() const {
    return countLeaves(root);
}
template <typename T>
int BinaryTreeType<T>::countLeaves(nodeType<T> *p) const {
    if (p == nullptr) {
        return 0;
    }
    if (p->lLink == nullptr && p->rLink == nullptr) {
        return 1;
    }
    return countLeaves(p->lLink) + countLeaves(p->rLink);
}
template <typename T>
int BinaryTreeType<T>::getHeight() const {
    return calculateHeight(root);
}
template <typename T>
int BinaryTreeType<T>::calculateHeight(nodeType<T> *p) const {
    if (p == nullptr) {
        return 0;
    }
    int leftHeight = calculateHeight(p->lLink);
    int rightHeight = calculateHeight(p->rLink);
    return 1 + max(leftHeight, rightHeight);
}