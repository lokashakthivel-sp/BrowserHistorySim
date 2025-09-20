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
    "Visit Page",
    "Open Page in Browser",
    "Back - Previous Page",
    "Forward - Next Page",
    "Close Current Page",
    "Show History",
    "Clear History",
    "Save and Exit"};
// add closing a current page function
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
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            invalidChoice();
            continue;
        }
        switch (choice)
        {
        case 1:
            browser.createTab();
            // browser.loadHistory();
            break;
        case 2:
            browser.switchTab(getIDFromUser());
            break;
        case 3:
            browser.closeTab(getIDFromUser());
            break;
        case 4:
            browser.displayTabs();
            break;
        case 5:
            browser.visitPage(getURLFromUser(), "");
            break;
        case 6:
            browser.openPage();
            break;
        case 7:
            browser.goBack();
            break;
        case 8:
            browser.goForward();
            break;
        case 9:
            browser.closePage();
            break;
        case 10:
            browser.showHistory();
            break;
        case 11:
            browser.clearHistory();
            break;
        case 12:
            browser.saveHistory();
            exitPrg();
            break;
        default:
            invalidChoice();
        }
    } while (choice != 12);
}