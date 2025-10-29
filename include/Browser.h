#pragma once
#include "Tab.h"
#include <array>
#include <utility>
// template to hold upto 3 tabs at a time
class Browser
{
private:
    // limiting no of tabs to 3
    static const int MAX_TABS_COUNT = 3;
    // each elt in tabs array is a pair containing a Tab * and a bool value saying if it is open or not
    std::array<std::pair<Tab *, bool>, MAX_TABS_COUNT> tabs;
    // currentTabIndex is 1 based index
    int currentTabIndex;
    int tabCount = 0;

public:
    Browser();
    ~Browser();

    void createTab();
    void switchTab(int index);
    void closeTab(int index);
    void displayTabs();

    void searchPage(std::string targetURL);
    void visitPage(std::string url, std::string timeStamp);
    void closePage();
    void goBack();
    void goForward();
    void showHistory();
    void openPage();

    void printBrowser();

    void saveHistory();
    void clearHistory();
    void loadHistory();
    Tab *getCurrentTab(int);
    int getTabCount();
};
