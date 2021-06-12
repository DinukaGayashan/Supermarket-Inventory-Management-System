#include "Stock.h"


void Stock::show_data()
{
	cout << "\nItem Details\n-----------------------\n";
	cout << "Item id\t\t: " << item_id << endl;
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
	display_categories();
	display_supply_type();

	cout << "\nAdd New Item\n-----------------------\n";

	item_category = category_check();

	cout << "Enter item name\t\t: ";
	getline(cin, item_name);

	if (item_category > 2) {
		cout << "Enter brand name\t\t: ";
		getline(cin, brand_name);

		supply_type = (supply_type_check() == 1 ? "local" : "imported");
	}

	number_of_items = int_check("Enter number of items");
	retail_price = rupees_check("Enter the retail price");
	discount = int_check("Enter the discount percentage"); 
	final_price = retail_price * (1 - (discount / 100.0));

	item_id = generate_item_id(item_name, brand_name, item_category);

	cout << "Item id\t\t\t\t: " << item_id;

	//cout << "Press Enter to save\n";
	//get keystroke

}


ostream& operator<<(ostream& out, const Stock& obj)
{
	out <<obj.item_id << "\n"<< obj.item_name << "\n" << obj.measure_unit << "\n" << obj.brand_name << "\n" << obj.supply_type << "\n" << obj.number_of_items << "\n" << obj.retail_price << "\n"
		<<obj.final_price << "\n" << obj.item_category << "\n" << obj.discount << endl;
	return out;
}

istream& operator >> (istream& in, Stock& obj)
{
	in >> obj.item_id;
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
	while (read_file >> obj)
	{
		items.emplace_back(obj);
	}
	return items;
}

