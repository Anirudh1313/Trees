#include <string>
#include <stdlib.h>
#include "BST.h"

using namespace std;

/**
 * Default constructor
 */

BinarySearchTree::BinarySearchTree() : root(nullptr)
{

}

BinarySearchTree::BinarySearchTree(BNode *root) : root(root)
{
}

/**
 * Destructor
 */

BinarySearchTree::~BinarySearchTree()
{
    clear();
}

/**
 * @return pointer to the root of the tree.
 */

BNode *BinarySearchTree::getRoot() const
{
    return root;
}

/**
 * Public method to return the height of a subtree.
 * @return the height.
 */



void BinarySearchTree::setHeight()
{
	setHeight(root);
}

void BinarySearchTree::setHeight(BNode *ptr) const
{
//	if(ptr == nullptr)
//		return;
//
//	ptr->height = 1+max(height(ptr->left), height(ptr->right));
//	setHeight(ptr->left);
//	setHeight(ptr->right);
	if(ptr == nullptr)
		return;

	ptr->height = depth(ptr);
	setHeight(ptr->left);
	setHeight(ptr->right);
}

int BinarySearchTree::depth(const BNode *ptr) const
{
	BNode *r = root;
	int i = 0;
	while(ptr != nullptr)
	{
		if(ptr->data > r->data)
		{
			i++;
			r = r->right;
		}
		else if(ptr->data < r->data)
		{
			i++;
			r = r->left;
		}
		else
		{
			return i;
		}
	}

	return -1;
}

int BinarySearchTree::height() const
{
    return height(root);
}

/**
 * Protected method to compute the height of a subtree.
 * @param ptr pointer to the root node of the subtree.
 * @return the height.
 */
int BinarySearchTree::height(const BNode *ptr) const
{

    return ptr == nullptr ? -1 : 1 + max(height(ptr->left), height(ptr->right));
}

/**
 * Public method to find the minimum data item in a subtree.
 * @return the minimum data item in the tree
 *         or nullptr if the tree is empty.
 */
int BinarySearchTree::findMin() const throw(string)
{
    if (isEmpty()) throw(string("Empty tree"));
    return findMin(root)->data;
}

/**
 * Private method to find the minimum data item in a subtree.
 * @param ptr pointer to the root node of the subtree.
 * @return pointer to the node containing the smallest data item
 *         or nullptr if the subtree is empty.
 */
BNode *BinarySearchTree::findMin(BNode *ptr) const
{
    if (ptr != nullptr)
    {
        while(ptr->left != nullptr) ptr = ptr->left;
    }

    return ptr;
}

/**
 * Public method to find the maximum data item in a subtree.
 * @return pointer to the maximum data item in the tree
 *         or nullptr if the tree is empty.
 */
int BinarySearchTree::findMax() const throw(string)
{
    if (isEmpty()) throw(string("Empty tree"));
    return findMax(root)->data;
}

/**
 * Private method to find the maximum data item in a subtree.
 * @param ptr pointer to the root node of the subtree.
 * @return pointer to the node containing the largest data item
 *         or nullptr if the subtree is empty.
 */
BNode *BinarySearchTree::findMax(BNode *ptr) const
{
    if (ptr != nullptr)
    {

        while(ptr->right != nullptr) ptr = ptr->right;
    }

    return ptr;
}

/**
 * Public method to empty a subtree.
 */

void BinarySearchTree::clear()
{
    clear(root);
}

/**
 * Private method to empty a subtree.
 * @param ptr pointer to the root node of the subtree.
 */

void BinarySearchTree::clear(BNode* &ptr)
{
    if (ptr != nullptr)
    {
        clear(ptr->left);
        clear(ptr->right);
        delete ptr;
        ptr = nullptr;
    }
}

/**
 * @return true if and only if the tree is empty.
 */
bool BinarySearchTree::isEmpty() const
{
    return root == nullptr;
}

/**
 * Public method to search for a data item in the tree.
 * @param data the data to search for.
 * @return true if and only if data is in the tree.
 */
bool BinarySearchTree::contains(const int data) const
{
    return contains(data, root);
}

/**
 * Private method to search for a data item in a subtree.
 * @param data the data to search for.
 * @param ptr pointer to the root node of the subtree.
 * @return true if and only if data is in the tree.
 */
bool BinarySearchTree::contains(const int data, BNode *ptr) const
{
    while (ptr != nullptr)
    {
        if (data < ptr->data)
        {
            ptr = ptr->left;
        }
        else if (data > ptr->data)
        {
            ptr = ptr->right;
        }
        else
        {
            return true;  // found
        }
    }

    return false;         // not found
}

/**
 * Public method to insert a data item into a subtree
 * and set the new root of the subtree.
 * @param data the data to insert into the tree.
 */
void BinarySearchTree::insert(const int data)
{
    insert(data, root);
}

/**
 * Protected method to insert a data item into a subtree
 * and set the new root of the subtree.
 * @param data the data to insert.
 * @param ptr pointer to the root node of the subtree.
 */
void BinarySearchTree::insert(const int data, BNode* &ptr)
{
    if (ptr == nullptr)
    {
        ptr = new BNode(data);
    }
    else
    {
        if (data < ptr->data)
        {
            insert(data, ptr->left);
        }
        else if (data > ptr->data)
        {
            insert(data, ptr->right);
        }
    }
}

