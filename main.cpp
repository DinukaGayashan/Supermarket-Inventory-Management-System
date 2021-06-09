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
	//stock.input_data(); stock.write_data(stock.get_item_category());
	
	//Stock::delete_item();
	/*
	vector<Stock> test = Stock::read_data(1);
	
	for (int i = 0; i < test.size(); i++) {
		test[i].show_data(); cout << endl;
	}
	*/

	console_position(0, 0);
	console_size(1920, 1080);

	Stock s1, s2("vghfjchgfv", "nfghjxfg", "chgjhhjd", "notape", 20, 43355, 20, 3);
	vector < Stock > stock = { s1, s2 };

	display_stock_table(stock);


	return 0;
}