//# include <iostream>
//# include <string>
//using namespace std;
//template <typename T>
//class Node 
//{    
//public:      
//	Node(T element);
//	void setData(T pVal);    
//	T getData();    
//	Node* GetNext(); 
//	void SetNext(Node *x);
//private:        
//	T data;   
//	Node *link ; 
//}; 
//template <typename T> 
//class List 
//{    
//public:         
//	List();   
//	void Insert(Node<T>*pBefore, Node<T>*pNew);     
//	void Delete(Node<T>*pToBeDeleted);    
//	void printList(); 
//	Node<T>* getFirst(){return first;}
//private:        
//	Node<T> *first ;
//};
//class Student
//{
//public:
//	Student(){}
//	void setname(string n);
//	string getname();
//	void setrollnumber(int r);
//	int getrollnumber();
//private:
//	string name;
//	int rollnumber;
//};
//class University
//{
//public:
//	University();
//	void setnumberOfStudents(int n);
//	int getnumberOfStudents();
//	void setList(Student* s);
//	void getList();
//	void removeStudent(int rn);
//	void ADDStudent(int rn);
//private:
//	int numberOfStudents;
//	List<Student*>* list;
//};
//template <class T>
//Node<T>::Node(T element)
//{
//	this->data=element;
//	this->link=NULL;
//}
//template <class T>
//void Node <T>::setData(T pval)
//{
//	this->data=pval;
//}
//template <class T>
// T Node <T>::getData()
//{
//	return data;
//}
//template<class T>
//Node<T> * Node <T>::GetNext()
//{
//	return link ;
//}
//template<class T>
//void Node<T>::SetNext(Node *x)
//{
//	this->link=x ;
//}
//template <class T>
//List<T>::List()
//{
//	this->first=NULL;
//}
//template <class T>
//void List<T>::Insert(Node<T>* pBefore, Node<T>* pNew)
//{
//	if(!first)
//	{
//		first=pNew;
//	}
//	else if (!pBefore&&first)
//	{
//		pNew->SetNext(first);
//		first=pNew;
//	}
//	else
//	{
//		pNew->SetNext(pBefore->GetNext());
//		pBefore->SetNext(pNew); 
//	}
//}
//template <class T>
//void List<T>::Delete(Node <T> * ptobedeleted)
//{
//	Node<T> *temp=first ;
//	if(ptobedeleted==first)
//	{
//		first=first->GetNext() ;
//	}
//	else 
//	{
//		while (temp->GetNext()!=ptobedeleted)
//		{
//			temp=temp->GetNext();
//		}
//		temp->SetNext(ptobedeleted->GetNext()) ;
//	}
//	delete ptobedeleted;
//}
//template <class T>
//void List <T>::printList()
//{
//	cout<<endl;
//	Node<T> *temp=first;
//	cout<<"Student List : "<<endl;
//	while(temp)
//	{
//		T test=temp->getData();
//		cout<<test->getname()<<" "<<test->getrollnumber()<<endl;
//		temp=temp->GetNext();
//	}
//	cout<<endl;
//}
//void Student::setname(string n)
//{
//	this->name=n;
//}
//string Student::getname()
//{
//	return name;
//}
//void Student::setrollnumber(int r)
//{ 
//	this->rollnumber=r;
//}
//int Student::getrollnumber()
//{
//	return rollnumber;
//}
//University::University()
//{
//	list = new List<Student*>();
//}
//void University::setnumberOfStudents(int n)
//{
//	this->numberOfStudents=n;
//}
//int University::getnumberOfStudents()
//{
//	return numberOfStudents;
//}
//void University::setList(Student* std)
//{
//	Node<Student*>* node = new Node<Student*>(std);
//	list->Insert(0,node);
//	setnumberOfStudents(getnumberOfStudents() + 1);
//}
//void University::removeStudent(int rn)
//{
//	Node<Student*>* n=list->getFirst();
//	while (n->getData()->getrollnumber()!=rn)
//	{
//		n = n->GetNext();
//	}
//	list->Delete(n);
//	setnumberOfStudents(getnumberOfStudents() - 1);
//}
//void University::ADDStudent(int rn)
//{
//	Node<Student*>* n=list->getFirst();
//
//	while (n->getData()->getrollnumber()!=rn)
//	{
//		n = n->GetNext();
//	}
//	cout << "Student Name: " << n->getData()->getname() << endl;
//	cout << "Rollnumber: " << n->getData()->getrollnumber() << endl;
//}
//void University::getList()
//{
//	list->printList();
//}
//void clientMenu()
//{
//	cout << endl;
//	cout << "1: Add Students" << endl;
//	cout << "2: Remove Students" << endl;
//	cout << "3: Print all Students Report" << endl;
//	cout << "4: Total Number of Students" << endl;
//	cout << "5: Search a Student" << endl;
//	cout << "6: Exit" << endl;
//	cout << endl;
//}
//int main()
//{
//	University uni;
//	int ch;
//	while(true)
//	{	
//		clientMenu();
//		cin>>ch;
//		switch(ch)
//		{
//		case 1:
//			{
//				Student* s=new Student();
//				string name;
//				int id;
//			    cout<<"Name: ";
//			    cin>>name;
//			    cout<<"Rollnumber: ";
//			    cin>>id;
//			    s->setname(name);
//			    s->setrollnumber(id);
//			    uni.setList(s);
//			    break;
//			}
//		case 2:
//			{
//				int id;
//			    cout<<"Rollnumber: ";
//			    cin>>id;
//			    uni.removeStudent(id);
//			    break;
//			}
//		case 3:
//			{
//				uni.getList();
//				break;
//			}
//		case 4:
//			{
//				cout<<"Number of Students: "<<uni.getnumberOfStudents() << endl;
//				break;
//			}
//		case 5:
//			{
//				int id;
//				cout<<"Rollnumber: ";
//				cin>>id;
//				uni.ADDStudent(id);
//				break;
//			}
//		case 6:
//			{
//				return 0;
//			}
//		default:
//			{
//				clientMenu();
//			}
//		}
//	}
//	return 0;
//}

#include<iostream>
using namespace std;
class fraction
{
	int num;
	int deno;
public:
	fraction();
	fraction(int n, int d);
	~fraction();
	void print();
};
fraction::fraction()
{
	num = 0;
	deno = 1;
}
fraction::fraction(int n, int d)
{
	num = n;
	deno = d;
}

void fraction::print()
{
	cout << num << "/" << deno << endl;
}
fraction::~fraction()
{
	cout << "Destructors are called for " << num << "/" << deno << endl;
}
int main()
{

	fraction f1;
	cout << "Fraction f1 = ";
	f1.print();
	fraction f2(1, 3);
	cout << "Fraction f2 = ";
	f2.print();
	system("pause");
	return 0;
}