#ifndef ERROR_H
#define ERROR_H

#include <iostream>
#include <string>
#include <tuple>
#include "User_interface.h"
#include "Date.h"

using namespace std;

int int_check(const string str);
bool is_int(const string str);

bool is_double(const string str);
double double_check(const string str);

int supply_type_check();
int category_check();
int vehicle_category_check();

int check_position();
bool is_name(const string name);
string check_name(const string input_str);
bool is_date(const Date date);
Date check_date(const string input_str);
int discount_check();

#endif
