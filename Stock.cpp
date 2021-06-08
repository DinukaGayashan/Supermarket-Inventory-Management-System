#include "Stock.h"
#include "Error_check.h"


void Stock::show_data()
{
	cout << "\nItem Details\n-----------------------\n";
	cout << "Item name\t\t\t: " << item_name << endl;
	cout << "Retail price\t\t\t: " << retail_price  << "/=" << endl;
	cout << "Number of items availabe\t: " << number_of_items << endl;
	if (brand_name.length()>0) {
		cout << "Brand name\t\t\t: " << brand_name << endl;
		cout << "Supply type\t\t\t: " << supply_type << endl;
	}

}

void Stock::input_data()
{
	cout << "Categories\n";
	cout << "-----------------------\n";
	cout << "1. Produce\n";
	cout << "2. Meat & Seafood\n";
	cout << "3. Grains\n";
	cout << "4. Bakery products\n";
	cout << "5. Frozen foods\n";
	cout << "6. Dairy products\n";
	cout << "7. Snacks & Sweets\n";
	cout << "8. Beverages\n";
	cout << "9. Health & Beauty\n";
	cout << "10. Condiments & Spices\n\n";

	cout << "Supply Type\n";
	cout << "-----------------------\n";
	cout << "1. Local\n";
	cout << "2. Imported\n\n\n";

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

	//cout << "Press Enter to save\n";
	//get keystroke

}


ostream& operator<<(ostream& out, const Stock& obj)
{
	out << obj.item_name << "\n" << obj.measure_unit << "\n" << obj.brand_name << "\n" << obj.supply_type << "\n" << obj.number_of_items << "\n" << obj.retail_price << "\n"
		<< obj.item_category << "\n" << obj.discount << endl;
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
	return items;
}




int Stock::get_item_category()
{
	return item_category;
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
			ctgry_dt[i].input_data();
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
}



