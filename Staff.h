#ifndef  STAFF_H
#define	 STAFF_H

#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Staff
{
private:
	string user_name;
	string password;
	string full_name;
	pair<int,string> position;
	string join_date;

public:
	Staff(string usr_nm = "default", string psswrd = "0000", string fll_nm = "default", pair<int, string > pstn = make_pair(0, "default"), string jn_dt = "0")
		:user_name(usr_nm), password(psswrd), full_name(fll_nm), position(pstn), join_date(jn_dt) {};
	

	friend ostream& operator << (ostream& out, const Staff& obj);
	friend istream& operator >> (istream& in, Staff& obj);

	void get_data();
	void show_data();


	string get_user_name();
	string get_password();
	string get_full_name();
	pair<int,string> get_position();
	string get_join_date();

};


#endif 
