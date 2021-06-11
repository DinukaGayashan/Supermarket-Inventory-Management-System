#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "User_interface.h"
#include "Error_check.h"

using namespace std;



class Stock
{
private:
	string item_id;
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
	Stock(string itm_id="default", string itm_nme = "", string msr_unt = "nounit", string brnd_nme = "nobrand", string spply_type = "notype", int nmbr_itms = 0, double rprc = 0, int dscnt = 0, int itm_ctgry = 0) :
	item_id(itm_id),item_name(itm_nme), measure_unit(msr_unt), brand_name(brnd_nme), supply_type(spply_type), number_of_items(nmbr_itms), retail_price(rprc), item_category(itm_ctgry), discount(dscnt),final_price(rprc){};
		

	friend ostream& operator << (ostream& out, const Stock& obj);
	friend istream& operator >> (istream& in, Stock& obj);


	void show_data();
	void input_data();
	void write_data(int file_index);
	static vector<Stock> read_data(int file_index);
	static vector<Stock> find_item(const string& item, bool name = 1);
	static void edit_item();
	static void delete_item();
	static void promotion(int promotion_percentage,int promotion_type);
	static Stock find_by_id(const string& id, const vector<Stock>& items, bool& error);
	string generate_item_id(const string& item_name_in, const string& brand_name_in, const int& category_in);

	//access data
	string get_item_id();
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


