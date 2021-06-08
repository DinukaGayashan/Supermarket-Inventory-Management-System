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


void Stock::write_data(int file_index)
{
	const vector<string> file_names{ "Stock_data\\produce.txt","meat_seafood.txt","grains.txt","bakery_products.txt","frozen_foods.txt", "dairy_products.txt","snacks_sweet.txt","beverages.txt","health_beauty.txt","condiments_spices.txt" };
	ofstream write_file;

	write_file.open(file_names[--file_index], ios::app | ios::binary);
	write_file.write((char*)this, sizeof(*this));

}


void Stock::read_data(int file_index,int n)
{

	const vector<string> file_names{ "Stock_data\\produce.txt","meat_seafood.txt","grains.txt","bakery_products.txt","frozen_foods.txt", "dairy_products.txt","snacks_sweet.txt","beverages.txt","health_beauty.txt","condiments_spices.txt" };
	string file_name = file_names[--file_index];

	ifstream read_file;
	read_file.open(file_name, ios::binary);

	read_file.seekg(n*sizeof(Stock));
	read_file.read((char*)this, sizeof(*this));

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
	vector<Stock> ctgry_dt;

	for (int i = 0; i < 1; i++) {
		temp.read_data(ctgry, i);
		ctgry_dt.emplace_back(temp);
	}

	string itm_nm;
	cout << "Enter item name :";
	getline(cin, itm_nm);

	size_t size = ctgry_dt.size();
	for (int i = 0; i < size; i++)
	{
		if (ctgry_dt[i].item_name == itm_nm) {
			ctgry_dt[i].input_data();

			const vector<string> file_names{ "Stock_data\\produce.txt","meat_seafood.txt","grains.txt","bakery_products.txt","frozen_foods.txt", "dairy_products.txt","snacks_sweet.txt","beverages.txt","health_beauty.txt","condiments_spices.txt" };
			string file_name = file_names[--ctgry];
			remove(file_name.c_str());

			ofstream write_file;
			write_file.open(file_name, ios::app | ios::binary);

			for (int j = 0; j < size; j++) {
				write_file.write((char*)&ctgry_dt[j], sizeof(ctgry_dt[j]));
			}

			return ;
		}
	}

	cerr << "No such item exists\n";


}

void Stock::delete_item()
{
}



