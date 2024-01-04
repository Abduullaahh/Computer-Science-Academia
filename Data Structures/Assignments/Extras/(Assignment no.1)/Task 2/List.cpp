#include "List.h"
#include<iostream>
using namespace std;
template <class T>
Node<T>::Node(T element)
{
	this->data=element;
	this->link=NULL;
}
template <class T>
void Node <T>::setData(T pval)
{
	this->data=pval;
}
template <class T>
 T Node <T>::getData()
{
	return data;
}
template<class T>
Node<T> * Node <T>::GetNext()
{
	return link ;
}
template<class T>
void Node<T>::SetNext(Node *x)
{
	this->link=x ;
}
template<class T>
List<T>::List()
{
	this->first=NULL;
}
template<class T>
Node<T> *List<T>::getFirst()
{
	return first;
}
template <class T>
void List<T>::Insert(Node<T>* pBefore, Node<T>* pNew)
{
	if(!first)
	{
		first=pNew;
	}
	else if (!pBefore&&first)
	{
		pNew->SetNext(first);
		first=pNew;
	}
	else
	{
		pNew->SetNext(first);
		pBefore->SetNext(pNew); 
	}
}
template <class T>
void List <T>::printList()
{
	Node<T> *temp;
	temp=first;
	int i=0;
	do
	{
		cout<<"Node"<<i+1<<" is "<<"= "<<temp->getData()<<endl; 
		temp=temp->GetNext();
		i++;
	}
	while(temp!=first);
	cout<<endl;
}
template <typename T> 
bool isCircular (List<T> * plist)
{
	Node<T> *temp;
	temp=plist->getFirst();
	 while(temp!=NULL)
	 {
		 if(temp->GetNext()==plist->getFirst())
		 {
			 return true;
		 }
		 temp=temp->GetNext();
	 }
	 return false;
}