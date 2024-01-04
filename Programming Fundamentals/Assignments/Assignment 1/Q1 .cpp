#include<iostream>
using namespace std;

int main()
{
	double i, u, p, a, b, c;
	cout << "Enter value of i =";
	cin >> i;
	u = 1.234;
	p = 3.334;
	a = sqrt((u * (i * sqrt(i))) * ((i * i) - 1));   //i*sqrt(i)=i pow 3/2  and a is the numerator of given formula
	b = sqrt((p * i) - 2) + sqrt((p * i) - 1);       //b is denominator of given formula
	c = a / b;                                       //c is the final solution of given formula
	cout << "Solved value of given formula is =" << c << endl;
	return 0;
}
