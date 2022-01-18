#include<iostream>
#include<string>
#include<fstream>
#include <conio.h>
#include <stdlib.h>
#include<windows.h>
using namespace std;
class parent {
protected:
	string name, Grade, post, Department, BankAccount, email;
	int pay, attendance;
public:
	int phone() {
		name = "\0";         //constructor to initialize strings with no character stored
		Grade = "\0";
		post = "\0";
		Department = "\0";
		BankAccount = "\0";
	}
	virtual bool login() = 0;
	virtual void menu() = 0;   //pure virtual functions
	void virtual get_name() = 0;
	void virtual get_post() = 0;
	void virtual get_payscale() = 0;
	void virtual get_email() = 0;
	void virtual get_Department() = 0;
	void virtual get_bankaccountID() = 0;
	void virtual insert() = 0;
	void virtual display() = 0;
	void virtual search() = 0;
	void virtual edit() = 0;
	void virtual deleteparticular() = 0;
	void virtual menu2() = 0;
	int virtual admin() = 0;
};
class child : public parent {
public:
	child() {



	}
	bool login();
	void menu();
	void get_name();
	void get_post();
	void get_payscale();
	void get_email();
	void get_Department();
	void get_bankaccountID();
	void insert();
	void display();
	void search();
	void edit();
	void deleteparticular();
	void menu2();
	int admin();
};
int child::admin()
{
	system("Color F");
	int x;
	cout << "ENTER 1 FOR ADMIN ACCESS, ENTER 2 IF YOU ARE AN EMPLOYEE" << endl;
	cin >> x;
	if (x == 1)
	{
		return 1;
	}
	if (x == 2)
	{
		return 2;
	}
}
bool child::login()
{
	system("Color E");
	cout << "-----------ONLY AUTHORIZED PERSONEL ALLOWED-----------" << endl;
	string username, password;
	cout << "Enter your UserName" << endl;
	cin >> username;
	cout << "Enter your Password" << endl;
	cin >> password;
	int count = 0;
	do {
		if (count == 3) {
			cout << "YOU ARE UNKNOWN PERSON FOR OUR SYSTEM WHO IS TRYING TO ACCESS THE SYSTEM, WE ARE TERMINATING THE PROGRAM DUE TO SECURITY PURPOSES" << endl;
			Sleep(999999);
			break;
			return 0;
		}
		if (username == "hama" && password == "123456")
		{
			cout << "------ACCESS GRANTED------" << endl;
			Sleep(3000);
			return 1;
		}
		else if (username != "hama" && password == "123456")
		{
			cout << "Wrong user name or password" << endl;
			cout << "Enter Details again" << endl;
			cin >> username;
			cin >> password;
			count++;
		}
		else if (username == "hama" && password != "123456")
		{
			cout << "Wrong user name or password" << endl;
			cout << "Enter Details again" << endl;
			cin >> username;
			cin >> password;
			count++;
		}
		else
		{
			cout << "Wrong user name or password" << endl;
			cout << "Enter Details again" << endl;
			cin >> username;
			cin >> password;
			count++;
		}
	} while (count<4);
}
void child::menu()
{
	system("cls");
	system("Color 3");
	cout << "-----------WELCOME TO GOVERNMENT COLLEGE LAHORE SALARY SECTION-----------" << endl;
	cout << "\n\n\n";
	cout << "ENTER 1 TO INSERT NEW RECORD" << endl;
	cout << "ENTER 2 TO DISPLAY ALL RECORDS" << endl;
	cout << "ENTER 3 TO SEARCH A RECORD" << endl;
	cout << "ENTER 4 TO EDIT A RECORD" << endl;
	cout << "ENTER 5 TO DELETE PARTICULAR RECORD " << endl;
	cout << "ENTER 6 TO EXIT " << endl;
}
void child::menu2()
{
	cout << "ENTER 1 TO SEARCH A RECORD" << endl;
	cout << "ENTER 2 TO EXIT " << endl;
}
void child::get_name()
{
	string localname = "\0";
	cout << " ENTER EMPLOYEE NAME" << endl;
	cin >> localname;
	if (localname.size() < 2)
	{
		cout << "YOU HAVE ENTERED AN INVALID NAME" << endl;
		cout << "ENTER NAME AGAIN" << endl;
		get_name();
	}
	else
	{
		name = localname;
	}
}
void child::get_post()
{
	string localpost = "\0";
	cout << "ENTER POST OF EMPLOYEE" << endl;
	cin >> localpost;
	if (localpost.size() < 2)
	{
		cout << "YOU HAVE ENTERED AN INVALID POST" << endl;
		cout << "ENTER VALID POST AGAIN" << endl;
		get_post();
	}
	else
	{
		post = localpost;
	}

}
void child::get_payscale()
{
	int localscale, localattendance1;
	cout << "VALID SCALES ARE EVEN NUMBERS FROM 8 TO 20" << endl;
	cout << "ENTER GRADE OF EMPLOYEE" << endl;
	cin >> localscale;
	cout << "Enter Attendance of Employee out of a total 22/23/20 days" << endl;
	cin >> localattendance1;
	if (localscale == 8 && localattendance1<24) {
		attendance = localattendance1;
		Grade = "8";
		pay = localattendance1 * 984;
	}
	else if (localscale == 10 && localattendance1<24) {
		attendance = localattendance1;
		Grade = "10";
		pay = localattendance1 * 1042;
	}
	else if (localscale == 12 && localattendance1<24) {
		attendance = localattendance1;
		Grade = "12";
		pay = localattendance1 * 1169;
	}
	else if (localscale == 14 && localattendance1<24) {
		attendance = localattendance1;
		pay = localattendance1 * 1303;
	}
	else if (localscale == 16 && localattendance1<24) {
		attendance = localattendance1;
		Grade = "16";
		pay = localattendance1 * 1671;
	}
	else if (localscale == 18 && localattendance1<24) {
		attendance = localattendance1;
		Grade = "18";
		pay = localattendance1 * 3057;
	}
	else if (localscale == 20 && localattendance1<24)
	{
		attendance = localattendance1;
		Grade = "20";
		pay = localattendance1 * 6010;
	}
	else
	{
		cout << "Enter Valid Pay scale or attendance as required" << endl;
		get_payscale();
	}

}
void child::get_email()
{
	string localemail = "\0";
	cout << " ENTER EMPLOYEES EMAIL ADDRESS ID" << endl;
	cin >> localemail;
	int a = localemail.size();
	bool b = false;
	for (int i = 0; i < a; i++)
	{
		if (localemail[i] == '@')
		{
			b = true;
			break;
		}
	}
	if (b == false)
	{
		cout << "YOU HAVE ENTERED AN INVALID EMAIL ADDRESS" << endl;
		cout << "PLESE ENTER A VALID EMAIL ADDRESS" << endl;
		get_email();
	}
	else
	{
		email = localemail;
	}
}
void child::get_Department()
{
	string localDepartment = "\0";
	cout << "ENTER EMPLOYEES DEPARTMENT" << endl;
	cin >> localDepartment;
	int a = localDepartment.size();
	if (a <= 3) {
		cout << "YOU HAVE ENTERED INVALID DEPARTMENT NAME" << endl;
		cout << "ENTER VALID DEPARTMENT" << endl;
		get_Department();
	}
	else
	{
		Department = localDepartment;
	}
}
void child::get_bankaccountID()
{
	string bankaccountid;
	cout << "Enter bank ID number" << endl;
	cin >> bankaccountid;
	int a = bankaccountid.size();
	if (a>16)
	{
		cout << "Enter a valid bank ID" << endl;
	}
	else if (a<16)
	{
		cout << "Enter a valid bank ID" << endl;
		get_bankaccountID();
	}
	else
	{
		BankAccount = bankaccountid;
	}
}
void child::insert()
{
	system("cls");
	system("Color 9");
	get_bankaccountID();
	get_name();
	get_post();
	get_email();
	get_payscale();
	get_Department();
	ofstream obj;
	obj.open("salary.txt", ios::app);
	if (!obj)
	{
		cout << "Error in opening the file";

	}
	else
	{
		obj << BankAccount << " " << name << " " << Department << " " << Grade << " " << post << " " << email << " " << attendance << " " << pay << endl;
		obj.close();
	}
	cout << "Enter any key to continue" << endl;
}
void child::display()
{
	system("cls");
	system("Color 2");
	string nam, departmento, grado, posto, emailo, bankaccounto; int payo, attendenco;
	ifstream file;
	file.open("salary.txt", ios::in);
	if (!file)
	{
		cout << "Error in opening the file" << endl;
	}
	else
	{
		while (file >> bankaccounto)
		{
			cout << "BankAccount" << ":\t" << bankaccounto << endl;
			file >> nam;
			cout << "Name" << ":\t" << nam << endl;
			file >> departmento;
			cout << "Department" << ":\t" << departmento << endl;
			file >> grado;
			cout << "Grade" << ":\t" << grado << endl;
			file >> posto;
			cout << "Post" << ":\t" << posto << endl;
			file >> emailo;
			cout << "Email" << ":\t" << emailo << endl;
			file >> attendenco;
			cout << "Attendance" << ":\t" << attendenco << " " << "days" << endl;
			file >> payo;
			cout << "Pay" << ":\t" << payo << "\tPKR" << endl;
		}
		file.close();
	}
	cout << "Enter any key to continue" << endl;
}
void child::search()
{
	system("cls");
	string search_by_bankID, nam, departmento, grado, posto, emailo, bankaccounto; int payo, attendenco;
	bool flag = false;
	cout << "Please Enter the Bank ID of the employee which you want to search" << endl;
	cin >> search_by_bankID;
	ifstream file;
	file.open("salary.txt", ios::in);
	if (!file)
	{
		cout << "ERROR IN OPENING THE FILE" << endl;
	}
	else
	{
		while (file >> bankaccounto)
		{
			if (search_by_bankID == bankaccounto)
			{
				flag = true;
				cout << "BankAccount" << ":\t" << bankaccounto << endl;
				file >> nam;
				cout << "Name" << ":\t" << nam << endl;
				file >> departmento;
				cout << "Department" << ":\t" << departmento << endl;
				file >> grado;
				cout << "Grade" << ":\t" << grado << endl;
				file >> posto;
				cout << "Post" << ":\t" << posto << endl;
				file >> emailo;
				cout << "Email" << ":\t" << emailo << endl;
				file >> attendenco;
				cout << "Attendance" << ":\t" << attendenco << " " << "days" << endl;
				file >> payo;
				cout << "Pay" << ":\t" << payo << " " << "PKR" << endl;
			}
		}
		if (flag != true)
		{
			cout << "This Bank Account does not exist" << endl;
		}
		file.close();
	}
	cout << "Press any key to continue" << endl;
}
void child::edit()
{
	system("cls");
	system("Color 4B");
	bool prcham = false;
	string search_by_bankID, nam, departmento, grado, posto, emailo, bankaccounto; int payo, attendenco;
	cout << "ENTER BANK ID OF EMPLOYEE OF WHOSE RECORD YOU WANT TO EDIT" << endl;
	cin >> search_by_bankID;
	ifstream file("salary.txt");
	ofstream temp("temp.txt");
	while (file >> bankaccounto)
	{
		if (bankaccounto == search_by_bankID)
		{
			prcham = true;
			cout << "Enter New bank ID:" << endl;
			cin >> bankaccounto;
			temp << bankaccounto << " ";
			cout << "Enter Name:" << endl;
			cin >> nam;
			temp << nam << " ";
			cout << "Enter New Department" << endl;
			cin >> departmento;
			temp << departmento << " ";
			cout << "Enter New Grade" << endl;
			cin >> grado;
			temp << grado << " ";
			cout << "Enter New Post" << endl;
			cin >> posto;
			temp << posto << " ";
			string localemail = "\0";
			bool b;
			cout << "Enter New Email ID:" << endl;
			cin >> localemail;
			int a = localemail.size();
			for (int i = 0; i < a; i++)
			{
				if (localemail[i] == '@')
				{
					b = true;
					break;
				}
			}
			if (b != true)
			{
				cout << "YOU HAVE ENTERED AN INVALID EMAIL ID" << endl;
				cout << "PLESE ENTER A VALID EMAIL ID" << endl;
				cout << "Returning to start" << endl;
				Sleep(6000);
				edit();
			}
			else
			{
				emailo = localemail;
			}

			temp << emailo << " ";
			cout << "Enter new attendance:" << endl;
			cin >> attendenco;
			temp << attendenco << " ";
			int localscale;
			cout << "VALID SCALES ARE EVEN NUMBERS FROM 8 TO 20, Enter a payscale" << endl;
			cin >> localscale;
			if (localscale == 8 && attendenco<24) {
				attendenco = attendenco;
				grado = "8";
				payo = attendenco * 984;
			}
			else if (localscale == 10 && attendenco<24) {
				attendenco = attendenco;
				grado = "10";
				payo = attendenco * 1042;
			}
			else if (localscale == 12 && attendenco<24) {
				attendenco = attendenco;
				grado = "12";
				payo = attendenco * 1169;
			}
			else if (localscale == 14 && attendenco<24) {
				attendenco = attendenco;
				grado = "14";
				payo = attendenco * 1303;
			}
			else if (localscale == 16 && attendenco<24) {
				attendenco = attendenco;
				grado = "16";
				payo = attendenco * 1671;
			}
			else if (localscale == 18 && attendenco<24) {
				attendenco = attendenco;
				grado = "18";
				payo = attendenco * 3057;
			}
			else if (localscale == 20 && attendenco<24)
			{
				attendenco = attendenco;
				grado = "20";
				payo = attendenco * 6010;
			}
			else
			{
				cout << "Enter Valid Pay scale as required" << endl;
				cout << "Returning to top again" << endl;
				Sleep(5000);
				search();
			}
			temp << payo << " ";
			file >> bankaccounto >> nam >> departmento >> grado >> posto >> emailo >> payo;
		}

		else
		{
			if (bankaccounto != search_by_bankID)
			{
				temp << bankaccounto << " ";
				file >> nam;
				temp << nam << " ";
				file >> departmento;
				temp << departmento << " ";
				file >> grado;
				temp << grado << " ";
				file >> posto;
				temp << posto << " ";
				file >> emailo;
				temp << emailo << " ";
				file >> attendenco;
				temp << attendenco << " ";
				file >> payo;
				temp << payo << " ";
			}
		}

	}
	if (prcham == false)
	{
		cout << "THIS BANK ID DOES NOT EXIST" << endl;
		cout << "WE ARE RETURNING BACK TO THE MENU" << endl;
		Sleep(5000);
	}
	file.close();
	temp.close();
	remove("salary.txt");
	rename("temp.txt", "salary.txt");
	cout << "Enter any key to continue" << endl;
}

