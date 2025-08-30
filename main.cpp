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
    "Back - Previous Page",
    "Forward - Next Page",
    "Close Current Page",
    "Show History",
    "Clear History",
    "Exit"};
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
            browser.loadHistory();
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
            browser.getCurrentTab()->visit(getURLFromUser());
            break;
        case 6:
            browser.getCurrentTab()->goBack();
            break;
        case 7:
            browser.getCurrentTab()->goForward();
            break;
        case 8:
            browser.getCurrentTab()->closeCurrentPage();
            break;
        case 9:
            browser.getCurrentTab()->showHistory();
            break;
        case 10:
            browser.getCurrentTab()->clearHistory(1);
            break;
        case 11:
            browser.saveHistory();
            exitPrg();
            break;
        default:
            invalidChoice();
        }
    } while (choice != 11);
}