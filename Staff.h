#ifndef  STAFF_H
#define	 STAFF_H

#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include "User_interface.h"


using namespace std;
struct Date
{
	int day=0, month=0, year=0;	
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
	Staff() {};
	Staff(Date jn_dt,string usr_nm = "default", string psswrd = "0000", string fll_nm = "default", pair<int, string > pstn = make_pair(0, "default"))
		:username(usr_nm), password(psswrd), full_name(fll_nm), position(pstn), join_date(jn_dt) {};
	

	friend ostream& operator << (ostream& out, const Staff& obj);
	friend istream& operator >> (istream& in, Staff& obj);

	//delete

	void add_user();
	void show_data();


	string get_user_name();
	string get_password();
	string get_full_name();
	pair<int,string> get_position();
	Date get_join_date();

};




#endif 
