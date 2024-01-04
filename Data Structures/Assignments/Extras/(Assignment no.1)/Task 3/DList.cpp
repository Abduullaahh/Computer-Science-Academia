#include "DList.h"
# include <iostream>
using namespace std;
template <class T>
Node<T>::Node(T element)
{
	this->data=element;
	this->next=nullptr;
	this->previous=nullptr;
};
template <class T>
void Node <T>::setData(T pval)
{
	this->data=pval;
};
template <class T>
 T Node <T>::getData()
{
	return data;
};
template<class T>
Node<T> * Node <T>::getNext()
{
	return next;
};
template<class T>
void Node<T>::setNext(Node *x)
{
	this->next=x;
};
template<class T>
Node<T>*Node<T>::getPrevious()
{
	return previous;
};
template<class T>
void Node<T>::setPrevious(Node *x)
{
	this->previous=x;
};
template <class T>
DList<T>::DList()
{
	this->first=nullptr;
};
template<class T>
void DList<T>::Insert(Node<T>* pBefore, Node<T>* pNew)
{
	if(!first)
	{
		first=pNew;
	}
	else if (!pBefore&&first)
	{
		pNew->setNext(nullptr);
		pNew->setPrevious(first);
		first=pNew;
	}
	else
	{
		pNew->setNext(pBefore->getNext());
		pBefore->setNext(pNew);
		pNew->setPrevious(pBefore);
	}
};
template<class T>
bool DList<T>::isPalindrome()
{
	if (first==NULL)
	{
       return true;
	}
	Node<T> *temp=first;
	while (temp->getNext()!=NULL)
	{
		temp=temp->getNext();
	}
	while (first!=temp)
	{
		if (first->getData()!=temp->getData())
		 {
            return false;
		 }
		first=first->getNext();
		temp=temp->getPrevious();
	}
	return true;
};
template <class T>
void DList<T>::Check()
{
	if(isPalindrome())
	{
		cout<<"Is Palindrome"<<endl;
	}
	else
	{
		cout<<"Is NOT Palindrome"<<endl;
	}
};