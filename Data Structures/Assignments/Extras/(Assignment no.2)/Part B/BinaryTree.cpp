#include "BinaryTree.h"
template<class DT>
BNode<DT>::BNode()
{
	data = 0;
	leftchild = 0;
	rightchild = 0;
};
template<class DT>
void BNode<DT>::setData(DT pdate)
{
	data = pdate;
};
template<class DT>
DT BNode<DT>::getData()
{
	return data;
};
template<class DT>
BNode<DT>* BNode<DT>::getLeftChild()
{
	return leftchild;
};
template<class DT>
void BNode<DT>::setLeftChild(BNode<DT>* n)
{
	leftchild = n;
};
template<class DT>
BNode<DT>* BNode<DT>::getRightChild()
{
	return rightchild;
};
template<class DT>
void BNode<DT>::setRightChild(BNode<DT>* n)
{
	rightchild = n;
};
template<class DT>
BinaryTree<DT>::BinaryTree()
{
	root = 0;
};
template<class DT>
void BinaryTree<DT>::BuildTree(DT* Arr, int Size)
{
	BNode<DT>** parent = new BNode<DT>*[Size];
	for (int i = 0; i < Size; i++)
	{
		BNode<DT>* newNode = new BNode<DT>();
		newNode->setData(Arr[i]);
		parent[i] = newNode;
	}
	for (int i = 1; i < Size; i++)
	{
		if (Arr[i] != 0)
		{
			if (i * 2 < Size)
			{
				if (Arr[i * 2] != 0)
					parent[i]->setLeftChild(parent[i * 2]);
			}
			if (i * 2 + 1 < Size)
			{
				if (Arr[i * 2 + 1] != 0)
					parent[i]->setRightChild(parent[(i * 2) + 1]);
			}
			if (!root)
				root = parent[i];
		}
	}
}
template<class DT>
void BinaryTree<DT>::InOrder(BNode<DT>* node)
{
	if (node)
	{
		InOrder(node->getLeftChild());
		cout << node->getData() << "  ";
		InOrder(node->getRightChild());
	}
};
template<class DT>
void BinaryTree<DT>::PostOrder(BNode<DT>* node)
{
	if (node)
	{
		PostOrder(node->getLeftChild());
		PostOrder(node->getRightChild());
		cout << node->getData() << "  ";
	}
};
template<class DT>
void BinaryTree<DT>::PreOrder(BNode<DT>* node)
{
	if (node)
	{
		cout << node->getData() << "  ";
		PreOrder(node->getLeftChild());
		PreOrder(node->getRightChild());
	}
};
template<class DT>
bool identical(BNode<DT>* root1, BNode<DT>* root2)
{
	if (root1 == NULL && root2 == NULL)
	{
		return true;
	}
	else if (root1 == NULL || root2 == NULL)
	{
		return false;
	}
	else
	{
		bool cand1 = identical(root1->getLeftChild(), root2->getLeftChild());
		bool cand2 = identical(root1->getRightChild(), root2->getRightChild());
		if (cand1 && cand2)
		{
			return true;
		}
		return false;
	}
}
template<class DT>
BNode<DT>* Intersection(BNode<DT>* t1, BNode<DT>* t2)
{
	if (!t1 && !t2)
	{
		return NULL;
	}
	if (identical(t1, t2))
	{
		if (t1->getData() < t2->getData())
		{
			t1->setData(t1->getData());
		}
		else
		{
			t1->setData(t2->getData());
		}
		t1->setLeftChild(Intersection(t1->getLeftChild(), t2->getLeftChild()));
		t1->setRightChild(Intersection(t1->getRightChild(), t2->getRightChild()));
	}
	return t1;
}