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
    cout << YELLOW << "History" << RESET << endl;
    HistoryNode *temp = head;
    while (temp)
    {
        cout << temp->url << endl;
        temp = temp->next;
    }
}

void HistoryList::closePage(string url)
{
    if (head == nullptr)
    {
        cout << RED << "No page visited" << RESET << endl;
        return;
    }
    HistoryNode *temp = head;
    while (temp != nullptr && temp->url != url)
    {
        temp = temp->next;
    }
    cout << GREEN << temp->url << RESET << "Closed" << endl;
    if (temp == nullptr)
    {
        cout << GREEN << url << RED << " not visited" << RESET << endl;
    }
    // deleting head
    if (temp->prev == NULL)
        head = temp->next;
    else
        temp->prev->next = temp->next;

    // except deleting tail
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

void HistoryList::clear(int flag)
{
    // to print only when explicitly called
    if (flag)
    {
        cout << YELLOW << "History Cleared" << RESET << endl;
    }
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