#include "User_interface.h"

void display_header()
{
	int size = 200;

	cout << endl;
	for (int i = 0; i < size/2-10; i++)
		cout << " ";
	cout << "CMD Supermarket\n";
	

	for (int i = 0; i < size; i++)
		cout << "_";
	cout << endl;
}

void set_console_position(int x, int y)
{
	HWND console_window = GetConsoleWindow();
	SetWindowPos(console_window, 0, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

void set_console_size(int w, int h)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, w, h, true);
}

void set_font_size(int a, int b) 
{
	PCONSOLE_FONT_INFOEX lp_console_current_font_ex = new CONSOLE_FONT_INFOEX();
	lp_console_current_font_ex->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, lp_console_current_font_ex);
	lp_console_current_font_ex->dwFontSize.X = a;
	lp_console_current_font_ex->dwFontSize.Y = b;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, lp_console_current_font_ex);
}

string get_date() 
{
	struct tm dt;
	time_t now = time(0);
	localtime_s(&dt, &now);
	return "Date: " + to_string(1900 + dt.tm_year) + "." + to_string(1 + dt.tm_mon) + "." + to_string(dt.tm_mday);
}

string get_time()
{
	struct tm dt;
	time_t now = time(0);
	localtime_s(&dt, &now);
	return "Time: " + to_string(dt.tm_hour) + "." + to_string(dt.tm_min) + "." + to_string(dt.tm_sec);
}

void display_category(int n)
{
	switch (n)
	{
	case 1:
		cout << "Produce            \t"; break;
	case 2:
		cout << "Meat & Seafood     \t"; break;
	case 3:
		cout << "Grains             \t"; break;
	case 4:
		cout << "Bakery products    \t"; break;
	case 5:
		cout << "Frozen foods       \t"; break;
	case 6:
		cout << "Dairy products     \t"; break;
	case 7:
		cout << "Snacks & Sweets    \t"; break;
	case 8:
		cout << "Beverages          \t"; break;
	case 9:
		cout << "Health & Beauty    \t"; break;
	case 10:
		cout << "Condiments & Spices\t"; break;
	default:
		cout << "no catagory defined\t"; break;
	}
}

void display_categories()
{
	cout << "\n\nCategories\n";
	cout << "-------------------------\n";
	cout << "1. Produce\n";
	cout << "2. Meat & Seafood\n";
	cout << "3. Grains\n";
	cout << "4. Bakery products\n";
	cout << "5. Frozen foods\n";
	cout << "6. Dairy products\n";
	cout << "7. Snacks & Sweets\n";
	cout << "8. Beverages\n";
	cout << "9. Health & Beauty\n";
	cout << "10. Condiments & Spices\n";
}

void display_supply_type()
{
	cout << "\nSupply Type\n";
	cout << "-------------------------\n";
	cout << "1. Local\n";
	cout << "2. Imported\n";
}

void display_source_type()
{
	cout << "\nSupply Type\n";
	cout << "-------------------------\n";
	cout << "1. Local\n";
	cout << "2. International\n";
}

void display_staff_positions()
{
	cout << "\nStaff Positions\n";
	cout << "---------------------------------------\n";
	cout << "1. Manager\n";
	cout << "2. Cashier\n";
	cout << "3. Floor worker\n";
}

void display_vehicle_types()
{
	cout << "\nVehicle Types\n";
	cout << "---------------------------------------\n";
	cout << "1. Large Truck\n";
	cout << "2. Small Truck\n";
	cout << "3. Van\n";
}

