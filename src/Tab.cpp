#include <iostream>
#include "Tab.h"
// for system() fn - opens a shell to execute the passed cli cmd
#include <cstdlib>
// for url validation
#include <regex>
using namespace std;

Tab::Tab(int id, bool isPrivate) : currentURL(""), tabID(id), isPrivate(isPrivate) {}
Tab::~Tab() {}

void Tab::visit(string url, string timeStamp)
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
    history.add(currentURL, timeStamp);
    cout << "Visited new page: " << B_GREEN << currentURL << RESET << endl;
}

void Tab::searchPage(string targetURL, AVL &tree)
{
    LinkedList *foundList = tree.searchVal(targetURL);
    if (foundList->isEmpty())
    {
        cout << B_RED << "Searched Page not found!" << RESET << endl;
        return;
    }
    if (!currentURL.empty())
    {
        backwardStack.push(currentURL);
        forwardStack.clear();
    }

    for (int i = 0; i < foundList->getSize(); i++)
        cout << " " << i + 1 << ". " << foundList->getURLAtIndex(i) << endl;

    int choice;
    cout << B_YELLOW << "    Enter choice of the URL to visit: ";
    cin >> choice;
    cout << RESET;
    if (choice > foundList->getSize())
    {
        cout << B_RED << "Choice out of bounds!" << RESET << endl;
        return;
    }
    currentURL = "www." + foundList->getURLAtIndex(choice - 1);
    history.add(currentURL, "");
    cout << "\nVisited searched page: " << B_GREEN << currentURL << RESET << endl;
}

void Tab::openBookmarkPage(LinkedList *bookmarkList)
{
    for (int i = 0; i < bookmarkList->getSize(); i++)
    {
        cout << i + 1 << ". " << bookmarkList->getURLAtIndex(i) << endl;
    }
    int choice;
    cout << B_YELLOW << "    Enter choice of URL to open: " << RESET;
    cin >> choice;
    if (choice > bookmarkList->getSize())
    {
        cout << B_RED << "Choice out of bounds!" << RESET << endl;
        return;
    }
    currentURL = bookmarkList->getURLAtIndex(choice - 1);
    history.add(currentURL, "");
    cout << "Visited bookmarked page: " << B_GREEN << currentURL << RESET << endl;
}

void Tab::goBack()
{
    if (backwardStack.isEmpty())
    {
        cout << B_RED << "No previous page" << RESET << endl;
        return;
    }
    // push currentURL to forwardStack
    forwardStack.push(currentURL);
    // set currentURL to top of backwardStack
    currentURL = backwardStack.pop();
    cout << "Back to: " << B_GREEN << currentURL << RESET << endl;
}

void Tab::goForward()
{
    if (forwardStack.isEmpty())
    {
        cout << B_RED << "No next page" << RESET << endl;
        return;
    }
    // push currentURL to backwardStack
    backwardStack.push(currentURL);
    // set currentURL to top of forwardStack
    currentURL = forwardStack.pop();
    cout << "Forward to: " << B_GREEN << currentURL << RESET << endl;
}

void Tab::openCurrentPage()
{
    // if url is valid open chrome browser with the url
    if (isValidURL(currentURL))
    {
        string cmd = "start " + currentURL;
        system(cmd.c_str());
        cout << B_GREEN << currentURL << RESET << " opened in default browser" << endl;
    }
    // if not valid open a custom 404 html page by passing the invalid url to display there
    else
    {
        cout << B_GREEN << currentURL << B_RED << " - Invalid url to open in browser" << RESET << endl;
        string cmd = "start ./default-page/defaultPage.html";
        system(cmd.c_str());
    }
}

bool Tab::isValidURL(const string &url)
{
    if (url.empty())
    {
        return false;
    }
    // must not contain spaces
    if (url.find(' ') != string::npos)
    {
        return false;
    }
    // must follow the standard url pattern
    regex pattern("^(https?://)?(www\\.)?[a-zA-Z0-9]+\\.[a-z]{2,}(/.*)?$");
    if (regex_match(url, pattern))
    {
        return true;
    }
    return false;
}

void Tab::closeCurrentPage()
{
    if (currentURL == "")
    {
        cout << B_RED << "No page visited" << RESET << endl;
        return;
    }
    // delete in history dll
    history.closePage(currentURL);
    if (!forwardStack.isEmpty())
    {
        currentURL = forwardStack.pop();
    }
    else if (!backwardStack.isEmpty())
    {
        currentURL = backwardStack.pop();
    }
    else
    {
        currentURL = "";
    }
}

void Tab::showHistory()
{
    history.showHistory(currentURL);
}

void Tab::clearHistory(int flag)
{
    currentURL = "";
    history.clear(flag);
}

int Tab::getTabID()
{
    // used in displayTabs fn in Browser
    return tabID;
}

HistoryNode *Tab::getHistoryHead()
{
    return history.getHead();
}

string Tab::getCurrentURL()
{
    return currentURL;
}

bool Tab::getIsPrivate()
{
    return isPrivate;
}