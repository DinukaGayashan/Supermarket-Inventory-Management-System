#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Error_check.h"
#include "Staff.h"
#include "Stock.h"
#include "Supply.h"
#include "User_interface.h"

using namespace std;

void search_stock_item_by_id()
{
	vector<Stock> all_stock;
	for (int ii = 1; ii < 11; ii++)
	{
		vector<Stock> temp = Stock::read_data(ii);
		for (int ij = 0; ij < temp.size(); ij++)
			all_stock.push_back(temp[ij]);
	}
	bool not_found = 0;
	string id;
	Stock item;
	cout << "\nEnter item ID\t\t: ";
	getline(cin, id);
	to_upper(id, 1);
	item = Stock::find_by_id(id, all_stock, not_found);
	if (not_found)
		display_error("SD01");
	else
		item.show_data();
}

void search_stock_item_by_name()
{
	vector<Stock> all_stock;
	for (int ii = 1; ii < 11; ii++)
	{
		vector<Stock> temp = Stock::read_data(ii);
		for (int ij = 0; ij < temp.size(); ij++)
			all_stock.push_back(temp[ij]);
	}
	string name;
	cout << "\nEnter item Name\t\t: ";
	getline(cin, name);
	to_upper(name, 1);
	vector<Stock> items = Stock::find_item(name, 1);
	if (items.size() == 0)
		display_error("SD02");
	else if (items.size() == 1)
		items[0].show_data();
	else
	{
		Stock item;
		Stock::find_name_and_display(item, all_stock, name, 1);
		item.show_data();
	}
}

void search_stock_item_by_category()
{
	int b1c = category_check();
	vector<Stock> stock = Stock::read_data(b1c);
	display_stock_table(stock);
}

void view_all_stock_items()
{
	vector<Stock> all_stock;
	for (int ii = 1; ii < 11; ii++)
	{
		vector<Stock> temp = Stock::read_data(ii);
		for (int ij = 0; ij < temp.size(); ij++)
			all_stock.push_back(temp[ij]);
	}
	display_stock_table(all_stock);
}

void search_supply_item_by_name()
{
	vector<Supply> all_supply = Supply::supply_read_data();
	string name;
	cout << "\nEnter item Name\t\t: ";
	getline(cin, name);
	to_upper(name, 1);
	vector<Supply> items;
	for (auto i : all_supply)
		if (i.get_supply_item_name() == name)
			items.push_back(i);

	if (items.size() == 0)
		display_error("SD02");
	else if (items.size() == 1)
		items[0].show_data();
	else
		Supply::display_supply_table(items);
}

void add_supply_item()
{
	Supply temp;
	temp.get_data();
	cout << "\nPress [ENTER] to save or press [ESC] to cancel.\n\n";
	char c = _getch();
	if (c == 13)
		temp.supply_write_data();
}

void view_item_details(int user_position, std::string &username)
{
	{
		if (user_position < 4)
		{
			do
			{
				display_header(username, user_position);
				cout << "Main menu  >  Stock  >  View item details\n\n";
				display_view_item_details();
				char b1 = _getch();

				if (b1 == '1')
				{
					if (user_position < 4)
					{
						display_header(username, user_position);
						cout << "Main menu  >  Stock  >  View item details  >  Search by item ID\n\n";
						search_stock_item_by_id();
					}
					else
						display_error("AM01");
					system("pause");
				}
				else if (b1 == '2')
				{
					if (user_position < 4)
					{
						display_header(username, user_position);
						cout << "Main menu  >  Stock  >  View item details  >  Search by item name\n\n";
						search_stock_item_by_name();
					}
					else
						display_error("AM01");
					system("pause");
				}
				else if (b1 == '3')
				{
					if (user_position < 4)
					{
						display_header(username, user_position);
						cout << "Main menu  >  Stock  >  View item details  >  Search by item category\n\n";
						search_stock_item_by_category();
					}
					else
						display_error("AM01");
					system("pause");
				}
				else if (b1 == '4')
				{
					if (user_position < 4)
					{
						display_header(username, user_position);
						cout << "Main menu  >  Stock  >  View item details  >  View all stock items\n\n";
						view_all_stock_items();
					}
					else
						display_error("AM01");
					system("pause");
				}
				else if (b1 == '5')
					break;
			} while (1);
		}
		else
		{
			display_error("AM01");
			system("pause");
		}
	}
}

