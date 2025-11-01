# 🖥️ **Advanced Browser Simulation (C++)**

This C++ project simulates a multi-tabbed browser environment within the command line. It goes beyond simple history by incorporating advanced data structures to manage page lookups, bookmarks, and persistent session data.

The simulation supports managing up to 3 tabs simultaneously, each with its own independent state, including navigation stacks, history, and privacy settings.

## 🚀 **Features**

Tab Management: Create, switch between, display, and close up to 3 active tabs.

**Private Mode**: Create tabs in a "private" mode, which prevents their history from being saved to disk.

**Navigation**: Go Back and Forward in each tab's session using stacks.

**History**: Full browsing history per-tab, implemented with a Doubly Linked List.

**Persistent Storage**: Automatically saves (non-private) and loads tab history to/from .txt files, preserving sessions between runs.

**Page Search**: Search for pages using a keyword. This feature is powered by an AVL Tree loaded from urls/urlList.csv for efficient (O(log n)) lookups.

**Bookmarks**: Add the current page to a persistent bookmark list, view all bookmarks, and open a page directly from your bookmarks.

**Open in Browser**: An option to "open" the current URL, which attempts to launch it in your system's default web browser.

## 🔧 **Technical Overview**

This project uses several key data structures to manage the browser's state:

**Browser**: The main class holding an array of Tab objects.

**Tab**: Contains two Stacks (for back/forward), a HistoryList, and the current URL.

**HistoryList**: A custom Doubly Linked List to store HistoryNode objects, allowing for efficient addition and traversal of history.

**AVL Tree**: A self-balancing binary search tree used to store and quickly search for Page objects based on their URL.

**LinkedList**: A simple linked list used to manage the list of saved bookmarks.

**FileManager**: A static class responsible for all file I/O, including reading/writing history and loading the AVL tree and bookmarks.

## 🛠️ **Build & Run**

A makefile is included for easy compilation on systems with g++ and make.

**Clone the repository:**<br>
git clone https://github.com/your-username/browser-history-simulation.git
cd browser-history-simulation

**Build using Make:**<br>
make<br>This will compile all source files from the src/ directory and create an executable named main.exe.

**Run the application:**<br>
./main.exe

**Clean build files:**<br>
make clean

## 📖 **How to Use**

Run the executable to start the simulation. The application is controlled by a simple menu.

**Main Menu Options:**

Create Tab: Creates a new tab (up to 3) and switches to it. You will be prompted if the tab should be private.

Switch Tab: Enter the ID of an open tab to switch to it.

Close Tab: Enter the ID of a tab to close (cannot close the currently active tab).

Display Tabs: Shows all open tabs and their current URL.

Visit Page: Enter a new URL to visit.

Search Page: Enter a keyword to search the pre-loaded URL list.

Open Page in Browser: Opens the current tab's URL in your system's default browser.

Back - Previous Page: Navigates to the previous page.

Forward - Next Page: Navigates to the next page.

Bookmark Current Page: Saves the current URL to your bookmarks.

Show Bookmarks: Displays all saved bookmarks.

Open Bookmarked Page: Prompts you to select a bookmark to visit.

Close Current Page: "Closes" the current page and moves to the most recent page in history.

Show History: Displays the full history for the current tab.

Clear History: Clears the history for the current tab or all tabs.

Save and Exit: Saves all non-private history and exits the program.
