#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Stock.h"
#include "Error_check.h"
#include "User_interface.h"
#include "Staff.h"

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
	
	//set_console_position(0, 0);
	//set_console_size(1920, 1080);
	//set_font_size(24,24);

	////Stock s1, s2("defsdd","vghfjchgfv", "nfghjxfg", "chgjhhjd", "notape", 20, 43355, 20, 3);
	//vector < Stock > stock = { s1, s2 };

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
	//vector<Stock> r = Stock::read_data(1);
	//display_stock_table(r);

	string name = "apPLe";
	string name2 = "AppLE";
	Stock s;

	cout << s.generate_item_id(name, "lAnka", 1) << endl;
	cout << s.generate_item_id(name2, "lanKA", 1) << endl;
	
	return 0;
}