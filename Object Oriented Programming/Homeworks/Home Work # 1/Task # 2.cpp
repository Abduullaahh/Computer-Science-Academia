#include<iostream>
using namespace std;
//------------------------------------------------------------------
class ATM
{
private:
	int totalCash;
public:
	ATM(int);
	void setCash(int);
	int getCash();
	void showBalance();
};
//---------------------------------------
ATM::ATM(int Total_Cash = 0)
{
	totalCash = Total_Cash;
}
//---------------------------------------
void ATM::setCash(int Total_Cash)
{
	totalCash = Total_Cash;
}
//---------------------------------------
int ATM::getCash()
{
	return totalCash;
}
//---------------------------------------
void ATM::showBalance()
{
	cout << "Your balance : " << totalCash;
}
//------------------------------------------------------------------
class AccountHolder
{
private:
	int Account_Number;
	int balance;
public:
	AccountHolder(int, int);
	void setAccountNumber(int);
	void setBalance(int);
	int getAccountNumber();
	int getBalance();
};
//---------------------------------------
AccountHolder::AccountHolder(int account_number = 0, int Balance = 0)
{
	Account_Number = account_number;
	balance = Balance;
}
//---------------------------------------
void AccountHolder::setAccountNumber(int account_number)
{
	Account_Number = account_number;
}
//---------------------------------------
void AccountHolder::setBalance(int Balance)
{
	balance = Balance;
}
//---------------------------------------
int AccountHolder::getAccountNumber()
{
	return Account_Number;
}
//---------------------------------------
int AccountHolder::getBalance()
{
	return balance;
}
//------------------------------------------------------------------
class Transaction : public ATM
{
private:
	AccountHolder* arr;
	int size;
public:
	Transaction(int, int);
	void Withdraw_Amount(int, int);
	void setData(int, int, int);
	void showBalance();
	void resize(int);
};
//---------------------------------------
Transaction::Transaction(int Size = 0, int cash = 0) :ATM(cash)
{
	size = Size;
	arr = new AccountHolder[size];
}
//---------------------------------------
void Transaction::Withdraw_Amount(int Account_Number, int withdrawal_amount)
{
	int chk = 0;
	for (int i = 0; i < size; i++)
	{
		if (Account_Number == arr[i].getAccountNumber())
		{
			if (withdrawal_amount < arr[i].getBalance())
			{
				if (withdrawal_amount < ATM::getCash())
				{
					arr[i].setBalance(arr[i].getBalance() - withdrawal_amount);
					cout << "Transaction done sucessfully\n";
				}
				else
				{
					cout << "Not enough cash in ATM.....SORRY!\n";
				}
			}
			else
			{
				cout << "Not enough cash in your account\n";
			}
			chk++;
		}
	}
	if (chk == 0)
	{
		cout << "Account does not exists\n";
	}
}
//---------------------------------------
void Transaction::setData(int ind, int Account_Number, int Balance)
{
	if (ind < size)
	{
		arr[ind].setAccountNumber(Account_Number);
		arr[ind].setBalance(Balance);
		cout << "Data saved successfully\n";
	}
	else
	{
		cout << "Invalid index\n";
	}
}
//---------------------------------------
void Transaction::showBalance()
{
	cout << "Enter account no : "; int acc_num; cin >> acc_num; int chk = 0;
	for (int i = 0; i < size; i++)
	{
		if (acc_num == arr[i].getAccountNumber())
		{
			chk++;
			cout << "Balance of account no. " << arr[i].getAccountNumber() << " is : " << arr[i].getBalance() << endl;
		}
	}
	if (chk == 0)
	{
		cout << "Account not exists\n";
	}
}
//---------------------------------------
void Transaction::resize(int Size)
{
	AccountHolder* newarr;
	newarr = new AccountHolder[Size];
	int i = 0;
	if (Size > size)
	{
		for (; i < size; i++)
		{
			newarr[i] = arr[i];
		}
		for (; i < Size; i++)
		{
			newarr[i] = 0;
		}
	}
	else
	{
		for (; i < Size; i++)
		{
			newarr[i] = arr[i];
		}
	}
	size = Size;
	delete[]arr;
	arr = NULL;
	arr = new AccountHolder[size];
	for (i = 0; i < size; i++)
	{
		arr[i] = newarr[i];
	}
	delete[]newarr;
	cout << "Array resized successfully\n";
}
//------------------------------------------------------------------
void menu()
{
	system("cls");
	cout << "---------------------------------------------\n";
	cout << "\t\tMENU\n";
	cout << "---------------------------------------------\n";
	cout << "Enter 1 : To insert a record\n";
	cout << "Enter 2 : To update ATM cash\n";
	cout << "Enter 3 : To update account holder's balance\n";
	cout << "Enter 4 : To view ATM cash\n";
	cout << "Enter 5 : To view account holder's balance\n";
	cout << "Enter 6 : To resize the array\n";
	cout << "Enter 7 : To withdraw amount from the account\n";
	cout << "Enter 0 : To terminate the program\n";
	cout << "---------------------------------------------\n";
}
//------------------------------------------------------------------
int main()
{
	Transaction t1(3, 5000); //3 is the size of array and 5000 is ATM cash
	ATM* a;
	a = &t1;
	int choice;
	int size = 3;
	do {
		menu();
		cout << "Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		default:
		{
			cout << "Enter correct option\n"; system("pause");
		}
		case 1:
		{
			int ind;
			cout << "Enter index no. : "; cin >> ind;
			if (ind < size)
			{
				int acc_num, bal;
				cout << "Enter account no. : "; cin >> acc_num;
				cout << "Enter balance : "; cin >> bal;
				t1.setData(ind, acc_num, bal);
			}
			else
			{
				cout << "Invalid index\n";
			}
			system("pause");
			break;
		}
		case 2:
		{
			int amount;
			cout << "Enter amount : "; cin >> amount;
			a->setCash(a->getCash() + amount);
			system("pause");
			break;
		}
		case 3:
		{
			int ind, acc_num, bal;
			cout << "Enter your imformation carefully\nin case of wrong imformation\nyou may lose your record\n";
			cout << "Enter index no. : "; cin >> ind;
			cout << "Enter account no. : "; cin >> acc_num;
			cout << "Enter new balance : "; cin >> bal;
			t1.setData(ind, acc_num, bal);
			system("pause");
			break;
		}
		case 4:
		{
			cout << "Cash in ATM : " << a->getCash() << endl;
			system("pause");
			break;
		}
		case 5:
		{
			t1.showBalance();
			system("pause");
			break;
		}
		case 6:
		{
			cout << "Enter new size of array : "; cin >> size;
			t1.resize(size);
			system("pause");
			break;
		}
		case 7:
		{
			int acc_num, withdraw_amount;
			cout << "Enter account no. : "; cin >> acc_num;
			cout << "Enter withdraw amount : "; cin >> withdraw_amount;
			if (withdraw_amount < a->getCash())
			{
				t1.Withdraw_Amount(acc_num, withdraw_amount);
				a->setCash(a->getCash() - withdraw_amount);
			}
			else
			{
				cout << "Not enough cash in ATM.....Sorry!\n";
			}
			system("pause");
			break;
		}
		case 0:
		{
			return 0;
		}
		}
	} while (choice != 0);
}
