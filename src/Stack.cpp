#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack() : top(nullptr) {}
Stack::~Stack()
{
    clear();
}

bool Stack::isEmpty()
{
    return top == nullptr;
}

void Stack::push(string url)
{
    Node *newNode = new Node(url);
    newNode->next = top;
    top = newNode;
}

string Stack::pop()
{
    if (Stack::isEmpty())
    {
        return "";
    }
    string topURL = top->url;
    Node *temp = top;
    top = top->next;
    delete temp;
    return topURL;
}

string Stack::peek()
{
    return Stack::isEmpty() ? "" : top->url;
}

void Stack::clear()
{
    while (top)
    {
        Node *temp = top;
        top = top->next;
        delete temp;
    }
}