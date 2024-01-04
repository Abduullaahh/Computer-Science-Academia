// Abdullah Tahir
// 21L-5419
// OOP LAB 
// QUIZ # 1
// l215419@lhr.nu.edu.pk

#include<iostream>
using namespace std;

//char **Generate_system(char **Seating_Plan, int &rows, int &cols);
void **Reserved_Ticket(char **Seating_Plan, int &rows, int &cols);
void Show_Record(char **Seating_Plan, int &rows, int &cols);

int F1 = 0, B1 = 0, E1 = 0;

int main()
{
	int rows, cols;
	cout << "Enter no. 0f rows : ";
	cin >> rows;
	cout << "Enter no. 0f rows : ";
	cin >> cols;
	char **Seating_Plan;
	Seating_Plan = new char*[rows];
	for (int i = 0; i < cols; i++)
	{
		Seating_Plan[i] = new char[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Seating_Plan[i][j] = '*';
		}
	}
	cout << "\nA	B	C	D	E	F\n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			cout << Seating_Plan[i][j] << "	";
		}
		cout << endl;
	}
	/*Generate_system(Seating_Plan, rows, cols);*/
	Reserved_Ticket(Seating_Plan, rows, cols);
	Show_Record(Seating_Plan, rows, cols);
	system("pause");
	return 0;
}

//char **Generate_system(char **Seating_Plan, int &rows, int &cols)
//{
//	Seating_Plan = new char*[rows];
//	for (int i = 0; i < rows; i++)
//	{
//		Seating_Plan[i] = new char[cols];
//
//		for (int j = 0; j < rows; j++)
//		{
//			Seating_Plan[i][j] = 'X';
//		}
//	}
//	return 0;
//}

void **Reserved_Ticket(char **Seating_Plan, int &rows, int &cols)
{
	char option;
	int floor, room;
	for (int i = 0; i < 1;)
	{
		cout << "Select an option\n > Press F for first class\n > Press B for business class\n > Press E for economy class\n";
		cin >> option;
		if (option == 'F' || option == 'f' || option == 'B' || option == 'b' || option == 'E' || option == 'e')
		{
			if (option == 'F' || option == 'f')
			{

				cout << "Floor 1 & 0\nEnter the room you want to reserve \n ";
				cout << "Enter floor no. : ";
				cin >> floor;
				cout << "Enter room no. : ";
				cin >> room;
				Seating_Plan[floor][room] = 'X';
				F1++;


			}
			else if (option == 'B' || option == 'b')
			{
				cout << "Floor 3 & 2\nEnter the room you want to reserve \n ";
				cout << "Enter floor no. : ";
				cin >> floor;
				cout << "Enter room no. : ";
				cin >> room;
				Seating_Plan[floor][room] = 'X';
				B1++;


			}
			else if (option == 'E' || option == 'e')
			{
				cout << "Floor 5 & 4\nEnter the room you want to reserve \n ";
				cout << "Enter floor no. : ";
				cin >> floor;
				cout << "Enter room no. : ";
				cin >> room;
				Seating_Plan[floor][room] = 'X';
				E1++;
			}
		}
		else
		{
			continue;
		}
		cout << "To reserve more rooms..... Press 1 else 0 : ";
		int z;
		cin >> z;
		if (z == 1)
		{
			continue;
		}
		else
		{
			break;
		}
	}
	return 0;
}

void Show_Record(char **Seating_Plan, int &rows, int &cols)
{
	cout << "\nA	B	C	D	E	F\n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << Seating_Plan[i][j] << "	";
		}
		cout << endl;
	}
	cout << "\nSeats reserved in first class floors : " << F1;
	cout << "\nSeats reserved in first class floors : " << B1;
	cout << "\nSeats reserved in first class floors : " << E1;
	cout << endl;
}