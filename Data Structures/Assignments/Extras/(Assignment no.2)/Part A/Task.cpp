#include "BinaryTree.h"
#include "BinaryTree.cpp"
int main()
{
	BinaryTree<int>* BT = new BinaryTree<int>();
	int Arr[8] = { 0,1,2,3,4,5,6,7 };
	BT->BuildTree(Arr, 8);
	BNode<int>* root = BT->getRoot();
	//Part i:
	if (BT->isComplete())
	{
		cout << "Tree is Complete" << endl;
	}
	else
	{
		cout << "Tree is not Complete" << endl;
	}
	//Part ii:
	cout << "Number of nodes at Level 2 is : ";
	BT->numberofNodesAtLevel(2);
	//Part iii:
	BNode<int>* a = root->getLeftChild();
	BNode<int>* b = root->getRightChild();
	if (BT->lowest_common_ancestor(a, b))
	{
		cout << "lowest common ancestor of node " << a->getData() << " and " << b->getData() << " is: " << BT->lowest_common_ancestor(a, b)->getData() << endl;
	}
	else
	{
		cout << " Not found " << endl;
	}
	return 0;
}