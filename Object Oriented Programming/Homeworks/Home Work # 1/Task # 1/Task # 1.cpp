#include<iostream>
using namespace std;

class Fraction
{
private:
	static int fractionsCount;
	int numerator;
	int denominator;
public:
	Fraction(int, int);
	void setNum(int);
	void setDen(int);
	int getNum() const;
	int getDen() const;
	Fraction operator + (const Fraction&);
	Fraction operator * (const Fraction&);
	void operator ++();
	void operator ++(int);
	void operator --();
	void operator --(int);
	bool operator == (const Fraction&);
	bool operator > (const Fraction&);
	friend ostream& operator << (ostream&, const Fraction&);
	friend istream& operator >> (istream&, Fraction&);
	bool isProper() const;
	static int getCount();
	void show() const;
	~Fraction();
};

int Fraction::fractionsCount = 0;

Fraction::Fraction(int n = 1, int d = 1)
{
	if (d != 0)
	{
		fractionsCount++;
		numerator = n;
		denominator = d;
	}
	else
	{
		cout << "Denominator cannot be zero\n";
	}
}

void Fraction::setNum(int n)
{
	numerator = n;
}

void Fraction::setDen(int d)
{
	denominator = d;
}

int Fraction::getNum() const
{
	return numerator;
}

int Fraction::getDen() const
{
	return denominator;
}

Fraction Fraction::operator + (const Fraction& F)
{
	Fraction f;
	if (denominator == F.denominator)
	{
		f.numerator = numerator + F.numerator;
		f.denominator = denominator;
	}
	else
	{
		f.numerator = numerator * F.denominator + F.numerator * denominator;
		f.denominator = denominator * F.denominator;
	}
	return f;
}

Fraction Fraction::operator * (const Fraction& F)
{
	Fraction f;
	f.numerator = numerator * F.numerator;
	f.denominator = denominator * F.denominator;
	return f;
}

void Fraction::operator ++()
{
	++numerator;
	++denominator;
}

void Fraction::operator ++(int inc)
{
	numerator++;
	denominator++;
}


void Fraction::operator --()
{
	--numerator;
	--denominator;
}


void Fraction::operator --(int inc)
{
	numerator--;
	denominator--;
}


