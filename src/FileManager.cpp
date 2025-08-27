#include <iostream>
#include <fstream>
#include "FileManager.h"
using namespace std;

// filename is of format history/tab1.txt

void FileManager::saveHistory(vector<Tab *> &tabs)
{
    for (int i = 0; i < tabs.size(); i++)
    {
        string filename = "history/tab" + to_string(i + 1) + ".txt";
        ofstream file(filename);
        if (!file)
        {
            cout << "Could not open " << filename << endl;
            return;
        }
        HistoryNode *temp = tabs[i]->getHistoryHead();
        // writing history DLL into file
        while (temp)
        {
            file << temp->url << "\n";
            temp = temp->next;
        }
        file.close();
    }
}

void FileManager::loadHistory(vector<Tab *> &tabs)
{
    for (int i = 0; i < tabs.size(); i++)
    {
        string filename = "history/tab" + to_string(i + 1) + ".txt";
        ifstream file(filename);
        if (!file)
        {
            cout << "No history stored" << filename << endl;
            return;
        }
        string url;
        // reading history from file
        while (getline(file, url))
        {
            if (!url.empty())
            {
                tabs[i]->visit(url);
            }
        }
        file.close();
    }
}