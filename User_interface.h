#ifndef CLI_H
#define CLI_H

#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <iomanip>
#include <ctime>
#include <stdexcept>
#include "Staff.h"
#include "Stock.h"
//#include "Supply.h"

class Stock;
//class Supply;
class Staff;

using namespace std;

void display_header(string user, int user_position);
void display_login_screen(string &username,int &user_position);
void display_main_menu(string username, int user_position);
void display_stock_menu(string username, int user_position);
void display_supply_menu(string username, int user_position);
void display_staff_menu(string username, int user_position);
void display_instructions();
void display_credits();
string get_date();
string get_time();
void set_console_size(int w, int h);
void set_console_position(int x, int y);
void set_font_size(int a, int b);
void display_category(int n);
void display_categories();
void display_supply_type();
void display_source_type();
void display_staff_positions();
void display_vehicle_types();
void display_error(string error);
void display_stock_table(vector <Stock>& stock);
void transaction_bill(vector <Stock> stock, string cashier, string date, string time);
void to_upper(string& input, bool to_upper);
string enter_password(const string& prompt);

#endif
