// Task-3
//---------------------------------------------------------
#include<iostream>
using namespace std;
//---------------------------------------------------------
class Roman
{
private:
    double N1, N2;
public:
    Roman()
    {
        N1 = '0';
        N2 = '0';
    }
    Roman(int n1, int n2);
    int DecimalValueOfRoman(char);
    int RomanToDecimalConverter(string);
    int Addition();
    int Subtraction();
    int Multiplication();
    int Division();
    int RelationalComparison();
    int IncrementDecrement();
    string DecimalToRomanConverter(int);
};
//---------------------------------------------------------
Roman::Roman(int m1, int m2)
{
    N1 = m1;
    N2 = m2;
}
//---------------------------------------------------------
int Roman::DecimalValueOfRoman(char n)
{
    if (n == 'I' || n == 'i')
    {
        return 1;
    }
    else if (n == 'V' || n == 'v')
    {
        return 5;
    }
    else if (n == 'X' || n == 'x')
    {
        return 10;
    }
    else if (n == 'L' || n == 'l')
    {
        return 50;
    }
    else if (n == 'C' || n == 'c')
    {
        return 100;
    }
    else if (n == 'D' || n == 'd')
    {
        return 500;
    }
    else if (n == 'M' || n == 'm')
    {
        return 1000;
    }
    else
    {
        cout << "Invalid Symbol\n";
        return -1;
    }
}
//---------------------------------------------------------
int Roman::RomanToDecimalConverter(string n)
{
    int get = 0;
    for (int i = 0; i < n.length(); i++)
    {
        char a = n[i];
        int n1 = DecimalValueOfRoman(a);

        if (i + 1 < n.length())
        {
            a = n[i + 1];
            int n2 = DecimalValueOfRoman(a);
            if (n1 >= n2)
            {
                get = get + n1;
            }
            else
            {
                get = get + n2 - n1;
                i++;
            }
        }
        else
        {
            get = get + n1;
        }
    }
    return get;
}
//---------------------------------------------------------
int Roman::Addition()
{
    int sum = 0;
    sum = N1 + N2;
    Roman R;
    cout << "Sum of numbers is : " << R.DecimalToRomanConverter(sum);
    cout << endl;
    return 0;
}
//---------------------------------------------------------
int Roman::Subtraction()
{
    int diff = 0;
    Roman R;
    diff = N1 - N2;
    if (diff < 0)
    {
        diff = diff * -1;
        cout << "Difference of numbers is : " << R.DecimalToRomanConverter(diff) << endl;
    }
    else
    {
        cout << "Difference of numbers is : " << R.DecimalToRomanConverter(diff) << endl;
    }
    return 0;
}
//---------------------------------------------------------
int Roman::Multiplication()
{
    int product = 0;
    product = N1 * N2;
    Roman R;
    cout << "Product of numbers is : " << DecimalToRomanConverter(product) << endl;
    return 0;
}
//---------------------------------------------------------
int Roman::Division()
{
    Roman R;
    double division = 0;
    division = N1 / N2;
    cout << "Division of numbers is : " << DecimalToRomanConverter(division) << endl;
    return 0;
}
//---------------------------------------------------------
int Roman::RelationalComparison()
{
    if (N1 == N2)
    {
        cout << "Numbers are equal" << endl;
    }
    else if (N1 != N2)
    {
        cout << "Numbers are not equal" << endl;
    }
    else if (N1 < N2)
    {
        cout << "First numbers is smaller and second is greater" << endl;
    }
    else if (N1 > N2)
    {
        cout << "Second numbers is smaller and first is greater" << endl;
    }
    return 0;
}
//---------------------------------------------------------
int Roman::IncrementDecrement()
{
    int n1 = 0, n2 = 0;
    n1 = N1;
    n2 = N2;
    cout << "Prefix increment of first number is : " << DecimalToRomanConverter(++N1) << " and of second number is :" << DecimalToRomanConverter(++N2) << endl;
    N1++; N2++;
    cout << "Postfix increment of first number is : " << DecimalToRomanConverter(N1) << " and of second number is :" << DecimalToRomanConverter(N2) << endl;
    cout << "Prefix decrement of first number is : " << DecimalToRomanConverter(--N1) << " and of second number is :" << DecimalToRomanConverter(--N1) << endl;
    N1--; N2--;
    cout << "Postfix decrement of first number is : " << DecimalToRomanConverter(N1) << " and of second number is :" << DecimalToRomanConverter(N2) << endl;
    N1 = n1;
    N2 = n2;
    return 0;
}

//---------------------------------------------------------
string Roman::DecimalToRomanConverter(int n)
{
    string RomanNumbers[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    int DecimalValues[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

    string result = "";

    for (int i = 0; i < 13; ++i)
    {
        while (n - DecimalValues[i] >= 0)
        {
            result = result + RomanNumbers[i];
            n = n - DecimalValues[i];
        }
    }

    return result;
}
//---------------------------------------------------------
int main()
{
    cout << "In roman counting :-\nSymbol	I	V	X	L	C	D	M\nValue	1	5	10	50	100	500	1000\n";
    string n1, n2;
    cout << "Enter 1st number : ";
    cin >> n1;
    cout << "Enter 2nd number : ";
    cin >> n2;
    int m1, m2;
    Roman r;
    m1 = r.RomanToDecimalConverter(n1);
    m2 = r.RomanToDecimalConverter(n2);
    cout << "Decimal value of first number : " << m1 << endl;
    cout << "Decimal value of second number : " << m2 << endl;
    Roman R1(m1, m2);
    R1.Addition();
    R1.Subtraction();
    R1.Multiplication();
    R1.Division();
    R1.RelationalComparison();
    R1.IncrementDecrement();
    return 0;
}
//---------------------------------------------------------