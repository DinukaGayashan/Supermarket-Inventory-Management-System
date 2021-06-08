#include <iostream>
#include <vector>
#include <fstream>
#include "Stock.h"
#include "Error_check.h"

using namespace std;

int main() 
{
	ifstream read_file;
	read_file.open("data.txt", ios::binary);
	vector<Stock> items;

	Stock temp;
	//temp.getdata();
	//temp.write_data();
	

	read_file.seekg(0);
	read_file.read(reinterpret_cast<char*>(&temp), sizeof(temp));
	while (!read_file.eof()) {
		
		items.push_back(temp);
		read_file.read(reinterpret_cast<char*>(&temp), sizeof(temp));
		
	}
	

	for(int i=0;i<items.size();i++)
		items[i].show_data();
	

	

	



	

	
}