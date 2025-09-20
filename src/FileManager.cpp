#include <iostream>

#include "FileManager.h"
using namespace std;

// filename is of format history/tab1.txt

// todo: the write during saving and exiting overwrites the history file

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
        file << temp->url << "," << temp->timeStamp << "\n";
        temp = temp->next;
    }
    cout << CYAN << "History saved" << RESET << endl;
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
    string line;
    string url;
    string timeStamp;

    bool flag = 0;
    // reading history from file
    while (getline(file, line))
    {
        if (!line.empty())
        {
            size_t pos = line.find(',');
            if (pos != string::npos)
            {
                string url = line.substr(0, pos);
                // convert timestamp to readable format
                string timeStr;
                stringstream ss(line.substr(pos + 1));
                getline(ss, timeStr);
                if (!line.empty() && line.back() == '\n')
                {
                    line.pop_back();
                }
                tab->visit(url, timeStr);
                flag = 1;
            }
        }
    }
    if (flag)
        cout << CYAN << "History loaded" << RESET << endl;
    file.close();
}