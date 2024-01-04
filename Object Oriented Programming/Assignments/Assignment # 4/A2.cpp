#include<iostream>
using namespace std;

class ComplexNumber
{
private:
	int real;
	int imaginary;
public:
	ComplexNumber()
	{
		real = 0; imaginary = 0;
	}

	ComplexNumber(int a, int b);

	~ComplexNumber()
	{
		//Does Nothing.
	}
	void Input();
	void Output();
	bool IsEqual(ComplexNumber);
	ComplexNumber Conjugate();
	ComplexNumber Add(ComplexNumber);
	ComplexNumber Subtract(ComplexNumber);
	ComplexNumber Multiplication(ComplexNumber);
	float Magnitude();
};

ComplexNumber::ComplexNumber(int a, int b)
{
	real = a;
	imaginary = b;
}

void ComplexNumber::Input()
{
	cout << "Enter Real : ";
	cin >> real;
	cout << "Enter Imaginary : ";
	cin >> imaginary;
	cout << endl;
}

void ComplexNumber::Output()
{

	if (imaginary >= 0)
	{
		cout << real << " + " << imaginary << "i\n\n";
	}
	else if (imaginary < 0)
	{
		cout << real << " - " << imaginary * (-1) << "i\n\n";
	}
}

bool ComplexNumber::IsEqual(ComplexNumber const C)
{
	if (C.real == real && C.imaginary == imaginary)
	{
		return true;
	}
	else
	{
		return false;
	}
}

ComplexNumber ComplexNumber::Conjugate()
{
	if (imaginary >= 0)
	{
		cout << real << " - " << imaginary << "i\n\n";
	}
	else if (imaginary < 0)
	{
		cout << real << " + " << imaginary * (-1) << "i\n\n";
	}
	ComplexNumber temp;
	return temp;
}

ComplexNumber ComplexNumber::Add(ComplexNumber const C)
{
	ComplexNumber temp;
	temp.real = real + C.real;
	temp.imaginary = imaginary + C.imaginary;
	if (temp.imaginary >= 0)
		cout << "c1 + c2 = " << temp.real << " + " << temp.imaginary << "i\n\n";
	if (temp.imaginary < 0)
		cout << "c1 + c2 = " << temp.real << " - " << temp.imaginary * (-1) << "i\n\n";
	return temp;
}

ComplexNumber ComplexNumber::Subtract(ComplexNumber const C)
{
	ComplexNumber temp;
	temp.real = real - C.real;
	temp.imaginary = imaginary - C.imaginary;
	if (temp.imaginary >= 0)
		cout << "c1 - c2 = " << temp.real << " + " << temp.imaginary << "i\n\n";
	if (temp.imaginary < 0)
		cout << "c1 - c2 = " << temp.real << " - " << temp.imaginary * (-1) << "i\n\n";
	return temp;
}

ComplexNumber ComplexNumber::Multiplication(ComplexNumber const C)
{
	ComplexNumber temp;
	temp.real = real * C.real;
	temp.imaginary = imaginary * C.imaginary;
	if (temp.imaginary >= 0)
		cout << "c1 * c2 = " << temp.real << " + " << temp.imaginary << "i\n\n";
	if (temp.imaginary < 0)
		cout << "c1 * c2 = " << temp.real << " - " << temp.imaginary * (-1) << "i\n\n";
	return temp;
}

float ComplexNumber::Magnitude()
{
	float magnitude;
	magnitude = sqrt((real * real) + (imaginary * imaginary));
	cout << magnitude << endl << endl;
	return 0;
}

int main()
{
	int a = 0, b = 0;
	ComplexNumber c1;
	ComplexNumber c(a, b);
	cout << "Enter c1 :-\n";
	c.Input();
	cout << "Enter c2 :-\n";
	c1.Input();
	cout << "c1 = ";
	c.Output();
	cout << "c2 = ";
	c1.Output();
	cout << "Conjugate of c1 = ";
	c.Conjugate();
	cout << "Conjugate of c2 = ";
	c1.Conjugate();
	bool A;
	A = c.IsEqual(c1);
	if (A)
	{
		cout << "c1 is equal to c2.\n\n";
	}
	else
	{
		cout << "c1 is not equal to c2.\n\n";
	}
	c.Add(c1);
	c.Subtract(c1);
	c.Multiplication(c1);
	cout << "Magnitude of c1 : ";
	c.Magnitude();
	cout << "Magnitude of c2 : ";
	c1.Magnitude();
	c.~ComplexNumber();
	return 0;
}