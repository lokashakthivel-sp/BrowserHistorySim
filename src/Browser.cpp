#include <iostream>
#include <iomanip>
#include "Browser.h"
#include "FileManager.h"
#include "AVL.h"
using namespace std;

AVL tree;

Browser::Browser() : currentTabIndex(-1)
{
    FileManager::createAVLfromURL(tree);
}
Browser::~Browser()
{
    for (pair<Tab *, bool> tab : tabs)
    {
        delete tab.first;
    }
}

void Browser::createTab()
{
    if (tabCount >= MAX_TABS_COUNT)
    {
        cout << B_RED << "Tab limit reached" << RESET << endl;
        return;
    }

    // after closing a non last tab (here except 3), there may be empty cell in any place, we want to check where it is and place the new tab
    for (int i = 0; i < MAX_TABS_COUNT; i++)
    {
        // if tab is not opened
        if (!tabs[i].second)
        {
            tabs[i].first = new Tab(i + 1);
            tabs[i].second = 1;
            currentTabIndex = i + 1;
            tabCount++;
            i++;
            break;
        }
    }

    loadHistory();

    // * currentTabIndex is 1 based starts at 1 not 0
    cout << "Tab " << currentTabIndex << " created and switched to" << endl;
}

void Browser::switchTab(int index)
{
    if (currentTabIndex <= 0)
    {
        cout << B_RED << "No open tabs" << RESET << endl;
        return;
    }
    // *index is 1 based ie starts at 1 not 0
    // invalid if tab is closed
    if (index < 1 || index > (int)tabs.size() || tabs[index - 1].second == 0)
    {
        cout << B_RED << "Invalid tab index" << RESET << endl;
        return;
    }
    // set currentTabIndex to specified index
    currentTabIndex = index;
    cout << "Switched to tab " << currentTabIndex << endl;
}

void Browser::closeTab(int index)
{
    if (currentTabIndex <= 0)
    {
        cout << B_RED << "No open tabs" << RESET << endl;
        return;
    }
    //*index is 1 based ie starts at 1 not 0
    if (index < 1 || index > MAX_TABS_COUNT)
    {
        cout << B_RED << "Invalid tab index" << RESET << endl;
        return;
    }

    if (currentTabIndex == index)
    {
        cout << B_RED << "Switch to some other tab to close current tab" << RESET << endl;
        return;
    }

    // save history before closing
    FileManager::saveHistory(tabs[index - 1].first);

    // delete specified tab content
    delete tabs[index - 1].first;
    tabs[index - 1].first = nullptr;
    tabs[index - 1].second = 0;
    tabCount--;

    if (tabCount == 0)
    {
        currentTabIndex = -1;
    }

    cout << "Closed Tab " << index << "current: " << currentTabIndex << endl;
}

Tab *Browser::getCurrentTab(int flag = 0)
{
    if (!flag)
        cout << "Current Tab " << B_GREEN << currentTabIndex << RESET << endl;
    return (currentTabIndex <= 0) ? nullptr : tabs[currentTabIndex - 1].first;
}

void Browser::visitPage(string url, string timeStamp)
{
    if (currentTabIndex <= 0)
    {
        cout << B_RED << "No open tabs" << RESET << endl;
        return;
    }
    getCurrentTab()->visit(url, timeStamp);
}

void Browser::searchPage(string targetURL)
{
    if (currentTabIndex <= 0)
    {
        cout << B_RED << "No open tabs" << RESET << endl;
        return;
    }
    getCurrentTab()->searchPage(targetURL, tree);
}

void Browser::closePage()
{
    if (currentTabIndex <= 0)
    {
        cout << B_RED << "No open tabs" << RESET << endl;
        return;
    }
    getCurrentTab()->closeCurrentPage();
}

void Browser::goBack()
{
    if (currentTabIndex <= 0)
    {
        cout << B_RED << "No open tabs" << RESET << endl;
        return;
    }
    getCurrentTab()->goBack();
}