bool Fraction::operator == (const Fraction& F)
{
	double n1, n2, d1, d2;
	n1 = numerator; d1 = denominator; n2 = F.numerator; d2 = F.denominator;
	if ((n1 / d1) == (n2 / d2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Fraction::operator > (const Fraction& F)
{
	if (numerator > F.numerator && denominator > F.denominator)
	{
		return true;
	}
	else if (numerator > F.numerator && denominator == F.denominator)
	{
		return true;
	}
	else
	{
		return false;
	}
}

ostream& operator << (ostream& out, const Fraction& F)
{
	out << F.numerator << " / " << F.denominator << endl;
	return out;
}

istream& operator >> (istream& in, Fraction& F)
{
	cout << "Enter numerator : "; in >> F.numerator;
	cout << "Enter denominator : "; in >> F.denominator;
	return in;
}

bool Fraction::isProper() const
{
	if (numerator < denominator)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Fraction::getCount()
{
	return fractionsCount;
}

void Fraction::show() const
{
	cout << numerator << " / " << denominator << endl;
}

Fraction::~Fraction()
{
	fractionsCount--;
}

int Menu()
{
	system("pause");
	system("cls");
	int opt;
	cout << "--------------------------------------------------------------\n";
	cout << "\n\t\tMENU\n";
	cout << "--------------------------------------------------------------\n";
	cout << "PRESS 0 : To set numenator or denominator of fraction\n";
	cout << "PRESS 1 : To get numenator or denominator of fraction\n";
	cout << "PRESS 2 : Addition of two fractions\n";
	cout << "PRESS 3 : Multiplication of two fractions\n";
	cout << "PRESS 4 : Increment / Decrements in fractions (post OR pre)\n";
	cout << "PRESS 5 : Check equality of two fractions\n";
	cout << "PRESS 6 : Check one fraction is greater or smaller than other\n";
	cout << "PRESS 7 : Check wether the fraction is proper\n";
	cout << "PRESS 8 : Get count of objects\n";
	cout << "PRESS 9 : To print a fraction\n";
	cout << "PRESS -1 : Exit\n";
	cout << "--------------------------------------------------------------\n";
	cout << "Enter option : "; cin >> opt;
	cout << "--------------------------------------------------------------\n";
	return opt;
}

int main()
{
	Fraction F1;
	Fraction F2;
	cout << "Enter fraction 1 :-\n"; cin >> F1;
	cout << "Enter fraction 2 :-\n"; cin >> F2;
	system("cls");
	cout << "Fraction 1 :-\n" << F1;
	cout << "Fraction 2 :-\n" << F2;
	int s = 0;
	for (int opt = 0; opt != -1;)
	{
		opt = Menu();
		if (opt == 0)
		{
			s = 0;
			int val = 0;
			cout << "For which fraction you want to set a value\nPress 1 for F1 OR Press 2 for F2\n";
			cin >> s;
			if (s == 1)
			{
				s = 0;
				cout << "Press 1 for numerator OR Press 2 denominator\n";
				cin >> s;
				if (s == 1)
				{
					cout << "Enter new value of numerator : "; cin >> val;
					F1.setNum(val);
				}
				else if (s == 2)
				{
					cout << "Enter new value of denominator : "; cin >> val;
					F1.setDen(val);
				}
			}
			else if (s == 2)
			{
				s = 0;
				cout << "Press 1 for numerator OR Press 2 denominator\n";
				cin >> s;
				if (s == 1)
				{
					cout << "Enter new value of numerator : "; cin >> val;
					F2.setNum(val);
				}
				else if (s == 2)
				{
					cout << "Enter new value of denominator : "; cin >> val;
					F1.setDen(val);
				}
			}
		}
		else if (opt == 1)
		{
			s = 0;
			int val = 0;
			cout << "For which fraction you want to get a value\nPress 1 for F1 OR Press 2 for F2\n";
			cin >> s;
			if (s == 1)
			{
				s = 0;
				cout << "Press 1 for numerator OR Press 2 denominator\n";
				cin >> s;
				if (s == 1)
				{
					cout << "Value of numerator : " << F1.getNum();
				}
				else if (s == 2)
				{
					cout << "Value of denominator : " << F1.getDen();
				}
			}
			else if (s == 2)
			{
				s = 0;
				cout << "Press 1 for numerator OR Press 2 denominator\n";
				cin >> s;
				if (s == 1)
				{
					cout << "Value of numerator : " << F2.getNum();
				}
				else if (s == 2)
				{
					cout << "Value of denominator : " << F2.getDen();
				}
			}
		}
		else if (opt == 2)
		{
			Fraction Sum;
			Sum = F1 + F2;
			cout << "Sum : " << Sum;
		}
		else if (opt == 3)
		{
			Fraction Product;
			Product = F1 * F2;
			cout << "Product : " << Product;
		}
		else if (opt == 4)
		{
			s = 0;
			cout << "In which fraction you want to make increment / decrement\nPress 1 for F1 OR Press 2 for F2\n";
			cin >> s;
			if (s == 1)
			{
				s = 0;
				cout << "Press 1 for Increment / Press 2 for Decrement\n";
				cin >> s;
				if (s == 1)
				{
					s = 0;
					cout << "Press 1 for Pre-Increment / Press 2 for Post-Increment\n";
					cin >> s;
					if (s == 1)
					{
						++F1;
					}
					else if (s == 2)
					{
						F1++;
					}
				}
				else if (s == 2)
				{
					s = 0;
					cout << "Press 1 for Pre-Decrement / Press 2 for Post-Decrement\n";
					cin >> s;
					if (s == 1)
					{
						--F1;
					}
					else if (s == 2)
					{
						F1--;
					}
				}
			}
			else if (s == 2)
			{
				s = 0;
				cout << "Press 1 for Increment / Press 2 for Decrement\n";
				cin >> s;
				if (s == 1)
				{
					s = 0;
					cout << "Press 1 for Pre-Increment / Press 2 for Post-Increment\n";
					cin >> s;
					if (s == 1)
					{
						++F2;
					}
					else if (s == 2)
					{
						F2++;
					}
				}
				else if (s == 2)
				{
					s = 0;
					cout << "Press 1 for Pre-Decrement / Press 2 for Post-Decrement\n";
					cin >> s;
					if (s == 1)
					{
						--F2;
					}
					else if (s == 2)
					{
						F2--;
					}
				}
			}
		}
		else if (opt == 5)
		{
			if (F1 == F2)
			{
				cout << "Fractions are equal\n";
			}
			else
			{
				cout << "Fractions are not equal\n";
			}
		}
		else if (opt == 6)
		{
			if (F1 > F2)
			{
				cout << "F1 is greater than F2\n";
			}
			else
			{
				cout << "F1 is equal or smaller than F2\n";
			}
		}
		else if (opt == 7)
		{
			s = 0;
			cout << "Which fraction you want to check\nPress 1 for F1 OR Press 2 for F2\n";
			cin >> s;
			if (s == 1)
			{
				if (F1.isProper())
				{
					cout << "F1 is proper fraction\n";
				}
				else
				{
					cout << "F1 is  not proper fraction\n";
				}
			}
			else if (s == 2)
			{
				if (F2.isProper())
				{
					cout << "F2 is proper fraction\n";
				}
				else
				{
					cout << "F2 is not proper fraction\n";
				}
			}
		}
		else if (opt == 8)
		{
			cout << "Total fractions created : " << F2.getCount();
		}
		else if (opt == 9)
		{
			s = 0;
			cout << "Which fraction you want to print\nPress 1 for F1 OR Press 2 for F2\n";
			cin >> s;
			if (s == 1)
			{
				cout << "Fraction 1 : "; F1.show();
			}
			else if (s == 2)
			{
				cout << "Fraction 2 : "; F2.show();
			}
		}
	}
	return 0;
}