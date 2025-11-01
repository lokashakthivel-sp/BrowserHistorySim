#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

LinkedList::~LinkedList()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

bool LinkedList::isEmpty()
{
    return head == nullptr;
}

int LinkedList::getSize()
{
    return size;
}

void LinkedList::insertAtEnd(std::string url)
{
    Node *newNode = new Node(url);
    size++;
    if (tail == nullptr)
    {
        head = tail = newNode;
        return;
    }
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

std::string LinkedList::getURLAtIndex(int index)
{
    Node *current = head;
    for (int i = 0; i < index && current != nullptr; i++)
    {
        current = current->next;
    }
    return current->url;
}