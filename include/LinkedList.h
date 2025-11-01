#pragma once
#include <string>
#include <iostream>
class LinkedList
{
private:
    class Node
    {
    public:
        Node *next, *prev;
        std::string url;
        Node(std::string url)
        {
            this->url = url;
        }
    };
    Node *head, *tail;
    int size;
public:
    LinkedList();
    ~LinkedList();

    bool isEmpty();
    int getSize();
    void insertAtEnd(std::string url);
    std::string getURLAtIndex(int index);
};