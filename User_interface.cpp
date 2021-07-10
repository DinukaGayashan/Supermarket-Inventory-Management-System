#include "User_interface.h"

void display_header(string user, int user_position)
{
	system("cls");

	int size = 200;

	cout << endl;
	for (int i = 0; i < size / 2 - 10; i++)
		cout << " ";
	cout << "The Supermarket\n";
	for (int i = 0; i < size / 2 - 10; i++)
		cout << " ";
	cout << "Inventory System\n";
	cout << "Date: " << get_date() << endl;
	cout << "Time: " << get_time() << endl;
	if (user.length() > 0)
	{
		cout << "Logged in as " << user<<", ";
		if (user_position == 0)
			cout << "Owner";
		else if (user_position == 1)
			cout << "Manager";
		else if (user_position == 2)
			cout << "Cashier";
		else if (user_position == 3)
			cout << "Floor worker";
		cout << "\n";
	}
	for (int i = 0; i < size; i++)
		cout << "_";
	cout << "\n\n";
}

void display_login_screen(string& username, int& user_position)
{
	display_header("", NULL);
	cout << "\nPlease login to enter inventory system.\n\n";

	string in_username,in_password,password;
	bool condition = 0;
	int pos = NULL;

	vector <Staff> users = Staff::read_staff_data();

	do
	{
		cout << "Username : ";
		getline(cin, in_username);
		to_upper(in_username, 1);
		for (int i = 0; i < users.size(); i++)
			if (users[i].get_username() == in_username)
			{
				condition = 1;
				password = users[i].get_password();
				pos = users[i].get_position().first;
			}
		if (condition == 0)
			display_error("SD06");
	} while (condition == 0);

	condition = 0;
	do
	{
		in_password=enter_password("Password : ");
		if (in_password == password)
			condition = 1;
		if (condition == 0)
		{
			cout << endl;
			display_error("SD08");
		}
	} while (condition == 0);

	username = in_username;
	user_position = pos;
}

void display_instructions()
{
	cout << "\n\tHelp\n";
	cout << "---------------------------------------------------------------------------------------------------------------------\n\n";
	cout << "\t?\tThe floor workers cannot access the staff section. They can only access the stock and supply,\n";
	cout << "\t\tand increase the number of stock of an existing product in the inventory.\n\n";
	cout << "\t?\tThe cashiers cannot access the staff section. They can only access the stock and supply\n";
	cout << "\t\tand reduce the stock of the relevant items after a successful transaction with a customer.\n\n";
	cout << "\t?\tThe managers can access all three sections stock, staff and supply. They can add or remove \n";
	cout << "\t\titems from the inventory, check the details of the staff members and also able to perform\n";
	cout << "\t\tall the actions of the cashier and floor workers.\n\n";
	cout << "\t?\tThe owner can access all three sections and is able to perform all the other actions performed\n";
	cout << "\t\tby oother three employees. In addition to that the owner is the only user that is able to add or\n";
	cout << "\t\tremove staff members.\n\n";
	system("pause");
}

void display_credits()
{
	cout << "\n\tCredits\n";
	cout << "---------------------------------------------------------------------------------------------------------------------\n\n";
	cout << "\t_________________________________________________________________________________\n\t|\t\t\t\t\t\t\t\t\t\t|\n";
	cout << "\t|\t\tDeveloped by: Team CMD\t\t\t\t\t\t|\n";
	cout << "\t|\t\t\t\t\t\t\t\t\t\t|\n\t|\t\t\t\tRANASINGHE R.A.C.M.\t\t\t\t|\n\t|\t\t\t\tKASTHURIARACHCHI K.A.D.G.\t\t\t|\n\t|\t\t\t\tWICKRAMASINGHE K.W.M.M.D.\t\t\t|\n";
	cout << "\t|_______________________________________________________________________________|\n\n\n";
	system("pause");
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
	cout << "\nSupply Types\n";
	cout << "-------------------------\n";
	cout << "1. Local\n";
	cout << "2. Imported\n";
}

void display_source_type()
{
	cout << "\nSupply Types\n";
	cout << "-------------------------\n";
	cout << "1. Local\n";
	cout << "2. International\n";
}

void display_staff_positions()
{
	cout << "\nStaff Positions\n";
	cout << "-------------------------\n";
	cout << "1. Manager\n";
	cout << "2. Cashier\n";
	cout << "3. Floor worker\n";
}

void display_vehicle_types()
{
	cout << "\nVehicle Types\n";
	cout << "-------------------------\n";
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
	else if (error == "SD06")	cerr << "\a\terror SD06: Non-existing username entered.\n";
	else if (error == "SD07")	cerr << "\a\terror SD07: Item do not exist in the stock. Add item before supplying.\n";
	else if (error == "SD08")	cerr << "\a\terror SD08: Invalid password entered.\n";
	else if (error == "SD09")	cerr << "\a\terror SD09: Already existing item entered.\n";
	else if (error == "SD10")	cerr << "\a\terror SD10: Non-existing username entered.\n";

	else if (error == "AM01")	cerr << "\a\terror AM01: You don't have access to this menu.\n";
}

