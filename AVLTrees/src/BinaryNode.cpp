 #include "BinaryNode.h"

/**
 * Constructor.
 * @param data the data item.
 */
long BinaryNode::pc;
long BinaryNode::cc;
BinaryNode::BinaryNode() :  data(0), height(0), left(nullptr), right(nullptr) {}

BinaryNode::BinaryNode(int data) : data(data), height(0), left(nullptr), right(nullptr) {}

/**
 * Constructor.
 * @param data the data item.
 * @param left the left link.
 * @param right the right link.
 */
BinaryNode::BinaryNode(const int data, BinaryNode *left, BinaryNode *right) : data(data), height(0), left(left), right(right) {}

/**
 * Destructor.
 */
BinaryNode::~BinaryNode() {}
