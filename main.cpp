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
	//temp.getdata();
	//temp.write_data();
	

	ifstream read_file;

	read_file.open("data.txt", ios::binary);
	read_file.read((char*)&temp, sizeof(temp));

	temp.show_data();

	

	



	

	
}