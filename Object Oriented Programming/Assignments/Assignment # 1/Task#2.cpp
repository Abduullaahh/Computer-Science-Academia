//#include<iostream>
//using namespace std;
////-------------------------------------------------
//static int IDX_Glb = 0;
////-------------------------------------------------
//class Set
//{
//private:
//	int* data;
//	int noOfElements;
//	int capacity;
//
//public:
//	Set(int);
//	Set(const Set& ref);
//	void insert(int element);
//	void remove(int element);
//	int getCardinality() const;
//	Set calcUnion(const Set& s2) const;
//	Set calcSymmetricDifference(const Set& s2);
//	Set calcDifference(const Set& s2) const;
//	int isMember(int val) const;
//	int isSubSet(const Set& s2) const;
//	void reSize(int newcapacity);
//	void update(int prVal, int curVal);
//	void show() const;
//	~Set();
//};
////-------------------------------------------------
//Set::Set(int cap = 0)
//{
//	capacity = cap;
//	data = new int[capacity];
//	for (int i = 0; i < capacity; i++)
//	{
//		data[i] = 0;
//	}
//	noOfElements = 0;
//}
////-------------------------------------------------
//Set::Set(const Set& ref)
//{
//	capacity = ref.capacity;
//	noOfElements = ref.noOfElements;
//	data = new int[noOfElements];
//	for (int i = 0; i < ref.capacity; i++)
//	{
//		data[i] = ref.data[i];
//	}
//}
////-------------------------------------------------
//void Set::insert(int element)
//{
//	for (; IDX_Glb < capacity;)
//	{
//		data[IDX_Glb] = element;
//		IDX_Glb += 1;
//		noOfElements++;
//		break;
//	}
//}
////-------------------------------------------------
//void Set::remove(int element)
//{
//	int temp = noOfElements;
//	for (int i = 0; i < capacity; i++)
//	{
//		if (data[i] == element)
//		{
//			for (int j = i; j < capacity; j++)
//			{
//				data[j] = data[j + 1];
//			}
//			/*capacity -= 1;*/
//			noOfElements -= 1;
//		}
//		if (i == (capacity - 1) && noOfElements == temp)
//		{
//			cout << "Element not exists\n";
//		}
//	}
//	if (noOfElements < temp)
//	{
//		cout << "Element " << element << " deleted from set " << endl;
//	}
//	if (noOfElements <= capacity / 2)
//	{
//		int* newarr;
//		capacity = capacity - (capacity / 4);
//		newarr = new int[capacity];
//		{
//			for (int i = 0; i < noOfElements; i++)
//			{
//				newarr[i] = data[i];
//			}
//		}
//		Set S(capacity);
//		IDX_Glb = 0;
//		for (int i = 0; i < noOfElements; i++)
//		{
//			S.insert(newarr[i]);
//		}
//		delete[]newarr;
//		cout << "Shrinked the set by 25% successfully\n";
//		capacity = noOfElements;
//	}
//	else
//	{
//		cout << "No need to shrink the set\n";
//	}
//}
////-------------------------------------------------
//int Set::getCardinality() const
//{
//	return noOfElements;
//}
////-------------------------------------------------
//Set Set::calcUnion(const Set& S2) const
//{
//	int iterations = capacity, check = 0;
//	bool condition = false;
//	for (int i = 0; i < S2.capacity; i++)
//	{
//		for (int j = 0; j < capacity; j++)
//		{
//			if (data[j] != S2.data[i])
//			{
//				condition = true;
//			}
//			else if (data[j] == S2.data[i])
//			{
//				condition = false;
//				break;
//			}
//		}
//		if (condition == true)
//		{
//			iterations++;
//		}
//	}
//	int* Union, idx = 0; condition = false;
//	Union = new int[iterations];
//	for (int i = 0; i < iterations; i++)
//	{
//		Union[i] = 0;
//
//	}
//	for (int i = 0; i < capacity; i++)
//	{
//		Union[i] = data[i];
//		idx++;
//	}
//	for (int i = 0; i < S2.capacity; i++)
//	{
//		for (int j = 0; j < capacity; j++)
//		{
//			if (data[j] != S2.data[i])
//			{
//				condition = true;
//			}
//			else if (data[j] == S2.data[i])
//			{
//				condition = false;
//				break;
//			}
//		}
//		if (condition == true)
//		{
//			Union[idx] = S2.data[i];
//			idx++;
//		}
//	}
//	IDX_Glb = 0;
//	Set S(iterations);
//	for (int i = 0; i < iterations; i++)
//	{
//		S.insert(Union[i]);
//	}
//	cout << endl;
//	return S;
//}
////-------------------------------------------------
//Set Set::calcSymmetricDifference(const Set& s2)
//{
//	Set S1(calcUnion(s2));
//	Set S2(calcDifference(s2));
//	int idx = 0;
//	bool con = false;
//	for (int i = 0; i < S1.capacity; i++)
//	{
//		for (int j = 0; j < S2.capacity; j++)
//		{
//			if (S1.data[i] != S2.data[j])
//			{
//				con = true;
//			}
//			else
//			{
//				con = false;
//				break;
//			}
//		}
//		if (con == true)
//		{
//			idx++;
//		}
//	}
//	con = false;
//	for (int i = 0; i < S2.capacity; i++)
//	{
//		for (int j = 0; j < S1.capacity; j++)
//		{
//			if (S2.data[i] != S1.data[j])
//			{
//				con = true;
//			}
//			else
//			{
//				con = false;
//				break;
//			}
//		}
//		if (con == true)
//		{
//			idx++;
//		}
//	}
//	int* Symdiff = new int[idx]; int ind = 0;
//	for (int i = 0; i < S1.capacity; i++)
//	{
//		for (int j = 0; j < S2.capacity; j++)
//		{
//			if (S1.data[i] != S2.data[j])
//			{
//				con = true;
//			}
//			else
//			{
//				con = false;
//				break;
//			}
//		}
//		if (con == true)
//		{
//			Symdiff[ind] = S1.data[i];
//			ind++;
//		}
//	}
//	for (int i = 0; i < S2.capacity; i++)
//	{
//		for (int j = 0; j < S1.capacity; j++)
//		{
//			if (S1.data[i] != S2.data[j])
//			{
//				con = true;
//			}
//			else
//			{
//				con = false;
//				break;
//			}
//		}
//		if (con == true)
//		{
//			Symdiff[ind] = S2.data[i];
//			ind++;
//		}
//	}
//	IDX_Glb = 0;
//	Set S(idx);
//	for (int i = 0; i < idx; i++)
//	{
//		S.insert(Symdiff[i]);
//	}
//	return S;
//}
////-------------------------------------------------
//Set Set::calcDifference(const Set& s2) const
//{
//	int size = 0;
//	for (int i = 0; i < capacity; i++)
//	{
//		for (int j = 0; j < s2.capacity; j++)
//		{
//			if (data[i] == s2.data[j])
//			{
//				size++;
//				break;
//			}
//		}
//	}
//	int* intsec = new int[size];
//	int indx = 0;
//	for (int i = 0; i < capacity; i++)
//	{
//		for (int j = 0; j < s2.capacity; j++)
//		{
//			if (data[i] == s2.data[j])
//			{
//				intsec[indx] = data[i];
//				indx++;
//				break;
//			}
//		}
//	}
//	IDX_Glb = 0;
//	Set S(size);
//	for (int i = 0; i < size; i++)
//	{
//		S.insert(intsec[i]);
//	}
//	return S;
//}
////-------------------------------------------------
//int Set::isMember(int val) const
//{
//	for (int i = 0; i < capacity; i++)
//	{
//		if (val == data[i])
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
////-------------------------------------------------
//int Set::isSubSet(const Set& s2) const
//{
//	int s = 0; bool con = false; int i = 0, chk = 0;
//	if (s2.capacity < capacity || s2.capacity == capacity)
//	{
//		s = s2.capacity;
//		for (; i < s2.capacity; i++)
//		{
//			if (con == true)
//			{
//				chk++;
//				con = false;
//			}
//			for (int j = 0; j < capacity; j++)
//			{
//				if (s2.data[i] == data[j])
//				{
//					con = true;
//					break;
//				}
//			}
//			if (con == false)
//			{
//				return 0;
//			}
//		}
//		chk++;
//		if (con == true && i == s && chk == s)
//		{
//			return 1;
//		}
//	}
//	else
//	{
//		return 0;
//	}
//}
////-------------------------------------------------
//void Set::reSize(int newcapacity)
//{
//	capacity = newcapacity;
//	int* temp;
//	temp = new int[capacity];
//	int chk = 0;
//	for (int i = 0; i < capacity; i++)
//	{
//		temp[i] = data[i]; chk++;
//	}
//	delete[]data;
//	data = NULL;
//	data = new int[capacity];
//	noOfElements = capacity;
//	for (int i = 0; i < chk; i++)
//	{
//		data[i] = temp[i];
//	}
//	cout << "Set resized.....New resized set : "; show();
//	delete[]temp;
//	temp = NULL;
//}
////-------------------------------------------------
//void Set::update(int prVal, int curVal)
//{
//	int i = 0; bool con = false, con1 = false;
//	for (; i < capacity; i++)
//	{
//		if (data[i] == prVal)
//		{
//			con = true;
//			for (int j = 0; j < capacity; j++)
//			{
//				if (curVal != data[i])
//				{
//					con1 = true;
//				}
//				else
//				{
//					con1 = false;
//					break;
//				}
//			}
//		}
//		if (i == capacity - 1 && con == false)
//		{
//			cout << "Target value not found\n";
//		}
//	}
//	if (con1 == true)
//	{
//		for (int i = 0; i < capacity; i++)
//		{
//			if (prVal == data[i])
//			{
//				data[i] = curVal;
//				cout << "Record update successfully\n";
//				break;
//			}
//		}
//	}
//	else
//	{
//		cout << "Violation set property. Can’t Modify the data\n";
//	}
//	cout << "Updated array : "; show();
//}
////-------------------------------------------------
//void Set::show() const
//{
//	cout << "\t{ ";
//	for (int i = 0; i < capacity; i++)
//	{
//		if (i < capacity - 1)
//		{
//			cout << data[i] << ", ";
//		}
//		else
//		{
//			cout << data[i];
//		}
//	}
//	cout << " }" << endl;
//}
////-------------------------------------------------
//Set::~Set()
//{
//	delete[]data;
//}
////-------------------------------------------------
//int Menu()
//{
//	system("pause");
//	system("cls");
//	int opt;
//	cout << "--------------------------------------------------------------\n";
//	cout << "\n\t\tMENU\n";
//	cout << "--------------------------------------------------------------\n";
//	cout << "\tAutomatic functions\n\n1.Set (int cap = 0) --> Created\n2.Set(const Set & ref) --> Created\n3.~Set() --> Created\n4.void insert(int element) --> To take input\n";
//	cout << "--------------------------------------------------------------\n";
//	cout << "4.To enter elements                                  : PRESS 0\n";
//	cout << "5.To remove an element from set                      : PRESS 1\n";
//	cout << "6.To get size of set                                 : PRESS 2\n";
//	cout << "7.To take union of sets                              : PRESS 3\n";
//	cout << "8.To take symmetric difference of sets               : PRESS 4\n";
//	cout << "9.To take intersection of sets                       : PRESS 5\n";
//	cout << "10.To check membership of an element in set          : PRESS 6\n";
//	cout << "11.To check if set 2 is subset of set 1              : PRESS 7\n";
//	cout << "12.To resize the sets                                : PRESS 8\n";
//	cout << "13.To update element of sets                         : PRESS 9\n";
//	cout << "14.To print the set                                  : PRESS 10\n";
//	cout << "PRESS -1 to exit\n";
//	cout << "--------------------------------------------------------------\n";
//	cout << "Enter any option : "; cin >> opt;
//	cout << "--------------------------------------------------------------\n";
//	return opt;
//}
////-------------------------------------------------
//int main()
//{
//	Set S;
//	int size = 0;
//	int chks1 = 0, chks2 = 0;
//	cout << "Set contains only distinct values. Avoid repitation\n";
//	cout << "---------------------------------------------------\n";
//	cout << "Enter size of set 1 : "; cin >> size;
//	cout << "Enter set 1 :-\n";
//	Set S1(size);
//	int* element;
//	element = new int[size];
//	int chk = 0;
//	bool con = false;
//	for (int i = 0; i < size;)
//	{
//		cout << "Enter element " << i + 1 << " : "; cin >> element[i];
//		if (i > 0)
//		{
//			for (int j = 0; j < chk; j++)
//			{
//				if (element[i] != element[j])
//				{
//					con = true;
//				}
//				else
//				{
//					con = false;
//					cout << "EROR : Element already exists\n";
//					break;
//				}
//			}
//		}
//		if (i == 0)
//		{
//			S1.insert(element[i]);
//			i++;
//			chk++;
//			chks1++;
//		}
//		if (con == true)
//		{
//			S1.insert(element[i]);
//			i++;
//			chk++;
//			chks1++;
//		}
//	}
//	cout << "---------------------------------------------------\n";
//	for (int i = 0; i < size; i++) { element[i] = 0; }IDX_Glb = 0; chk = 0; con = false;
//	cout << "Enter size of set 2 : "; cin >> size;
//	cout << "Enter set 2 :-\n";
//	Set S2(size);
//	for (int i = 0; i < size;)
//	{
//		cout << "Enter element " << i + 1 << " : "; cin >> element[i];
//		if (i > 0)
//		{
//			for (int j = 0; j < chk; j++)
//			{
//				if (element[i] != element[j])
//				{
//					con = true;
//				}
//				else
//				{
//					con = false;
//					cout << "EROR : Element already exists\n";
//					break;
//				}
//			}
//		}
//		if (i == 0)
//		{
//			S2.insert(element[i]);
//			i++;
//			chk++;
//			chks2++;
//		}
//		if (con == true)
//		{
//			S2.insert(element[i]);
//			i++;
//			chk++;
//			chks2++;
//		}
//	}
//	cout << "---------------------------------------------------\n";
//	IDX_Glb = 0;
//	for (int opt = 0; opt != -1;)
//	{
//		opt = Menu();
//		if (opt == 0)
//		{
//			cout << "Set contains only distinct values. Avoid repitation\n";
//			cout << "---------------------------------------------------\n";
//			cout << "In which set do you want to enter elements\nPress 1 for set 1 and 2 for set 2\n";
//			int s = 0;
//			cin >> s;
//			if (s == 1)
//			{
//				if (chks1 < S1.getCardinality())
//				{
//					element = NULL;
//					element = new int[S1.getCardinality()];
//					con = false;
//					IDX_Glb = chks1;
//					int loop = S1.getCardinality();
//					for (int i = chks1; i < loop;)
//					{
//						cout << "Enter element " << i + 1 << " : "; cin >> element[i];
//						for (int j = 0; j < chk; j++)
//						{
//							if (element[i] != element[j])
//							{
//								con = true;
//							}
//							else
//							{
//								con = false;
//								cout << "EROR : Element already exists\n";
//								break;
//							}
//						}
//						if (con == true)
//						{
//							S1.insert(element[i]);
//							i++;
//						}
//					}
//					cout << "---------------------------------------------------\n";
//				}
//				else
//				{
//					cout << "Set is full\n";
//				}
//			}
//			else if (s == 2)
//			{
//				if (chks2 < S2.getCardinality())
//				{
//					for (int i = 0; i < size; i++) { element[i] = 0; }con = false;
//					element = new int[S2.getCardinality()];
//					IDX_Glb = chks2;
//					int loop = S2.getCardinality();
//					for (int i = chks2; i < loop;)
//					{
//						cout << "Enter element " << i + 1 << " : "; cin >> element[i];
//						for (int j = 0; j < chk; j++)
//						{
//							if (element[i] != element[j])
//							{
//								con = true;
//							}
//							else
//							{
//								con = false;
//								cout << "EROR : Element already exists\n";
//								break;
//							}
//						}
//						if (con == true)
//						{
//							S2.insert(element[i]);
//							i++;
//							chk++;
//						}
//					}
//					cout << "---------------------------------------------------\n";
//					IDX_Glb = 0;
//				}
//				else
//				{
//					cout << "Set is full\n";
//				}
//			}
//		}
//		if (opt == 1)
//		{
//			int s = 0;
//			cout << "From which element do you want to remove element?\nPress 1 for set 1 OR Press 2 for set 2\n";
//			cin >> s;
//			int element_delete = 0;
//			if (s == 1)
//			{
//				cout << "Enter element to delete : "; cin >> element_delete;
//				S1.remove(element_delete);
//			}
//			else if (s == 2)
//			{
//				cout << "Enter element to delete : "; cin >> element_delete;
//				S2.remove(element_delete);
//			}
//		}
//		else if (opt == 2)
//		{
//			int s = 0;
//			cout << "For which element do you want to know no. of elements?\nPress 1 for set 1 OR Press 2 for set 2\n";
//			cin >> s;
//			if (s == 1)
//			{
//				cout << "Number of elements currently in set 1 : " << S1.getCardinality() << endl;
//			}
//			else if (s == 2)
//			{
//				cout << "Number of elements currently in set 2 : " << S2.getCardinality() << endl;
//			}
//		}
//		else if (opt == 3)
//		{
//			Set S3(S1.calcUnion(S2));
//			cout << "Union of sets is : ";
//			S3.show();
//			cout << endl;
//		}
//		else if (opt == 4)
//		{
//			Set S3(S1.calcSymmetricDifference(S2));
//			cout << "Symmetric Difference of sets is : ";
//			S3.show();
//			cout << endl;
//		}
//		else if (opt == 5)
//		{
//			Set S3(S1.calcDifference(S2));
//			cout << "Intersection of sets is : ";
//			S3.show();
//			cout << endl;
//		}
//		else if (opt == 6)
//		{
//			int val;
//			int s = 0;
//			cout << "In which set do you want to check membership of element?\nPress 1 for set 1 OR Press 2 for set 2\n";
//			cin >> s;
//			if (s == 1)
//			{
//				cout << "Enter any value to check its membership in set " << s << " : "; cin >> val;
//				if (S1.isMember(val) == 1)
//				{
//					cout << "Value is member of set 1\n";
//				}
//				else
//				{
//					cout << "Value is not member of set 1\n";
//				}
//			}
//			else if (s == 2)
//			{
//				cout << "Enter any value to check its membership in set " << s << " : "; cin >> val;
//				if (S2.isMember(val) == 1)
//				{
//					cout << "Value is member of set 2\n";
//				}
//				else
//				{
//					cout << "Value is not member of set 2\n";
//				}
//			}
//		}
//		else if (opt == 7)
//		{
//			if (S1.isSubSet(S2) == 1)
//			{
//				cout << "Set 2 is subset of set 1\n";
//			}
//			else
//			{
//				cout << "Set 2 is not subset of set 1\n";
//			}
//		}
//		else if (opt == 8)
//		{
//			int s = 0;
//			cout << "Which set you want to resize \nPress 1 for set 1 OR Press 2 for set 2\n";
//			cin >> s;
//			if (s == 1)
//			{
//				cout << "[1] : Resize the set\n[2] : Shrink the set to total no. of elements\n";
//				cin >> s;
//				if (s == 1)
//				{
//					cout << "Enter new size : "; cin >> s;
//					S1.reSize(s);
//				}
//				else if (s == 2)
//				{
//					S1.reSize(S1.getCardinality());
//				}
//			}
//			else if (s == 2)
//			{
//				cout << "[1] : Resize the set\n[2] : Shrink the set to total no. of elements\n";
//				cin >> s;
//				if (s == 1)
//				{
//					cout << "Enter new size : "; cin >> s;
//					S2.reSize(s);
//				}
//				else if (s == 2)
//				{
//					S2.reSize(S2.getCardinality());
//				}
//			}
//		}
//		else if (opt == 9)
//		{
//			int s = 0;
//			cout << "Which set do you want to update?\nPress 1 for set 1 OR Press 2 for set 2\n";
//			cin >> s;
//			if (s == 1)
//			{
//				int prVal, curVal;
//				cout << "Enter the value you want to update : "; cin >> prVal;
//				cout << "Enter the updated value : "; cin >> curVal;
//				S1.update(prVal, curVal);
//			}
//			else if (s == 2)
//			{
//				int prVal, curVal;
//				cout << "Enter the value you want to update : "; cin >> prVal;
//				cout << "Enter the updated value : "; cin >> curVal;
//				S2.update(prVal, curVal);
//			}
//		}
//		else if (opt == 10)
//		{
//			int s = 0;
//			cout << "Which set do you want to print?\nPress 1 for set 1 OR Press 2 for set 2\n";
//			cin >> s;
//			if (s == 1)
//			{
//				cout << "Set " << s << " : "; S1.show();
//			}
//			else if (s == 2)
//			{
//				cout << "Set " << s << " : "; S2.show();
//			}
//		}
//		else if (opt == -1)
//		{
//			delete[]element;
//			return 0;
//		}
//	}
//}