void child::deleteparticular()
{
	system("cls");
	system("Color 6E");
	string search_by_bankID, nam, departmento, grado, posto, emailo, bankaccounto; int payo, attendenco;
	string local_ID;
	cout << "Enter Bank ID of employee whose record you want to remove" << endl;
	cin >> local_ID;
	ifstream file("salary.txt");
	ofstream temp("temp.txt");
	bool flag = false;
	while (file >> bankaccounto)
	{
		if (local_ID != bankaccounto)
		{
			temp << local_ID << " ";
			file >> nam;
			temp << nam << " ";
			file >> departmento;
			temp << departmento << " ";
			file >> grado;
			temp << grado << " ";
			file >> posto;
			temp << posto << " ";
			file >> emailo;
			temp << emailo << " ";
			file >> attendenco;
			temp << attendenco << " ";
			file >> payo;
			temp << payo << " ";
		}
		else
		{
			flag = true;
			file >> bankaccounto >> nam >> departmento >> grado >> emailo >> attendenco >> payo;
			cout << "Record Has been removed from this system successfully" << endl;
		}
	}
	if (flag == false)
	{
		cout << "THIS BANK ID DOES NOT EXIST" << endl;
		cout << "WE ARE RETURNING BACK TO THE MENU" << endl;
		Sleep(5000);
	}
	temp.close();
	file.close();
	remove("salary.txt");
	rename("temp.txt", "salary.txt");
	cout << "Enter any key to continue" << endl;
}
int main()
{
	parent *a;
	child b;
	a = &b;
	int s1, s2, s3, s4;
	s3 = a->admin();
	if (s3 == 1)
	{
		s1 = a->login();
		if (s1 == 1)
		{
			a->menu();
			do
			{

				cout << endl;
				cin >> s2;
				if (s2 == 1)
				{
					a->insert();
					_getch();
					cout << endl;
					a->menu();
				}
				else if (s2 == 2)
				{
					a->display();
					_getch();
					cout << endl;
					a->menu();
				}
				else if (s2 == 3)
				{
					a->search();
					_getch();
					cout << endl;
					a->menu();
				}
				else if (s2 == 4)
				{
					a->edit();

					_getch();
					cout << endl;
					a->menu();
				}
				else if (s2 == 5)
				{
					a->deleteparticular();
					_getch();
					cout << endl;
					a->menu();
				}
				else if (s2 == 6)
				{
					cout << "EXITING FROM SALARY SYSTEM" << endl;
					return 0;
				}

			} while (1);
		}
	}
	if (s3 == 2)
	{
		a->menu2();
		do
		{
			cout << endl;
			cin >> s4;
			if (s4 == 1)
			{
				a->search();
				_getch();
				cout << endl;
				system("cls");
				a->admin();
			}
			else if (s4 == 2)
			{
				cout << "EXITING" << endl;
				system("cls");
				return 0;
			}
		} while (1);

	}

}

