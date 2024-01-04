#include<iostream>
using namespace std;

int main()
{
	int a, b, Inches, Feets, Yards;
	cout << "Enter number of Inches=" << endl;
	cin >> a;                                  //a is given number of inches
	Yards = a / 36;
	b = a - (Yards * 36);                 //b is the remaining number of inches after calculating yards
	Feets = b / 12;
	Inches = b - (Feets * 12);                 //Inches remaining after calculating yards and feets
	cout << "Yards=" << Yards << endl << "Feets=" << Feets << endl << "Inches=" << Inches << endl;
	return 0;
}
