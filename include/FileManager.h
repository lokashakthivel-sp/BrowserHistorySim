#pragma once
#include "Tab.h"
#include <vector>
#include <string>

// to save and load history of each tab from separate files
class FileManager
{
public:
    // set to static so it can be accessed without object
    static void saveHistory(Tab *);
    static void loadHistory(Tab *);
};
