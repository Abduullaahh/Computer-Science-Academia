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
};
template <class DT>
int BinaryTree<DT>::calculateDepth(BNode<DT>* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		int leftDepth = calculateDepth(root->getLeftChild());
		int rightDepth = calculateDepth(root->getRightChild());
		if (leftDepth > rightDepth)
		{
			return leftDepth + 1;
		}
		else
		{
			return rightDepth + 1;
		}
	}
};
template <class DT>
int BinaryTree<DT>::countNodes(BNode<DT>* r)
{
	if (r == NULL)
		return 0;
	return 1 + countNodes(r->getRightChild()) + countNodes(r->getLeftChild());
}
template <class DT>
int BinaryTree<DT>::check(BNode<DT>* r)
{
	if (r == NULL)
		return true;
	int h = calculateDepth(r);
	int n = countNodes(r);
	if (n == pow(2, h) - 1)
		return 1;
	else
		return 0;
}
template <class DT>
bool BinaryTree<DT>::isComplete()
{
	if (check(root))
	{
		return true;
	}
	else
	{
		return false;
	}
}
template <class DT>
bool BinaryTree<DT>::isNodePresent(BNode<DT>* root, BNode<DT>* node)
{
	if (root == nullptr)
	{
		return false;
	}
	if (root == node)
	{
		return true;
	}
	return isNodePresent(root->getLeftChild(), node) || isNodePresent(root->getRightChild(), node);
}
template <class DT>
bool BinaryTree<DT>::findLCA(BNode<DT>* root, BNode<DT>*& lca, BNode<DT>* x, BNode<DT>* y)
{
	if (root == NULL)
	{
		return false;
	}
	if (root == x || root == y)
	{
		lca = root;
		return true;
	}
	bool left = findLCA(root->getLeftChild(), lca, x, y);
	bool right = findLCA(root->getRightChild(), lca, x, y);
	if (left && right)
	{
		lca = root;
	}
	return left || right;
}
template <class DT>
BNode<DT>* BinaryTree<DT>::lowest_common_ancestor(BNode<DT>* a, BNode<DT>* b)
{
	BNode<DT>* lca = NULL;
	if (isNodePresent(root, b) && isNodePresent(root, a))
	{
		findLCA(root, lca, a, b);
	}
	if (lca != nullptr)
	{
		return lca;
	}
	else
	{
		return NULL;
	}
}
template <class DT>
int BinaryTree<DT>::numberofNodesAtLevel(int klevel)
{
	queue <BNode <DT>*>* q = new queue <BNode <DT>*>();
	int level = 1;
	int flag = 0;
	q->push(root);
	q->push(NULL);
	while (!q->empty())
	{
		BNode<DT>* temp = q->front();
		if (level == klevel && temp != NULL)
		{
			flag = 1;
			cout << temp->getData() << " ";
		}
		q->pop();
		if (temp == NULL)
		{
			if (q->front())
				q->push(NULL);
			level += 1;
			if (level > klevel)
				break;
		}
		else
		{
			if (temp->getLeftChild())
				q->push(temp->getLeftChild());
			if (temp->getRightChild())
				q->push(temp->getRightChild());
		}
	}
	cout << endl;
	return flag;
}