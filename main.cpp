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
    "Show History",
    "Exit"};
int main()
{
    Browser browser;
    // browser.createTab();
    int choice;
    do
    {
        // browser.displayTabs();
        printMenu(options, 60);
        cin >> choice;
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
            browser.getCurrentTab()->visit(getURLFromUser());
            break;
        case 6:
            browser.getCurrentTab()->goBack();
            break;
        case 7:
            browser.getCurrentTab()->goForward();
            break;
        case 8:
            browser.getCurrentTab()->showHistory();
            break;
        case 9:
            exitPrg();
            break;
        default:
            invalidChoice();
        }
    } while (choice != 9);
}