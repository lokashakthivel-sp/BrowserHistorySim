#include <iostream>
#include "Tab.h"
using namespace std;

Tab::Tab(int id) : currentURL(""), tabID(id) {}
Tab::~Tab() {}

void Tab::visit(string url)
{
    // clear forwardStack and push string-currentURL to backwardStack when currentURL is not empty
    if (!currentURL.empty())
    {
        backwardStack.push(currentURL);
        forwardStack.clear();
    }
    // set currentURL
    currentURL = url;
    // add to history
    history.add(url);
    cout << "Visited: " << url << endl;
}

void Tab::goBack()
{
    if (backwardStack.isEmpty())
    {
        cout << "No previous page" << endl;
        return;
    }
    // push currentURL to forwardStack
    forwardStack.push(currentURL);
    // set currentURL to top of backwardStack
    currentURL = backwardStack.pop();
    cout << "Back to: " << currentURL << endl;
}

void Tab::goForward()
{
    if (forwardStack.isEmpty())
    {
        cout << "No next page" << endl;
        return;
    }
    // push currentURL to backward
    backwardStack.push(currentURL);
    // set currentURL to top of forwardStack
    currentURL = forwardStack.pop();
    cout << "Forward to: " << currentURL << endl;
}

void Tab::showHistory()
{
    history.showHistory();
}

int Tab::getTabID()
{
    // used in displayTabs fn in Browser
    return tabID;
}
/* 
void Tab::setTabID(int id)
{
    tabID=id;
} */

HistoryNode *Tab::getHistoryHead()
{
    return history.getHead();
}

string Tab::getCurrentURL()
{
    return currentURL;
}