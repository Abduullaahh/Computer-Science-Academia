# include "DList.h"
# include "DList.cpp"
# include <iostream>
using namespace std;
int main()
{
	Node<char> *a, *b, *c, *d, *e;    
	a = new Node<char>('C');  
	b = new Node<char>('I');  
	c = new Node<char>('V');  
	d = new Node<char>('I');  
	e = new Node<char>('C'); 
	DList<char> *list; 
	list = new DList<char>(); 
	list->Insert(0 , a);  
	list->Insert(a , b);  
	list->Insert(b , c);  
	list->Insert(c , d);  
	list->Insert(d, e); 
	list->Check();
	return 0;
}