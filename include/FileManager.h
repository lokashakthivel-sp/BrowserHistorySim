#pragma once
#include "Tab.h"
#include <vector>
#include <string>

// to save and load history of each tab from separate
class FileManager
{
public:
    void saveHistory(std::vector<Tab *> &tabs);
    void loadHistory(std::vector<Tab *> &tabs);
};
