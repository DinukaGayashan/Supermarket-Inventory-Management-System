#include "Supply.h"
#include "Error_check.h"


ostream& operator<<(ostream& out, const Supply& obj)
{
	out << obj.source << "\n" << obj.vehicle_type << "\n" << obj.reg_number << "\n" << obj.item_name << "\n" << obj.quantity <<  "\n" << obj.name_of_origin << "\n" << obj.date_of_depature.day << "\n"
		<< obj.date_of_depature.month << "\n" << obj.date_of_depature.year << "\n" << obj.date_of_arrival.day << "\n"
		<< obj.date_of_arrival.month << "\n" << obj.date_of_arrival.year << "\n" << obj.status << endl;
	return out;
}

istream& operator >> (istream& in, Supply& obj)
{
	in >> obj.source;
	in >> obj.vehicle_type;
	in >> obj.reg_number;
	in >> obj.item_name;
	in >> obj.quantity;
	in >> obj.name_of_origin;
	in >> obj.date_of_depature.day;
	in >> obj.date_of_depature.month;
	in >> obj.date_of_depature.year;
	in >> obj.date_of_arrival.day;
	in >> obj.date_of_arrival.month;
	in >> obj.date_of_arrival.year;
	in >> obj.status;

	return in;
}


void Supply::supply_write_data() {
	ofstream write_file;
	write_file.open("Supply\\Supply_data.txt", ios::app);
	to_upper(this->source, 1);
	to_upper(this->vehicle_type, 1);
	to_upper(this->reg_number, 1);
	to_upper(this->item_name, 1);
	to_upper(this->name_of_origin, 1);

	write_file << *this;
}

vector<Supply>  Supply::supply_read_data()
{
	vector<Supply> items;
	ifstream readfile;
	readfile.open("Supply\\Supply_data.txt");
	Supply item;
	while (readfile >> item)
		items.emplace_back(item);

	return items;
}

void Supply::update()
{

	Stock temp;
	vector<Stock> itm;

	find_and_display(temp, itm);

	int ctgry = temp.get_item_category();

	if (ctgry > 2) {
		temp.set_supply_type(supply_type_check());
	}

	int q = int_check("Enter number of items\t");

	temp.set_quantity(q);
	

	write_all_data(temp);
}

bool Supply::check_item()
{
	vector<Stock> items = find_item(item_name, true);
	return bool(items.size());
}
