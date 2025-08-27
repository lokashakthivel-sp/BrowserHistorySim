#pragma once
#include "HistoryNode.h"
//template for obj which stores history of tab in DLL data structure
class HistoryList
{
private:
    HistoryNode *head, *tail;

public:
    HistoryList();
    ~HistoryList();

    void add(std::string url);
    void showHistory();
    void clear();
};