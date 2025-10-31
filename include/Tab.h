#pragma once
#include "Stack.h"
#include "HistoryList.h"
#include "AVL.h"
// template for tab obj
class Tab
{
private:
    Stack forwardStack;
    Stack backwardStack;
    HistoryList history;
    std::string currentURL;
    int tabID;
    bool isPrivate;

public:
    Tab(int id, bool isPrivate);
    ~Tab();
    void visit(std::string url, std::string timeStamp);
    void searchPage(std::string targetURL, AVL &tree);
    void openBookmarkPage(std::vector<std::string> &bookmarkList);
    void goBack();
    void goForward();
    void openCurrentPage();
    void closeCurrentPage();
    void showHistory();
    void clearHistory(int flag);

    int getTabID();
    HistoryNode *getHistoryHead();
    std::string getCurrentURL();
    bool getIsPrivate();

    bool isValidURL(const std::string &url);
};