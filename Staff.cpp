#include "Staff.h"
#include "Error_check.h"


ostream& operator<<(ostream& out, const Staff& obj)
{
	out << obj.username << "\n" << obj.password << "\n" << obj.full_name << "\n" << obj.position.first << "\n" << obj.position.second << "\n" << obj.join_date.day << "\n" 
	<< obj.join_date.month << "\n" << obj.join_date.year << "\n" << endl;
	return out;
}

istream& operator >> (istream& in, Staff& obj)
{
	in >> obj.username;
	in >> obj.password;
	in >> obj.full_name;
	in >> obj.position.first;
	in >> obj.position.second;
	in >> obj.join_date.day;
	in >> obj.join_date.month;
	in >> obj.join_date.year;
	
	return in;
}

void Staff::staff_write_data() {
	ofstream write_file;
	write_file.open("Staff\\staff_data.txt", ios::app);
	to_upper(this->username,1);
	to_upper(this->password, 1);
	to_upper(this->full_name, 1);
	to_upper(this->position.second, 1);
	
	write_file << *this;
}

vector<Staff>  Staff::read_staff_data()
{
	vector<Staff> members;
	ifstream readfile;
	readfile.open("Staff\\staff_data.txt");
	Staff member;
	while (readfile >> member)
		members.emplace_back(member);

	return members;
}

void Staff::add_user()
{
	void display_staff_positions();	//check(user interface functions are not working)
	
	cout << "\nAdd New User\n---------------------------------------\n";
	
	full_name = check_name("Enter full name");
	

	while (true) {
		username = check_name("Enter user name");

		vector<Staff> users = read_staff_data();
		bool flag = false;
		for (Staff  i : users) {
			if (i.username == username) {
				flag = true;
				cerr << "username already exists";
				break;
			}
		}

		if (flag == 0) {
			break;
		}
	}
	
	
	position.first = check_position();
	const string positions[4] = { "owner","manager","cashier","floor" };
	position.second = positions[position.first];

	join_date = check_date("Enter join date");

}

void Staff::show_data()
{
	cout << "\nUser Details\n---------------------------------------\n";
	cout << "Username\t: " << username << endl;
	cout << "Full Name\t: " << full_name  << endl;
	cout << "Position\t: " << position.second <<  endl;
	//need to add support
	//cout << "Joined Date\t: " << join_date << endl;
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

Date Staff::get_join_date()
{
	return join_date;
}
