#pragma once
template <typename T> 
class Node 
{    
public:      
	Node(T element);
	void setData(T pVal);    
	T getData();    
	Node* getNext(); 
	void setNext(Node *x); 
	Node* getPrevious();
	void setPrevious(Node* x);

private:        
	T data;
	Node *next ;
	Node *previous ;

}; 
template <typename T> 
class DList 
{    
public:         
	DList();   
	void Insert(Node<T>*pBefore, Node<T>*pNew);
	bool isPalindrome();
	void Check();   
private:        
	Node<T> *first ;
};