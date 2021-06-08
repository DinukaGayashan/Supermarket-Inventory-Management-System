#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Stock
{
private:
	string item_name;
	string measure_unit;
	string brand_name;
	string supply_type;			
	int number_of_items;
	double retail_price;
	int item_category;
	int discount;
	double final_price = retail_price * (1 - (discount / 100.0));

public:
	Stock(string itm_nme = "", string msr_unt = "", string brnd_nme = "", string spply_type = "", int nmbr_itms = 0, double rprc = 0, int dscnt = 0, int itm_ctgry = 0): 
	item_name(itm_nme), measure_unit(msr_unt), brand_name(brnd_nme), supply_type(spply_type), number_of_items(nmbr_itms), retail_price(rprc), item_category(itm_ctgry), discount(dscnt){};
		
	void show_data();
	void input_data();
	void write_data(int file_index);
	void read_data(int file_index, int n);
	int get_item_category();
	static void edit_item();
	static void delete_item();


};

#endif


