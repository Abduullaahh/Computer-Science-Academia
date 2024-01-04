//Task - 2
//----------------------------------------------------------------
#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;
//----------------------------------------------------------------
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
//----------------------------------------------------------------
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
//----------------------------------------------------------------
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
//----------------------------------------------------------------
void String::StringLength()
{
    int i = 0;
    int l = 0;
    for (; Str[i] != '\0'; i++) { l++; }
    cout << "Length of string is : " << l << endl;
}
//----------------------------------------------------------------
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
//----------------------------------------------------------------
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
//----------------------------------------------------------------
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
//----------------------------------------------------------------
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
//----------------------------------------------------------------
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
//----------------------------------------------------------------
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
//----------------------------------------------------------------
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
//----------------------------------------------------------------
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
//----------------------------------------------------------------
String String::operator =(const String& S)
{
    for (int i = 0; S.Str[i] != '\0'; i++)
    {
        Str[i] = S.Str[i];
    }
    cout << "String assigned\n";
    return S;
}
//----------------------------------------------------------------
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
//----------------------------------------------------------------
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
//----------------------------------------------------------------
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
//----------------------------------------------------------------
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
//----------------------------------------------------------------
istream& operator >> (istream& in, String& S)
{
    cout << "Enter string : ";
    cin.getline(S.Str, 100);
    return in;
}
//----------------------------------------------------------------
ostream& operator << (ostream& out, const String& S)
{
    out << "String is : ";
    out << S.Str;
    return out;
}
//----------------------------------------------------------------
int main()
{
    char str[100];
    char comp[100];
    cout << "Enter a string : ";
    cin.getline(str, 100);
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
    cout << S;
    return 0;
}
//----------------------------------------------------------------