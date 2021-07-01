#include "Supply.h"

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

void Supply::get_data()
{
	display_source_type();
	display_vehicle_types();

	cout << "\nAdd New Supply Item\n---------------------------------------\n";

	cout << "Enter item name\t\t\t: ";
	getline(cin, item_name);
	to_upper(item_name, 1);

	quantity = int_check("Enter number of items\t");

	cout << "Enter item origin\t\t\t: ";
	getline(cin, name_of_origin);
	to_upper(name_of_origin, 1);

	cout << "Enter item source\t\t\t: ";
	source = (supply_type_check() == 1 ? "Local" : "International");

	date_of_depature = check_date("Enter depature date");

	date_of_arrival = check_date("Enter arival date");

	if (source == "Local")
	{
		int v_t = vehicle_category_check();
		if (v_t == 1)
			vehicle_type = "Large Truck";
		else if (v_t == 2)
			vehicle_type = "Small Truck";
		else
			vehicle_type = "Van";
	}
	else
		vehicle_type = "Ship";
	
	cout << "Enter vehicle register number\t\t: ";
	getline(cin, reg_number);
	to_upper(reg_number, 1);

	//cout << "Press Enter to save\n";
	//get keystroke

}

void Supply::show_data()
{
	cout << "\nSupply Details\n---------------------------------------\n";
	to_upper(item_name, 0);
	cout << "Item name\t\t: " << item_name << endl;
	cout << "Quantity\t\t: " << quantity << endl;
	to_upper(name_of_origin, 0);
	cout << "Item origin\t\t: " << name_of_origin << endl;
	cout << "Item source\t\t: " << source << endl;
	cout << "Depature date\t\t: " << date_of_depature.year << "." << date_of_depature.month << "." << date_of_depature.day << endl;
	cout << "Arrival date\t\t: " << date_of_arrival.year << "." << date_of_arrival.month << "." << date_of_arrival.day << endl;
	cout << "Vehicle type\t\t: " << vehicle_type << endl;
	cout << "Vehicle register number\t: " << reg_number << endl;
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
