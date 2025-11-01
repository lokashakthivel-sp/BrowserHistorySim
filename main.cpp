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
    "Bookmark Current Page",
    "Show Bookmarks",
    "Open Bookmarked Page",
    "Close Current Page",
    "Show History",
    "Clear History",
    "Save and Exit"};

int main()
{
    Browser browser;
    int choice, count = 0;
    do
    {
        if (count % 3 == 0)
            printMenu(options);
        count++;
        cout << B_YELLOW << "Choice: " << RESET;
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
            browser.visitPage(getURLFromUser(0), "");
            break;
        case 6:
            browser.searchPage(getURLFromUser(1));
            break;
        case 7:
            browser.openPage();
            break;
        case 8:
            browser.goBack();
            break;
        case 9:
            browser.goForward();
            break;
        case 10:
            browser.addBookmark();
            break;
        case 11:
            browser.showBookmark();
            break;
        case 12:
            browser.openBookmarkPage();
            break;
        case 13:
            browser.closePage();
            break;
        case 14:
            browser.showHistory();
            break;
        case 15:
            browser.clearHistory();
            break;
        case 16:
            exitPrg();
            browser.saveHistory();
            break;
        default:
            invalidChoice();
        }
        if (choice != 16)
            browser.printBrowser();
    } while (choice != 16);
}