void display_error(string error)
{
	if (error == "II01")		cerr << "\a\terror II01: Input must be a counting number.\n";
	else if (error == "II02")	cerr << "\a\terror II02: Input must be larger than zero.\n";
	else if (error == "II03")	cerr << "\a\terror II03: Input value limit (xe10) exceeded.\n";
	else if (error == "II04")	cerr << "\a\terror II04: Input must be in the range of 1 to 10.\n";
	else if (error == "II05")	cerr << "\a\terror II05: Input must be either 1 or 2.\n";
	else if (error == "II06")	cerr << "\a\terror II06: Input must be in the range of 1 to 3.\n";
	else if (error == "II07")	cerr << "\a\terror II07: Input must be in the range of 0 to 100.\n";

	else if (error == "ID01")	cerr << "\a\terror ID01: Input must be a value with two decimal points.\n";
	else if (error == "ID02")	cerr << "\a\terror ID02: Input must be larger than zero.\n";
	else if (error == "ID03")	cerr << "\a\terror ID03: Input value limit (xe10) exceeded.\n";

	else if (error == "IB01")	cerr << "\a\terror IB01: Input must be either 1 or 0.\n";

	else if (error == "IS01")	cerr << "\a\terror IS01: Input must be a phrase with letters.\n";
	else if (error == "IS02")	cerr << "\a\terror IS02: Input passwords are not matching.\n";

	else if (error == "IA01")	cerr << "\a\terror IA01: Input must be a valid date.\n";

	else if (error == "SD01")	cerr << "\a\terror SD01: Invalid item ID entered.\n";
	else if (error == "SD02")	cerr << "\a\terror SD02: Non-existing item name entered.\n";
	else if (error == "SD03")	cerr << "\a\terror SD03: Non-existing brand name entered.\n";
	else if (error == "SD04")	cerr << "\a\terror SD04: Item quantity exceeded. No enough items.\n";
	else if (error == "SD05")	cerr << "\a\terror SD05: Already existing username entered.\n";
}

void display_help(string error)
{
	cout << "Error Coding\n";
	cout << "---------------------------------------\n";
	cout << "First letter corresponds to the task type (Input, Process)\n";
	cout << "Second letter corresponds to the data type\n";

	if (error == "II01")
		cerr << "error II01: ";


}

