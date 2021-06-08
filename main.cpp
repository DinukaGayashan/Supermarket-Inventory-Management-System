#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Stock.h"
#include "Error_check.h"

using namespace std;

int main() 
{
	Stock stock;
	//stock.input_data();
	//stock.write_data(stock.get_item_category());

	//Stock::edit_item();
	stock.read_data(1, 0);
	stock.show_data();

}