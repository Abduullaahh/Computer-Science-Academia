#include<iostream>
using namespace std;

int main()
{
	int a, b;
	cout << "Enter a number" << endl;
	cin >> a;
	cout << "Enter a number" << endl;
	cin >> b;
	a = a + b;
	b = a - b;
	a = a - b;
	cout << "First number is a=" << a << endl << "Second number is b=" << b << endl;
	return 0;
}