/**
 * Public method to remove a data item from a subtree
 * and set the new root of the subtree.
 * Do nothing if the data item is not found.
 * @param data the data to remove.
 */
void BinarySearchTree::remove(const int data)
{
    remove(data, root);
}

/**
 * Protected method to remove a data item from a subtree
 * and set the new root of the subtree.
 * Do nothing if the data item is not found.
 * @param data the data to remove.
 * @param ptr pointer to the root node of the subtree.
 */
void BinarySearchTree::remove(const int data, BNode* &ptr)
{
    if (ptr == nullptr) return;   // not found, so do nothing

    // First search for the target node to remove.
    if (data < ptr->data)
    {
        remove(data, ptr->left);
    }
    else if (data > ptr->data)
    {
        remove(data, ptr->right);
    }

    // Remove a target node with two children.
    else if ((ptr->left  != nullptr) && (ptr->right != nullptr))
    {
        // Replace the target node's data with the successor node's data.
        ptr->data = findMin(ptr->right)->data;

        // Search for and remove the successor node.
        remove(ptr->data, ptr->right);
    }

    // Remove a target node with one or no children.
    else
    {
        BNode *oldNode = ptr;
        ptr = (ptr->left != nullptr) ? ptr->left
                                     : ptr->right;
        delete oldNode;
    }
}



//BNode *minTree(int a[], int start, int end)
//{
//
//	if(end < start)
//		return nullptr;
//	int mid = (start + end)/2;
//	BNode *ptr = new BNode(a[mid]);
//	ptr->left = minTree(a, start, mid-1);
//	ptr->right = minTree(a, mid+1, end);
//	return ptr;
//
//}
bool BinarySearchTree::isBalanced() //checking if the tree is balanced are not, height should be less than
{
	if(!isBalanced(root))
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool BinarySearchTree::isBalanced(BNode* &ptr)
{
	if(ptr == nullptr)
		return true;

	int heightdiff = height(ptr->left) - height(ptr->right);

	if(abs(heightdiff) > 1)
	{
		return false;
	}
	else
	{
		return isBalanced(ptr->left) && isBalanced(ptr->right);
	}


//    if (ptr == nullptr) return -1;
//
//    int leftHeight  = isBalanced(ptr->left);
//    int rightHeight = isBalanced(ptr->right);
//
//    if ((abs(height(ptr->left) - height(ptr->right)) > 1) || (height(ptr->left)  != leftHeight) || (height(ptr->right) != rightHeight))
//    {
//        return -2;       // unbalanced
//    }
//
//    return height(ptr);

//	if(ptr == nullptr)
//		return true;
//
//	int h = height(ptr->left) - height(ptr->right);
//	if(abs(h) <= 1 && isBalanced(ptr->left) && isBalanced(ptr->right))
//		return true;
//
//	return false;
}

bool BinarySearchTree::checkBST()   //check whether tree is a binary Search Tree or not.
{
	return checkBST(root);
}
bool BinarySearchTree::checkBST(BNode *ptr) //in a binary tree all the nodes on the left side should be
//                                            less than the node and all the nodes on the right side should be greater than node
{
	//=============
	//base rule:-
	//=============
	if(ptr == nullptr)
	{
		return true;
	}

	//=============
	//condition:-
	//=============
	//BST CONDITION:
	//ptr->left->data should be less than ptr->data     &&     ptr->right->data should be greater than the ptr->data.

	if(ptr->left != nullptr && ptr->data < ptr->left->data)
	{
		return false;
	}
	if((ptr->right != nullptr && ptr->data >= ptr->right->data))
	{
		return false;
	}

	//Recursive function to check for all the left and right nodes.
	if(!checkBST(ptr->left) || !checkBST(ptr->right)) //even if one node doesn't satisfy the situation, it returns false
	{
		return false;
	}

	//all nodes should satisfy the condition
	return true;

}

BNode *BinarySearchTree::lca(int n1, int n2)  //least common ancestor for two nodes
{
	return lca(root, n1, n2);
}

BNode *BinarySearchTree::lca(BNode *ptr, int n1, int n2)
{
	if(ptr == nullptr)
		return nullptr;

	if(ptr->data > n1 && ptr->data > n2)
	{
		return lca(ptr->left, n1, n2);
	}
	else if(ptr->data < n1 && ptr->data < n2)
	{
		return lca(ptr->right, n1, n2);
	}

	return ptr;

}

//============================================================================
//check if a BST is present in a BST

bool BinarySearchTree::containsTree(BNode *ptr1, BNode *ptr2)
{
	if(ptr2 == nullptr)
		return true;

	return searchTree(ptr1, ptr2);
}

bool BinarySearchTree::searchTree(BNode *ptr1, BNode *ptr2)    //Search for the root node of the 2nd tree
{
	if(ptr1 == nullptr)
		return false;
	else if(ptr1->data == ptr2->data && matchTree(ptr1, ptr2))
	{
		return true;
	}

	return searchTree(ptr1->left, ptr2) || searchTree(ptr1->right, ptr2);
}

bool BinarySearchTree::matchTree(BNode *ptr1, BNode *ptr2)  //check if all the nodes are matching are not
{
	if(ptr1 == nullptr && ptr2 == nullptr)
		return true;
	else if(ptr1 == nullptr || ptr2 == nullptr)
		return false;
	else if(ptr1->data != ptr2->data)
		return false;
	else
		return matchTree(ptr1->left, ptr1->left) && matchTree(ptr1->right, ptr2->right);
}


