#include<iostream>
#include<fstream>
using namespace std;
//------------------------------------------------------------------------------------
int s = 0;                           // * Size maintaing variable
string A[100];                       // * For storing file data
//------------------------------------------------------------------------------------
void WriteReadPrintFile();           // * Writing, Reading, Printing data from file
string boolconvt(int i);             // * For changing '1' & '0' to 'yes' & 'no'
//------------------------------------------------------------------------------------
void impalindrome(int abool[100]);   // * For checking Imperfect-Palindromes
void anagram(int abool[]);           // * For checking Super-Anagrams
//------------------------------------------------------------------------------------
int main()
{
	int Impalin[100];
	int anag[100];
	WriteReadPrintFile();
	impalindrome(Impalin);
	anagram(anag);
	cout << "\n-----------------------\n";
	cout << " O   U   T   P   U   T";
	cout << "\n-----------------------\n";
	for (int j = 0; j < s; j = j + 2)
	{
		cout << boolconvt(Impalin[j]) << "\t";
		cout << boolconvt(Impalin[j + 1]) << "\t";
		cout << boolconvt(anag[j / 2]);
		cout << endl;
	}
	return 0;
}
//-----------------------------------------------------------
void WriteReadPrintFile()
{
	//--------------------
	// Writing on file
	//--------------------
	ofstream fout("file.txt");
	fout << "read dare\nstake takes\ntofu tofu\naabbba aabbaa\none two" << endl;
	//--------------------
	// Reading from file
	//--------------------
	ifstream fin;
	fin.open("file.txt");
	cout << "Data Read From File : " << endl;
	if (fin.is_open())
	{
		for (; !(fin.eof()); s++)
		{
			fin >> A[s];
		}
	}
	else
	{
		cout << "File not found\n";
	}
	//--------------------------------------
	// Printing data after reading the file
	//--------------------------------------
	for (int i = 0; i < s; i = i + 2)
	{
		cout << A[i] << "\t";
		cout << A[i + 1] << "\n";
	}
}
//-----------------------------------------------------------
string boolconvt(int i)
{
	//------------------------------------------------------
	// Recieving '1' & '0' and converting into 'yes' & 'no'
	//------------------------------------------------------
	if (i == 0)
	{
		return "no";
	}
	else if (i == 1)
	{
		return "yes";
	}
}
//-----------------------------------------------------------
void impalindrome(int abool[100])
{
	bool chk = true;
	// cond = conditions, len = length
	int cond = 0, count = 0, len = 0;
	for (int i = 0; i < s; i++)
	{
		len = A[i].size();
		for (int j = 0; j < len; j++)
		{
			if (A[i][j] != A[i][len - j - 1])
			{
				chk = true;
				break;
			}
			else
			{
				chk = false;
			}
		}
		if (chk)
		{
			cond = 0;
			count = 0;
			for (int k = 0; k < len / 2; k++)
			{
				if (A[i][k] != A[i][len - k])
				{
					cond += 2;
					count++;
				}
			}

			if (cond <= 2)
			{
				chk = true;
			}
			else
			{
				chk = false;
			}
		}
		if (chk == true)
		{
			abool[i] = 1;
		}
		else
		{
			abool[i] = 0;
		}
	}
}
//-----------------------------------------------------------
void anagram(int abool[])
{
	bool equal = false, found = false, cons = true;
	int  len = 0, len1 = 0, count1 = 0, count2 = 0, boolcount = 0, val = 0;
	for (int i = 1; i < s; i = i + 2)
	{
		boolcount = (i / 2);
		len = A[i - 1].size();
		len1 = A[i].size();
		int max;
		if (len > len1)
		{
			max = len;
		}
		else
		{
			max = len1;
		}
		val = A[i - 1].size() - A[i].size();
		if (val > 2)
		{
			abool[boolcount] = 0;
			found = false;
			cons = false;
		}
		else if (len == len1)
		{

			for (int j = 0; j < len; j++)
			{
				if (A[i - 1][j] != A[i][j])
				{
					found = false;
					break;
				}
				else
				{
					found = true;
				}
			}
			if (found)
			{
				cons = true;
				abool[boolcount] = 1;
			}
			else
			{
				cons = false;
				abool[boolcount] = 0;
			}

		}
		if (!cons)
		{
			for (int j = 0, k = 0; j < len; j++, k++)
			{
				if (A[i][j] == A[i - 1][k])
				{
					count2++;
				}
				else
				{
					j--;
					count1++;
					if (count1 >= 2)
					{
						break;
					}
				}
			}

			if (count2 == len)
			{
				abool[boolcount] = 0;
			}
			else
			{
				abool[boolcount] = 1;
			}
		}

	}
}
//-----------------------------------------------------------
