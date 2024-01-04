#include<iostream>
#include<string>
using namespace std;
void Menu();
void Account(string& n, string& at, int& b2);             // n : Name, at : Account Type, b : Balance
int Balance();
int Deposit();
int Withdraw();
void Exit();
//-------------------------
void Choice();
//-------------------------
string n, at;
int b, b2 = 0;     // Real Balance;
int main()
{
	//---------------------------
	//   STEP 0 : Getting Info
	//---------------------------
	cout << "Enter your Name : ";
	cin >> n;
	cout << "\nEnter your Account Type : ";
	cin >> at;
	cout << "\nEnter your Balance : ";
	cin >> b;
	b2 = b;
	cout << "\n-------------------------------------------\n";
	Choice();
}
//---------------------------
//  Main working of all Functions
//---------------------------
void Choice()
{
	int  i = 1, c;         // c : Selection
	Menu();
	cin >> c;
	cout << "-------------------------------------------\n";
	while (i == 1)
	{
		if (c != 1 && c != 2 && c != 3 && c != 4 && c != 5)            // For worng option
		{
			while (c != 1 && c != 2 && c != 3 && c != 4 && c != 5)
			{
				cout << "Select right option\n";
				cout << "-------------------------------------------\n";
				cin >> c;
				cout << "-------------------------------------------\n";
				if (c == 1 || c == 2 || c == 3 || c == 4 || c == 5)
				{
					break;
				}
			}
		}
		// For right option
		if (c == 1)
		{
			Account(n, at, b2);
		}
		else if (c == 2)
		{
			Balance();
		}
		else if (c == 3)
		{
			Deposit();
		}
		else if (c == 4)
		{
			Withdraw();
		}
		else if (c == 5)
		{
			Exit();
		}
		i++;
	}
}
//----------------
//  STEP 0 : Menu
//----------------
void Menu()
{
	cout << "Menu : \n";
	cout << "1. Account Info (press 1)\n";
	cout << "2. Balance (press 2)\n";
	cout << "3. Deposit (press 3)\n";
	cout << "4. Withdraw (press 4)\n";
	cout << "5. Exit (press 5)\n";
	cout << "-------------------------------------------\n";
}
//------------------------
//  STEP 1 : Account Info
//------------------------
void Account(string& n, string& at, int& b2)
{
	cout << "Account Info :\n";
	cout << "Name : " << n << endl;
	cout << "ID : " << rand() % 1000 << endl;
	cout << "Account Type : " << at << endl;
	cout << "Balance : " << b << endl;
	cout << "-------------------------------------------\n";
	cout << "Press enter for menu\n";
	cout << "-------------------------------------------\n";
	cin.ignore();
	cin.get();
	Choice();
}
//-------------------
//  STEP 2 : Balance
//-------------------
int Balance()
{
	if (b >= 1000)
	{
		cout << "Your Balance is : " << b << endl;
		cout << "-------------------------------------------\n";
	}
	else if (b < 1000)
	{
		cout << "Low Balance\n";
		cout << "-------------------------------------------\n";
	}
	cout << "Press enter for menu\n";
	cout << "-------------------------------------------\n";
	cin.ignore();
	cin.get();
	Choice();
	return 0;
}
//------------------
//  STEP 3 : Deposit
//------------------
int Deposit()
{
	int d;
	cout << "Your current Balance is : " << b;
	cout << " \nEnter the amount to be deposited\n";
	cout << "-------------------------------------------\n";
	cin >> d;
	cout << "-------------------------------------------\n";
	if (d < 0)                  // For negative amounts
	{
		for (int i = 1; i == 1; i++)
		{
			cout << "Invalid amount\n";
			cout << " \nEnter the amount to be deposited\n";
			cout << "-------------------------------------------\n";
			cin >> d;
			cout << "-------------------------------------------\n";
			if (d > 0)
			{
				b = b + d;
				cout << " Your Balance after diposit is : " << b << endl;
				cout << "-------------------------------------------\n";
			}
			else
			{
				Choice();
			}

		}
	}
	else if (d > 0)             // For positive amounts
	{
		b = b + d;
		cout << " Your Balance after diposit is : " << b << endl;
		cout << "-------------------------------------------\n";
	}
	cout << "Press enter for menu\n";
	cout << "-------------------------------------------\n";
	cin.ignore();
	cin.get();
	Choice();
	return 0;
}
//--------------------
//  STEP 4 : Withdraw
//--------------------
int Withdraw()
{
	int w, x, i = 1;              // x : Tax, cur : Amount remaning, w : Amount to be withdrawn
	cout << " Enter amount you want to withdraw\n";
	cout << " [NOTE : Amount can not be other than multiple of 500]\n";
	cout << "-------------------------------------------\n";
	cin >> w;
	cout << "-------------------------------------------\n";
	if (w % 500 != 0)
	{
		while (w % 500 != 0)
		{
			cout << " Eror : You can only withdraw multiples of 500\n";
			cout << " Enter valid amount\n";
			cout << "-------------------------------------------\n";
			cin >> w;
			cout << "-------------------------------------------\n";
			if (w % 500 == 0)
			{
				break;
			}
		}
	}
	if (b < w && w == 500)
	{
		cout << " Not enough cash\n";
	}
	if (b >= w && w % 500 == 0)
	{
		if (w < 4000)                          // For less then 4000
		{
			b = b - w;
			cout << " Your remaining amount is : " << b << "\n";
			cout << " No tax has been deducted\n";
			cout << "-------------------------------------------\n";
		}
		else if (w >= 4000 && w < 6000)        // For 4000-5999
		{
			x = (0.053 * w);
			w = w + x;
			b = b - w;
			cout << " Your remaining amount is : " << b << "\n" << "5.3% Tax (" << x << ") has been deducted from your account\n ";
			cout << "-------------------------------------------\n";
		}
		else if (w >= 6000 && w < 10000)       // For 6000 - 9999
		{
			x = (0.068 * w);
			w = w + x;
			b = b - w;
			cout << " Your remaining amount is : " << b << "\n" << "6.8% Tax (" << x << ") has been deducted from your account\n ";
			cout << "-------------------------------------------\n";
		}
		else if (w >= 10000)                   // For 10000 and more
		{
			x = (0.084 * w);
			w = w + x;
			b = b - w;
			cout << " Your remaining amount is : " << b << "\n" << "8.4% Tax (" << x << ") has been deducted from your account\n ";
			cout << "-------------------------------------------\n";
		}
	}
	cout << "Press enter for menu\n";
	cout << "-------------------------------------------\n";
	cin.ignore();
	cin.get();
	Choice();
	return 0;
}
//----------------
//  STEP 5 : EXIT
//----------------
void Exit()
{
	if (b2 == b)
	{
		cout << "Kanjoos insan!  :(\n";
		exit;
	}
	else
	{
		cout << "Thank You for Using FAST Banking\n";
		cout << "Tumhara Grade pakka hai!\n";
		exit;
	}
}
