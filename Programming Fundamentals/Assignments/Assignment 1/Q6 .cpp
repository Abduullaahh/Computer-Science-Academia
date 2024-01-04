#include<iostream>
using namespace std;

int main()
{
	int  a, b, c;
	cout << "Enter purchased quantity =" << endl;
	cin >> a;                                                     //a is purchased quantity
	b = a * 100;                                                  //b is the cost of purchased quantity
	if (b > 1000)
	{
		c = b - (b / 10);                                         //c is the cost after discount 
	}
	else
	{
		c = b;                                                    //here c = b is total cost without discount 
		cout << " Total Cost is=" << b << endl;
	}
	return 0;
}
