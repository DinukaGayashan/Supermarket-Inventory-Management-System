#include "Staff.h"


ostream& operator<<(ostream& out, const Staff& obj)
{
	out << obj.user_name << "\n" << obj.password << "\n" << obj.full_name << "\n" << obj.position.first << "\n" << obj.position.second << "\n" << obj.join_date << endl;
	return out;
}

istream& operator >> (istream& in, Staff& obj)
{
	in >> obj.user_name;
	in >> obj.password;
	in >> obj.full_name;
	in >> obj.position.first;
	in >> obj.position.second;
	in >> obj.join_date;
	
	return in;
}


void Staff::get_data()
{
}

void Staff::show_data()
{
}

string Staff::get_user_name()
{
	return user_name;
}

string Staff::get_password()
{
	return password;
}

string Staff::get_full_name()
{
	return full_name;
}

pair<int, string> Staff::get_position()
{
	return position;
}

string Staff::get_join_date()
{
	return join_date;
}
