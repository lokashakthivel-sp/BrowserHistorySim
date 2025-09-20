#pragma once
#include <string>
// Node struct for history list (DLL)
struct HistoryNode
{
    std::string url;
    std::string timeStamp;
    HistoryNode *next, *prev;

    HistoryNode(std::string url, std::string timeStamp) : url(url), timeStamp(timeStamp), next(nullptr), prev(nullptr) {}
};