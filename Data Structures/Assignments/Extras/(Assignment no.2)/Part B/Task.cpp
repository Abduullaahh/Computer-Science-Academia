#include "BinaryTree.h"
#include "BinaryTree.cpp"
int main()
{
	//Binary Tree no.1
	BinaryTree<int>* BT1 = new BinaryTree<int>();
	int Arr1[15] = { 0,1,2,3,4,5,6,7,8,9,10,0,12,13,14 };
	BT1->BuildTree(Arr1, 15);
	BNode<int>* root1 = BT1->getRoot();

	//Binary Tree no.2
	BinaryTree<int>* BT2 = new BinaryTree<int>();
	int Arr2[10] = { 0,3,7,1,4,2,5,9,2,8 };
	BT2->BuildTree(Arr2, 10);
	BNode<int>* root2 = BT2->getRoot();

	//Binary Tree no.3
	BinaryTree<int>* BT3 = new BinaryTree<int>();
	BT3->setRoot(Intersection(root1, root2));
	BNode<int>* root3 = BT3->getRoot();
	cout << "***************************************************" << endl;
	cout << "Preorder Traversal is: " << endl;
	BT3->PreOrder(root3);
	cout << endl;
	cout << "***************************************************" << endl;
	cout << "Post order Traversal is: " << endl;
	BT3->PostOrder(root3);
	cout << endl;
	cout << "***************************************************" << endl;
	cout << "Inorder Traversal is: " << endl;
	BT3->InOrder(root3);
	cout << endl;
	cout << "***************************************************" << endl;
	return 0;
}