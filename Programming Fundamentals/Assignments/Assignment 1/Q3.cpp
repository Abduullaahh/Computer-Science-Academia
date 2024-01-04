#include<iostream>
using namespace std;

int main()
{
	int a, b, Years, Months, Days;
	cout << "Enter number of days=";
	cin >> a;                      //a is given number of days
	Years = a / 365;
	b = { a - (Years * 365) };     //b are the remaining days after calculating years
	Months = b / 30;
	Days = { b - (Months * 30) };    //Days are the remaining days after calculating years and months
	cout << "Years=" << Years << endl << "Months=" << Months << endl << "Days=" << Days << endl;
	return 0;
}
