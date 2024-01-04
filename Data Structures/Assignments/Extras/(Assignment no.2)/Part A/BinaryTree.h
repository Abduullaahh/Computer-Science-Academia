#pragma once
#include<iostream>
#include<cmath>
#include<queue>
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
	//Part i:
	int calculateDepth(BNode<DT>* root);
	int countNodes(BNode<DT>* r);
	int check(BNode<DT>* r);
	bool isComplete();
	//Part ii:
	int numberofNodesAtLevel(int level);
	//Part iii:
	bool isNodePresent(BNode<DT>* root, BNode<DT>* node);
	bool findLCA(BNode<DT>* root, BNode<DT>*& lca, BNode<DT>* x, BNode<DT>* y);
	BNode<DT>* lowest_common_ancestor(BNode<DT>* a, BNode<DT>* b);
	BNode<DT>* getRoot() { return root; }
private:
	BNode<DT>* root;
};