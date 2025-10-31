#pragma once
#include <string>
#include <vector>
struct Node
{
    std::string data;
    int height;
    Node *left, *right;
};

class AVL
{
private:
    Node *createNode(std::string x);

    int height(Node *node);

    Node *rightRotate(Node *k2);
    Node *leftRotate(Node *k2);

    Node *insert(std::string x, Node *t);
    std::vector<Node *> search(std::string x, Node *t, std::vector<Node *> &matchingURL);

public:
    Node *root;
    AVL();

    void insertVal(std::string x);
    std::vector<Node *> searchVal(std::string x);
    void displayInorder(Node *root);
};
