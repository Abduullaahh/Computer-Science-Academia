#include<iostream>
using namespace std;

int main()
{
	char x, y;
	cout << "Enter any character" << endl;
	cin >> x;                                //x is character entered by the user
	y = x + 3;                               //y is the 3rd next character of x
	cout << "3rd next character is" << endl << y << endl;
	return 0;
}
