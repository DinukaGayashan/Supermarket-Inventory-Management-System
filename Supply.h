#ifndef SUPPLY_H
#define SUPPLY_H

#include "Stock.h"
#include "Date.h"

class Stock;
class Supply : public Stock
{
private:
	string supply_item_name;
	int supply_quantity;
	string source; //local or international
	string origin_name; //farm or factory
	Date date_of_depature;
	Date date_of_arrival;
	string vehicle_type; //small van, medium, large or ship
	string reg_number;
	bool status; //false until accepted

public:
	
	void get_data();
	void show_data();

	friend ostream& operator << (ostream& out, const Supply& obj);
	friend istream& operator >> (istream& in, Supply& obj);

	void supply_write_data();
	static vector<Supply>  supply_read_data();

	void update_stock();

	bool check_stock_item(string& supply_item_name) const;

	string get_supply_item_name();
	//int get_supply_quantity();
	//string get_source();
	//string get_origin_name();
	//Date get_date_of_depature();
	//Date get_date_of_arrival();
	//string get_vehicle_type();
	//string get_reg_number();
	//bool get_status();

	static void display_supply_table(vector <Supply> supply);

};

#endif // !SUPPLY_H