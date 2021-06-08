#include <iostream>
#include <vector>
#include <fstream>
#include "Stock.h"
#include "Error_check.h"

using namespace std;

int main() 
{
	vector<Stock> items;

	Stock temp;

	ifstream read_file;

	read_file.open("item_data.txt", ios::binary);
	read_file.read((char*)&temp, sizeof(temp));

	temp.show_data();

	//ofstream fout;
	//fout.open("data.txt", ios::app | ios::binary);
	//fout.write((char*)&temp, sizeof(temp));

	



	

	
}