#include <iostream>
#include "Tab.h"
// for system() fn - opens a shell to execute the passed cli cmd
#include <cstdlib>
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
    cout << "Visited: " << GREEN << url << RESET << endl;
}

void Tab::goBack()
{
    if (backwardStack.isEmpty())
    {
        cout << RED << "No previous page" << RESET << endl;
        return;
    }
    // push currentURL to forwardStack
    forwardStack.push(currentURL);
    // set currentURL to top of backwardStack
    currentURL = backwardStack.pop();
    cout << "Back to: " GREEN << currentURL << RESET << endl;
}

void Tab::goForward()
{
    if (forwardStack.isEmpty())
    {
        cout << RED << "No next page" << RESET << endl;
        return;
    }
    // push currentURL to backward
    backwardStack.push(currentURL);
    // set currentURL to top of forwardStack
    currentURL = forwardStack.pop();
    cout << "Forward to: " << GREEN << currentURL << RESET << endl;
}

void Tab::showHistory()
{
    history.showHistory();
}

void Tab::clearHistory()
{
    currentURL = "";
    history.clear();
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