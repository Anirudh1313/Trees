///**
// * Test the binary search tree and AVL tree implementations.
// * The AVL tree is derived from the binary search tree.
// *
// * Create a tree of height 5 and then repeatedly
// * delete the root. The AVL tree should remain balanced
// * after each node insertion and deletion.
// */
//
//#include <iostream>
//#include <vector>
//#include <time.h>
//
//#include "BinarySearchTree.h"
//#include "AvlTree.h"
//#include "BinaryTreeChecker.h"
//#include "BinaryTreePrinter.h"
//
//using namespace std;
//
//const bool DUMP = false;
//
//void testBST();
//void testAVL();
//
//void buildTree(BinarySearchTree& tree,
//               BinaryTreeChecker& checker,
//               BinaryTreePrinter& printer,
//               string kind);
//
//void dismantleTree(BinarySearchTree& tree,
//                   BinaryTreeChecker& checker,
//                   BinaryTreePrinter& printer);
//
///**
// * Main.
// */
//int main( )
//{
//    testBST();
//    testAVL();
//}
//
///**
// * Run the test with a binary search tree.
// */
//void testBST()
//{
//    cout << endl;
//    cout << "**********************" << endl;
//    cout << "* BINARY SEARCH TREE *" << endl;
//    cout << "**********************" << endl;
//
//    BinarySearchTree  tree;
//    BinaryTreeChecker checker(tree);
//    BinaryTreePrinter printer(tree);
//
//    buildTree(tree, checker, printer, "BST");
//    dismantleTree(tree, checker, printer);
//}
//
///**
// * Run the test with an AVL tree.
// */
//void testAVL()
//{
//    cout << endl;
//    cout << "************" << endl;
//    cout << "* AVL TREE *" << endl;
//    cout << "************" << endl;
//
//    AvlTree tree;
//    BinaryTreeChecker checker(tree);
//    BinaryTreePrinter printer(tree);
//
//    buildTree(tree, checker, printer, "AVL");
//    dismantleTree(tree, checker, printer);
//}
//
//static const int VALUES[] = {
//    62,71,29,88,11,41,21,66,57,27,39,40,77,20,51,49,82,37,
//    94,63,76,91,70,64,60,90,12,80,23,10,52,35,96,75,28
//};
//
///**
// * Build a binary search tree containing unique random integer data items.
// * @param tree the tree to make.
// * @param maxNodes the maximum number of nodes to generate.
// * @param checker the binary tree checker to use.
// * @param printer the binary tree printer to use.
// * @param insertPrint true iff print a message after each node insertion
// */
//void buildTree(BinarySearchTree& tree,
//              BinaryTreeChecker& checker,
//              BinaryTreePrinter& printer,
//              string kind)
//{
//    for (int n : VALUES)
//    {
//        cout << endl << "Inserted node " << n << ":" << endl;
//
//        tree.insert(n);  // insert into tree
//        checker.add(n);  // store with the tree checker
//
//        cout << endl;
//        printer.print();
//    }
//
//    cout << endl;
//    cout << "*****" << endl;
//    cout << "***** COMPLETED " << kind << " TREE:" << endl;
//    cout << "*****" << endl << endl;
//    printer.print();
//}
//
///**
// * Dismantle a binary tree.
// * @param tree the tree to test.
// * @param checker the binary tree checker to use.
// * @param printer the binary tree printer to use.
// */
//void dismantleTree(BinarySearchTree& tree,
//                   BinaryTreeChecker& checker,
//                   BinaryTreePrinter& printer)
//{
//    int status = BinaryTreeChecker::NO_ERROR;
//
//    // Delete the root node each time through the loop.
//    // Print the tree after each deletion.
//    while (!tree.isEmpty())
//    {
//        BinaryNode *root = tree.getRoot();
//        int data = root->data;
//        cout << endl << "Deleted root node " << data << ":" << endl;
//
//        tree.remove(data);
//        checker.remove(data);
//
//        cout << endl;
//        printer.print();
//
//        status = checker.check(DUMP);
//        if (status != BinaryTreeChecker::NO_ERROR) break;
//    }
//
//    // What was the status?
//    string msg;
//    switch (status)
//    {
//        case BinaryTreeChecker::NO_ERROR:
//        {
//            msg = ">>>>> The tree is now empty.";
//            break;
//        }
//        case BinaryTreeChecker::DATA_MISMATCH:
//        {
//            msg =  ">>>>> Data mismatch.";
//            break;
//        }
//        case BinaryTreeChecker::INSUFFICIENT_DATA:
//        {
//            msg =  ">>>>> Data missing from tree.";
//            break;
//        }
//        case BinaryTreeChecker::REMAINING_DATA:
//        {
//            msg =  ">>>>> Data remaining in tree.";
//            break;
//        }
//    }
//    cout << msg << endl;
//}

#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <iomanip>
#include <chrono>



#include "BinarySearchTree.h"
#include "AvlTree.h"
//#include "BinaryTreeChecker.h"
//#include "BinaryTreePrinter.h"

using namespace std;
using namespace std::chrono;

//const bool DUMP = false;

const int MAX = 1000000;

void testBST(int val[MAX], int i, int n);
void testAVL(int val[MAX], int i, int n);

void buildTree(BinarySearchTree& tree, string kind, long time, int val[MAX], int i, int n);
void dismantleTree(BinarySearchTree& tree, long time);

/**
 * Main.
 */
