// #pragma once
#include "AVL.h"
#include <iostream>
// for string comparison
#include <algorithm>

AVL::AVL()
{
    root = nullptr;
}

int max(const int &a, const int &b)
{
    return (a < b) ? b : a;
}

Node *AVL::createNode(std::string x)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->height = 0;
    newNode->left = newNode->right = nullptr;

    return newNode;
}

int AVL::height(Node *node)
{
    if (node == nullptr)
        return -1;
    else
        return node->height;
}

// left - left case - rotate right
Node *AVL::rightRotate(Node *k2)
{
    // here k1 is the left child, k2 is parent
    Node *k1 = k2->left;

    k2->left = k1->right;
    k1->right = k2;

    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), height(k2)) + 1;

    return k1;
}

// right - right case - rotate left
Node *AVL::leftRotate(Node *k2)
{
    // here k1 is the right child, k2 is parent
    Node *k1 = k2->right;

    k2->right = k1->left;
    k1->left = k2;

    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->right), height(k2)) + 1;

    return k1;
}

Node *AVL::insert(std::string x, Node *t)
{
    if (t == nullptr)
    {
        t = createNode(x);
        return t;
    }
    else
    {
        if (t->data > x)
        {
            // insert into left side of t
            t->left = insert(x, t->left);
            // if property violated we check if the x is placed in the left or right of the //* left child
            if (height(t->left) - height(t->right) == 2)
            {
                // if inserted into //* left of left child
                if (t->left->data > x)
                    t = rightRotate(t);
                // if inserted into //* right of left child
                else
                {
                    // first left rotate the left child and inserted one(right side), three nodes will form a chain
                    t->left = leftRotate(t->left);
                    // then right rotate the left child and root, now the inverted V will form
                    t = rightRotate(t);
                }
            }
        }
        else if (t->data < x)
        {
            // insert into right side of t
            t->right = insert(x, t->right);
            // if property violated we check if the x is placed in the left or right of the //* right child
            if (height(t->right) - height(t->left) == 2)
            {
                // if inserted into //* right of right child
                if (t->right->data < x)
                    t = leftRotate(t);
                // if inserted into //* left of right child
                else
                {
                    // first right rotate the right child and inserted one(left side), three nodes will form a chain
                    t->right = rightRotate(t->right);
                    // then left rotate the right child and root, now the inverted V will form
                    t = leftRotate(t);
                }
            }
        }
    }
    t->height = max(height(t->left), height(t->right)) + 1;
    return t;
}

LinkedList *AVL::search(std::string x, Node *t, LinkedList *matchingURL)
{
    if (t == nullptr)
        return matchingURL;

    if (t->data.find(x) != std::string::npos)
    {
        matchingURL->insertAtEnd(t->data);
    }
    if (t->data > x)
        return search(x, t->left, matchingURL);
    else
        return search(x, t->right, matchingURL);
}

void AVL::insertVal(std::string x)
{
    root = insert(x, root);
}

LinkedList *AVL::searchVal(std::string x)
{
    transform(x.begin(), x.end(), x.begin(), ::tolower);
    LinkedList *matchingURL = new LinkedList();
    return search(x, root, matchingURL);
    ;
}

void AVL::displayInorder(Node *root)
{
    if (root == nullptr)
        return;
    displayInorder(root->left);
    std::cout << root->data << " ";
    displayInorder(root->right);
}