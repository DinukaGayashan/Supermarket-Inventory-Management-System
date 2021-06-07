#include "Error_check.h"

bool is_int(string str)
{
	size_t size = str.length();
	if (str == "-0" || str=="-" || size == 0)
		return false;

	for (int i = (str[0] == '-' ? 1 : 0); i < size; i++)
		if ((int)str[i] < (int)'0' || (int)str[i]>(int)'9')
			return false;

	return true;
}

int int_check(string str)
{
	int value(0);
	string input;
	while (true)
	{
		cout << str << "\t: ";
		getline(cin, input);

		if (is_int(input))
		{
			if (input.size() > 10)
			{
				cout << "Error 003 : Value limit exceeded\n";
				continue;
			}
			value = stoi(input);
			if (value < 0)
			{
				cout << "Error 002 : Value must be larger than 0\n";
				continue;
			}
			break;
		}

		cout << "Error 001 : Invalid input (Input must be an integer)\n";
	}

	return value;
}


bool is_double(string str)
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

double rupees_check(string str)
{
	double value(0);
	string input;
	while (true)
	{
		cout << str << "\t: ";
		getline(cin, input);

		if (is_double(input))
		{
			bool flag = false;
			size_t str_length = input.length();
			for (int i = 0; i < str_length; i++) {
				if (input[i] == '.' && i < str_length - 3)
				{
					cout << "Error 004 : Cannot have more than two decimal values\n";
					flag = true;
				}
			}
			if (flag)
				continue;
			if (input.length() > 10)
			{
				cout << "Error 003 : Value limit exceeded\n";
				continue;
			}
			value = stof(input);
			if (value < 0)
			{
				cout << "Error 002 : Value must be larger than or equal to 0\n";
				continue;
			}
			break;
		}

		cout << "Error 001 : Invalid input (Input must be a double)\n";
	}

	return value;
}

int supply_type_check()
{
	int type;

	while (true) {
		type = int_check("Enter supply type");

		if (type != 1 && type != 2) {
			cout << "Error Supply value must be either 1 or 2\n";
			continue;
		}
		break;
	}

	return type;
}

int category_check() {
	int ctgry;

	while (true) {
		ctgry = int_check("Enter Category type");

		if (ctgry > 10 || ctgry < 1) {
			cout << "Error category must be between 1 - 10\n";
			continue;
		}
		break;
	}

	return ctgry;
}