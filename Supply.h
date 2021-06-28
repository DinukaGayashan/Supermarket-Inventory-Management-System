#ifndef SUPPLY_H
#define SUPPLY_H

#include "Stock.h"
#include "Staff.h"
#include <string>
#include <fstream>
#include <vector>


using namespace std;

class Supply : public Stock
{
	string source; //local or international
	string vehicle_type;
	string reg_number;
	string item_name;
	int quantity;
	string name_of_origin;
	Date date_of_depature;
	Date date_of_arrival;
	bool status; //false until accepted

public:
	
	void get_data();
	void show_data();

	friend ostream& operator << (ostream& out, const Supply& obj);
	friend istream& operator >> (istream& in, Supply& obj);

	void supply_write_data();
	static vector<Supply>  supply_read_data();

	void update();

	bool check_item();

};

#endif // !SUPPLY_H