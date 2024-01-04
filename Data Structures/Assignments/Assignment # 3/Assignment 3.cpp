#include<iostream>
#include<string>
using namespace std;

class Library_AVL
{
	class Node
	{
	public:
		int ISSN;
		string Title;
		int List_of_Authors;
		int Reference_Copies;
		int Issuable_Copies;
		string* Names;
		Node* Next;
		Node* Previous;
		Node operator=(const Node& a)
		{
			ISSN = a.ISSN;
			Issuable_Copies = a.Issuable_Copies;
			Title = a.Title;
			Reference_Copies = a.Reference_Copies;
			List_of_Authors = a.List_of_Authors;
			if (Names != nullptr)
			{
				delete[]Names;
			}
			Names = new string[List_of_Authors];
			for (int i = 0; i < List_of_Authors; i++)
			{
				Names[i] = a.Names[i];
			}
			return *this;
		}
	};
	class B_Node
	{
	public:
		int Data;
		Node* Pointer;
		B_Node* Left;
		B_Node* Right;
		int Height;
	};
	B_Node* Root;

public:
	//-------------------------------------------
	Library_AVL()
	{
		Root = nullptr;
	}
	//-------------------------------------------
	void Rotate_Left(B_Node*& x)
	{
		B_Node* y = x->Right;
		x->Right = y->Left;
		y->Left = x;
		x->Height = 1 + Max(Get_Height(x->Left), Get_Height(x->Right));
		y->Height = 1 + Max(x->Height, Get_Height(y->Right));
		x = y;
	}
	//-------------------------------------------
	void Double_Rotate_Left(B_Node*& x)
	{
		Rotate_Right(x->Right);
		Rotate_Left(x);
	}
	//-------------------------------------------
	void Rotate_Right(B_Node*& x)
	{
		B_Node* y = x->Left;
		x->Left = y->Right;
		y->Right = x;
		x->Height = 1 + Max(Get_Height(x->Left), Get_Height(x->Right));
		y->Height = 1 + Max(x->Height, Get_Height(y->Left));
		x = y;
	}
	//-------------------------------------------
	void Double_Rotate_Right(B_Node*& x)
	{
		Rotate_Left(x->Left);
		Rotate_Right(x);
	}
	//-------------------------------------------
	int Get_Height(B_Node* r)
	{
		if (r == nullptr)
		{
			return -1;
		}
		else
		{
			return r->Height;
		}
	}
	//-------------------------------------------
	int Max(int x, int y)
	{
		if (x > y)
		{
			return x;
		}
		else
		{
			return y;
		}
	}
	//-------------------------------------------
	Node Find_Minimum(B_Node* r)
	{
		if (r->Left == nullptr)
		{
			return *(r->Pointer);
		}
		return Find_Minimum(r->Left);
	}
	//-------------------------------------------
	int Balance_Factor(B_Node* r)
	{
		int h = Get_Height(r->Left) - Get_Height(r->Right);
		return h;
	}
	//-------------------------------------------
	void Insert_Wrapper()
	{
		int ISSN; cout << "Enter ISSN: "; cin >> ISSN;
		Insert(Root, nullptr, ISSN);
	}
	//-------------------------------------------
	void Insert_Main(Node*& x)
	{
		cin.ignore(); cout << "Enter Title : "; getline(cin, x->Title);
		cout << "Enter number of authors : "; cin >> x->List_of_Authors;
		cout << "Enter authors name\n";  x->Names = new string[x->List_of_Authors];
		cin.ignore();
		for (int i = 0; i < x->List_of_Authors; i++)
		{
			cout << "Author " << i + 1 << " : ";
			getline(cin, x->Names[i]);
		}
		cout << "Enter number of Reference Books : ";
		cin >> x->Reference_Copies;
		cout << "Enter number of Issuable Books : ";
		cin >> x->Issuable_Copies;
	}
	//-------------------------------------------
	void Insert(B_Node*& r, Node* x, int data)
	{
		if (r == nullptr)
		{
			Node* temp = new Node;
			temp->ISSN = data;
			if (x == nullptr)
			{
				temp->Next = nullptr;
				temp->Previous = nullptr;
			}
			else
			{
				if (data > x->ISSN)
				{
					temp->Previous = x;
					temp->Next = x->Next;
					if (x->Next != nullptr)
					{
						x->Next->Previous = temp;
					}
					x->Next = temp;
				}
				else
				{
					temp->Next = x;
					temp->Previous = x->Previous;
					if (x->Previous != nullptr)
					{
						x->Previous->Next = temp;
					}
					x->Previous = temp;
				}
			}
			Insert_Main(temp);

			r = new B_Node;
			r->Pointer = temp;
			r->Left = nullptr;
			r->Right = nullptr;
			r->Data = data;
			r->Height = 0;
		}
		else
		{
			if (r->Data < data)
			{
				Insert(r->Right, r->Pointer, data);
				if (Get_Height(r->Left) - Get_Height(r->Right) == -2)
				{
					if (data > r->Right->Data)
					{
						Rotate_Left(r);
					}
					else
					{
						Double_Rotate_Left(r);
					}
				}
			}
			else if (r->Data > data)
			{
				Insert(r->Left, r->Pointer, data);
				if (Get_Height(r->Left) - Get_Height(r->Right) == 2)
				{
					if (data < r->Left->Data)
					{
						Rotate_Right(r);
					}
					else
					{
						Double_Rotate_Right(r);
					}
				}
			}
			r->Height = 1 + Max(Get_Height(r->Left), Get_Height(r->Right));
		}
	}
	//-------------------------------------------
	void Remove(int a)
	{
		Remove_Main(Root, a);
	}
	//-------------------------------------------
	void Remove_Main(B_Node*& root, int a)
	{
		if (root != nullptr)
		{
			if (root->Data > a)
			{
				Remove_Main(root->Left, a);
				if (Get_Height(root->Left) - Get_Height(root->Right) == -2)
				{
					if (Balance_Factor(root->Right) <= 0)
					{
						Rotate_Left(root);
					}
					else if (Balance_Factor(root->Left) == 1)
					{
						Double_Rotate_Left(root);
					}
				}
				root->Height = 1 + Max(Get_Height(root->Left), Get_Height(root->Right));
				return;
			}
			else if (root->Data < a)
			{
				Remove_Main(root->Right, a);
				if (Get_Height(root->Left) - Get_Height(root->Right) == 2)
				{
					if (Balance_Factor(root->Left) >= 0)
					{
						Rotate_Right(root);
					}
					else if (Balance_Factor(root->Left) == -1)
					{
						Double_Rotate_Right(root);
					}
				}
				root->Height = 1 + Max(Get_Height(root->Left), Get_Height(root->Right));
				return;
			}
			else if (root->Data == a)
			{
				if (root->Left == nullptr && root->Right == nullptr)
				{
					if (root->Pointer->Previous != nullptr)
					{
						root->Pointer->Previous->Next = root->Pointer->Next;
					}
					if (root->Pointer->Next != nullptr)
					{
						root->Pointer->Next->Previous = root->Pointer->Previous;
					}
					delete root->Pointer;
					delete root;
					root = nullptr;
				}
				else if (root->Left == nullptr)
				{
					B_Node* temp = root;
					root = root->Right;
					if (temp->Pointer->Previous != nullptr)
					{
						temp->Pointer->Previous->Next = temp->Pointer->Next;
					}
					if (temp->Pointer->Next != nullptr)
					{
						temp->Pointer->Next->Previous = temp->Pointer->Previous;
					}

					delete temp->Pointer;
					delete temp;
				}
				else if (root->Right == nullptr)
				{
					B_Node* temp = root;
					root = root->Left;
					if (temp->Pointer->Previous != nullptr)
					{
						temp->Pointer->Previous->Next = temp->Pointer->Next;
					}
					if (temp->Pointer->Next != nullptr)
					{
						temp->Pointer->Next->Previous = temp->Pointer->Previous;
					}
					delete temp->Pointer;
					delete temp;
				}
				else
				{
					*(root->Pointer) = Find_Minimum(root->Right);
					root->Data = root->Pointer->ISSN;
					Remove_Main(root->Right, root->Data);
				}
			}
		}
	}
	//-------------------------------------------
	void Update_Wrapper(int y)
	{
		int x = Update(Root, y);
		if (!x)
		{
			cout << "Book not exist\n";
		}
	}
	//-------------------------------------------
	bool Update(B_Node* r, int a)
	{
		if (r == nullptr)
		{
			return 0;
		}
		else if (r->Data > a)
		{
			return Update(r->Left, a);
		}
		else if (r->Data > a)
		{
			return Update(r->Right, a);
		}
		else
		{
			Updates_Main(r->Pointer);
			return 1;
		}
	}
	//-------------------------------------------
	int Updates_Main(Node* p)
	{
		int opt;
		cout << "-------------------------------\n";
		cout << "\tUpdate Options\n";
		cout << "-------------------------------\n";
		while (1)
		{
			cout <<
				"[1]To Update Title\n"
				"[2]To Update Authors List\n"
				"[3]To Update no of reference books\n"
				"[4]To Update no of issuable books\n"
				"[5]To Exit\n"
				"-------------------------------\n";
			"Select any opition : ";
			cin >> opt;
			system("cls");
			switch (opt)
			{

			default:
			{
				cout << "Select right option\n"; break;
			}
			case 1:
			{
				cin.ignore();
				cout << "Enter new Title\n";
				getline(cin, p->Title);
				system("pause");
				system("cls");
				break;
			}
			case 2:
			{
				cout << "Enter new no. of authors : ";
				cin >> p->List_of_Authors;
				p->Names = new string[p->List_of_Authors];
				cin.ignore();
				cout << "Enter authors name\n";
				for (int i = 0; i < p->List_of_Authors; i++)
				{
					cout << "Author [" << i + 1 << "] : ";
					getline(cin, p->Names[i]);
				}
				system("pause");
				system("cls");
				break;
			}
			case 3:
			{
				cout << "Enter new no. of reference books : ";
				cin >> p->Reference_Copies;
				system("pause");
				system("cls");
				break;
			}
			case 4:
			{
				cout << "Enter new no. of issuable books : ";
				cin >> p->Issuable_Copies;
				system("pause");
				system("cls");
				break;
			}
			case 5:
			{
				return 0;
			}
			}
		}
	}
	//-------------------------------------------
	void Review(int y)
	{
		int ind = Review_Main(Root, y);
		if (!ind)
		{
			cout << "Book not exist\n";
		}
	}
	//-------------------------------------------
	bool Review_Main(B_Node* r, int a)
	{
		if (r == nullptr)
		{
			return 0;
		}
		else if (r->Data > a)
		{
			return Review_Main(r->Left, a);
		}
		else if (r->Data > a)
		{
			return Review_Main(r->Right, a);
		}
		else
		{
			Print_Main(r->Pointer);
			return 1;
		}
	}
	//-------------------------------------------
	void Print_Wrapper()
	{
		Print(Root);
	}
	//-------------------------------------------
	void Print(B_Node* x)
	{
		if (x == nullptr)
		{
			return;
		}
		Print(x->Left);
		Print_Main(x->Pointer);
		Print(x->Right);
	}
	//-------------------------------------------
	void Print_Main(Node* x)
	{
		cout << "-------------------------------";
		cout << "\n         Book Details";
		cout << "\n-------------------------------";
		cout << "\nISSN : " << x->ISSN;
		cout << "\nTitle : " << x->Title;
		cout << "\nAuthors :-";
		for (int i = 0; i < x->List_of_Authors; i++)
		{
			cout << "\n[" << i + 1 << "] " << x->Names[i];

		}
		cout << "\nReference Copies : " << x->Reference_Copies;
		cout << "\nIssuable Copies : " << x->Issuable_Copies;
		cout << "\n-------------------------------\n";
	}
	//-------------------------------------------
};

