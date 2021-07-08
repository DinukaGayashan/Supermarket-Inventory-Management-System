#include "Error_check.h"

bool is_int(const string str)
{
	size_t size = str.length();
	if (str == "-0" || str=="-" || size == 0)
		return false;

	for (int i = (str[0] == '-' ? 1 : 0); i < size; i++)
		if ((int)str[i] < (int)'0' || (int)str[i]>(int)'9')
			return false;

	return true;
}

int int_check(const string str)
{
	int value(0);
	string input;
	while (true)
	{
		cout << str << ": ";
		getline(cin, input);

		if (is_int(input))
		{
			if (input.size() > 10)
			{
				display_error("II03");
				continue;
			}
			value = stoi(input);
			if (value < 0)
			{
				display_error("II02");
				continue;
			}
			break;
		}
		display_error("II01");
	}

	return value;
}


bool is_double(const string str)
{
	size_t size = str.length();
	if (str == "-0" || str == "-." || str == "-" || str[0] == '.' || size == 0)
		return false;

	int dotCount = 0;
	for (int i = (str[0] == '-' ? 1 : 0); i < size; i++)
	{
		if ((str[i] < '0' || str[i]>'9') && str[i] != '.')
			return false;
		if (str[i] == '.')
			dotCount++;
		if (dotCount > 1)
			return false;
	}

	return true;
}

double rupees_check(const string str)
{
	double value(0);
	string input;
	while (true)
	{
		cout << str << ": ";
		getline(cin, input);

		if (is_double(input))
		{
			bool flag = false;
			size_t str_length = input.length();
			for (int i = 0; i < str_length; i++) {
				if (input[i] == '.' && i < str_length - 3)
				{
					display_error("ID01");//check
					flag = true;
				}
			}
			if (flag)
				continue;
			if (input.length() > 10)
			{
				display_error("ID03");
				continue;
			}
			value = stof(input);
			if (value < 0)
			{
				display_error("ID02");
				continue;
			}
			break;
		}

		display_error("ID01");
	}

	return value;
}

int supply_type_check()
{
	int type;

	while (true) {
		type = int_check("Enter supply type number");

		if (type != 1 && type != 2) {
			display_error("II05");
			continue;
		}
		break;
	}

	return type;
}

int category_check() 
{
	int ctgry;

	while (true) {
		ctgry = int_check("Enter category number\t");

		if (ctgry > 10 || ctgry < 1) {
			display_error("II04");
			continue;
		}
		break;
	}
	return ctgry;
}

int vehicle_category_check() 
{
	int vctgry;

	while (true) {
		vctgry = int_check("Enter vehicle category\t");

		if (vctgry > 3 || vctgry < 1) {
			display_error("II06");
			continue;
		}
		break;
	}
	return vctgry;
}

int discount_check() {
	int dscnt;

	while (true) {
		dscnt = int_check("Enter Discount Percentage");

		if (dscnt > 100 || dscnt < 0) {
			display_error("II07");
			continue;
		}
		break;
	}

	return dscnt;
}

bool is_name(const string name) {
	for (char i : name)
		if ((i < 'a' || i > 'z') && (i < 'A' || i > 'Z') && i!=' ')
			return false;

	return true;
}

bool is_date(const Date date) {
	const int day = date.day;
	const int month = date.month;
	const int year = date.year;

	if (day < 1 || day > 31)		return false;
	if (month < 1 || month > 12)	return false;
	if (year < 2000 || year > 2050) return false;

	if (!(month % 2 == 1 || month == 8) && day > 30)	return false;

	//leap years were not concerned
	if (month == 2 && day > 29)	return false;

	return true;

}

int check_position() {
	int position;

	while (true) {
		position = int_check("Enter position\t");

		if (position > 3 || position < 0) {
			display_error("II06");
			continue;
		}
		break;
	}

	return position;
}

string check_name(const string input_str) {
	string name;

	while (true) {
		cout << input_str << ": ";
		getline(cin, name);

		if (is_name(name)==false) {
			display_error("IS01");
			continue;
		}
		break;
	}

	return name;
}


Date check_date(const string input_str) {

	Date date;
	while (true) {
		cout << input_str <<endl;
		date.day = int_check("Enter day\t");
		date.month = int_check("Enter month\t");
		date.year = int_check("Enter year\t");

		if (is_date(date) == false) {
			display_error("IA01");
			continue;
		}
		break;
	}

	return date;
}