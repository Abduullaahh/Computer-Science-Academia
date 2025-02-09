// Task 1
//--------------------------------------------------------
#include<iostream>
#include<cmath>
using namespace std;
//--------------------------------------------------------
double product;
//--------------------------------------------------------
class VectorType
{
private:
	double* x;
	double* y;
	double* z;
public:
	VectorType();
	VectorType(double, double, double);
	VectorType(const VectorType& V);
	VectorType operator* (const VectorType& V);
	double Length(const VectorType& V);
	void Angle(double& V, double& U);
	VectorType operator +(const VectorType& V);
	VectorType operator -(const VectorType& V);
	VectorType operator ++();
	VectorType operator --();
	VectorType operator ==(const VectorType& V);
	VectorType operator !=(const VectorType& V);
	friend ostream& operator << (ostream& out, const VectorType& c);
	friend istream& operator >> (istream& in, VectorType& c);
	~VectorType();
};
//--------------------------------------------------------
VectorType::VectorType()
{
	x = new double;
	y = new double;
	z = new double;
	x = 0;
	y = 0;
	z = 0;
}
//--------------------------------------------------------
VectorType::VectorType(double a, double b, double c)
{
	x = new double;
	y = new double;
	z = new double;
	*x = a;
	*y = b;
	*z = c;
}
//--------------------------------------------------------
VectorType::VectorType(const VectorType& V)
{
	x = new double;
	y = new double;
	z = new double;
	*x = *V.x;
	*y = *V.y;
	*z = *V.z;
}
//--------------------------------------------------------
VectorType VectorType::operator* (const VectorType& V)
{
	double X, Y, Z;
	X = *x * (*V.x);
	Y = *y * (*V.y);
	Z = *z * (*V.z);
	product = X + Y + Z;
	cout << "Dot Product of vectors is : " << product << endl;
	return *this;
}
//--------------------------------------------------------
double VectorType::Length(const VectorType& V)
{
	static int n = 1, length = 0;
	length = sqrt((*x * (*x)) + (*y * (*y)) + (*z * (*z)));
	if (n == 1)
	{
		cout << "Length of vector V : " << length << endl;
	}
	else if (n == 2)
	{
		cout << "Length of vector U : " << length << endl;
	}
	n++;
	return length;
}
//--------------------------------------------------------
void VectorType::Angle(double& V, double& U)
{
	double angle = 0;
	double LenPro = 0;
	LenPro = V * U;
	double ang = product / LenPro;
	angle = acos(ang);
	cout << "Angle between vector V and U is : " << angle << endl;
}
//--------------------------------------------------------
VectorType VectorType::operator +(const VectorType& V)
{
	double X, Y, Z;
	X = *x + (*V.x);
	Y = *y + (*V.y);
	Z = *z + (*V.z);
	cout << "Sum of vectors is : " << X << " i + (" << Y << ") j + (" << Z << ") k" << endl;
	return *this;
}
//--------------------------------------------------------
VectorType VectorType:: operator -(const VectorType& V)
{
	double X, Y, Z;
	X = *x - (*V.x);
	Y = *y - (*V.y);
	Z = *z - (*V.z);
	cout << "Difference of vectors is : " << X << " i + (" << Y << ") j + (" << Z << ") k" << endl;
	return *this;
}
//--------------------------------------------------------
VectorType VectorType::operator ++()
{

	static int v = 1;
	++(*x); ++(*y); ++(*z);
	cout << "Pre increment for vector " << v << " : " << *x << " i + (" << *y << ") j + (" << *z << ") k" << endl;
	(*x)++; (*y)++; (*z)++;
	cout << "Post increment for vector " << v << " : " << *x << " i + (" << *y << ") j + (" << *z << ") k" << endl;
	v++;
	return *this;
}
//--------------------------------------------------------
VectorType VectorType::operator --()
{
	static int u = 1;
	--(*x); --(*y); --(*z);
	cout << "Post discrement for vector " << u << " : " << *x << " i + (" << *y << ") j + (" << *z << ") k" << endl;
	(*x)--; (*y)--; (*z)--;
	cout << "Pre discrement for vector " << u << " : " << *x << " i + (" << *y << ") j + (" << *z << ") k" << endl;
	u++;
	return *this;
}
//--------------------------------------------------------
VectorType VectorType::operator ==(const VectorType& V)
{
	if (*x == *V.x && *y == *V.y && *z == *V.z)
	{
		cout << "Vectors are equal\n";
	}
	return *this;
}
//--------------------------------------------------------
VectorType  VectorType::operator !=(const VectorType& V)
{
	if (*x != *V.x || *y != *V.y || *z != *V.z)
	{
		cout << "Vectors are not equal\n";
	}
	return *this;
}
//--------------------------------------------------------
istream& operator >> (istream& in, VectorType& V)
{
	cout << "x : ";
	in >> *V.x;
	cout << "y : ";
	in >> *V.y;
	cout << "z : ";
	in >> *V.z;
	return in;
}
//--------------------------------------------------------
ostream& operator << (ostream& out, const VectorType& V)
{
	out << "\n\tVector V = " << *V.x << " i + (" << *V.y << ") j + (" << *V.z << ") k\n";
	return out;
}
//--------------------------------------------------------
VectorType::~VectorType()
{
	delete x, y, z;
}
//--------------------------------------------------------
int main()
{
	VectorType V();
	double a, b, c, d, e, f;
	cout << "Enter first vector V\n";
	cout << "x : ";
	cin >> a;
	cout << "y : ";
	cin >> b;
	cout << "z : ";
	cin >> c;
	cout << "\n\tVector V = " << a << " i + (" << b << ") j + (" << c << ") k\n";
	VectorType V1(a, b, c);
	cout << "\nEnter second vector U\n";
	cout << "x : ";
	cin >> d;
	cout << "y : ";
	cin >> e;
	cout << "z : ";
	cin >> f;
	cout << "\n\tVector U = " << d << " i + (" << e << ") j + (" << f << ") k\n\n";
	VectorType V2(d, e, f);
	V1* V2;
	double L1 = 0, L2 = 0;
	L1 = V1.Length(V1);
	L2 = V2.Length(V2);
	V1.Angle(L1, L2);
	V1 + V2;
	V1 - V2;
	V1.operator++();
	V1.operator--();
	V2.operator++();
	V2.operator--();
	V1 == V2;
	V1 != V2;
	cout << "Vector V :-\n";
	cin >> V1;
	cout << "Vector U :-\n";
	cin >> V2;
	cout << "\nVector V : " << V1;
	cout << "Vector U : " << V2;
	return 0;
}