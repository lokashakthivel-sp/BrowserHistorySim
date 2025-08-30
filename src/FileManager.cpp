#include <iostream>
#include <fstream>
#include "FileManager.h"
using namespace std;

// filename is of format history/tab1.txt

//! rewrite based on changes to tabs array
void FileManager::saveHistory(Tab *tab)
{
    string filename = "history/tab" + to_string(tab->getTabID()) + ".txt";
    ofstream file(filename);
    if (!file)
    {
        cout << RED << "Could not open " << filename << RESET << endl;
        return;
    }
    HistoryNode *temp = tab->getHistoryHead();
    // writing history DLL into file
    while (temp)
    {
        file << temp->url << "\n";
        temp = temp->next;
    }
    file.close();
}

void FileManager::loadHistory(Tab *tab)
{

    string filename = "history/tab" + to_string(tab->getTabID()) + ".txt";
    ifstream file(filename);
    if (!file)
    {
        cout << RED << "No history stored" << filename << RESET << endl;
        return;
    }
    string url;
    // reading history from file
    while (getline(file, url))
    {
        if (!url.empty())
        {
            tab->visit(url);
        }
    }
    file.close();
}