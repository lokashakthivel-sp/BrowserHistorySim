#include "UI.h"

string repeat(string s, int count)
{
    string res = "";
    for (int i = 0; i < count; i++)
    {
        res += s;
    }
    return res;
}

void printMenu(vector<string> &options, int width)
{
    cout << BOLD << BLUE << "." << repeat(".", width - 2) << "." << RESET << "\n";
    cout << BOLD << BLUE << ":" << RESET
         << BG_BLUE << setw((width - 2) / 2 + 12) << "Browser History Sim Menu"
         << setw((width - 2) / 2 - 8) << RESET << CYAN << ":" << RESET << "\n";
    cout << BOLD << BLUE << ":" << repeat(".", width - 2) << ":" << RESET << "\n";

    for (int i = 0; i < (int)options.size(); i++)
    {
        cout << BOLD << BLUE << ": " << RESET
             << setw(2) << i + 1 << ". " << options[i]
             << setw(width - ((int)options[i].size()) - 3) << BOLD << BLUE << ":" << RESET << "\n";
    }

    cout << BOLD << BLUE << ":" << repeat(".", width - 2) << ":" << RESET << "\n";
    cout << YELLOW << "Choice: " << RESET;
}

void printBrowser()
{
}

int getIDFromUser()
{
    int id;
    cout << YELLOW << "    Enter the tab id: " << RESET;
    cin >> id;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return 0;
    }
    cout << endl;
    return id;
}

/* string getTimeNow()
{
    string timeStr;
    auto now = chrono::system_clock::now();
        time_t time = chrono::system_clock::to_time_t(now);
        timeStamp = ctime(&time);
    return timeStr;
} */

string getURLFromUser()
{
    string url;
    cout << YELLOW << "    Enter the url: " << RESET;
    cin >> url;
    cout << endl;
    return url;
}

void exitPrg()
{
    cout << BOLD << CYAN << "Saving and Exiting..." << RESET << endl;
}

void invalidChoice()
{
    cout << BOLD << RED << "Invalid choice!!" << RESET << endl;
}