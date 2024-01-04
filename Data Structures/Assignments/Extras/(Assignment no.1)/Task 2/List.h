#pragma once
template<class T>
class Node
{ 
public: 
	Node(T element);
	void setData(T pVal); 
	T getData();
	Node* GetNext();
	void SetNext(Node *x);
private: 
	T data;
	Node *link;
};
template<class T>
class List
{
private:
	Node<T> *first;
public:
	List();
	void Insert(Node<T>* pBefore, Node<T>* pNew);
	Node<T>* getFirst();
	void printList();
};