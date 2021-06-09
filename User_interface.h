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
void display_category(int n);
void display_categories();
void display_supply_type();
void display_error(string error);
void display_error_discription(string error);
void display_stock_table(vector <Stock> stock);

#endif