void display_stock_table(vector <Stock>& stock)
{
	size_t max_name = 9, max_brand_name = 10;
	size_t size = stock.size();
	double total = 0;
	int length = 180;

	for (int i = 0; i < size; i++)
	{
		if (stock[i].get_item_name().length() > max_name)
			max_name = stock[i].get_item_name().length() + 1;
	}

	for (int i = 0; i < size; i++)
	{
		if (stock[i].get_item_brand_name().length() > max_brand_name)
			max_brand_name = stock[i].get_item_brand_name().length();
	}

	cout << "\n";
	for (int i = 0; i < (max_name + max_brand_name + length-16) / 2; i++)
		cout << " ";
	cout << "Stock Table\n";

	for (int i = 0; i < max_name + max_brand_name + length; i++)
		cout << "-";

	cout << "\n|    " << "Item ID" << "    |";

	cout << "       " << "Item Catagory" << "       |";

	for (int i = 0; i < (max_name ) / 2; i++)
		cout << " ";
	cout << "   Item Name   ";
	for (int i = 0; i < (max_name ) / 2; i++)
		cout << " ";
	cout << "|";

	for (int i = 0; i < (max_brand_name ) / 2; i++)
		cout << " ";
	cout << "  Brand Name  ";
	for (int i = 0; i < (max_brand_name ) / 2; i++)
		cout << " ";
	cout << "|";

	cout << "    " << "Supply Type" << "    |";
	cout << "     " << "Quantity" << "     |";
	cout << " " << " Retail Price " << " |";
	cout << " " << "Discount" << " |";
	cout << " " << " Final Price " << " |";
	cout << "     " << "Stock Value" << "     |";

	cout << endl;

	for (int i = 0; i < max_name + max_brand_name + length; i++)
		cout << "-";

	for (int i = 0; i < size; i++)
	{
		cout << endl;

		cout << "    " << stock[i].get_item_id() << "          ";

		display_category(stock[i].get_item_category());
		cout << "    ";

		to_upper(stock[i].get_item_name(), 0);
		
		cout << stock[i].get_item_name();
		for (int j = 0; j < (max_name - stock[i].get_item_name().length()); j++)
			cout << " ";
		cout << "               ";

		to_upper(stock[i].get_item_brand_name(), 0);
		cout << stock[i].get_item_brand_name();
		for (int j = 0; j < (max_brand_name - stock[i].get_item_brand_name().length()); j++)
			cout << " ";
		cout << "              ";

		cout << stock[i].get_item_supply_type();
		if (stock[i].get_item_supply_type() == "Local")
			cout << "   ";
		else if (stock[i].get_item_supply_type() == "notype")
			cout << "   ";
		cout << "\t";
		
		if (stock[i].get_item_category() == 1 || stock[i].get_item_category() == 2 || stock[i].get_item_category() == 3)
			cout << fixed << setprecision(3) << "\t" << stock[i].get_quantity() / 1000.0 << " kg\t";
		else
			cout << fixed << setprecision(0) << "\t" << stock[i].get_quantity() << "\t\t";

		cout << fixed << setprecision(2);

		cout << "   ";
		cout << stock[i].get_retail_price() << "\t";
		cout << "   ";
		cout << stock[i].get_discount() << "%\t        ";
		cout << stock[i].get_final_price() << "\t\t";

		total = total + stock[i].get_retail_price() * stock[i].get_quantity();
		cout << stock[i].get_retail_price() * stock[i].get_quantity() << "/=";
	}

	cout << endl;

	for (int i = 0; i < max_name + max_brand_name + length; i++)
		cout << "-";

	cout << endl;
	for (int i = 0; i < (max_name + max_brand_name + length - 40); i++)
		cout << " ";
	cout << "Total Stock value : Rs\t" << total << "/=";

	cout << endl;
}
//
//void display_supply_table(vector <Supply>& supply)
//{
//	size_t max_name = 9, max_brand_name = 10;
//	size_t size = stock.size();
//	double total = 0;
//	int length = 180;
//
//	for (int i = 0; i < size; i++)
//	{
//		if (stock[i].get_item_name().length() > max_name)
//			max_name = stock[i].get_item_name().length() + 1;
//	}
//
//	for (int i = 0; i < size; i++)
//	{
//		if (stock[i].get_item_brand_name().length() > max_brand_name)
//			max_brand_name = stock[i].get_item_brand_name().length();
//	}
//
//	cout << "\n";
//	for (int i = 0; i < (max_name + max_brand_name + length - 16) / 2; i++)
//		cout << " ";
//	cout << "Stock Table\n";
//
//	for (int i = 0; i < max_name + max_brand_name + length; i++)
//		cout << "-";
//
//	cout << "\n|    " << "Item ID" << "    |";
//
//	cout << "       " << "Item Catagory" << "       |";
//
//	for (int i = 0; i < (max_name) / 2; i++)
//		cout << " ";
//	cout << "   Item Name   ";
//	for (int i = 0; i < (max_name) / 2; i++)
//		cout << " ";
//	cout << "|";
//
//	for (int i = 0; i < (max_brand_name) / 2; i++)
//		cout << " ";
//	cout << "  Brand Name  ";
//	for (int i = 0; i < (max_brand_name) / 2; i++)
//		cout << " ";
//	cout << "|";
//
//	cout << "    " << "Supply Type" << "    |";
//	cout << "     " << "Quantity" << "     |";
//	cout << " " << " Retail Price " << " |";
//	cout << " " << "Discount" << " |";
//	cout << " " << " Final Price " << " |";
//	cout << "     " << "Stock Value" << "     |";
//
//	cout << endl;
//
//	for (int i = 0; i < max_name + max_brand_name + length; i++)
//		cout << "-";
//
//	for (int i = 0; i < size; i++)
//	{
//		cout << endl;
//
//		cout << "    " << stock[i].get_item_id() << "          ";
//
//		display_category(stock[i].get_item_category());
//		cout << "    ";
//
//		to_upper(stock[i].get_item_name(), 0);
//
//		cout << stock[i].get_item_name();
//		for (int j = 0; j < (max_name - stock[i].get_item_name().length()); j++)
//			cout << " ";
//		cout << "               ";
//
//		to_upper(stock[i].get_item_brand_name(), 0);
//		cout << stock[i].get_item_brand_name();
//		for (int j = 0; j < (max_brand_name - stock[i].get_item_brand_name().length()); j++)
//			cout << " ";
//		cout << "              ";
//
//		cout << stock[i].get_item_supply_type();
//		if (stock[i].get_item_supply_type() == "Local")
//			cout << "   ";
//		else if (stock[i].get_item_supply_type() == "notype")
//			cout << "   ";
//		cout << "\t";
//
//		if (stock[i].get_item_category() == 1 || stock[i].get_item_category() == 2 || stock[i].get_item_category() == 3)
//			cout << fixed << setprecision(3) << "\t" << stock[i].get_quantity() / 1000.0 << " kg\t";
//		else
//			cout << fixed << setprecision(0) << "\t" << stock[i].get_quantity() << "\t\t";
//
//		cout << fixed << setprecision(2);
//
//		cout << "   ";
//		cout << stock[i].get_retail_price() << "\t";
//		cout << "   ";
//		cout << stock[i].get_discount() << "%\t        ";
//		cout << stock[i].get_final_price() << "\t\t";
//
//		total = total + stock[i].get_retail_price() * stock[i].get_quantity();
//		cout << stock[i].get_retail_price() * stock[i].get_quantity() << "/=";
//	}
//
//	cout << endl;
//
//	for (int i = 0; i < max_name + max_brand_name + length; i++)
//		cout << "-";
//
//	cout << endl;
//	for (int i = 0; i < (max_name + max_brand_name + length - 40); i++)
//		cout << " ";
//	cout << "Total Stock value : Rs\t" << total << "/=";
//
//	cout << endl;
//}

