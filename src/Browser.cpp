#include <iostream>
#include "Browser.h"
using namespace std;

Browser::Browser() : currentTabIndex(-1) {}
Browser::~Browser()
{
    for (Tab *tab : tabs)
    {
        delete tab;
    }
}

void Browser::createTab()
{
    if (tabs.size() >= MAX_TABS_COUNT)
    {
        cout << "Tab limit reached" << endl;
        return;
    }
    // to create new tabs with incremented ids
    int id = tabs.size() + 1;
    // create a new tab from Tab
    Tab *newTab = new Tab(id);
    // pushback to tabs vector
    tabs.push_back(newTab);
    // set currentTabIndex tabs size ie last pushed tab
    // *currentTabIndex is 1 based starts at 1 not 0
    currentTabIndex = tabs.size();
    cout << "Tab " << id << " created and switched to" << endl;
}

void Browser::switchTab(int index)
{
    // *index is 1 based ie starts at 1 not 0
    if (index < 1 || index > tabs.size())
    {
        cout << "Invalid tab index" << endl;
        return;
    }
    // set currentTabIndex to specified index
    currentTabIndex = index;
    cout << "Switched to tab " << tabs[currentTabIndex]->getTabID() << endl;
}

void Browser::closeTab(int index)
{
    //*index is 1 based ie starts at 1 not 0
    if (index < 1 || index > tabs.size())
    {
        cout << "Invalid tab index" << endl;
        return;
    }
    // delete specified tab content
    delete tabs[index - 1];
    // erase that tab from vector also
    tabs.erase(tabs.begin() + index - 1);

    // suppose tabs becomes empty, set currentTabIndex to -1
    // or else set it to min of index and tabs size
    ////min() - casting tabs.size() from size_t to int
    currentTabIndex = (tabs.empty()) ? -1 : min(index, (int)tabs.size());
}

Tab *Browser::getCurrentTab()
{
    return (currentTabIndex == -1) ? nullptr : tabs[currentTabIndex];
}

void Browser::displayTabs()
{
    cout << "Open Tabs:" << endl;
    for (int i = 0; i < tabs.size(); i++)
    {
        cout << (i == currentTabIndex ? "->" : "  ");
        cout << "Tab " << tabs[i]->getTabID() << "Current URL: " << (tabs[i]->getCurrentURL().empty() ? "empty" : tabs[i]->getCurrentURL()) << endl;
    }
}

int Browser::getTabCount()
{
    return tabs.size();
}