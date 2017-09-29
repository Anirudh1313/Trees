/*
 * BNode.h
 *
 *  Created on: Jun 19, 2017
 *      Author: krishnasaianirudhkatamreddy
 */

#ifndef BNODE_H_
#define BNODE_H_


class BNode
{
public:
	BNode();
	BNode(int data);
	BNode(int data, BNode *left, BNode *right);
	virtual ~BNode();

	bool operator ==(const BNode& other);
	bool operator >(const BNode& other);
	bool operator <(const BNode& other);

	int height;
	int data;
	BNode *left;
	BNode *right;
};


#endif /* BNODE_H_ */