void Browser::goForward()
{
    if (currentTabIndex <= 0)
    {
        cout << B_RED << "No open tabs" << RESET << endl;
        return;
    }
    getCurrentTab()->goForward();
}

void Browser::showHistory()
{
    if (currentTabIndex <= 0)
    {
        cout << B_RED << "No open tabs" << RESET << endl;
        return;
    }
    cout << B_YELLOW << "History" << RESET << endl;
    getCurrentTab()->showHistory();
}

void Browser::openPage()
{
    if (currentTabIndex <= 0)
    {
        cout << B_RED << "No open tabs" << RESET << endl;
        return;
    }
    getCurrentTab()->openCurrentPage();
}

void Browser::displayTabs()
{
    if (currentTabIndex <= 0)
    {
        cout << B_RED << "No open tabs" << RESET << endl;
        return;
    }
    cout << "Current Tab " << B_GREEN << currentTabIndex << RESET << endl;
    for (int i = 0; i < MAX_TABS_COUNT; i++)
    {
        // if tab is closed we skip
        if (tabs[i].second == 0)
        {
            continue;
        }
        // for current tab
        if (i + 1 == currentTabIndex)
        {
            cout << B_CYAN << "->";
        }
        else
        {
            cout << RESET << "  ";
        }
        cout << "Tab " << tabs[i].first->getTabID() << " Current URL: " << (tabs[i].first->getCurrentURL().empty() ? "..." : tabs[i].first->getCurrentURL()) << endl;
    }
}

// for use in fileManager
int Browser::getTabCount()
{
    return tabCount;
}

void Browser::saveHistory()
{
    for (int i = 0; i < MAX_TABS_COUNT; i++)
    {
        if (tabs[i].second == 0)
        {
            continue;
        }
        FileManager::saveHistory(tabs[i].first);
    }
}

void Browser::clearHistory()
{
    if (currentTabIndex <= 0)
    {
        cout << B_RED << "No open tabs" << RESET << endl;
        return;
    }
    Tab *tempTab = getCurrentTab();
    tempTab->clearHistory(1);
    FileManager::saveHistory(tempTab);
}

string repeat1(string s, int count)
{
    string res = "";
    for (int i = 0; i < count; i++)
    {
        res += s;
    }
    return res;
}

void Browser::printBrowser()
{

    if (currentTabIndex <= 0)
        return;

    cout << "\n\n"
         << B_MAGENTA << repeat1("-", 50) << "\n"
         << "|" << RESET;

    cout << BOLD << "\033[103m" << setw(26) << "Browser" << setw(23) << RESET << BOLD << "\033[101m" << " X " << RESET;
    cout << B_MAGENTA << "|\n"
         << "|" << repeat1("-", 48) << "|" << "\n"
         << "| " << RESET;
    // cout << "Tabs:";
    int widthAfterTab3 = 52;
    for (int i = 0; i < MAX_TABS_COUNT; i++)
    {
        if (i + 1 == currentTabIndex)
            cout << "\033[47;95m";
        if (tabs[i].second == 1)
        {

            cout << BOLD << " Tab " << tabs[i].first->getTabID() << " " << RESET << B_CYAN << " | " << RESET;
            widthAfterTab3 -= 10;
        }
    }
    cout << setw(widthAfterTab3) << B_MAGENTA << "|" << "\n"
         << "|" << repeat1("-", 48) << "|" << "\n"
         << "|" << RESET;

    cout << " URL: ";
    string url = getCurrentTab(1)->getCurrentURL();
    if (url.empty())
    {
        url = "...";
    }

    cout << B_BLUE << url
         << setw(47 - url.length()) << B_MAGENTA << "|" << "\n";

    cout << "|" << repeat1("-", 48) << "|\n|";
    cout << " History"
         << setw(42) << "|\n";
    getCurrentTab(1)->showHistory();
    cout << B_MAGENTA << "|" << repeat1("_", 48) << "|"
         << RESET << "\n"
         << endl;
}

void Browser::loadHistory()
{
    FileManager::loadHistory(getCurrentTab());
}