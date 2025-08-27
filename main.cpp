#include "Browser.h"
#include "FileManager.h"
#include <iostream>
#include "UI.h"
using namespace std;
vector<string> options = {
    "Create Tab",
    "Switch Tab",
    "Close Tab",
    "Display Tabs",
    "",
    "",
};
int main()
{
    Browser browser;
    // browser.createTab();
    int choice;
    do
    {
        // browser.displayTabs();
        printMenu(options);
        cin >> choice;
        switch (choice)
        {
        case 1:
            browser.createTab();
            break;
        case 2:
            int id = getIDFromUser();
            browser.switchTab(id);
            break;
        case 3:
            int id = getIDFromUser();
            browser.closeTab(id);
            break;
        case 4:
            browser.displayTabs();
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 7:
            /* code */
            break;
        case 8:
            /* code */
            break;

        default:
            break;
        }
    } while (choice != 8);
}