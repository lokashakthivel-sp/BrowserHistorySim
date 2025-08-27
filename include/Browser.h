#pragma once
#include "Tab.h"
#include <vector>
// template to hold upto 3 tabs at a time
class Browser
{
private:
    std::vector<Tab> tabs; // limit size to 3
    int currentTabIndex;

public:
    Browser();
    ~Browser();

    void createTab();
    void switchTab(int id);
    void closeTab(int id);
    Tab *getCurrentTab();
    void displayTabs();
    int getTabCount();
};
