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

										if (items.size() == 0) {
											display_error("SD02");
										}

										else {
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
										cout << "Main menu  >  Stock  >  Add promotion  > For an item\n\n";
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
										cout << "Main menu  >  Stock  >  Add promotion  > For a brand\n\n";
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
										cout << "Main menu  >  Stock  >  Add promotion  > For a category\n\n";
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
							display_header(username, user_position);
							cout << "Main menu  >  Supply  >  View supply details\n\n";
							Supply::display_supply_table(Supply::supply_read_data());
						}
						else
							display_error("AM01");
						system("pause");
					}
					else if (c == '2')
					{
						if (user_position < 4)
						{
							display_header(username, user_position);
							cout << "Main menu  >  Supply  >  Add supply item\n\n";
							Supply temp;
							temp.get_data();
							temp.supply_write_data();
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














	//cout << username <<endl<< user_position;

	//display_main_menu(username, user_position);



	/*Stock s1, s2("AAA00000","vghfjcfggjfv", "nfghjxfg", "chghhjd", "notype", 20, 90, 2, 3);
	vector < Stock > stock = { s1, s2 };*/

	//display_stock_table(stock);
	
	//display_categories();
	//Staff s;
	//s.add_user();
	//s.show_data();

	//Stock stock1, stock2;
	//stock1.input_data();
	//stock1.write_data(stock1.get_item_category());
	//
	//stock2.input_data();
	//stock2.write_data(stock2.get_item_category());

	//cout << "NOOOOOOOb";
	//vector<Stock> r = Stock::read_data(3);
	//display_stock_table(r);
	/*
	string name = "apPLe";
	string name2 = "AppLE";
	Stock s;

	cout << s.generate_item_id(name, "lAnka", 1) << endl;
	cout << s.generate_item_id(name2, "lanKA", 1) << endl;
	*/
	/*
	Stock array[12];
	
	for (int i = 0; i < 5; i++)
	{
		array[i].input_data();
		array[i].write_data(array[i].get_item_category());
	}*/

	//vector < Stock > stock = Stock::find_item("cucumber", 1);
	//cout << fixed << setprecision(2);
	//stock[0].show_data();
	//cout << endl << endl;
	//display_stock_table(stock);
	
	//Stock::edit_item();
	//Stock::delete_item();
	//Beep(500, 1000);
	//Stock::promotion(2);
	//Stock::read_data(8);
	/*
	string test = "my name is Chathurinda 123";
	to_upper(test,1);
	cout << test;
	to_upper(test, 0);
	cout << test;*/


	//Stock::delete_item();

	/*string d=get_date();
	string t= get_time();
	transaction_bill(stock, "dfgddhfgdsrgf",d,t);*/

	//promotion 2 check
	// vector < Stock > stock = Stock::find_item("cucumber", 1); capital check!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


	//Staff s1;
	//s1.add_user();
	//s1.staff_write_data();
	//s1.show_data();
	//

	//Staff s1;
	//s1.add_user();
	//s1.write_data();
	//s1.show_data();
	//Stock s2;
	//s2.input_data();

	//string password = get_password("Enter password : ");
	//cout << password;
	//display_header();
	
	/*Staff s1,s2 ;
	vector < Staff > staff = { s1 ,s2};
	display_staff_table(staff);*/

	//Stock s1;
	//
	//s1.get_data();
	//s1.supply_write_data();
	//s1.show_data();
	//s1.edit_item();
	//s1.show_data();

	/*Stock s;
	

	//display_login_screen();

//Staff::display_staff_table(Staff::read_staff_data());



	/*Stock s1;
	s1.edit_item();*/

	/*Supply s2;
	s2.update_stock();*/

	//Staff s3;
	
//Stock::transaction("kk"); 
//Stock::read_transaction();



	return 0;
}