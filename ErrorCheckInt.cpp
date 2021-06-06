#include "ErorCheck.h"

bool isInt(string str)
{
	int size = str.length();
	if (str == "-0" || size == 0)
		return false;

	for (int i = (str[0] == '-' ? 1 : 0); i < size; i++)
		if ((int)str[i] < (int)'0' || (int)str[i]>(int)'9')
			return false;

	return true;
}

int intCheck()
{
	int value(0);
	string input;
	while (true)
	{
		cout << "Enter Number\t: ";
		getline(cin, input);

		if (isInt(input))
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