void display_stock_table(vector <Stock>& stock)
{
	size_t max_name = 9, max_brand_name = 10;
	size_t size = stock.size();
	double total = 0;
	int length = 178;

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
	cout << "  Item Name  ";
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

		cout << "    " << stock[i].get_item_id() << "            ";

		display_category(stock[i].get_item_category());
		cout << "    ";

		to_upper(stock[i].get_item_name(), 0);
		
		cout << stock[i].get_item_name();
		for (int j = 0; j < (max_name - stock[i].get_item_name().length()); j++)
			cout << " ";
		cout << "              ";

		if (stock[i].get_item_brand_name()=="NOBRAND")
			cout << "  -    ";
		else
		{
			to_upper(stock[i].get_item_brand_name(), 0);
			cout << stock[i].get_item_brand_name();
		}

		for (int j = 0; j < (max_brand_name - stock[i].get_item_brand_name().length()); j++)
			cout << " ";
		cout << "              ";

		if (stock[i].get_item_supply_type() == "notype")
			cout << "  -   ";
		else
			cout << stock[i].get_item_supply_type();
		if (stock[i].get_item_supply_type() == "Local")
			cout << "   ";
		else if (stock[i].get_item_supply_type() == "notype")
			cout << "  ";
		cout << "           ";
		
		if (stock[i].get_item_category() == 1 || stock[i].get_item_category() == 2 || stock[i].get_item_category() == 3)
			cout << fixed << setprecision(3)  << stock[i].get_quantity() / 1000.0 << " kg";
		else
		{
			cout << fixed << setprecision(0) << stock[i].get_quantity();
			if (stock[i].get_quantity() < 10)
				cout << "       ";
			else if (stock[i].get_quantity() < 100)
				cout << "      ";
			else if (stock[i].get_quantity() < 1000)
				cout << "     ";
			else if (stock[i].get_quantity() < 10000)
				cout << "    ";
			else if (stock[i].get_quantity() < 100000)
				cout << "   ";
			else if (stock[i].get_quantity() < 1000000)
				cout << "  ";
			else if (stock[i].get_quantity() < 10000000)
				cout << " ";
		}

		cout << fixed << setprecision(2);

		cout << "          ";
		cout << stock[i].get_retail_price();
		if (stock[i].get_retail_price() < 10)
			cout << "       ";
		else if (stock[i].get_retail_price() < 100)
			cout << "      ";
		else if (stock[i].get_retail_price() < 1000)
			cout << "     ";
		else if (stock[i].get_retail_price() < 10000)
			cout << "    ";
		else if (stock[i].get_retail_price() < 100000)
			cout << "   ";
		else if (stock[i].get_retail_price() < 1000000)
			cout << "  ";
		else if (stock[i].get_retail_price() < 10000000)
			cout << " ";
		cout << "     ";
		cout << stock[i].get_discount() << "%";
		if (stock[i].get_discount() < 10)
			cout << "       ";
		else if (stock[i].get_discount() < 100)
			cout << "      ";
		else if (stock[i].get_discount() < 1000)
			cout << "     ";
		else if (stock[i].get_discount() < 10000)
			cout << "    ";
		else if (stock[i].get_discount() < 100000)
			cout << "   ";
		else if (stock[i].get_discount() < 1000000)
			cout << "  ";
		else if (stock[i].get_discount() < 10000000)
			cout << " ";
		cout << "   ";
		cout << stock[i].get_final_price() ;
		if (stock[i].get_final_price() < 10)
			cout << "       ";
		else if (stock[i].get_final_price() < 100)
			cout << "      ";
		else if (stock[i].get_final_price() < 1000)
			cout << "     ";
		else if (stock[i].get_final_price() < 10000)
			cout << "    ";
		else if (stock[i].get_final_price() < 100000)
			cout << "   ";
		else if (stock[i].get_final_price() < 1000000)
			cout << "  ";
		else if (stock[i].get_final_price() < 10000000)
			cout << " ";
		cout << "      ";
		total = total + stock[i].get_retail_price() * stock[i].get_quantity();
		cout << stock[i].get_retail_price() * stock[i].get_quantity() << "/=";
	}

	cout << endl;

	for (int i = 0; i < max_name + max_brand_name + length; i++)
		cout << "-";

	cout << endl;
	cout << "   Total Stock value";
	for (int i = 0; i < (max_name + max_brand_name + length - 39); i++)
		cout << " ";
	cout << "Rs " << total << "/=";
	cout << endl;

	for (int i = 0; i < max_name + max_brand_name + length; i++)
		cout << "-";
	cout << endl;
	cout << endl;
}



void transaction_bill(vector <Stock> stock, string cashier, string customer, string date, string time)
{
	int length = 80;
	double total = 0;

	cout << endl;
	for (size_t i = 0; i < length; i++)
		cout << "-";
	cout << endl;
	for (size_t i = 0; i < length / 2 - 8; i++)
		cout << " ";
	cout << "The Supermarket\n";

	for (size_t i = 0; i < length; i++)
		cout << "-";
	
	cout << endl;
	to_upper(cashier, 0);
	cout << "Cashier: " << cashier;
	for (size_t i = cashier.length(); i < length - 25; i++)
		cout << " ";
	cout << "Date: "<<date;
	
	cout << endl;
	to_upper(customer, 0);
	cout << "Customer: " << customer;
	for (int i = customer.length(); i < length - 26; i++)
		cout << " ";
	cout << "Time: " << time;

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
		cout << stock[i].get_item_id() << "        ";

		to_upper(stock[i].get_item_name(), 0);
		cout << stock[i].get_item_name();
		for (size_t j = stock[i].get_item_name().length(); j < 18; j++)
			cout << " ";

		if (stock[i].get_item_brand_name() == "NOBRAND")
			cout << "  -    ";
		else
		{
			to_upper(stock[i].get_item_brand_name(), 0);
			cout << stock[i].get_item_brand_name();
		}
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
	cout << "\n\n";
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
	return to_string(1900 + dt.tm_year) + "." + to_string(1 + dt.tm_mon) + "." + to_string(dt.tm_mday);
}

string get_time()
{
	struct tm dt;
	time_t now = time(0);
	localtime_s(&dt, &now);
	return to_string(dt.tm_hour) + "." + to_string(dt.tm_min) + "." + to_string(dt.tm_sec);
}