void add_promotion(int user_position, std::string &username)
{
	{
		if (user_position < 2)
		{
			do
			{
				display_header(username, user_position);
				cout << "Main menu  >  Stock  >  Add promotion\n\n";
				display_add_promotion();
				char b5 = _getch();

				if (b5 == '1')
				{
					if (user_position < 2)
					{
						display_header(username, user_position);
						cout << "Main menu  >  Stock  >  Add promotion  >  For an item\n\n";
						Stock::promotion(1);
					}
					else
						display_error("AM01");
					system("pause");
				}
				else if (b5 == '2')
				{
					if (user_position < 2)
					{
						display_header(username, user_position);
						cout << "Main menu  >  Stock  >  Add promotion  >  For a brand\n\n";
						Stock::promotion(2);
					}
					else
						display_error("AM01");
					system("pause");
				}
				else if (b5 == '3')
				{
					if (user_position < 2)
					{
						display_header(username, user_position);
						cout << "Main menu  >  Stock  >  Add promotion  >  For a category\n\n";
						Stock::promotion(3);
					}
					else
						display_error("AM01");
					system("pause");
				}
				else if (b5 == '4')
					break;
			} while (1);
		}
		else
		{
			display_error("AM01");
			system("pause");
		}
	}
}

void transaction(int user_position, std::string &username)
{
	{
		if (user_position < 3)
		{
			do
			{
				display_header(username, user_position);
				cout << "Main menu  >  Stock  >  Transaction\n\n";
				display_transaction();
				char b6 = _getch();

				if (b6 == '1')
				{
					if (user_position < 3)
					{
						display_header(username, user_position);
						cout << "Main menu  >  Stock  >  Transaction  > New transaction\n\n";
						Stock::transaction(username);
					}
					else
						display_error("AM01");
					system("pause");
				}
				else if (b6 == '2')
				{
					if (user_position < 3)
					{
						display_header(username, user_position);
						cout << "Main menu  >  Stock  >  Add promotion  > Transaction log\n\n";
						Stock::read_transaction();
					}
					else
						display_error("AM01");
					system("pause");
				}
				else if (b6 == '3')
					break;
			} while (1);
		}
		else
		{
			display_error("AM01");
			system("pause");
		}
	}
}

void display_stock_menu(int user_position, string username)
{
	if (user_position < 4)
	{
		do
		{
			display_header(username, user_position);
			cout << "Main menu  >  Stock\n\n";
			display_stock();

			char b = _getch();

			if (b == '1')
				view_item_details(user_position, username);
			else if (b == '2')
			{
				if (user_position < 2)
				{
					display_header(username, user_position);
					cout << "Main menu  >  Stock  >  Add item\n\n";
					Stock::input_data();
				}
				else
					display_error("AM01");
				system("pause");
			}
			else if (b == '3')
			{
				if (user_position < 2)
				{
					display_header(username, user_position);
					cout << "Main menu  >  Stock  >  Edit item\n\n";
					Stock::edit_item();
				}
				else
					display_error("AM01");
				system("pause");
			}
			else if (b == '4')
			{
				if (user_position < 2)
				{
					display_header(username, user_position);
					cout << "Main menu  >  Stock  >  Remove item\n\n";
					Stock::delete_item();
				}
				else
					display_error("AM01");
				system("pause");
			}
			else if (b == '5')
				add_promotion(user_position, username);
			else if (b == '6')
				transaction(user_position, username);
			else if (b == '7')
				break;
		} while (1);
	}
	else
	{
		display_error("AM01");
		system("pause");
	}
}

