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
	//set_font_size(24,24);

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

		cout << "\nSelect option number\n\n";
		cout << "1. Stock\n";
		cout << "2. Supply\n";
		cout << "3. Staff\n";
		cout << "4. Help\n";
		cout << "5. Credits\n";
		cout << "6. Log out\n";
		cout << "7. Exit\n";

		char a = _getch();

		if (a == '1')
		{
			do
			{
				display_header(username, user_position);

				cout << "\nSelect option\n\n";
				cout << "1. Display item details\n";
				cout << "2. Display all stock items\n";
				cout << "3. Staff\n";
				cout << "4. Instructions\n";
				cout << "5. Credits\n";
				cout << "6. Go back to main menu\n";

				char b = _getch();

				if (b == '1')
				{
					
				}
				else if (b == '2')
				{
					
				}
				else if (b == '3')
				{
					if (user_position < 2)
						display_staff_menu(username, user_position);
					else
						display_error("AM01");
				}
				else if (b == '4')
				{
					display_instructions(username, user_position);
				}
				else if (b == '5')
				{
					display_credits(username, user_position);
				}
				else if (b == '6')
				{
					break;
				}
			} while (1);
		}
		else if (a == '2')
		{
			display_supply_menu(username, user_position);
		}
		else if (a == '3')
		{
			if (user_position < 2)
				display_staff_menu(username, user_position);
			else
			{
				display_error("AM01");
				system("pause");
			}
		}
		else if (a == '4')
		{
			display_instructions(username, user_position);
		}
		else if (a == '5')
		{
			display_credits(username, user_position);
		}
		else if (a == '6')
		{
			logout = 1;
		}
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