#pragma once
#include <string>
// Node struct for history list (DLL)
struct HistoryNode
{
    std::string url;
    HistoryNode *next, *prev;
    HistoryNode(std::string url) : url(url), next(nullptr), prev(nullptr) {}
};