/*
 * BNode.cpp

 *
 *  Created on: Jun 19, 2017
 *      Author: krishnasaianirudhkatamreddy
 #*/

#include "BNode.h"


BNode::BNode() : data(0), height(0), left(nullptr), right(nullptr) {}

BNode::BNode(int data) : data(data), height(0), left(nullptr), right(nullptr) {}

BNode::BNode(int data, BNode *l, BNode *r) : data(data), height(0), left(l), right(r) {}

BNode::~BNode() {}

bool BNode::operator ==(const BNode& other)
{
	return data == other.data;
}

bool BNode::operator <(const BNode& other)
{
	return data < other.data;
}

bool BNode::operator >(const BNode& other)
{
	return data > other.data;
}



