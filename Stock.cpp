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

void Stock::getdata()
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


void Stock::write_data()
{
	ofstream write_file;

	write_file.open("data.txt", ios::app | ios::binary);
	write_file.write((char*)this, sizeof(*this));

}

/*
void Stock::read_data()
{
	ifstream read_file;

	read_file.open("item_data.txt", ios::binary);
	read_file.read((char*)this, sizeof(*this));

}
*/

