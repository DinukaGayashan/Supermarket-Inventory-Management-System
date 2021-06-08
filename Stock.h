#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <iostream>
#include <fstream>

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
	Stock(string itm_nme = "", string msr_unt = "", string brnd_nme = "", string spply_type = "", int nmbr_itms = 0, double rprc = 0, int dscnt = 0, int itm_ctgry = 0) {};
		
	void show_data();
	void getdata();
	void write_data();
	//void read_data();


};

#endif


