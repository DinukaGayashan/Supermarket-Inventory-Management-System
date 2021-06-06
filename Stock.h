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
	int numberOfItems;
	double retailPrice;
	int discount;
	double finalPrice = retailPrice * (1 - (discount / 100.0));

public:
	void showData();

};

#endif