int main()
{
	Library_AVL Tree[10];
	int opt, ISSN, ind = 0;
	while (1)
	{
		cout << "--------------------------------\n";
		cout << "\t    Library\n";
		cout << "--------------------------------\n";
		cout << "[You can enter maximum 10 books]\n";
		cout << "     Current book count : " << ind;
		cout << "\n--------------------------------\n";
		cout << "[1]To Create New record of book\n";
		cout << "[2]To Remove a book record\n";
		cout << "[3]To Update a book record\n";
		cout << "[4]To Review a book record\n";
		cout << "[5]To Quit\n";
		cout << "-------------------------------\n";
		cout << "Select any option : ";
		cin >> opt;
		system("cls");
		switch (opt)
		{

		default:
		{
			cout << "Select right option\n"; break;
		}
		case 1:
		{
			if (ind < 10)
			{
				Tree[ind].Insert_Wrapper(); ind++;
				cout << "Inserted Sucessfully :)\n";
			}
			else
			{
				cout << "Library is full :(\n";
			}
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			cout << "Enter ISSN : ";
			cin >> ISSN;
			Tree[ISSN - 1].Remove(ISSN);
			cout << "Removed Sucessfully :)\n";
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			cout << "Enter ISSN : ";
			cin >> ISSN;
			Tree[ISSN - 1].Update_Wrapper(ISSN);
			cout << "Updated Sucessfully :)\n";
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			cout << "Enter ISSN : ";
			cin >> ISSN;
			cout << endl;
			Tree[ISSN - 1].Review(ISSN);
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			return 0;
		}
		}
	}
}