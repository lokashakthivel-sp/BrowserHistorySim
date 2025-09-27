#include <iostream>
#include <chrono>
#include "HistoryList.h"
using namespace std;

HistoryList::HistoryList() : head(nullptr), tail(nullptr) {}
HistoryList::~HistoryList()
{
    clear(0);
}

void HistoryList::add(string url, string timeStamp = "")
{
    if (timeStamp == "")
    {
        auto now = chrono::system_clock::now();
        time_t time = chrono::system_clock::to_time_t(now);
        timeStamp = ctime(&time);
    }
    if (timeStamp.back() == '\n')
        timeStamp.pop_back();
    HistoryNode *newNode = new HistoryNode(url, timeStamp);
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

void HistoryList::showHistory(string currentUrl)
{
    if (!head)
    {
        cout << B_RED << "  No history to show" << RESET << endl;
        return;
    }
    HistoryNode *temp = head;
    int i = 0;
    while (temp)
    {
        if (temp->url == currentUrl)
        {
            cout << B_CYAN << "  ->";
        }
        else
        {
            cout << RESET << "    ";
        }
        cout << ++i << ". " << temp->url << " - " << temp->timeStamp << RESET << endl;
        temp = temp->next;
    }
}

void HistoryList::closePage(string url)
{
    if (head == nullptr)
    {
        cout << B_RED << "No page visited" << RESET << endl;
        return;
    }
    HistoryNode *temp = head;
    while (temp != nullptr && temp->url != url)
    {
        temp = temp->next;
    }
    cout << B_GREEN << temp->url << RESET << " Closed" << endl;
    if (temp == nullptr)
    {
        cout << B_GREEN << url << B_RED << " not visited" << RESET << endl;
        return;
    }
    // deleting head
    if (temp->prev == NULL)
        head = temp->next;
    else
        temp->prev->next = temp->next;

    // except deleting tail
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;

    delete temp;
}

void HistoryList::clear(int flag)
{
    // to print only when explicitly called
    if (flag)
    {
        cout << B_YELLOW << "History Cleared" << RESET << endl;
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