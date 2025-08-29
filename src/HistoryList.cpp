#include <iostream>
#include "HistoryList.h"
using namespace std;

HistoryList::HistoryList() : head(nullptr), tail(nullptr) {}
HistoryList::~HistoryList()
{
    clear();
}

void HistoryList::add(string url)
{
    HistoryNode *newNode = new HistoryNode(url);
    // add new url to last of the history list
    if (head == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void HistoryList::showHistory()
{
    if (!head)
    {
        cout << RED << "No history to show" << RESET << endl;
        return;
    }
    cout << YELLOW << "Full History" << RESET << endl;
    HistoryNode *temp = head;
    while (temp)
    {
        cout << temp->url << endl;
        temp = temp->next;
    }
}

void HistoryList::clear()
{
    cout << YELLOW << "History Cleared" << RESET << endl;
    // clearing history list
    while (head)
    {
        HistoryNode *temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

HistoryNode *HistoryList::getHead()
{
    // needed in FileManager for saving and loading
    return head;
}