#pragma once
#include <string>
#include <vector>
#include "Page.h"
#include "LinkedList.h"
struct Node
{
    Page page;
    int height;
    Node *left, *right;
    Node(Page newPage)
    {
        page = newPage;
    }
};

class AVL
{
private:
    Node *createNode(Page newPage);

    int height(Node *node);

    Node *rightRotate(Node *k2);
    Node *leftRotate(Node *k2);

    Node *insert(Page page, Node *t);
    std::vector<Page> search(std::string x, Node *t, std::vector<Page> &matchingURL);

    void destroy(Node *root);

public:
    Node *root;
    AVL();
    ~AVL();
    void insertVal(Page page);
    std::vector<Page> searchVal(std::string x);
    void displayInorder(Node *root);
};
