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
         << BG_BLUE << setw((width - 2) / 2 + 7) << "Browser Tabs Menu"
         << setw((width - 2) / 2 - 3) << RESET << CYAN << ":" << RESET << "\n";
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

int getIDFromUser()
{
    int id;
    cout << YELLOW << "\tEnter the tab id: " << RESET;
    cin >> id;
    cout << endl;
    return id;
}

string getURLFromUser()
{
    string url;
    cout << YELLOW << "\tEnter the url: " << RESET;
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