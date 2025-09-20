#pragma once
#include "HistoryNode.h"
#include "ColorCodes.h"
// class for obj which stores history of tab in DLL data structure
class HistoryList
{
private:
    HistoryNode *head, *tail;

public:
    HistoryList();
    ~HistoryList();

    void add(std::string url, std::string timeStamp);
    void closePage(std::string url);
    void showHistory(std::string currentUrl);
    void clear(int flag = 0);
    HistoryNode *getHead();
};