void display_staff_table(vector <Staff>& staff)
{
	size_t max_username = 8, max_full_name = 9;
	size_t size = staff.size();
	int length = 60;

	for (int i = 0; i < size; i++)
	{
		if (staff[i].get_username().length() > max_username)
			max_username = staff[i].get_username().length();
	}

	for (int i = 0; i < size; i++)
	{
		if (staff[i].get_full_name().length() > max_full_name)
			max_full_name = staff[i].get_full_name().length();
	}

	cout << "\n";
	for (int i = 0; i < (max_username + max_full_name + length - 16) / 2; i++)
		cout << " ";
	cout << "Staff Table\n";

	for (int i = 0; i < max_username + max_full_name + length; i++)
		cout << "-";

	cout << "\n|";
	for (int i = 0; i < (max_username) / 2; i++)
		cout << " ";
	cout << "Username";
	for (int i = 0; i < (max_username) / 2; i++)
		cout << " ";
	cout << "|";

	for (int i = 0; i < (max_full_name) / 2; i++)
		cout << " ";
	cout << " Full Name ";
	for (int i = 0; i < (max_full_name) / 2; i++)
		cout << " ";
	cout << "|";

	cout << "      " << "Position" << "      |";

	cout << "   " << "Joined date" << "   |";

	cout << "\n";
	for (int i = 0; i < max_username + max_full_name + length; i++)
		cout << "-";

	for (int i = 0; i < size; i++)
	{
		cout << endl;

		cout << "     ";
		cout << staff[i].get_username();
		for (int j = 0; j < (max_username - staff[i].get_username().length()); j++)
			cout << " ";
		cout << "          ";

		cout << staff[i].get_full_name();
		for (int j = 0; j < (max_full_name - staff[i].get_full_name().length()); j++)
			cout << " ";
		cout << "           ";

		cout << staff[i].get_position().second;
		for (int j = 0; j < (12 - staff[i].get_position().second.length()); j++)
			cout << " ";
		cout << "       ";

		cout << "1999.23.53";
		//cout << get_join_date().year << "." << get_join_date().month << "." << get_join_date().day << endl;
	}
	cout << endl;
	for (int i = 0; i < max_username + max_full_name + length; i++)
		cout << "-";
	cout << endl;
}

