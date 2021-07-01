#include "Stock.h"
#include <cmath>

void Stock::show_data()
{
	cout << "\nItem Details\n---------------------------------------\n";
	cout << "Item id\t\t\t: " << item_id << endl;
	to_upper(item_name, 0);
	cout << "Item name\t\t: " << item_name << endl;
	cout << "Retail price\t\t: " << retail_price  << "/=" << endl;
	cout << "Final price\t\t: " << final_price << "/=" << endl;
	cout << "Available quantity\t: " << quantity << endl;
	if (brand_name != "nobrand") {
		to_upper(brand_name, 0);
		cout << "Brand name\t\t: " << brand_name << endl;
		cout << "Supply type\t\t: " << supply_type << endl;
	}
}

void Stock::input_data()
{
	display_categories();
	display_supply_type();

	cout << "\nAdd New Item\n---------------------------------------\n";

	item_category = category_check();

	cout << "Enter item name\t\t: ";
	getline(cin, item_name);
	to_upper(item_name, 1);

	if (item_category > 2) {
		cout << "Enter brand name\t: ";
		getline(cin, brand_name);
		to_upper(brand_name, 1);

		supply_type = (supply_type_check() == 1 ? "Local" : "Imported");
	}

	quantity = int_check("Enter number of items\t");
	retail_price = rupees_check("Enter the retail price\t");
	discount = int_check("Enter discount percentage"); 
	final_price = retail_price * (1 - (discount / 100.0));

	item_id = generate_item_id(item_name, brand_name, item_category);

	cout << "Item ID\t\t\t: " << item_id<<endl;

	//cout << "Press Enter to save\n";
	//get keystroke

}


ostream& operator<<(ostream& out, const Stock& obj)
{
	out <<obj.item_id << "\n"<< obj.item_name << "\n" << obj.measure_unit << "\n" << obj.brand_name << "\n" << obj.supply_type << "\n" << obj.quantity << "\n" << obj.retail_price << "\n"
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
	in >> obj.quantity;
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
	to_upper(this->brand_name, 1);
	to_upper(this->item_name, 1);
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


void Stock::transaction(const string& cashier_name)
{
	vector<Stock> items;

	for (int i = 1; i < 11; i++) {
		vector<Stock> temp = read_data(i);
		for (auto j : temp)
			items.emplace_back(j);
	}
		

	vector<Stock> bill_items;
	while (true) {
		string id;
		Stock temp;
		bool err = false;
		while (true) {
			cout << "Enter Item ID : ";
			getline(cin, id);
			to_upper(id, 1);
			temp = find_by_id(id, items, err);
			if (err == true)
			{
				display_error("SD01");
				continue;
			}
			break;
		}
		int quantity = 0;
		while (true) {
			quantity = int_check("Enter quantity");
			if (quantity > temp.quantity) {
				display_error("SD04");
				continue;
			}
			break;
		}

		temp.final_price = temp.final_price * quantity;
		temp.quantity = quantity;

		cout << "press 'V' to confirm\n";
		cout << "press 'E' to cancel\n";
		cout << "press 'F' to finish\n";


		if (GetAsyncKeyState('V')) {
			bill_items.push_back(temp);
		}

		if (GetAsyncKeyState('E')) {
			continue;
		}
		if (GetAsyncKeyState('F')) {
			break;
		}
	}

	if (bill_items.size() == 0)
		return;

	for (int i = 0; i < bill_items.size(); i++) {
		for (int j = 0; j < items.size(); j++) {
			if (bill_items[i].item_id == items[j].item_id) {
				items[j].quantity -= bill_items[i].quantity;
			}
		}
	}

	cout << "Updating...\n";
	for (int j = 0; j < items.size(); j++)
		write_all_data(items[j]);

	cout << "Done....\n";

	//bill ui

	//print bill


	//logging
	string file_name = "transactions\\"+cashier_name + get_date() + ".txt"; //get time also need to be added
	ofstream write_file,transaction;
	write_file.open("transactions\\names.txt",ios::app);
	write_file << file_name;	//must test to find whether endl is needed
	transaction.open(file_name, ios::app);
	transaction << get_date() << endl;
	//transaction << get_time() << endl;
	transaction << cashier_name << endl;

	for (Stock i : bill_items) {
		transaction << i;
	}


}

void Stock::read_transaction() {
	ifstream read_file;
	read_file.open("transactions\\names.txt");

	vector<string> file_names;

	string fname;
	while (read_file >> fname)
		file_names.emplace_back(fname);

	for (string i : file_names) {
		ifstream input;
		input.open(i);
		string dt,tm,cname;
		vector<Stock> items;
		Stock t;
		input >> dt;
		input >> tm;
		input >> cname;

		while (input >> t)
			items.emplace_back(t);


		//print bill

	
		

	}
}

void Stock::set_quantity(int amount)
{
	quantity = quantity + amount;
}

void Stock::set_supply_type(int t)
{
	supply_type = (t == 1 ? "Local" : "Imported");
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

		while (true) {
			cout << "Enter brand name\t: ";
			getline(cin, brandName);
			to_upper(brandName, 1);
			items = find_item(brandName, false);
			if (items.size() == 0) {
				display_error("SD03");
				continue;
			}
			break;
		}
		
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
		cout << "Enter item name\t\t: ";
		getline(cin, itm_nm);
		to_upper(itm_nm, 1);

		items = find_item(itm_nm);

		if (items.size() == 0)
			display_error("SD02");
		else
			break;
	}

	display_stock_table(items);

	while (id) {
		bool error = false;
		string id;
		cout << "Enter item ID : ";
		getline(cin, id);
		item = find_by_id(id, items, error);

		if (error == false)
			break;

		display_error("SD01");
	}
}

string Stock::get_item_id()
{
	return item_id;
}

int Stock::get_item_category()
{
	return item_category;
}

string& Stock::get_item_name()
{
	return item_name;
}

string& Stock::get_item_brand_name()
{
	return brand_name;
}

string Stock::get_item_supply_type()
{
	return supply_type;
}

int Stock::get_quantity()
{
	return quantity;
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
	//to_upper(item, 1);
	
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

		temp.supply_type = (supply_type_check() == 1 ? "Local" : "Imported");
	}

	temp.quantity = int_check("Enter number of items\t");
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
	itm = read_data(ctgry);
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

	if (itm.size() == 0) {
		ofstream write_file;
		write_file.open(file_name);
		write_file.close();
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

