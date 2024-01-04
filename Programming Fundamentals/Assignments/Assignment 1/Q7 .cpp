#include<iostream>
using namespace std;

int main()
{
	double a, π, r, A, L, W, B, H;                     //r=radius , A=area , L=length , W=width , B=base , H=height
	cout << "1-For area of circle enter a=1" << endl;
	cout << "2-For area of regtangular enter a=2" << endl;
	cout << "3-For area of triangle enter a=3" << endl;
	cout << "Enter value of a" << endl;
	cin >> a;
	if (a == 1)                                        //if a is 1 then area of circle
	{
		cout << "enter radius of the circle=" << endl;
		cin >> r;
		π = 3.14159;
		A = π * (r * r);                               //A= area of circle
		cout << "Area of circle is= " << A << endl;
	}
	else if (a == 2)                                   //if a is 2 then area of retangular
	{
		cout << "enter Length of regtangular=" << endl;
		cin >> L;
		cout << "enter Width of regtangular=" << endl;
		cin >> W;
		A = L * W;                                      //A= area of regtangular
		cout << "Area of regtangular is=" << A << endl;
	}
	else if (a == 3)                                    //if a 3 then area of triangle
	{
		cout << "enter Base of triangle=" << endl;
		cin >> B;
		cout << "enter Height of triangle=" << endl;
		cin >> H;
		A = 0.5 * B * H;                                 //A= area of triangle
		cout << "Area of triangle is=" << A << endl;
	}
	if (a >= 4)
	{
		cout << exit;
	}
	return 0;
}
