#include<iostream>
#include<cstring>
using namespace std;
//--------------------------------------------------------
// Task 1
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
//Task - 2
//--------------------------------------------------------
class String
{
private:
    char* Str;
    char* Compare;
    int Len;
public:
    String();
    String(char[], char[], int);
    void StringLength();
    void StringUpperCase();
    void StringLowerCase();
    char StringAt();
    void SubString();
    void StartingIndexOfSubstring();
    void CompareTwoStrings();
    void Concatenate();
    void Prepend();
    String operator =(const String& S);
    bool operator ==(const String& S);
    bool operator !=(const String& S);
    bool operator <(const String& S);
    bool operator >(const String& S);
    friend ostream& operator << (ostream& out, const String& S);
    friend istream& operator >> (istream& in, String& S);
};
//--------------------------------------------------------
String::String()
{
    Len = 0;
    Str = new char[Len];
    for (int i = 0; i < Len; i++)
    {
        Str[i] = ' ';
    }
    Compare = new char[Len];
    for (int i = 0; i < Len; i++)
    {
        Compare[i] = ' ';
    }
}
//--------------------------------------------------------
String::String(char str[], char comp[], int len)
{
    Len = len;
    Str = new char[Len];
    int i = 0;
    for (; str[i] != '\0'; i++)
    {
        Str[i] = str[i];
    }
    Str[i] = '\0';
    Compare = new char[Len];
    i = 0;
    for (; comp[i] != '\0'; i++)
    {
        Compare[i] = comp[i];
    }
    Compare[i] = '\0';
}
//--------------------------------------------------------
void String::StringLength()
{
    int i = 0;
    int l = 0;
    for (; Str[i] != '\0'; i++) { l++; }
    cout << "Length of string is : " << l << endl;
}
//--------------------------------------------------------
void String::StringUpperCase()
{
    cout << "String in upper case letters : ";
    for (int i = 0; i < Len; i++)
    {
        if (int(Str[i]) > 96 && int(Str[i] < 123))
        {
            cout << char(Str[i] - 32);
        }
        else if (int(Str[i]) > 64 && int(Str[i] < 91))
        {
            cout << char(Str[i]);
        }
    }
    cout << endl;
}
//--------------------------------------------------------
void String::StringLowerCase()
{
    cout << "String in lower case letters : ";
    for (int i = 0; Str[i] != '\0'; i++)
    {
        if (int(Str[i]) > 96 && int(Str[i] < 123))
        {
            cout << char(Str[i]);
        }
        else if (int(Str[i]) > 64 && int(Str[i] < 91))
        {
            cout << char(Str[i] + 32);
        }
    }
    cout << endl;
}
//--------------------------------------------------------
char String::StringAt()
{
    int idx = 0;
    char Char;
    int i = 0;
    while (i < Len)
    {
        cout << "Enter index : ";
        cin >> idx;
        if (idx >= 0 && idx <= Len)
        {
            break;
        }
        else
        {
            cout << "Enter valid index\n";
            i++;
        }
    }
    for (int i = 0; Str[i] != '\0'; i++)
    {
        if (i == idx)
        {
            Char = Str[i];
            cout << "Character at given index is : " << Str[i] << endl;
            return Char;
        }
    }
}
//--------------------------------------------------------
void String::SubString()
{
    int idx = 0, idx0 = 0;
    int i = 0;
    while (i < Len)
    {
        cout << "Enter starting index : ";
        cin >> idx;
        cout << "Enter ending index : ";
        cin >> idx0;
        if ((idx >= 0 && idx <= Len) && (idx0 >= 0 && idx0 <= Len))
        {
            break;
        }
        else
        {
            cout << "Enter valid index\n";
            i++;
        }
    }
    cout << "Substring between given indexes is : ";
    for (int i = 0; Str[i] != '\0'; i++)
    {
        if (i >= idx && i <= idx0)
        {
            cout << Str[i];
        }
    }
    cout << endl;
}
//--------------------------------------------------------
void String::StartingIndexOfSubstring()
{
    string substr;
    cout << "Enter substring : ";
    cin >> substr;
    int temp = 0;
    for (int i = 0; Str[i] != '\0'; i++)
    {
        int j = 0;
        if (Str[i] == substr[j])
        {
            temp = i;
            for (; Str[i] == substr[j];)
            {
                i++;
                j++;
            }
            if (substr[j] == '\0')
            {
                cout << "The starting index of substring is : " << temp;
            }
            else
            {
                i = temp;
                temp = 0;
            }
        }
    }
    if (temp == 0)
    {
        cout << "The substring not found";
    }
    cout << endl;
}
//--------------------------------------------------------
void String::CompareTwoStrings()
{
    int chk = 0;
    for (int i = 0; Str[i] != '\0'; i++)
    {
        if (Str[i] != Compare[i])
        {
            chk++;
        }
    }
    if (chk != 0)
    {
        cout << "Strings are not equal" << endl;
    }
    else
    {
        cout << "Both strings are equal" << endl;
    }
}
//--------------------------------------------------------
void String::Concatenate()
{
    char constr[100] = { ' ' };
    char comp[100] = { ' ' };
    string Comp = " ";
    int ComP = 0;
    float COMP = 0.0;
    cout << "Enter string which is to be concatenated (Character) : ";
    cin >> comp;
    cout << "Enter string which is to be concatenated (String) : ";
    cin >> Comp;
    cout << "Enter string which is to be concatenated (Integer) : ";
    cin >> ComP;
    cout << "Enter string which is to be concatenated (Float) : ";
    cin >> COMP;
    //-----------------------------------------
    int i = 0;
    for (; Str[i] != '\0'; i++)
    {
        constr[i] = Str[i];
    }
    for (int j = 0; comp[j] != '\0'; i++, j++)
    {
        constr[i] = comp[j];
    }
    constr[i] = '\0';
    cout << "Concatenated string with characters : ";
    for (int i = 0; constr[i] != '\0'; i++)
    {
        cout << constr[i];
    }
    cout << endl;
    //-----------------------------------------
    i = 0;
    for (; Str[i] != '\0'; i++)
    {
        constr[i] = Str[i];
    }
    for (int j = 0; Comp[j] != '\0'; i++, j++)
    {
        constr[i] = Comp[j];
    }
    constr[i] = '\0';
    cout << "Concatenated string with string : ";
    for (int i = 0; constr[i] != '\0'; i++)
    {
        cout << constr[i];
    }
    cout << endl;
    //-----------------------------------------
    i = 0;
    for (; Str[i] != '\0'; i++)
    {
        constr[i] = Str[i];
    }
    /*constr[i] = (int)(ComP);
    i++;*/
    constr[i] = '\0';
    cout << "Concatenated string with integer : ";
    for (int i = 0; constr[i] != '\0'; i++)
    {
        cout << constr[i];
    }
    cout << ComP;
    cout << endl;
    //-----------------------------------------
    i = 0;
    for (; Str[i] != '\0'; i++)
    {
        constr[i] = Str[i];
    }
    /* constr[i] = (int)(COMP);
     i++;*/
    constr[i] = '\0';
    cout << "Concatenated string with float : ";
    for (int i = 0; constr[i] != '\0'; i++)
    {
        cout << constr[i];
    }
    cout << COMP;
    cout << endl;
}
//--------------------------------------------------------
void String::Prepend()
{
    char prestr[100] = { ' ' };
    char comp[100] = { ' ' };
    string Comp = " ";
    int ComP = 0;
    float COMP = 0.0;
    cout << "Enter string which is to be prepended (Character) : ";
    cin >> comp;
    cout << "Enter string which is to be prepended (String) : ";
    cin >> Comp;
    cout << "Enter string which is to be prepended (Integer) : ";
    cin >> ComP;
    cout << "Enter string which is to be prepended (Float) : ";
    cin >> COMP;
    //-----------------------------------------
    int i = 0;
    for (; comp[i] != '\0'; i++)
    {
        prestr[i] = comp[i];
    }
    for (int j = 0; Str[j] != '\0'; i++, j++)
    {
        prestr[i] = Str[j];
    }
    prestr[i] = '\0';
    cout << "Prepended string with characters : ";
    for (int i = 0; prestr[i] != '\0'; i++)
    {
        cout << prestr[i];
    }
    cout << endl;
    //-----------------------------------------
    i = 0;
    for (; comp[i] != '\0'; i++)
    {
        prestr[i] = Comp[i];
    }
    for (int j = 0; Str[j] != '\0'; i++, j++)
    {
        prestr[i] = Str[j];
    }
    prestr[i] = '\0';
    cout << "Prepended string with string : ";
    for (int i = 0; prestr[i] != '\0'; i++)
    {
        cout << prestr[i];
    }
    cout << endl;
    //-----------------------------------------
    i = 0;
    /*prestr[i] = (int)(ComP);
    i++;*/
    for (int j = 0; Str[j] != '\0'; i++, j++)
    {
        prestr[i] = Str[j];
    }
    prestr[i] = '\0';
    cout << "Prepended string with integer : ";
    cout << ComP;
    for (int i = 0; prestr[i] != '\0'; i++)
    {
        cout << prestr[i];
    }
    cout << endl;
    //-----------------------------------------
    i = 0;
    /*prestr[i] = (int)(COMP);
    i++;*/
    for (int j = 0; Str[j] != '\0'; i++, j++)
    {
        prestr[i] = Str[j];
    }
    prestr[i] = '\0';
    cout << "Prepended string with float : ";
    cout << COMP;
    for (int i = 0; prestr[i] != '\0'; i++)
    {
        cout << prestr[i];
    }
    cout << endl;
}
//--------------------------------------------------------
String String::operator =(const String& S)
{
    for (int i = 0; S.Str[i] != '\0'; i++)
    {
        Str[i] = S.Str[i];
    }
    cout << "String assigned\n";
    return S;
}
//--------------------------------------------------------
bool String::operator ==(const String& S)
{
    int l = 0, L = 0, chk = 0;
    for (int i = 0; Str[i] != '\0'; i++)
    {
        l++;
    }
    for (int i = 0; Compare[i] != '\0'; i++)
    {
        L++;
    }
    if (l == L)
    {
        for (int i = 0; i < L; i++)
        {
            if (Compare[i] == Str[i])
            {
                continue;
            }
            else
            {
                chk++;
                break;
            }
        }
    }
    else
    {
        return false;
    }
    if (l == L && chk == 0)
    {
        cout << "Strings are equal\n";
        return true;
    }
    else
    {
        return false;
    }
}
//--------------------------------------------------------
bool String::operator !=(const String& S)
{
    int l = 0, L = 0, chk = 0;
    for (int i = 0; Str[i] != '\0'; i++)
    {
        l++;
    }
    for (int i = 0; Compare[i] != '\0'; i++)
    {
        L++;
    }
    if (l == L)
    {
        for (int i = 0; i < L; i++)
        {
            if (Compare[i] == Str[i])
            {
                continue;
            }
            else
            {
                chk++;
                break;
            }
        }
    }
    else
    {
        cout << "Strings are not equal\n";
        return false;
    }
    if (l == L && chk == 0)
    {
        return true;
    }
    else
    {
        cout << "Strings are not equal\n";
        return false;
    }
}
//--------------------------------------------------------
bool String::operator <(const String& S)
{
    int l = 0, L = 0, chk = 0;
    for (int i = 0; Str[i] != '\0'; i++)
    {
        l++;
    }
    for (int i = 0; Compare[i] != '\0'; i++)
    {
        L++;
    }
    if (l < L)
    {
        cout << "New string is greater than previous one\n";
        return true;
    }
    else
    {
        return false;
    }
}
//--------------------------------------------------------
bool String::operator >(const String& S)
{
    int l = 0, L = 0, chk = 0;
    for (int i = 0; Str[i] != '\0'; i++)
    {
        l++;
    }
    for (int i = 0; Compare[i] != '\0'; i++)
    {
        L++;
    }
    if (l > L)
    {
        cout << "New string is smaller than previous one\n";
        return true;
    }
    else
    {
        return false;
    }
}
//--------------------------------------------------------
istream& operator >> (istream& in, String& S)
{
    cout << "Enter string : ";
    cin.getline(S.Str, 100);
    return in;
}
//--------------------------------------------------------
ostream& operator << (ostream& out, const String& S)
{
    out << "String is : ";
    out << S.Str;
    return out;
}
//--------------------------------------------------------
// Task-3
//--------------------------------------------------------
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
    int Addition();
    int Subtraction();
    int Multiplication();
    int Division();
    int RelationalComparison();
    int IncrementDecrement();
    string DecimalToRomanConverter(int);
};
//--------------------------------------------------------
Roman::Roman(int m1, int m2)
{
    N1 = m1;
    N2 = m2;
}

