//Abdullah Tahir
//Roll : 21L-5419 , Section : 1J
//PF Assignment # 1 , Question#5(2)

#include<iostream>
using namespace std;

int main()
{
	int a, b;
	cout << "Enter first number" << endl;
	cin >> a;
	cout << "Enter second number" << endl;
	cin >> b;
	a = a * b;
	b = a / b;
	a = a / b;
	cout << "First number is a=" << a << endl << "Second number is b=" << b << endl;
	return 0;
}