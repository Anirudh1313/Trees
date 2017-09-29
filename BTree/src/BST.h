/*
 * BST.h
 *
 *  Created on: Jun 19, 2017
 *      Author: krishnasaianirudhkatamreddy
 */

#ifndef BST_H_
#define BST_H_

#include <string>
#include "BNode.h"

//const int MAX = 101;

using namespace std;

//class BST
//{
//public:
//	BST();
//	BST(BNode *root);
//	virtual ~BST();
//
//	BNode *get_root() { return root; }
//
//	void clear();
//	void clear(BNode* &ptr);
//
//	bool isEmpty();
//
//	bool contains(const int data) const;
//	bool contains(const int data, BNode *ptr) const;
//
//	int findmin() const throw(string);
//	int findmax() const throw(string);
//
//	int height() const;
//
//	//int depth(BNode *ptr) throw(string);
//
//	void insert(const int data);
//	void remove(const int data);
//
//	bool check() throw(string);
//	bool check(BNode* ptr);
////	BNode* minTree(int a[MAX]);
////	BNode* minTree(int a[MAX], int start, int end);
//
//protected:
//	int height(BNode* ptr) const;
//	virtual void insert(const int data, BNode* &ptr);
//	virtual void remove(const int data, BNode* &ptr);
//
//
//private:
//	BNode *root;
//
//	BNode *findmin(BNode *ptr) const;
//	BNode *findmax(BNode *ptr) const;
//
//};

class BinarySearchTree
{
public:
    BinarySearchTree();
    BinarySearchTree(BNode *root);
    //BinarySearchTree(const BinarySearchTree& rhs);
    virtual ~BinarySearchTree();

    BNode *getRoot() const;
    int height() const;
    int findMin() const throw(string);
    int findMax() const throw(string);

    void clear();
    bool isEmpty() const;
    bool contains(const int data) const;
    void insert(const int data);
    void remove(const int data);
    int depth(const BNode *ptr) const;
    void setHeight();

    bool isBalanced();
    bool isBalanced(BNode* &ptr);
    bool checkBST();
    bool checkBST(BNode *ptr);

    BNode *lca(int n1, int n2);
    BNode *lca(BNode *ptr, int n1, int n2);

    bool containsTree(BNode *ptr1, BNode *ptr2);
    bool searchTree(BNode *ptr1, BNode *ptr2);
    bool matchTree(BNode *ptr1, BNode *ptr2);



protected:
    virtual int height(const BNode *ptr) const;
    virtual void insert(const int data, BNode* &ptr);
    virtual void remove(const int data, BNode* &ptr);

private:
    BNode *root;

    void setHeight(BNode *ptr) const;
    BNode *findMin(BNode *ptr) const;
    BNode *findMax(BNode *ptr) const;
    void clear(BNode* &ptr);
    bool contains(const int data, BNode *ptr) const;
};


#endif /* BST_H_ */
