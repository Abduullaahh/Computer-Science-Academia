#include<iostream>
using namespace std;
//------------------------------------------------------------------
class Customer
{
private:
	char Name[20];
	int Hours;
	double MBs;
	double Dail_Ups;
	double Chrg_Pr_Connec;
	double In_Cost;
	double Add_Rates;
	double Bill;
public:
	Customer(char*, int, double, double);
	char* get_Name();
	int get_Hours();
	double get_MBs();
	double get_Dail_Ups();
	void set_Bill(double);
	virtual double ComputeBill();
};
//---------------------------------------
Customer::Customer(char* name = 0, int Hrs = 0, double dail_ups = 0, double Mbs = 0)
{
	int i = 0;
	for (; name[i] != '\0'; i++)
	{
		Name[i] = name[i];
	}
	Name[i] = '\0';
	Hours = Hrs;
	MBs = Mbs;
	Dail_Ups = dail_ups;
	Chrg_Pr_Connec = 0;
	In_Cost = 10;
	Add_Rates = 4;
	Bill = 0;
}
//---------------------------------------
double Customer::ComputeBill()
{
	if (Hours <= 4)
	{
		Bill = 10;
	}
	else if (Hours > 4)
	{
		Bill = (Hours - 4) * 4;
	}
	return Bill;
}
//---------------------------------------
char* Customer::get_Name() { return Name; }
int Customer::get_Hours() { return Hours; }
double Customer::get_MBs() { return MBs; }
double Customer::get_Dail_Ups() { return Dail_Ups; }
void Customer::set_Bill(double bill) { Bill = bill; }
//------------------------------------------------------------------
class Hacker : virtual public Customer
{
private:
	double Chrg_Pr_Connec;
	double In_Cost;
	double Add_Rates;
	double Bill;
public:
	Hacker(char*, int, double, double);
	virtual double ComputeBill();
};
//---------------------------------------
Hacker::Hacker(char* name = 0, int Hrs = 0, double dail_ups = 0, double Mbs = 0) : Customer(name, Hrs, dail_ups, Mbs)
{
	Chrg_Pr_Connec = 0;
	In_Cost = 20;
	Add_Rates = 2.50;
	Bill = 0;
}
//---------------------------------------
double Hacker::ComputeBill()
{
	if (get_Hours() < 11)
	{
		Bill = 10;
	}
	else if (get_Hours() > 10)
	{
		Bill = (get_Hours() - 4) * 2.50;
	}
	return Bill;
}
//------------------------------------------------------------------
class ChatRoom : public Customer
{
private:
	double Chrg_Pr_Connec;
	double In_Cost;
	double Add_Rates;
	double Bill;
public:
	ChatRoom(char*, int, double, double);
	virtual double ComputeBill();
};
//---------------------------------------
ChatRoom::ChatRoom(char* name = 0, int Hrs = 0, double dail_ups = 0, double Mbs = 0) : Customer(name, Hrs, dail_ups, Mbs)
{
	Chrg_Pr_Connec = 10;
	In_Cost = 50;
	Add_Rates = 0;
	Bill = 0;
}
//---------------------------------------
double ChatRoom::ComputeBill()
{
	if (get_Dail_Ups() > 0)
	{
		Bill = 50 + (get_Dail_Ups() * 0.10);
	}
	else
	{
		Bill = 50;
	}
	return Bill;
}
//------------------------------------------------------------------
int main()
{
	char* Name;
	int Hours;
	double Dail_Ups;
	int MBs;
	int opt = 1;
	int Bill1 = 0;
	int Bill2 = 0;
	int Bill3 = 0;
	Customer* Customer_Plan[3];
	while (opt != 0)
	{
		system("cls");
		Name = new char[20]; cin.ignore();
		cout << "Enter your name : "; cin.getline(Name, 20);
		cout << "Enter usage in hours : "; cin >> Hours;
		cout << "Enter no of dail ups : "; cin >> Dail_Ups;
		cout << "Enter MBs of hard-drive used : "; cin >> MBs;
		Customer_Plan[0] = new Customer(Name, Hours, Dail_Ups, MBs);
		Customer_Plan[1] = new Hacker(Name, Hours, Dail_Ups, MBs);
		Customer_Plan[2] = new ChatRoom(Name, Hours, Dail_Ups, MBs);
		Bill1 = Customer_Plan[0]->ComputeBill();
		Bill2 = Customer_Plan[1]->ComputeBill();
		Bill3 = Customer_Plan[2]->ComputeBill();
		cout << "Customer Plan Bill : " << Bill1 << "$" << endl;
		cout << "Hacker Plan Bill   : " << Bill2 << "$" << endl;
		cout << "ChatRoom Plan Bill : " << Bill3 << "$" << endl;
		if (Bill1 < Bill2 && Bill1 < Bill3)
		{
			cout << "Mr. " << Customer_Plan[0]->get_Name() << ", you should get Customer plan because it will cost you least, that is " << Bill1 << "$";
		}
		else if (Bill2 < Bill1 && Bill2 < Bill3)
		{
			cout << "Mr. " << Customer_Plan[0]->get_Name() << ", you should get Hacker plan because it will cost you least, that is " << Bill2 << "$";
		}
		else if (Bill3 < Bill1 && Bill3 < Bill2)
		{
			cout << "Mr. " << Customer_Plan[0]->get_Name() << ", you should get ChatRoom plan because it will cost you least, that is " << Bill3 << "$";
		}
		cout << endl;
		cout << "Press 0 to Exit OR any key to Continue\n";
		cin >> opt;
		if (opt == 0)
		{
			delete[]Name; Name = NULL;
			return 0;
		}
	}
}
//------------------------------------------------------------------