#pragma once
#include "Tab.h"
#include <vector>
// template to hold upto 3 tabs at a time
class Browser
{
private:
    // limiting no of tabs to 3
    const int MAX_TABS_COUNT = 3;
    std::vector<Tab *> tabs;
    // currentTabIndex will be 1 based index
    int currentTabIndex;

public:
    Browser();
    ~Browser();

    void createTab();
    void switchTab(int index);
    void closeTab(int index);
    Tab *getCurrentTab();
    void displayTabs();
    int getTabCount();
};
