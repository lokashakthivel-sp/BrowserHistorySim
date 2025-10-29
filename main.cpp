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
    "Search Page",
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
            browser.printBrowser();
            break;
        case 2:
            browser.switchTab(getIDFromUser());
            browser.printBrowser();
            break;
        case 3:
            browser.closeTab(getIDFromUser());
            browser.printBrowser();
            break;
        case 4:
            browser.displayTabs();
            browser.printBrowser();
            break;
        case 5:
            browser.visitPage(getURLFromUser(0), "");
            browser.printBrowser();
            break;
        case 6:
            browser.searchPage(getURLFromUser(1));
            browser.printBrowser();
            break;
        case 7:
            browser.openPage();
            browser.printBrowser();
            break;
        case 8:
            browser.goBack();
            browser.printBrowser();
            break;
        case 9:
            browser.goForward();
            browser.printBrowser();
            break;
        case 10:
            browser.closePage();
            browser.printBrowser();
            break;
        case 11:
            browser.showHistory();
            browser.printBrowser();
            break;
        case 12:
            browser.clearHistory();
            browser.printBrowser();
            break;
        case 13:
            exitPrg();
            browser.saveHistory();
            break;
        default:
            invalidChoice();
        }
    } while (choice != 13);
}