#include "Staff.h"
#include "Error_check.h"


ostream& operator<<(ostream& out, const Staff& obj)
{
	out << obj.username << "\n" << obj.password << "\n" << obj.full_name << "\n" << obj.position.first << "\n" << obj.position.second << "\n" << obj.join_date << endl;
	return out;
}

istream& operator >> (istream& in, Staff& obj)
{
	in >> obj.username;
	in >> obj.password;
	in >> obj.full_name;
	in >> obj.position.first;
	in >> obj.position.second;
	in >> obj.join_date;
	
	return in;
}


void Staff::add_user()
{
	void display_staff_positions();	//check(user interface functions are not working)
	
	cout << "\nAdd New User\n-----------------------\n";
	
	full_name = check_name("Enter full name");	//name check
	
	username = check_name("Enter user name");		//username check
	
	position.first = check_position();
	const string positions[4] = { "owner","manager","cashier","floor" };
	position.second = positions[position.first];

	cout << "Enter join date\t\t: ";
		//date function
}

void Staff::show_data()
{
	cout << "\nUser Details\n-----------------------\n";
	cout << "Username\t: " << username << endl;
	cout << "Full Name\t: " << full_name  << endl;
	cout << "Position\t: " << position.second <<  endl;
	cout << "Joined Date\t: " << join_date << endl;
}

string Staff::get_user_name()
{
	return username;
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
