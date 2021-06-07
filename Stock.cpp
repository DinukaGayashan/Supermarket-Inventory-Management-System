#include "Stock.h"
#include "Error_check.h"

Stock::Stock(string itm_nme, string msr_unt , string brnd_nme , string spply_type , int nmbr_itms , double rprc , int dscnt )
:item_name(itm_nme), measure_unit(msr_unt), brand_name(brnd_nme), supply_type(spply_type), number_of_items(nmbr_itms), retail_price(rprc), discount(dscnt)
{
	cout << "Select Category\n";
	cout << "===============\n";

	//need to add the menu 
	// produce is number 1
	// meat is number 2
	cout << "1.----\n";

	int category = int_check("Enter the category");

	cout << "Enter item name\t:";
	getline(cin, itm_nme);

	if (category > 2) {
		cout << "Enter brand name\t:";
		getline(cin, brnd_nme);

		spply_type = (supply_type_check() == 1 ? "local" : "imported");
	}

	nmbr_itms = int_check("Enter number of items");
	rprc = rupees_check("Enter the retail price");

	item_name = itm_nme;
	brand_name = brnd_nme;
	supply_type = spply_type;
	number_of_items = nmbr_itms;
	retail_price = rprc;

}


void Stock::show_data()
{
	cout << "\n";
	cout << "Item name\t\t\t: " << item_name << endl;
	cout << "Retail price\t\t\t: " << retail_price  << "/=" << endl;
	cout << "Number of items availabe\t: " << number_of_items << endl;
	cout << "Brand name\t\t\t: " << brand_name << endl;
	cout << "Supply type\t\t\t: " << supply_type << endl;

}

