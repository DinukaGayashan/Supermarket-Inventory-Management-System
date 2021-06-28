#ifndef  STAFF_H
#define	 STAFF_H

#include <iostream>
#include <string>
#include <tuple>
#include <fstream>
#include <utility>
#include "User_interface.h"


using namespace std;
struct Date
{
	int day, month, year;
	Date(int d = 0,int m=0,int y=0):day(d), month(m), year(y){}
};

class Staff
{
private:
	
	string username;
	string password;
	string full_name;
	pair<int,string> position;
	Date join_date;

public:
	Staff():username("default"), password("0000"), full_name("default"), position(1,"none"), join_date(0,0,0) {}
	
	friend ostream& operator << (ostream& out, const Staff& obj);
	friend istream& operator >> (istream& in, Staff& obj);

	//delete

	void add_user();
	void show_data();
	void staff_write_data();
	static  vector<Staff> staff_read_data();


	string get_user_name();
	string get_password();
	string get_full_name();
	pair<int,string> get_position();
	Date get_join_date();

};




#endif 
