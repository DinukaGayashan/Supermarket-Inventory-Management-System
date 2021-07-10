#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

#include "Stock.h"
#include "Supply.h"
#include "Staff.h"
#include "Error_check.h"
#include "User_interface.h"

using namespace std;

int main() 
{	
	set_console_position(0, 0);
	set_console_size(1920, 1080);
	//set_font_size(24,22);
	
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
		cout << "Select option number\n\n";
		cout << "\t1. Stock\n";
		cout << "\t2. Supply\n";
		cout << "\t3. Staff\n";
		cout << "\t4. Help\n";
		cout << "\t5. Credits\n";
		cout << "\t6. Log out\n";
		cout << "\t7. Exit\n";
		cout << endl;

		char a = _getch();

		if (a == '1')
		{			
			if (user_position < 4)
			{
				do
				{	
					display_header(username, user_position);
					cout << "Main menu  >  Stock\n\n";
					cout << "Select option\n\n";
					cout << "\t1. View item details\n";
					cout << "\t2. Add item\n";
					cout << "\t3. Edit item\n";
					cout << "\t4. Remove item\n";
					cout << "\t5. Add promotion\n";
					cout << "\t6. Transaction\n";
					cout << "\t7. Go back to main menu\n";
					cout << endl;

					char b = _getch();

					if (b == '1')
					{						
						if (user_position < 4)
						{						
							do
							{
								display_header(username, user_position);
								cout << "Main menu  >  Stock  >  View item details\n\n";
								cout << "Select option\n\n";
								cout << "\t1. Search by item ID\n";
								cout << "\t2. Search by item name\n";
								cout << "\t3. Search by item category\n";
								cout << "\t4. View all stock items\n";
								cout << "\t5. Go back\n";
								cout << endl;

								char b1 = _getch();

								if (b1 == '1')
								{									
									if (user_position < 4)
									{
										display_header(username, user_position);
										cout << "Main menu  >  Stock  >  View item details  >  Search by item ID\n\n";
										vector<Stock> all_stock;
										for (int ii = 1; ii < 11; ii++)
										{
											vector <Stock> temp = Stock::read_data(ii);
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
										vector<Stock> all_stock;
										for (int ii = 1; ii < 11; ii++)
										{
											vector <Stock> temp = Stock::read_data(ii);
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
										int b1c = category_check();
										vector <Stock> stock = Stock::read_data(b1c);
										display_stock_table(stock);
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
										vector<Stock> all_stock;
										for (int ii = 1; ii < 11; ii++)
										{
											vector <Stock> temp = Stock::read_data(ii);
											for (int ij = 0; ij < temp.size(); ij++)
												all_stock.push_back(temp[ij]);
										}
										display_stock_table(all_stock);
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
					{						
						if (user_position < 2)
						{
							do
							{
								display_header(username, user_position);
								cout << "Main menu  >  Stock  >  Add promotion\n\n";
								cout << "Select option\n\n";
								cout << "\t1. For an item\n";
								cout << "\t2. For a brand\n";
								cout << "\t3. For a category\n";
								cout << "\t4. Go back\n";
								cout << endl;

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
					else if (b == '6')
					{
						if (user_position < 3)
						{
							do
							{
								display_header(username, user_position);
								cout << "Main menu  >  Stock  >  Transaction\n\n";
								cout << "Select option\n\n";
								cout << "\t1. New transaction\n";
								cout << "\t2. Transaction log\n";
								cout << "\t3. Go back\n";
								cout << endl;

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
		else if (a == '2')
		{
			if (user_position < 4)
			{
				do
				{
					display_header(username, user_position);
					cout << "Main menu  >  Supply\n\n";
					cout << "Select option\n\n";
					cout << "\t1. View supply details\n";
					cout << "\t2. Add supply item\n";
					cout << "\t3. Update stock\n";
					cout << "\t4. Go back to main menu\n";
					cout << endl;

					char c = _getch();

					if (c == '1')
					{
						if (user_position < 4)
						{							
							do
							{
								display_header(username, user_position);
								cout << "Main menu  >  Supply  >  View supply details\n\n";
								cout << "Select option\n\n";
								cout << "\t1. Search by name\n";
								cout << "\t2. View all supply items\n";
								cout << "\t3. Go back\n";
								cout << endl;

								char c1 = _getch();

								if (c1 == '1')
								{
									if (user_position < 3)
									{
										display_header(username, user_position);
										cout << "Main menu  >  Supply  >  View supply details  >  Search by name\n\n";
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
							}
							while (1);
						}
						else
						{
							display_error("AM01");
							system("pause");
						}
					}
					else if (c == '2')
					{
						if (user_position < 4)
						{
							display_header(username, user_position);
							cout << "Main menu  >  Supply  >  Add supply item\n\n";
							Supply temp;
							temp.get_data();
						}
						else
							display_error("AM01");
						system("pause");
					}
					else if (c == '3')
					{
						if (user_position < 4)
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
		else if (a == '3')
		{
			if (user_position < 2)
			{
				do
				{
					display_header(username, user_position);
					cout << "Main menu  >  Staff\n\n";
					cout << "Select option\n\n";
					cout << "\t1. View staff details\n";
					cout << "\t2. Add staff member\n";
					cout << "\t3. Remove staff member\n";
					cout << "\t4. Go back to main menu\n";
					cout << endl;
	
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