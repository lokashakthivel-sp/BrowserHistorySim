#include <iostream>
#include "Tab.h"
// for system() fn - opens a shell to execute the passed cli cmd
#include <cstdlib>
// for url validation
#include <regex>
using namespace std;

Tab::Tab(int id) : currentURL(""), tabID(id) {}
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
    history.add(url, timeStamp);
    cout << "Visited: " << GREEN << currentURL << RESET << endl;
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
    // push currentURL to backwardStack
    backwardStack.push(currentURL);
    // set currentURL to top of forwardStack
    currentURL = forwardStack.pop();
    cout << "Forward to: " << GREEN << currentURL << RESET << endl;
}

void Tab::openCurrentPage()
{
    // if url is valid open chrome browser with the url
    if (isValidURL(currentURL))
    {
        string cmd = "start " + currentURL;
        system(cmd.c_str());
        cout << GREEN << currentURL << RESET << " opened in default browser" << endl;
    }
    // if not valid open a custom 404 html page by passing the invalid url to display there
    else
    {
        cout << GREEN << currentURL << RED << " - Invalid url to open in browser" << RESET << endl;
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
        cout << RED << "No page visited" << RESET << endl;
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