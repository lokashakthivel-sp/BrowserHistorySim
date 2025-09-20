#include <iostream>
#include "Browser.h"
#include "FileManager.h"
using namespace std;

Browser::Browser() : currentTabIndex(-1) {}
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
        cout << RED << "Tab limit reached" << RESET << endl;
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
        cout << RED << "No open tabs" << RESET << endl;
        return;
    }
    // *index is 1 based ie starts at 1 not 0
    // invalid if tab is closed
    if (index < 1 || index > (int)tabs.size() || tabs[index - 1].second == 0)
    {
        cout << RED << "Invalid tab index" << RESET << endl;
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
        cout << RED << "No open tabs" << RESET << endl;
        return;
    }
    //*index is 1 based ie starts at 1 not 0
    if (index < 1 || index > tabCount)
    {
        cout << RED << "Invalid tab index" << RESET << endl;
        return;
    }
    FileManager::saveHistory(tabs[index - 1].first);

    // delete specified tab content
    delete tabs[index - 1].first;
    tabs[index - 1].first = nullptr;
    tabs[index - 1].second = 0;
    tabCount--;

    // suppose tabs becomes empty, set currentTabIndex to -1 or else set it to min of index and MAX tab count

    if (currentTabIndex == index)
    {
        currentTabIndex = (tabs.empty()) ? -1 : min(index + 1, (int)MAX_TABS_COUNT);
        if (tabCount < currentTabIndex)
        {
            currentTabIndex = tabCount;
        }
    }

    cout << "Closed tab " << index << endl;
}

Tab *Browser::getCurrentTab()
{
    cout << "Current Tab " << GREEN << currentTabIndex << RESET << endl;
    return (currentTabIndex == -1) ? nullptr : tabs[currentTabIndex - 1].first;
}

void Browser::visitPage(string url, string timeStamp)
{
    if (currentTabIndex <= 0)
    {
        cout << RED << "No open tabs" << RESET << endl;
        return;
    }
    getCurrentTab()->visit(url, timeStamp);
}

void Browser::closePage()
{
    if (currentTabIndex <= 0)
    {
        cout << RED << "No open tabs" << RESET << endl;
        return;
    }
    getCurrentTab()->closeCurrentPage();
}

void Browser::goBack()
{
    if (currentTabIndex <= 0)
    {
        cout << RED << "No open tabs" << RESET << endl;
        return;
    }
    getCurrentTab()->goBack();
}

void Browser::goForward()
{
    if (currentTabIndex <= 0)
    {
        cout << RED << "No open tabs" << RESET << endl;
        return;
    }
    getCurrentTab()->goForward();
}

void Browser::showHistory()
{
    if (currentTabIndex <= 0)
    {
        cout << RED << "No open tabs" << RESET << endl;
        return;
    }
    getCurrentTab()->showHistory();
}

void Browser::openPage()
{
    if (currentTabIndex <= 0)
    {
        cout << RED << "No open tabs" << RESET << endl;
        return;
    }
    getCurrentTab()->openCurrentPage();
}

void Browser::displayTabs()
{
    if (currentTabIndex <= 0)
    {
        cout << RED << "No open tabs" << RESET << endl;
        return;
    }
    cout << "Current Tab " << GREEN << currentTabIndex << RESET << endl;
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
            cout << CYAN << "->";
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
        cout << RED << "No open tabs" << RESET << endl;
        return;
    }
    Tab *tempTab = getCurrentTab();
    tempTab->clearHistory(1);
    FileManager::saveHistory(tempTab);
}

void Browser::loadHistory()
{
    FileManager::loadHistory(getCurrentTab());
}