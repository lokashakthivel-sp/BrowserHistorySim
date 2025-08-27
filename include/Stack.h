#pragma once
#include <string>
// stack to move forward and backward in tab history
class Stack
{
private:
    struct Node
    {
        std::string url;
        Node *next;
        Node(std::string url) : url(url), next(nullptr) {}
    };
    Node *top;

public:
    Stack();
    ~Stack();

    void push(std::string url);
    std::string pop();
    std::string peek();
    bool isEmpty();
    void clear();
};
