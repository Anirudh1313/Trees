#include <iostream>
#include "AvlTree.h"

using namespace std;

/**
 * Default constructor.
 */
AvlTree::AvlTree()
    : BinarySearchTree()
{
}

/**
 * Destructor.
 */
AvlTree::~AvlTree()
{
}

/**
 * Private method to compute the height of a subtree.
 * Overrides the base class method.
 * @param ptr pointer to the root node of the subtree.
 * @return the height of the subtree.
 */
int AvlTree::height(const BinaryNode *ptr) const
{
	BinaryNode::pc += 1;
    return ptr == nullptr ? -1 : ptr->height;
}

/**
 * Private method to insert a data item into a subtree
 * and set the new root of the subtree.
 * Overrides the base class method.
 * @param data the data to insert.
 * @param ptr pointer to the root node of the subtree.
 */
void AvlTree::insert(const int data, BinaryNode* &ptr)
{
	BinaryNode::pc += 1;
	BinaryNode::cc += 1;
    BinarySearchTree::insert(data, ptr);
    balance(ptr);
}

/**
 * Private method to remove a data item from a subtree
 * and set the new root node of the subtree.
 * Do nothing if the data item is not found.
 * Overrides the base class method.
 * @param data the data to remove.
 * @param ptr pointer to the root node of the subtree.
 */
void AvlTree::remove(const int data, BinaryNode* &ptr)
{
    BinarySearchTree::remove(data, ptr);
    balance(ptr);
}

/**
 * Private method to balance the tree.
 * @param ptr pointer to the node to balance.
 * @return pointer to the balanced node.
 */
BinaryNode *AvlTree::balance(BinaryNode* &ptr)
{
    if (ptr == nullptr) return ptr;

//
//    cout << "height: " << height(ptr->left) << " , " << height(ptr->right) << endl;
    // Left side too high.
    if (height(ptr->left) - height(ptr->right) > 1)
    {
        if (height(ptr->left->left) >= height(ptr->left->right))
        {
//        	int hr = height(ptr->right);
//        	int hlr = height(ptr->left->right);

            ptr = singleRightRotation(ptr);

//            ptr->right->height = max(hr, hlr) + 1;
//            cout << "    --- Single right rotation at node " << ptr->data << endl;
        }
        else
        {
            ptr = doubleLeftRightRotation(ptr);
//            cout << "    --- Double left-right rotation at node " << ptr->data << endl;
        }
    }

    // Right side too high.
    else if (height(ptr->right) - height(ptr->left) > 1)
    {
        if (height(ptr->right->right) >= height(ptr->right->left))
        {
//        		int hl = height(ptr->left);
//        		int hrl = height(ptr->right->left);
//        		int hrr = ptr->right->right->height;
            ptr = singleLeftRotation(ptr);
//            ptr->left->height = max(hl+1, hrl+1);
//            cout << "    --- Single left rotation at node " << ptr->data << endl;
        }
        else
        {
            ptr = doubleRightLeftRotation(ptr);
//            cout << "    --- Double right-left rotation at node " << ptr->data << endl;
        }
    }

     //Recompute the node's height.
    ptr->height = (max(height(ptr->left), height(ptr->right)) + 1);
//    cout << "height of ptr: " << ptr->height << endl;

    if (checkBalance(ptr) < 0)
    {
        cout << endl << "***** Tree unbalanced!" << endl;
    }

    return ptr;
}

/**
 * Case 1 (outside left-left): Rebalance with a single right rotation.
 * Update heights and return the new root node.
 * @param k2 pointer to the node to rotate.
 * @return pointer to the new root node.
 */
BinaryNode *AvlTree::singleRightRotation(BinaryNode *k2)
{
	BinaryNode *plr =  k2->left;

	BinaryNode::pc += 4;
	//BinaryNode::cc += 4;
	int hr = height(k2->right);
	int hlr = height(k2->left->right);

	k2->left = plr->right;
	plr->right = k2;



	k2 = plr;
	BinaryNode::cc += 1;
	k2->right->height = max(hr, hlr) + 1;
	return k2;

}

/**
 * Case 2 (inside left-right): Rebalance with a double left-right rotation.
 * @param k3 pointer to the node to rotate.
 * @return pointer to the new root node.
 */
BinaryNode *AvlTree::doubleLeftRightRotation(BinaryNode *k3)
{
//	BinaryNode *pl = k3->left;
//	BinaryNode *plr = pl->right;
//	BinaryNode *plrl = plr->left;
//
//	k3->left = plr;
//	plr->left = pl;
//	pl->right = plrl;
//
//	k3->left = plr->right;
//	plr->right = k3;
//
//	k3 = plr;



	BinaryNode *ptr = singleLeftRotation(k3->left);
	k3->left = ptr;

	BinaryNode *ptr1 = singleRightRotation(k3);
	return ptr1;



    /***** Complete this member function. *****/
}

/**
 * Case 3 (inside right-left): Rebalance with a double left rotation.
 * @param k1 pointer to the node to rotate.
 * @return pointer to the new root node.
 */
BinaryNode *AvlTree::doubleRightLeftRotation(BinaryNode *k1)
{
//	BinaryNode *pr = k1->right;
//	BinaryNode *prl = pr->left;
//
//	pr->left = prl->right;
//	prl->right = pr;
//	k1->right = prl;
//
//	k1->right = prl->left;
//	prl->left = k1;
//
//	k1 = prl;
//	return k1;

	BinaryNode *ptr = singleRightRotation(k1->right);
	k1->right = ptr;

	BinaryNode *ptr1 = singleLeftRotation(k1);
	return ptr1;
    /***** Complete this member function. *****/
}

/**
 * Case 4 (outside right-right): Rebalance with a single left rotation.
 * Update heights and return the new root node.
 * @param k2 pointer to the node to rotate.
 * @return pointer to the new root node.
 */
BinaryNode *AvlTree::singleLeftRotation(BinaryNode *k1)
{
	BinaryNode *pr = k1->right;

	int hl = height(k1->left);
	int hrl = height(k1->right->left);
//	int hrr = k1->right->right->height;

	BinaryNode::pc += 4;
	//BinaryNode::cc += 4;

	k1->right = pr->left;
	pr->left = k1;

//	k1->left = nullptr;
//	pr->right->right = nullptr;
////	pr->right->height = hrr;
//	k1->height = max(k1->left->height+1, k1->right->height+1);

	k1 = pr;
	BinaryNode::cc += 1;
    k1->left->height = max(hl+1, hrl+1);

	return k1;
    /***** Complete this member function. *****/
}

/**
 * Private method for a paranoid check of whether a tree node is balanced.
 * @param ptr pointer to the node to check.
 * @return the height of the node if balanced, -1 if the node is null,
 *         or -2 if unbalanced.
 */
int AvlTree::checkBalance(BinaryNode *ptr)
{
    if (ptr == nullptr) return -1;

    int leftHeight  = checkBalance(ptr->left);
    int rightHeight = checkBalance(ptr->right);

    if ((abs(height(ptr->left) - height(ptr->right)) > 1) || (height(ptr->left)  != leftHeight) || (height(ptr->right) != rightHeight))
    {
        return -2;       // unbalanced
    }

    return height(ptr);  // balanced
}
