// Abdullah Tahir
// 21L-5419
// OOP LAB 
// QUIZ # 1
// l215419@lhr.nu.edu.pk

#include<iostream>
using namespace std;

class Rectangle
{
private:

	int length, breadth;

public:

	Rectangle()
	{
		length = 0;
		breadth = 0;
		int area;
		area = length * breadth;
		cout << "Area : " << area << endl;
	}

	Rectangle(int& a)
	{
		length = a;
		breadth = a;
		int area;
		area = length * breadth;
		cout << "Area : " << area << endl;
	}

	Rectangle(int& a, int& b)
	{
		length = a;
		breadth = b;
		int area;
		area = a * b;
		cout << "Area : " << area << endl;
	}
};

int main()
{
	int a, b;

	cout << "Enter length : ";
	cin >> a;
	cout << "Enter breadth : ";
	cin >> b;

	Rectangle r1();
	Rectangle r2(a);
	Rectangle r3(a, b);

	system("pause");
	return 0;
}
