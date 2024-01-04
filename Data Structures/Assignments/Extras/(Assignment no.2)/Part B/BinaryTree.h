#pragma once
#include<iostream>
using namespace std;
template<class DT>
class BNode
{
public:
	BNode();
	void setLeftChild(BNode<DT>* n);
	BNode<DT>* getLeftChild();
	void setRightChild(BNode<DT>* n);
	BNode<DT>* getRightChild();
	void setData(DT pdate);
	DT getData();
private:
	DT data;
	BNode* leftchild;
	BNode* rightchild;
};
template<class DT>
class BinaryTree
{
public:
	BinaryTree();
	void BuildTree(DT* Arr, int Size);
	void InOrder(BNode<DT>* node);
	void PostOrder(BNode<DT>* node);
	void PreOrder(BNode<DT>* node);
	BNode<DT>* setRoot(BNode<DT>* r) { return this->root = r; }
	BNode<DT>* getRoot() { return root; }
private:
	BNode<DT>* root;
};