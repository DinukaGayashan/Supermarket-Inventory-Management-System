#include "Staff.h"

ostream& operator<<(ostream& out, const Staff& obj)
{
	out << obj.username << "\n" << obj.password << "\n" << obj.full_name << "\n" << obj.position.first << "\n" << obj.position.second << "\n" << obj.join_date.day << "\n" 
	<< obj.join_date.month << "\n" << obj.join_date.year << endl;
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

vector<Staff> Staff::read_staff_data()
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
	display_staff_positions();
	
	cout << "\nAdd New User\n---------------------------------------\n";
	
	full_name = check_name("Enter full name\t");
	
	while (true) {
		username = check_name("Enter username\t");
		to_upper(username, 1);
		vector<Staff> users = read_staff_data();
		bool flag = false;
		for (Staff  i : users) {
			if (i.username == username) {
				flag = true;
				display_error("SD05");
				break;
			}
		}

		if (flag == 0) {
			break;
		}
	}
	position.first = check_position();
	const string positions[4] = { "owner","manager","cashier","floor worker" };
	position.second = positions[position.first];

	join_date = check_date("Enter join date");

	string password1, password2;
	do
	{
		password1 = enter_password("Enter password\t: ");
		password2 = enter_password("\nConfirm password: ");
		cout << endl;
		if (password1 != password2)
			display_error("IS02");
	} while (password1 != password2);
	password = password1;
}

void Staff::show_data()
{
	cout << "\nUser Details\n---------------------------------------\n";
	cout << "Username\t: " << username << endl;
	to_upper(full_name, 0);
	cout << "Full Name\t: " << full_name  << endl;
	to_upper(position.second, 0);
	cout << "Position\t: " << position.second <<  endl;
	//need to add support
	//cout << "Joined Date\t: " << join_date << endl;
}

//string Staff::get_username()
//{
//	return username;
//}
//
//string Staff::get_password()
//{
//	return password;
//}
//
//string Staff::get_full_name()
//{
//	return full_name;
//}
//
//pair<int, string> Staff::get_position()
//{
//	return position;
//}
//
//Date Staff::get_join_date()
//{
//	return join_date;
//}

void Staff:: display_staff_table(vector <Staff> staff)
{
	size_t max_username = 8, max_full_name = 9;
	size_t size = staff.size();
	int length = 59;

	for (int i = 0; i < size; i++)
	{
		if (staff[i].username.length() > max_username)
			max_username = staff[i].username.length();
	}

	for (int i = 0; i < size; i++)
	{
		if (staff[i].full_name.length() > max_full_name)
			max_full_name = staff[i].full_name.length();
	}

	cout << "\n";
	for (int i = 0; i < (max_username + max_full_name + length - 18) / 2; i++)
		cout << " ";
	cout << "Staff Table\n";

	for (int i = 0; i < max_username + max_full_name + length; i++)
		cout << "-";

	cout << "\n|";
	for (int i = 0; i < (max_username) / 2; i++)
		cout << " ";
	cout << "Username";
	for (int i = 0; i < (max_username) / 2; i++)
		cout << " ";
	cout << "|";

	for (int i = 0; i < (max_full_name) / 2; i++)
		cout << " ";
	cout << " Full Name ";
	for (int i = 0; i < (max_full_name) / 2; i++)
		cout << " ";
	cout << "|";

	cout << "      " << "Position" << "      |";

	cout << "   " << "Joined date" << "   |";

	cout << "\n";
	for (int i = 0; i < max_username + max_full_name + length; i++)
		cout << "-";

	for (int i = 0; i < size; i++)
	{
		cout << endl;
		cout << "     ";

		to_upper(staff[i].username, 0);
		cout << staff[i].username;
		for (int j = 0; j < (max_username - staff[i].username.length()); j++)
			cout << " ";
		cout << "          ";

		to_upper(staff[i].full_name, 0);
		cout << staff[i].full_name;
		for (int j = 0; j < (max_full_name - staff[i].full_name.length()); j++)
			cout << " ";
		cout << "          ";

		to_upper(staff[i].position.second, 0);
		cout << staff[i].position.second;
		for (int j = 0; j < (12 - staff[i].position.second.length()); j++)
			cout << " ";
		cout << "        ";

		cout << staff[i].join_date.year << "." << staff[i].join_date.month << "." << staff[i].join_date.day;
	}
	cout << endl;
	for (int i = 0; i < max_username + max_full_name + length; i++)
		cout << "-";
	cout << endl;
}