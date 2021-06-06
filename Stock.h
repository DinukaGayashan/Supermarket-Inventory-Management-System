#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <iostream>
using namespace std;

class Stock
{
private:
	string itemName;
	string measureUnit;
	string brandName;
	string supplyType;			
	int numberOfItems;
	double retailPrice;
	int discount;
	double finalPrice = retailPrice * (1 - (discount / 100.0));

public:
	Stock(string itmNme = "", string msrUnt = "", string brndNme = "", string spplyType = "", int nmbrItms = 0, double rprc = 0, int dscnt = 0);
		
	void showData();

};

#endif


