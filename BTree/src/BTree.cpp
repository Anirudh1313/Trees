//============================================================================
// Name        : BTree.cpp
// Author      : anirudh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include "BST.h"

using namespace std;

/* ALGORITHM-1:
 *
 * requirement:
 *
 */
BNode *minTree(int a[], int start, int end) //constructing a BST with minimum height.
{
	if(end < start)
		return nullptr;

	int mid = (start + end)/2;
	BNode *ptr = new BNode(a[mid]);
	ptr->left = minTree(a, start, mid-1);
	ptr->right = minTree(a, mid+1, end);
	return ptr;
}

void preorder(BNode *ptr)
{
	if(ptr == nullptr)
		return;

	cout << ptr->data << " ";
	preorder(ptr->left);
	preorder(ptr->right);
}

void postorder(BNode *ptr)
{
	if(ptr == nullptr)
		return;
	postorder(ptr->left);
	postorder(ptr->right);
	cout << ptr->data << " ";
}

void listForDifferentDepths(BNode *ptr, list<int> list[])
{
	if(ptr == nullptr)
		return;

	list[ptr->height].push_back(ptr->data);  //ptr->height depth of the ptr in BST.
	cout << ptr->data << " ";
	listForDifferentDepths(ptr->left, list);
	listForDifferentDepths(ptr->right, list);
}

void reorder(BNode *ptr)
{
	if(ptr == nullptr)
		return;
	reorder(ptr->left);
	cout << ptr->data << " ";
	reorder(ptr->right);
}

int main()
{
	BinarySearchTree b1;

	int a[20];
	for(int i = 0; i < 20; i++)
	{
		a[i] = i;
	}

	int n = sizeof(a)/sizeof(a[0]);

	b1.insert(2);
	cout << b1.findMin() << endl;

	BNode *ptr = minTree(a, 0, n-1);

	BinarySearchTree b2(ptr);
//	b2.insert(101);
//	b2.insert(102);
//	b2.insert(100);

	b2.setHeight();
	cout << "* " << ptr->height << endl;


	cout << endl;
	cout << "Tree elements: ";
	int h = b2.height()+1;
	list<int> list1[h];
	listForDifferentDepths(ptr, list1);

	list<int>::iterator it;

	for(int i = 0; i < h; i++)
	{
		cout << "\nlist-" << i << ": ";
		for(it = list1[i].begin(); it != list1[i].end(); it++)
		{
			cout << " " << *it;
		}
	}
	cout << endl;
	//cout << ptr->data << endl;
//
	if(b2.isBalanced())
	{
		cout << "The tree is balanced!" << endl;
	}
	else
	{
		cout << "The tree is not balanced!" << endl;
	}

//	b2.checkBST()? cout << "Yes!, its a BST!" << endl : cout << "No! its not a BST!" << endl;


//	while(ptr->right != nullptr)  //going to the last node;
//	{
//		ptr = ptr->right;
//	}
//	//ptr->right = new BNode(5);
//	cout << "** " << b2.depth(ptr) << endl;
//	cout << ptr->right->data << endl;


	/*===================================
	 *checking whether the tree is a BST
	 *===================================
	*/
	b2.checkBST()? cout << "Yes!, its a BST!" << endl : cout << "No! its not a BST!" << endl;


	/*===============================================================
	 *finding the least common ancestor of the two nodes in the tree
	 *===============================================================
	*/
	BNode *lcaptr = b2.lca(1, 6);
	cout << "lca value: " << lcaptr->data << endl;

	/*===================================================================================================
	 *moving the ptr2 to right side and checking whether the pointers tree is a sub tree of the main tree
	 *===================================================================================================
	*/
	BNode *ptr2 = ptr;
	for(int j = 2; j > 0; j--)
	{
		ptr2 = ptr2->right;
	}
	//BNode *ptr1 = new BNode(4);
	if(b2.containsTree(ptr, ptr2))
		cout << "Yes! " << ptr2->data << " is sub-tree of " << ptr->data <<"." << endl;
	else
		cout << "No! " << ptr2->data << " is not sub-tree of " << ptr->data <<"." << endl;


	cout << "\nPreorder traversal: ";
	preorder(b2.getRoot());
	cout << "\nReorder traversal: ";
	reorder(b2.getRoot());
	cout << "\nPostorder traversal: ";
	postorder(b2.getRoot());

	return 0;

}

//BNode *minTree(int a[MAX], BNode *ptr)
//{
//	return minTree(a, 0, sizeof(a), ptr);
//}
//
//BNode *minTree(int a[MAX], int start, int end, BNode *ptr)
//{
//
//	if(end < start)
//		return nullptr;
//	int mid = (start + end)/2;
//	ptr = new BNode(a[mid]);
//	ptr->left = minTree(a, start, mid-1, ptr);
//	ptr->right = minTree(a, mid+1, end, ptr);
//	return ptr;
//
//}

//	cout << ptr->data << endl;
//	preorder(ptr);
//
//	cout << endl;
//	cout << ptr->data << endl;
//	reorder(ptr);
//	cout << endl;
//	cout << ptr->data << endl;
//
//
//	cout << "height: " << b2.height() << endl;
//	cout << "depth: " << b2.depth(ptr->right->left) << endl;

