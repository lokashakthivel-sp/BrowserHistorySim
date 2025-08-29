#include <iostream>
#include "Browser.h"
#include "ColorCodes.h"
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

    // * currentTabIndex is 1 based starts at 1 not 0
    // currentTabIndex = (int)tabs.size();
    cout << "Tab " << currentTabIndex << " created and switched to" << endl;
}

void Browser::switchTab(int index)
{
    // *index is 1 based ie starts at 1 not 0
    // invalid if tab is closed
    if (index < 1 || index > (int)tabs.size() || tabs[index - 1].second == 0)
    {
        cout << RED << "Invalid tab index" << RESET << endl;
        return;
    }
    // set currentTabIndex to specified index
    currentTabIndex = index;
    cout << "Switched to tab " << getCurrentTab()->getTabID() << endl;
}

// ! issue
void Browser::closeTab(int index)
{
    //*index is 1 based ie starts at 1 not 0
    if (index < 1 || index > tabCount)
    {
        cout << RED << "Invalid tab index" << RESET << endl;
        return;
    }
    // delete specified tab content
    delete tabs[index - 1].first;
    tabs[index - 1].first = nullptr;
    tabs[index - 1].second = 0;
    tabCount--;
    //! tabs.erase(tabs.begin() + index - 1);

    // suppose tabs becomes empty, set currentTabIndex to -1
    // or else set it to min of index and tabs size
    ////min() - casting tabs.size() from size_t to int

    if (currentTabIndex == index)
    {
        currentTabIndex = (tabs.empty()) ? -1 : min(index + 1, (int)MAX_TABS_COUNT);
    }

    cout << "Closed tab " << index << endl;
    //! the history/ .txt files will not be pointing to correct tabs after closing tab
}

Tab *Browser::getCurrentTab()
{
    return (currentTabIndex == -1) ? nullptr : tabs[currentTabIndex - 1].first;
}

void Browser::displayTabs()
{
    if (currentTabIndex <= 0)
    {
        cout << RED << "No open tabs" << RESET << endl;
    }
    cout << "Open Tabs: " << currentTabIndex << tabCount << endl;
    //
    for (int i = 0; i < MAX_TABS_COUNT; i++)
    {
        if (tabs[i].second == 0)
        {
            continue;
        }
        if (i + 1 == currentTabIndex)
        {
            cout << CYAN << "->";
        }
        else
        {
            cout << RESET << "  ";
        }
        cout << "Tab " << tabs[i].first->getTabID() << " Current URL: " << (tabs[i].first->getCurrentURL().empty() ? "empty" : tabs[i].first->getCurrentURL()) << endl;
    }
}

/*
int Browser::getTabCount()
{
    return tabs.size();
}

void Browser::incTabCount()
{
    tabCount++;
}
*/