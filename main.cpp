#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Stock.h"
#include "Error_check.h"

using namespace std;

int main() 
{
	//Stock stock;
	//stock.input_data(); stock.write_data(stock.get_item_category());
	
	Stock::delete_item();
	
	vector<Stock> test = Stock::read_data(1);
	
	for (int i = 0; i < test.size(); i++) {
		test[i].show_data(); cout << endl;
	}



	
}