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
    void visit(std::string url, std::string timeStamp);
    void goBack();
    void goForward();
    void openCurrentPage();
    void closeCurrentPage();
    void showHistory();
    void clearHistory(int flag);

    int getTabID();
    HistoryNode *getHistoryHead();
    std::string getCurrentURL();

    bool isValidURL(const std::string &url);
};