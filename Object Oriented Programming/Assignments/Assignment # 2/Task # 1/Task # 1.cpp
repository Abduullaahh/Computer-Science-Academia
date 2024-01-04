#include<iostream>
using namespace std;
//------------------------------------------------------------------
class Garment
{
private:
	char name[20];
public:
	Garment(char*);
	char* getName();
	virtual int calculatePrice() = 0;
};
//---------------------------------------
Garment::Garment(char* Name = 0)
{
	int i = 0;
	for (; Name[i] != '\0'; i++)
	{
		name[i] = Name[i];
	}
	name[i] = '\0';
}
//---------------------------------------
char* Garment::getName()
{
	return name;
}
//------------------------------------------------------------------
//------------------------------------------------------------------
class Upper : public Garment
{
public:
	Upper(char*, int);
	virtual int getCollorSize() = 0;
	int collorSize;
};
//---------------------------------------
Upper::Upper(char* Name = 0, int CollorSize = 0) : Garment(Name)
{
	collorSize = CollorSize;
}
//------------------------------------------------------------------
class Shirt : virtual public Upper
{
public:
	Shirt(char*, int);
	int calculatePrice();
	int getCollorSize();
};
//---------------------------------------
Shirt::Shirt(char* Name = 0, int CollorSize = 0) : Upper(Name, CollorSize) {}
//---------------------------------------
int Shirt::calculatePrice()
{
	int Collar_size = Shirt::getCollorSize();
	Collar_size -= 1;
	int Shirt_Price = Collar_size * 20 + 10;
	return Shirt_Price;
}
//---------------------------------------
int Shirt::getCollorSize()
{
	return Upper::collorSize;
}
//------------------------------------------------------------------
//------------------------------------------------------------------
class Lower : public Garment
{
public:
	int waist;
	Lower(char*, int);
	virtual int getWaist() = 0;
};
//---------------------------------------
Lower::Lower(char* Name = 0, int Waist = 0) : Garment(Name)
{
	waist = Waist;
}
//------------------------------------------------------------------
class Pajama : virtual public Lower
{
public:
	Pajama(char*, int);
	int getWaist();
	int calculatePrice();
};
//---------------------------------------
Pajama::Pajama(char* Name = 0, int Waist = 0) : Lower(Name, Waist) {}
//---------------------------------------
int Pajama::getWaist()
{
	return Lower::waist;
}
//---------------------------------------
int Pajama::calculatePrice()
{
	int Waist = Pajama::getWaist();
	Waist -= 2;
	int Pajama_price = Waist * 15 + 50;
	return Pajama_price;
}
//------------------------------------------------------------------
class Trouser : virtual public Lower
{
public:
	Trouser(char*, int);
	int getWaist();
	int calculatePrice();
};
//---------------------------------------
Trouser::Trouser(char* Name = 0, int Waist = 0) : Lower(Name, Waist) {}
//---------------------------------------
int Trouser::getWaist()
{
	return Lower::waist;
}
//---------------------------------------
int Trouser::calculatePrice()
{
	int Waist = Trouser::getWaist();
	Waist -= 3;
	int Trouser_price = Waist * 20 + 100;
	return Trouser_price;
}
//------------------------------------------------------------------
//------------------------------------------------------------------
void Menu()
{
	system("cls");
	cout << "-----------------------------------------\n";
	cout << "\t\t~MAIN MENU~\n";
	cout << "-----------------------------------------\n";
	cout << "Press 1 : To add an item to shopping cart\n";
	cout << "Press 2 : To remove an item from the cart\n";
	cout << "Press 3 : To make the payment\n";
	cout << "-----------------------------------------\n";
}
//------------------------------------------------------------------
void menucart()
{
	system("cls");
	cout << "-----------------------------------------\n";
	cout << "\t\t~Available Items~\n";
	cout << "-----------------------------------------\n";
	cout << "Press 1 : To add a shirt to cart\n";
	cout << "Press 2 : To add a pajama to cart\n";
	cout << "Press 3 : To add a trouser to cart\n";
	cout << "-----------------------------------------\n";
}
//------------------------------------------------------------------
//------------------------------------------------------------------
int main()
{
	Garment** ShoppingCart = new Garment * [10];
	int cart = 0, Bill = 0;
	int Opt;
	do {
		Menu();
		cout << "Enter your choice : ";
		cin >> Opt;
		switch (Opt)
		{
		default:
		{
			cout << "Enter correct option\n"; system("pause");
		}
		case 1:
		{
			if (cart < 10)
			{
				int opt;
				menucart();
				cout << "Enter your choice : ";
				cin >> opt;
				switch (opt)
				{
				default:
				{
					cout << "Enter correct option\n"; system("pause");
				}
				case 1:
				{
					cout << "Enter collar size : "; int colr_size = 0; cin >> colr_size;
					char Name[6] = { 'S','h','i','r', 't', '\0' };
					ShoppingCart[cart] = new Shirt(Name, colr_size);
					Bill += ShoppingCart[cart]->calculatePrice();
					cout << "Shirt added to cart in price : " << ShoppingCart[cart]->calculatePrice() << endl;
					break;
				}
				case 2:
				{
					cout << "Enter waist : "; int waist = 0; cin >> waist;
					char Name[7] = { 'P','a','j','a','m','a','\0' };
					ShoppingCart[cart] = new Pajama(Name, waist);
					Bill += ShoppingCart[cart]->calculatePrice();
					cout << "Pajama added to cart in price : " << ShoppingCart[cart]->calculatePrice() << endl;
					break;
				}
				case 3:
				{
					cout << "Enter waist : "; int waist = 0; cin >> waist;
					char Name[8] = { 'T','r','o','u','s','e','r','\0' };
					ShoppingCart[cart] = new Trouser(Name, waist);
					Bill += ShoppingCart[cart]->calculatePrice();
					cout << "Trouser added to cart in price : " << ShoppingCart[cart]->calculatePrice() << endl;
					break;
				}
				}
				cart++;
			}
			else
			{
				cout << "Cart is full\n";
			}
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			if (cart > 0)
			{
				cout << "Your current bill : " << Bill << endl;
				cout << "Your current cart :-\n";
				int item = 0;
				for (int i = 0; i < cart; i++)
				{
					cout << "[" << i << "] : " << ShoppingCart[i]->getName() << " | Price :" << ShoppingCart[i]->calculatePrice() << endl;
				}
				cout << "Enter the item no to remove : "; cin >> item;
				if (item < cart && item > -1)
				{
					Bill -= ShoppingCart[item]->calculatePrice();;
					Garment** newcart = new Garment * [10];
					int ind = 0;
					for (int i = 0; i < cart; i++)
					{
						if (i != item)
						{
							newcart[ind] = ShoppingCart[i]; ind++;
						}
					}
					cart -= 1;
					ShoppingCart = NULL; ShoppingCart = new Garment * [10];
					for (int i = 0; i < cart; i++)
					{
						ShoppingCart[i] = newcart[i];
					}
					system("cls");
					cout << "Your updated bill : " << Bill << endl;
					cout << "Your updated cart :-\n";
					for (int i = 0; i < cart; i++)
					{
						cout << "[" << i << "] : " << ShoppingCart[i]->getName() << "| Price :" << ShoppingCart[i]->calculatePrice() << endl;
					}
				}
				else
				{
					cout << "Invalid item no\n";
				}
			}
			else
			{
				cout << "You haven't bought anything yet\n";
			}
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			if (Bill != 0)
			{
				cout << "Your bill : " << Bill << "\n~Thank you for shopping at our store~\n";
			}
			else
			{
				cout << "Your bill : " << Bill << "\n~You haven't bought anything~\n";
			}
			delete[]ShoppingCart;
			return 0;
		}
		}
	} while (Opt != 0);
}
//------------------------------------------------------------------
//------------------------------------------------------------------
