#pragma once
#include "Tab.h"
#include "AVL.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class FileManager
{
public:
    // set to static so it can be accessed without object
    static void saveHistory(Tab *);
    static void loadHistory(Tab *);

    static void createAVLfromURL(AVL &tree);
    static void loadBookmarks(std::vector<std::string> &bookmarkList);

    static void addBookmark(std::string url);
};
