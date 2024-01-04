# include<iostream>
using namespace std;
//-------------------------------------------
void Question1();
int c[20], s = 0;
void Insert();
void Delete();
void Update();
//-------------------------------------------
void Question2();
int a[10], b[10];
void Union();
void Intersection();
//-------------------------------------------
int main()
{
	int op;
	cout << "Press 1 for question 1 \nPress 2 for question 2\n";
	cin >> op;
	if (op == 1)
	{
		Question1();
	}
	else if (op == 2)
	{
		Question2();
	}
	return 0;
}
//-------------------------------------------
void Question1()
{
	int op;
	cout << "Press 1 for Insertion\n";
	cout << "Press 2 for Deletion\n";
	cout << "Press 3 for Update\n";
	cout << "Press 4 to quit\n";
	cin >> op;
	if (op == 1)
		Insert();
	else if (op == 2)
		Delete();
	else if (op == 3)
		Update();
	else if (op == 4)
		exit;
	else
	{
		system("cls");
		cout << "Select right option\n";
		Question1();
	}
}
void Insert()
{
	int n, min, temp;
	cout << "Enter number : ";
	cin >> n;
	for (int k = 0; k < 20; k++)
	{
		if (c[k] == 0)
		{
			s++;
			c[k] = n;
			for (int i = 0; i < s; i++)
			{
				for (int j = i + 1; j < s; j++)
				{
					if (c[i] > c[j])
					{
						temp = c[i];
						c[i] = c[j];
						c[j] = temp;
					}
				}
			}
			break;
		}
		else
		{
			if (k == 19)
			{
				cout << "Array is full\n";
				break;
			}
			continue;
		}
		cout << "Inserted\n";

	}
	for (int i = 0; i < s; i++)
	{
		cout << c[i] << "\t";
	}
	cout << endl << "s = " << s << endl;
	Question1();
}
void Delete()
{
	int n, chk = 0;
	cout << "Enter number to delete : ";
	cin >> n;
	for (int i = 0; i < 20; i++)
	{
		if (c[i] == n)
		{// j = i because array is updated next to deleted element
			for (int j = i; j < 19; j++)
			{
				c[j] = c[j + 1];
			}
			chk++;
			s--;
			break;
		}
	}
	if (chk == 0)
	{
		cout << "\nElement not found\n";
	}
	else
	{
		cout << "\nDeleted\n";
		cout << "\nNew array is :\n";
		for (int i = 0; i < 19; i++)
		{
			if (c[i] != 0)
				cout << c[i] << "\t";
		}
	}
	cout << endl << "s = " << s << endl;
	Question1();
}
void Update()
{
	int n, up, chk = 0;
	cout << "Enter number to be updated : ";
	cin >> n;
	cout << "Enter the updated number : ";
	cin >> up;
	for (int i = 0; i < 20; i++)
	{
		if (c[i] == n)
		{
			c[i] = up;
			chk++;
			break;
		}
	}
	if (chk == 0)
	{
		cout << "\nElement not found\n";
	}
	else
	{
		cout << "\nUpdated\n";
		cout << "\nUpdated array is :\n";
		for (int i = 0; i < 20; i++)
		{
			if (c[i] != 0)
				cout << c[i] << "\t";
		}
	}
	cout << endl;
	Question1();
}
//-------------------------------------------
void Question2()
{
	cout << "Enter values of array 1\n";
	cout << "NOTE : A set can not have repeated elements \n";
	for (int i = 0; i < 10; i++)
	{
		cout << "Value no. " << i + 1 << " = ";
		cin >> a[i];
	}
	cout << endl;
	cout << "Enter values of array 2\n";
	for (int i = 0; i < 10; i++)
	{
		cout << "Value no. " << i + 1 << " = ";
		cin >> b[i];
	}
	cout << endl;
	Union();
	Intersection();
}
void Union()
{

	cout << "Union of arrays is : ";
	int union1[20];
	for (int i = 0; i < 10; i++)
	{
		union1[i] = a[i];
	}
	int count = 0;
	int check = 0;
	count = 10;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < count; j++)
		{
			if (b[i] != union1[j])
			{
				check = 0;
			}
			else
			{
				check = 1;
				break;
			}
		}
		if (check == 0)
		{
			union1[count] = b[i];
			count += 1;
		}
	}
	for (int i = 0; i < count; i++)
	{
		cout << union1[i] << "    ";
	}
	cout << endl;
}
void Intersection()
{
	int intsec[10];
	cout << "Intersection of arrays is : ";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (a[i] == b[j])
			{
				intsec[i] = a[i];
				cout << intsec[i] << "    ";
			}
		}
	}
}
//-------------------------------------------55
