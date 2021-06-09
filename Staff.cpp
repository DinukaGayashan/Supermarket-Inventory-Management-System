#include "Staff.h"


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
	
	cout << "Enter full name\t\t: ";
	getline(cin, full_name);	//name check
	
	cout << "Enter username\t\t: ";
	getline(cin, username);		//username check
	
	cout << "Enter position number\t: ";
	cin>> position.first;		//4.owner 1-manager,2-cashier,3-floor

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
