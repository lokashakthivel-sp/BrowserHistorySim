#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
// ANSI color codes
#include "ColorCodes.h"
using namespace std;

void printMenu(vector<string> &options, int width = 50);
int getIDFromUser();
// string getTimeNow();
string getURLFromUser(int flag);
void exitPrg();
void invalidChoice();

void searchURL(string targetURL);