#include "List.h"
#include "List.cpp"
#include<iostream>
using namespace std;
int main()
{
	Node<int> *a, *b, *c, *d, *e;    
	a = new Node<int>(1);  
	b = new Node<int>(2);  
	c = new Node<int>(3);  
	d = new Node<int>(4);  
	e = new Node<int>(5); 
	List<int> *list;
	list = new List<int>();
	//I have make the list circular in Insert function
	list->Insert(0 , a);  
	list->Insert(a , b);  
	list->Insert(b , c);
	list->Insert(c , d);
	list->Insert(d , e);
	list->printList();
	if(isCircular(list))
	{
		cout<<"Yes ,The list is circular"<<endl;
	}
	else
	{
		cout<<"NO ,The list is not circular"<<endl;
	}
	return 0;
}