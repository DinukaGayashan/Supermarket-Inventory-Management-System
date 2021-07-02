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
	//Stock stock;
	//stock.input_data(); 
	//stock.write_data(stock.get_item_category());
	
	//Stock::delete_item();
	/*
	vector<Stock> test = Stock::read_data(1);
	
	for (int i = 0; i < test.size(); i++) {
		test[i].show_data(); cout << endl;
	}
	*/
	
	set_console_position(0, 0);
	set_console_size(1920, 1080);
	//set_font_size(24,24);

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

	/*Supply s1;
	
	s1.get_data();
	s1.supply_write_data();
	s1.show_data();
	s1.update();
	s1.show_data();*/

	/*Stock s;
	s.transaction("kk");*/

	//display_login_screen();

Staff::display_staff_table(Staff::read_staff_data());


	return 0;
}