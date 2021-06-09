#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <iomanip>
#include "Stock.h"

using namespace std;

void console_size(int w, int h);
void console_position(int x, int y);
void category(int n);
void categories();
void supply_type();
void error(string error);
void error_discription(string error);
void stock_table(vector <Stock> stock);

#endif