void transaction_bill(vector <Stock> stock, string cashier, string date, string time)
{
	int length = 80, total = 0;

	for (size_t i = 0; i < length / 2 - 8; i++)
		cout << " ";
	cout << "CMD Supermarket\n";

	for (size_t i = 0; i < length; i++)
		cout << "-";
	//bill number
	cout << endl;
	cout << "Cashier: " << cashier;

	for (size_t i = cashier.length(); i < length - 25; i++)
		cout << " ";
	cout << date;
	cout << endl;
	for (int i = 0; i < length - 16; i++)
		cout << " ";
	cout << time;

	cout << endl;
	for (int i = 0; i < length; i++)
		cout << "-";

	cout << endl;
	cout << "Item code     Item name        Brand name       Price * Quantity       Amount";

	cout << endl;
	for (int i = 0; i < length; i++)
		cout << "-";

	for (int i = 0; i < stock.size(); i++)
	{
		cout << endl;
		cout << stock[i].get_item_id() << "      ";

		cout << stock[i].get_item_name();
		for (size_t j = stock[i].get_item_name().length(); j < 18; j++)
			cout << " ";

		cout << stock[i].get_item_brand_name();
		for (size_t j = stock[i].get_item_brand_name().length(); j < 18; j++)
			cout << " ";

		cout << "" << stock[i].get_final_price();

		cout << " * " << stock[i].get_quantity();

		cout << "\t         " << stock[i].get_final_price()* stock[i].get_quantity();

		total = total + stock[i].get_final_price() * stock[i].get_quantity();
	}

	cout << endl;
	for (int i = 0; i < length; i++)
		cout << "-";

	cout << endl;
	cout << "Total";
	for (int i = 0; i < length - 12; i++)
		cout << " ";
	cout << total;

	cout << endl;
	for (int i = 0; i < length; i++)
		cout << "-";
}

void to_upper(string& input, bool to_upper)
{
	if (to_upper == 1)
	{
		size_t len = input.size();
		for (size_t i = 0; i < len; i++) {
			if (input[i] == ' ')
				input[i] = '_';
			else if (input[i] >= 'a' && input[i] <= 'z')
				input[i] = input[i] - 32;
		}
	}
	else
	{
		size_t len = input.size();
		if (input[0] == '_')
			input[0] = ' ';
		for (size_t i = 1; i < len; i++) {
			if (input[i] == '_')
				input[i] = ' ';
			else if (input[i] >= 'A' && input[i] <='Z')
				input[i] = input[i] + 32;
		}
	}
}

string enter_password(const string& prompt)
{
	string result;

	DWORD mode = 0, count;
	HANDLE ih = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE oh = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!GetConsoleMode(ih, &mode))
		throw runtime_error("getpassword: You must be connected to a console to use this program.\n");
	SetConsoleMode(ih, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

	WriteConsoleA(oh, prompt.c_str(), prompt.length(), &count, NULL);
	char c;
	while (ReadConsoleA(ih, &c, 1, &count, NULL) && (c != '\r') && (c != '\n'))
	{
		if (c == '\b')
		{
			if (result.length())
			{
				WriteConsoleA(oh, "\b \b", 3, &count, NULL);
				result.erase(result.end() - 1);
			}
		}
		else
		{
			WriteConsoleA(oh, "*", 1, &count, NULL);
			result.push_back(c);
		}
	}

	SetConsoleMode(ih, mode);

	return result;
}