//static int val[max];
int main( )
{
    int val[MAX];
    cout << "**********************************************************************************************|***********************************************************************************" << endl;
    cout << "* SIZE ******************************** BINARY SEARCH TREE ***********************************|*********************************      AVL TREE     *******************************" << endl;
    cout << "**********************************************************************************************|***********************************************************************************" << endl;

    cout << "           Insertion probe_count compare_count     search probe_count compare_count   delete  |  Insertion probe_count compare_count     search probe_count compare_count   delete" << endl;
    for(int n = 1000; n <= 10000; n += 1000)
    {
        cout << setw(6) << right << n;

        srand(time(NULL));
        for(int i = 0; i < n; i++)
        {
        	val[i] = rand()%10000;
        }
        int i = 0;
        testBST(val, i, n);
        i = 0;
        testAVL(val, i, n);
        cout << endl;
    }

}

/**
 * Run the test with a binary search tree.
 */
void testBST(int val[MAX], int i, int n)
{


    BinarySearchTree  tree;
    //BinaryTreeChecker checker(tree);
    //BinaryTreePrinter printer(tree);
    long time = 0;

    buildTree(tree, "BST", time, val, i, n);
    time = 0;
    dismantleTree(tree, time);
}

/**
 * Run the test with an AVL tree.
 */
void testAVL(int val[MAX], int i, int n)
{


    AvlTree tree;
    //BinaryTreeChecker checker(tree);
    //BinaryTreePrinter printer(tree);
    long time = 0;


    buildTree(tree, "AVL", time, val, i, n);

    time = 0;

    dismantleTree(tree, time);

    time = 0;
}

//static int VALUES[] = {123213,2443,232,132,23,423,32,324,324,234,234,4,2432,432,43,43,4,44,34,4,24,234,234,234,324,34,324,243,43,432,4324,324,24,25,55,65,77,4576,5756,75,7658,57,67,587,87,867,87,87,87,878,8,7,8768,78,768,67867,856,756435,5,758,455,467,5686,67,75,765,856,37,47,557,84,6,868,686,5,856,58,57};


/**
 * Build a binary search tree containing unique random integer data items.
 * @param tree the tree to make.
 * @param maxNodes the maximum number of nodes to generate.
 * @param checker the binary tree checker to use.
 * @param printer the binary tree printer to use.
 * @param insertPrint true iff print a message after each node insertion
 */
void buildTree(BinarySearchTree& tree, string kind, long time, int val[MAX], int i, int n)
{
	time = 0;
    for(i = 0; i < n; i++)
    {
        steady_clock::time_point start_time = steady_clock::now();

        tree.insert(val[i]);  // insert into tree
        //checker.add(val[i]);  // store with the tree checker

        steady_clock::time_point end_time = steady_clock::now();
        long elapsed_time = duration_cast<microseconds>(end_time - start_time).count();

        time += elapsed_time;
//        cout << endl;
//        printer.print();
    }

    cout << " " << time << " ms " << BinaryNode::pc << " " << BinaryNode::cc;
//    cout << endl;
//    cout << "*****" << endl;
//    cout << "***** COMPLETED " << kind << " TREE:" << endl;
//    cout << "*****" << endl << endl;

    time = 0;
    BinaryNode::pc = 0;
    BinaryNode::cc = 0;

    for (i = 0; i < n; i++)
    {
        steady_clock::time_point start_time = steady_clock::now();

        tree.contains(val[i]);  // insert into tree
        //checker.add(val[i]);  // store with the tree checker

        steady_clock::time_point end_time = steady_clock::now();
        long elapsed_time = duration_cast<microseconds>(end_time - start_time).count();

        time += elapsed_time;
//        cout << endl;
//        printer.print();
    }
    cout << " " << time << " ms " << BinaryNode::pc << " " << BinaryNode::cc;
    //printer.print();
    time = 0;
}

/**
 * Dismantle a binary tree.
 * @param tree the tree to test.
 * @param checker the binary tree checker to use.
 * @param printer the binary tree printer to use.
 */
void dismantleTree(BinarySearchTree& tree, long time)
{
    //int status = BinaryTreeChecker::NO_ERROR;

    // Delete the root node each time through the loop.
    // Print the tree after each deletion.
    time = 0;
    while (!tree.isEmpty())
    {
        BinaryNode *root = tree.getRoot();
        int data = root->data;
//        cout << endl << "Deleted root node " << data << ":" << endl;
        steady_clock::time_point start_time = steady_clock::now();

        tree.remove(data);
        //checker.remove(data);

        steady_clock::time_point end_time = steady_clock::now();
        long elapsed_time = duration_cast<microseconds>(end_time - start_time).count();

        time += elapsed_time;

//        cout << endl;
//        printer.print();

//        status = checker.check(DUMP);
//        if (status != BinaryTreeChecker::NO_ERROR) break;
    }

    // What was the status?
//    string msg;
//    switch (status)
//    {
//        case BinaryTreeChecker::NO_ERROR:
//        {
//            msg = ">>>>> The tree is now empty.";
//            break;
//        }
//        case BinaryTreeChecker::DATA_MISMATCH:
//        {
//            msg =  ">>>>> Data mismatch.";
//            break;
//        }
//        case BinaryTreeChecker::INSUFFICIENT_DATA:
//        {
//            msg =  ">>>>> Data missing from tree.";
//            break;
//        }
//        case BinaryTreeChecker::REMAINING_DATA:
//        {
//            msg =  ">>>>> Data remaining in tree.";
//            break;
//        }
//    }
//    cout << msg << endl;
    cout << " " << time << " ms";
}


