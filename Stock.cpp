#include "Stock.h"
#include "Error_check.h"


void Stock::show_data()
{
	final_price = retail_price * (1 - (discount / 100.0));
	cout << "\nItem Details\n-----------------------\n";
	cout << "Item name\t\t: " << item_name << endl;
	cout << "Retail price\t\t: " << retail_price  << "/=" << endl;
	cout << "Final price\t\t: " << final_price << "/=" << endl;
	cout << "Available quantity\t: " << number_of_items << endl;
	if (brand_name != "nobrand") {
		cout << "Brand name\t\t: " << brand_name << endl;
		cout << "Supply type\t\t: " << supply_type << endl;
	}
}

void Stock::input_data()
{
	void display_categories();
	void display_supply_type();

	cout << "\nAdd New Item\n-----------------------\n";

	item_category = category_check();

	cout << "Enter item name\t\t: ";
	getline(cin, item_name);

	if (item_category > 2) {
		cout << "Enter brand name\t: ";
		getline(cin, brand_name);

		supply_type = (supply_type_check() == 1 ? "local" : "imported");
	}

	number_of_items = int_check("Enter number of items");
	retail_price = rupees_check("Enter the retail price");
	discount = int_check("Enter the discount percentage"); 
	final_price = retail_price * (1 - (discount / 100.0));

	//cout << "Press Enter to save\n";
	//get keystroke

}


ostream& operator<<(ostream& out, const Stock& obj)
{
	out << obj.item_name << "\n" << obj.measure_unit << "\n" << obj.brand_name << "\n" << obj.supply_type << "\n" << obj.number_of_items << "\n" << obj.retail_price << "\n"
		<<obj.final_price << "\n" << obj.item_category << "\n" << obj.discount << endl;
	return out;
}

istream& operator >> (istream& in, Stock& obj)
{
	in >> obj.item_name;
	in >> obj.measure_unit;
	in >> obj.brand_name;
	in >> obj.supply_type;
	in >> obj.number_of_items;
	in >> obj.retail_price;
	in >> obj.final_price;
	in >> obj.item_category;
	in >> obj.discount;
	return in;
}


void Stock::write_data(int file_index)
{
	const vector<string> file_names{ "Stock_data\\produce.txt","Stock_data\\meat_seafood.txt","Stock_data\\grains.txt","Stock_data\\bakery_products.txt","Stock_data\\frozen_foods.txt", "Stock_data\\dairy_products.txt","Stock_data\\snacks_sweet.txt","Stock_data\\beverages.txt","Stock_data\\health_beauty.txt","Stock_data\\condiments_spices.txt" };
	ofstream write_file;
	write_file.open(file_names[--file_index], ios::app);
	write_file << *this;

}

vector<Stock> Stock::read_data(int file_index)
{
	vector<Stock> items;
	const vector<string> file_names{ "Stock_data\\produce.txt","Stock_data\\meat_seafood.txt","Stock_data\\grains.txt","Stock_data\\bakery_products.txt","Stock_data\\frozen_foods.txt", "Stock_data\\dairy_products.txt","Stock_data\\snacks_sweet.txt","Stock_data\\beverages.txt","Stock_data\\health_beauty.txt","Stock_data\\condiments_spices.txt" };
	ifstream read_file;
	read_file.open(file_names[--file_index]);

	Stock obj;
	while (!read_file.eof())
	{
		read_file >> obj;
		items.emplace_back(obj);
		
	}
	items.pop_back();
	return items;
}


int Stock::get_item_category()
{
	return item_category;
}

string Stock::get_item_name()
{
	return item_name;
}

string Stock::get_item_brand_name()
{
	return brand_name;
}

string Stock::get_item_supply_type()
{
	return supply_type;
}

int Stock::get_number_of_items()
{
	return number_of_items;
}


double Stock::get_retail_price()
{
	return retail_price;
}

double Stock::get_final_price()
{
	return retail_price * (1 - (discount / 100.0));
}

int Stock::get_discount()
{
	return discount;
}

void Stock::edit_item()
{
	//print categories

	Stock temp;

	int ctgry = int_check("Enter category");
	vector<Stock> ctgry_dt = read_data(ctgry);

	string itm_nm;
	cout << "Enter item name :";
	getline(cin, itm_nm);

	size_t size = ctgry_dt.size();
	for (int i = 0; i < size; i++)
	{
		if (ctgry_dt[i].item_name == itm_nm) {
			if (ctgry_dt[i].item_category > 2) {

				cout << "Enter brand name\t: ";
				getline(cin, ctgry_dt[i].brand_name);

				ctgry_dt[i].supply_type = (supply_type_check() == 1 ? "local" : "imported");
			}

			ctgry_dt[i].number_of_items = int_check("Enter number of items");
			ctgry_dt[i].retail_price = rupees_check("Enter the retail price");
			ctgry_dt[i].discount = int_check("Enter the discount percentage");
			
			const vector<string> file_names{ "Stock_data\\produce.txt","Stock_data\\meat_seafood.txt","Stock_data\\grains.txt","Stock_data\\bakery_products.txt","Stock_data\\frozen_foods.txt", "Stock_data\\dairy_products.txt","Stock_data\\snacks_sweet.txt","Stock_data\\beverages.txt","Stock_data\\health_beauty.txt","Stock_data\\condiments_spices.txt" };
			string file_name = file_names[--ctgry];
			remove(file_name.c_str());

			for (int j = 0; j < size; j++) {
				ctgry_dt[j].write_data(ctgry+1);
			}

			return ;
		}
	}

	cerr << "No such item exists\n";

}

void Stock::delete_item()
{
	Stock temp;

	int ctgry = int_check("Enter category");
	vector<Stock> ctgry_dt = read_data(ctgry);

	string itm_nm;
	cout << "Enter item name :";
	getline(cin, itm_nm);

	size_t size = ctgry_dt.size();
	for (int i = 0; i < size; i++)
	{
		if (ctgry_dt[i].item_name == itm_nm) {
			
			ctgry_dt.erase(ctgry_dt.begin() + i);

			const vector<string> file_names{ "Stock_data\\produce.txt","Stock_data\\meat_seafood.txt","Stock_data\\grains.txt","Stock_data\\bakery_products.txt","Stock_data\\frozen_foods.txt", "Stock_data\\dairy_products.txt","Stock_data\\snacks_sweet.txt","Stock_data\\beverages.txt","Stock_data\\health_beauty.txt","Stock_data\\condiments_spices.txt" };
			string file_name = file_names[--ctgry];
			remove(file_name.c_str());

			for (int j = 0; j < size-1; j++) {
				ctgry_dt[j].write_data(ctgry + 1);
			}

			return;
		}
	}

	cerr << "No such item exists\n";

}



