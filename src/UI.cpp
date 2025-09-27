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
    cout << BOLD << B_BLUE << "." << repeat(".", width - 2) << "." << RESET << "\n";
    cout << BOLD << B_BLUE << ":" << RESET
         << BG_BLUE << setw((width - 2) / 2 + 12) << "Browser History Sim Menu"
         << setw((width - 2) / 2 - 8) << RESET << BOLD << B_BLUE << ":" << "\n";
    cout << BOLD << B_BLUE << ":" << repeat(".", width - 2) << ":" << RESET << "\n";

    for (int i = 0; i < (int)options.size(); i++)
    {
        cout << BOLD << B_BLUE << ": " << RESET
             << setw(2) << i + 1 << ". " << options[i]
             << setw(width - ((int)options[i].size()) - 3) << BOLD << B_BLUE << ":" << RESET << "\n";
    }

    cout << BOLD << B_BLUE << ":" << repeat(".", width - 2) << ":" << RESET << "\n";
    cout << B_YELLOW << "Choice: " << RESET;
}

int getIDFromUser()
{
    int id;
    cout << B_YELLOW << "    Enter the tab id: " << RESET;
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
    cout << B_YELLOW << "    Enter the url: " << RESET;
    cin >> url;
    cout << endl;
    return url;
}

void exitPrg()
{
    cout << BOLD << B_CYAN << "Saving and Exiting..." << RESET << endl;
}

void invalidChoice()
{
    cout << BOLD << B_RED << "Invalid choice!!" << RESET << endl;
}