//--------------------------------------------------------
int Roman::Addition()
{
    int sum = 0;
    sum = N1 + N2;
    Roman R;
    cout << "Sum of numbers is : " << R.DecimalToRomanConverter(sum);
    cout << endl;
    return 0;
}
//--------------------------------------------------------
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
//--------------------------------------------------------
int Roman::Multiplication()
{
    int product = 0;
    product = N1 * N2;
    Roman R;
    cout << "Product of numbers is : " << DecimalToRomanConverter(product) << endl;
    return 0;
}
//--------------------------------------------------------
int Roman::Division()
{
    Roman R;
    double division = 0;
    division = N1 / N2;
    cout << "Division of numbers is : " << DecimalToRomanConverter(division) << endl;
    return 0;
}
//--------------------------------------------------------
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
//--------------------------------------------------------
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

//--------------------------------------------------------
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
//-------------------------------------------------------
int Menu()
{
	int Option;
	cout << "Select any option :-\nPress 1 for task 1\nPress 2 for task 2\nPress 3 for task 3\nEnter your selection : ";
    cin >> Option;
    if (Option==1|| Option == 2|| Option == 3)
    {
        return Option;
    }
    while (Option < 1 || Option > 3)
    {
        cout << "Select right option : ";
        cin >> Option;
    }
	return Option;
}
//-------------------------------------------------------
int main()
{
	int Option;
    again:
	Option = Menu();
	if (Option == 1)
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
	}
	else if(Option == 2)
	{
        char str[100];
        char comp[100];
        cin.ignore();
        cout << "Enter a string : ";
        cin.getline(str, 100);
        cin.ignore();
        cout << "Enter string to be compared : ";
        cin.getline(comp, 100);
        String S(str, comp, 100);
        S.StringLength();
        S.StringUpperCase();
        S.StringLowerCase();
        S.StringAt();
        S.SubString();
        S.StartingIndexOfSubstring();
        S.CompareTwoStrings();
        S.Concatenate();
        S.Prepend();
        S.operator=(S);
        S.operator==(S);
        S.operator!=(S);
        S.operator<(S);
        S.operator>(S);
        cin.ignore();
        cin >> S;
        cout << S << endl;
	}
	else if (Option == 3)
	{
        cout << "In roman counting :-\nSymbol	I	V	X	L	C	D	M\nValue	1	5	10	50	100	500	1000\n";
        int n1, n2;
        cout << "Enter 1st number : ";
        cin >> n1;
        cout << "Enter 2nd number : ";
        cin >> n2;
        string m1, m2;
        Roman r;
        m1 = r.DecimalToRomanConverter(n1);
        m2 = r.DecimalToRomanConverter(n2);
        cout << "Roman value of first number : " << m1 << endl;
        cout << "Roman value of second number : " << m2 << endl;
        Roman R1(n1, n2);
        R1.Addition();
        R1.Subtraction();
        R1.Multiplication();
        R1.Division();
        R1.RelationalComparison();
        R1.IncrementDecrement();
	}
    int repeat;
    cout << "Press 1 to quit\nPress any other number to continue\nEnter your choice : ";
    cin >> repeat;
    if (repeat==1)
    {
        return 0;
    }
    else
    {
        system("cls");
        goto again;
        /*Menu();*/
    }
}
//-------------------------------------------------------