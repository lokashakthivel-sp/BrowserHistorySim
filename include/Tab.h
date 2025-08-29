#pragma once
#include "Stack.h"
#include "HistoryList.h"
// template for tab obj
class Tab
{
private:
    Stack forwardStack;
    Stack backwardStack;
    HistoryList history;
    std::string currentURL;
    int tabID;

public:
    Tab(int id);
    ~Tab();
    void visit(std::string url);
    void goBack();
    void goForward();
    void showHistory();

    void setTabID(int id);
    int getTabID();
    HistoryNode *getHistoryHead();
    std::string getCurrentURL();
};