void view_supply_details(int user_position, std::string &username)
{
	{
		if (user_position < 4)
		{
			do
			{
				display_header(username, user_position);
				cout << "Main menu  >  Supply  >  View supply details\n\n";
				display_view_supply_details();
				char c1 = _getch();

				if (c1 == '1')
				{
					if (user_position < 3)
					{
						display_header(username, user_position);
						cout << "Main menu  >  Supply  >  View supply details  >  Search by name\n\n";
						search_supply_item_by_name();
					}
					else
						display_error("AM01");
					system("pause");
				}
				else if (c1 == '2')
				{
					if (user_position < 3)
					{
						display_header(username, user_position);
						cout << "Main menu  >  Supply  >  View supply details  >  View all supply items\n\n";
						Supply::display_supply_table(Supply::supply_read_data());
					}
					else
						display_error("AM01");
					system("pause");
				}
				else if (c1 == '3')
					break;
			} while (1);
		}
		else
		{
			display_error("AM01");
			system("pause");
		}
	}
}

void display_supply_menu(int user_position, string username)
{
	if (user_position < 4)
	{
		do
		{
			display_header(username, user_position);
			cout << "Main menu  >  Supply\n\n";
			display_supply();
			char c = _getch();

			if (c == '1')
				view_supply_details(user_position, username);
			else if (c == '2')
			{
				if (user_position < 2)
				{
					display_header(username, user_position);
					cout << "Main menu  >  Supply  >  Add supply item\n\n";
					add_supply_item();
				}
				else
					display_error("AM01");
				system("pause");
			}
			else if (c == '3')
			{
				if (user_position < 2 || user_position == 4)
				{
					display_header(username, user_position);
					cout << "Main menu  >  Supply  >  Update stock\n\n";
					Supply temp;
					temp.update_stock();
				}
				else
					display_error("AM01");
				system("pause");
			}
			else if (c == '4')
				break;
		} while (1);
	}
	else
	{
		display_error("AM01");
		system("pause");
	}
}

void display_staff_menu(int user_position, string username)
{
	if (user_position < 2)
	{
		do
		{
			display_header(username, user_position);
			cout << "Main menu  >  Staff\n\n";
			display_staff();

			char d = _getch();

			if (d == '1')
			{
				if (user_position < 2)
				{
					display_header(username, user_position);
					cout << "Main menu  >  Staff  >  View staff details\n\n";
					Staff::display_staff_table(Staff::read_staff_data());
				}
				else
					display_error("AM01");
				system("pause");
			}
			else if (d == '2')
			{
				if (user_position < 1)
				{
					display_header(username, user_position);
					cout << "Main menu  >  Staff  >  Add staff member\n\n";
					Staff temp;
					temp.add_user();
					temp.staff_write_data();
				}
				else
					display_error("AM01");
				system("pause");
			}
			else if (d == '3')
			{
				if (user_position < 1)
				{
					display_header(username, user_position);
					cout << "Main menu  >  Staff  >  Remove staff member\n\n";
					Staff::remove_user();
				}
				else
					display_error("AM01");
				system("pause");
			}
			else if (d == '4')
				break;
		} while (1);
	}
	else
	{
		display_error("AM01");
		system("pause");
	}
}

int main()
{
	set_console_position(0, 0);
	set_console_size(1920, 1080);
	set_font_size(24, 22);

	string username;
	int user_position;
	bool logout = 1;

	do
	{
		if (logout)
		{
			display_login_screen(username, user_position);
			logout = 0;
		}

		display_header(username, user_position);
		cout << "Main menu\n\n";
		display_main_menu();

		char a = _getch();

		if (a == '1')
			display_stock_menu(user_position, username);
		else if (a == '2')
			display_supply_menu(user_position, username);
		else if (a == '3')
			display_staff_menu(user_position, username);
		else if (a == '4')
		{
			display_header(username, user_position);
			cout << "Main menu  >  Help\n\n";
			display_instructions();
		}
		else if (a == '5')
		{
			display_header(username, user_position);
			cout << "Main menu  >  Credits\n\n";
			display_credits();
		}
		else if (a == '6')
			logout = 1;
		else if (a == '7')
		{
			system("cls");
			return 0;
		}
	} while (1);

	return 0;
}