string Stock::get_item_id()
{
	return item_id;
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

void Stock::promotion(int promotion_type)
{
	vector<Stock> items;
	vector<Stock> dis;
	//for an item item name or code ???
	if (promotion_type == 1) {
		Stock temp;
		find_and_display(temp, items,false);
		int t = discount_check();
		for (int i = 0; i < (int)items.size(); i++) {
			items[i].discount = t;
			items[i].final_price = items[i].retail_price * (1 - (items[i].discount) / 100.0f);
			
			write_all_data(items[i]);
			dis.emplace_back(items[i]);
		}

		display_stock_table(dis);
	}

	//for a brand
	if (promotion_type == 2) {
		string brandName;
		cout << "enter brand name :";
		getline(cin, brandName);
		items = find_item(brandName, false);
		display_stock_table(items);

		int t = discount_check();

		for (int i = 0; i < (int)items.size(); i++) {
			items[i].discount = t;
			items[i].final_price = items[i].retail_price*(1 - (items[i].discount)/ 100.0f);
			write_all_data(items[i]);
			dis.emplace_back(items[i]);
		}
		display_stock_table(dis);
	}

	if (promotion_type == 3) {
		int ctgry = category_check();
		items = read_data(ctgry);
		display_stock_table(items);

		int t = discount_check();

		for (int i = 0; i < (int)items.size(); i++) {
			items[i].discount = t;
			items[i].final_price = items[i].retail_price * (1 - (items[i].discount) / 100.0f);
			write_all_data(items[i]);
			dis.emplace_back(items[i]);
		}
		display_stock_table(dis);

	}

}

void Stock::find_and_display(Stock& item, vector<Stock>& items, bool id)
{
	while (true) {
		string itm_nm;
		cout << "Enter item name\t\t:";
		getline(cin, itm_nm);

		items = find_item(itm_nm);

		if (items.size() == 0)
			cerr << "No such item exists\n";
		else
			break;
	}

	display_stock_table(items);

	while (id) {
		bool error = false;
		string id;
		cout << "Enter ID : ";
		getline(cin, id);
		item = find_by_id(id, items, error);

		if (error == false)
			break;

		cerr << "invalid id\n";
	}
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


vector<Stock> Stock::find_item(const string& item,bool name)
{
	vector<Stock> items;

	for (int i = 1; i < 11; i++) {
		vector<Stock> temp = read_data(i);
		for (auto j : temp)
			if((name==1 ? j.item_name: j.brand_name) == item)
				items.emplace_back(j);
		
	}
	return items;
}

Stock Stock::find_by_id(const string& id, const vector<Stock>& items, bool& error ) {
	
	Stock t;
	for (auto i : items) {
		if (i.item_id == id)
			return i;
	}
	
	error = true;
	return t;
}



void Stock::edit_item()
{
	Stock temp;
	vector<Stock> itm;
	
	find_and_display(temp, itm);

	int ctgry = temp.item_category;
	
	if (temp.item_category > 2) {

		temp.supply_type = (supply_type_check() == 1 ? "local" : "imported");
	}

	temp.number_of_items = int_check("Enter number of items\t");
	temp.retail_price = rupees_check("Enter the retail price\t");
	temp.discount = int_check("Enter the discount percentage");
	temp.final_price = temp.retail_price * (1 - (temp.discount / 100.0));

	write_all_data(temp);
}

void Stock::delete_item()
{
	Stock temp;
	vector<Stock> itm;
	find_and_display(temp, itm);
	
	int ctgry = temp.item_category;
	int index(0);
	for (int i = 0; i<int(itm.size()); i++)
		if (itm[i].item_id == temp.item_id)
			index = i;

	itm.erase(itm.begin() + index);

	const vector<string> file_names{ "Stock_data\\produce.txt","Stock_data\\meat_seafood.txt","Stock_data\\grains.txt","Stock_data\\bakery_products.txt","Stock_data\\frozen_foods.txt", "Stock_data\\dairy_products.txt","Stock_data\\snacks_sweet.txt","Stock_data\\beverages.txt","Stock_data\\health_beauty.txt","Stock_data\\condiments_spices.txt" };
	string file_name = file_names[--ctgry];
	remove(file_name.c_str());

	for (int j = 0; j <int(itm.size()); j++) {
		itm[j].write_data(ctgry + 1);
	}

}

void Stock::write_all_data(const Stock& temp)
{
	int ctgry = temp.item_category;
	vector<Stock> itms = read_data(ctgry);
	for (int k = 0; k < (int)itms.size(); k++)
		if (itms[k].item_id == temp.item_id)
			itms[k] = temp;

	const vector<string> file_names{ "Stock_data\\produce.txt","Stock_data\\meat_seafood.txt","Stock_data\\grains.txt","Stock_data\\bakery_products.txt","Stock_data\\frozen_foods.txt", "Stock_data\\dairy_products.txt","Stock_data\\snacks_sweet.txt","Stock_data\\beverages.txt","Stock_data\\health_beauty.txt","Stock_data\\condiments_spices.txt" };
	string file_name = file_names[--ctgry];
	remove(file_name.c_str());

	for (int j = 0; j < int(itms.size()); j++)
		itms[j].write_data(ctgry + 1);
}

string Stock::generate_item_id(const string& item_name_in, const string& brand_name_in,const int& category_in)
{
	string id = "";

	size_t number_length = 5;
	char b = brand_name_in[0];
	char i = item_name_in[0];

	
	id += (category_in+64);

	//if first letter is lower case making it up to upper case
	if (i >= 'a') {
		i = i - 32;
	}
	id += i;

	if (b >= 'a') {
		b = b - 32;
	}
	id += b;

	//generating the number
	int sum = 0;
	int index = 1;
	for (char i : brand_name_in) {
		sum += index++ *(int) ( i >='a' ? i-32:i);
	}

	index = 1;
	for (char i : item_name_in) {
		sum += index++ * (int)(i >= 'a' ? i - 32 : i);
	}

	string number = to_string(sum);
	string front = "";
	for (size_t i = 0; i < number_length - number.length(); i++) {
		front += '0';
	}

	front += number;
	id += front;
	return id;
}

