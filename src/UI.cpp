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
    // Clear screen & move cursor to top
    cout << "\033[2J\033[H";
    cout << BOLD << BLUE << "┌" << repeat("─", width - 2) << "┐" << RESET << "\n";
    cout << BOLD << BLUE << "│" << RESET
         << BG_BLUE << setw((width - 2) / 2 + 7) << "Browser Tabs Menu"
         << setw((width - 2) / 2 - 3) << RESET << CYAN << "│" << RESET << "\n";
    cout << BOLD << BLUE << "├" << repeat("─", width - 2) << "┤" << RESET << "\n";

    for (int i = 0; i < (int)options.size(); i++)
    {
        cout << BOLD << BLUE << "│ " << RESET
             << setw(2) << i + 1 << ". " << options[i]
             << setw(width - ((int)options[i].size()) + 5) << BLUE "│" RESET << "\n";
    }

    cout << BOLD << BLUE << "└" << repeat("─", width - 2) << "┘" << RESET << "\n";
    cout << YELLOW << "Choice: " << RESET;
}

int getIDFromUser()
{
    int id;
    cout << YELLOW << "\tEnter the tab id: ";
    cin >> id;
    cout << endl;
    return id;
}