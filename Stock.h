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
	double final_price ;

public:
	Stock(string itm_nme = "", string msr_unt = "nounit", string brnd_nme = "nobrand", string spply_type = "notype", int nmbr_itms = 0, double rprc = 0, int dscnt = 0, int itm_ctgry = 0): 
	item_name(itm_nme), measure_unit(msr_unt), brand_name(brnd_nme), supply_type(spply_type), number_of_items(nmbr_itms), retail_price(rprc), item_category(itm_ctgry), discount(dscnt),final_price(rprc){};
		

	friend ostream& operator << (ostream& out, const Stock& obj);
	friend istream& operator >> (istream& in, Stock& obj);


	void show_data();
	void input_data();
	void write_data(int file_index);
	static vector<Stock> read_data(int file_index);
	static void edit_item();
	static void delete_item();

	//access data
	string get_item_name();
	string get_item_brand_name();
	string get_item_supply_type();
	int get_number_of_items();
	double get_retail_price();
	double get_final_price();
	int get_discount();
	int get_item_category();


};

#endif


