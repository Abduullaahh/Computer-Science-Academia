#include<iostream>
#include "Circle.h"
using namespace std;

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
	cout << "Point() called\n";
}

void Point::print()
{
	cout << "(" << x << ", " << y << ")";
}

Point::~Point()
{
	cout << "~Point() called\n";
}

Circle::Circle(int x, int y, float r) : center(x, y)
{
	radius = r;
	cout << "Circle() called\n";
}

Circle:: ~Circle()
{
	cout << "~Circle() called\n";
}

void Circle::print()
{
	cout << "Center: ";
	center.print();
	cout << endl;
	cout << "Radius: " << radius << endl;
}

int main()
{
	int x, y;
	float r;
	cout << "Enter value of x : ";
	cin >> x;
	cout << "Enter value of y : ";
	cin >> y;
	cout << "Enter value of radius : ";
	cin >> r;
	Circle c(x, y, r);
	c.print();
	return 0;
}