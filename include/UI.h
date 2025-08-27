#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
// ANSI color codes
#include "ColorCodes.h"
using namespace std;

void printMenu(vector<string> &options, int width=40);
int getIDFromUser();
string getURLFromUser();
void exitPrg();
void invalidChoice();