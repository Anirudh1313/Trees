#ifndef BINARY_NODE_H
#define BINARY_NODE_H

class BinaryNode
{
public:
	BinaryNode();
    BinaryNode(int data);
    BinaryNode(const int data, BinaryNode *left, BinaryNode *right);
    virtual ~BinaryNode();

    int data;
    int height;  // node height

   static long pc;
   static long cc;

    BinaryNode *left;
    BinaryNode *right;
};


#endif // BINARY_TREE_PRINTER_H
