// testTree.cpp - Unit test for Binary Search Tree constructors (Integers).
// Results: March data (Passed)
//
// Author Andreas Lau
// Modified on 07/04/2020
//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------
// Includes

#include <iostream>
#include <fstream>

#include "BSTree.h"
#include "date.h"
//--------------------------------------------------------------------------------------------

void testIntTextFile(void);

int main()
{
    testIntTextFile();
    return(0);
}


void printKey(int key)
{
    std::cout << key << ", ";
}

void testIntTextFile(void)
{
    std::ifstream inFile("./data/intTestData.txt");
    if(!inFile)
        exit(-1);
    std::string input;

    BST<int> testTree;

    while(getline(inFile, input, ','))
    {
        testTree.AddLeaf(stoi(input));
    }

    std::cout << "Tree 1:\nIn order traversal: ";
    testTree.ProcessInOrder(printKey);
    std::cout << std::endl << std::endl;

    std::cout << "Pre order traversal: ";
    testTree.ProcessPreOrder(printKey);
    std::cout << std::endl << std::endl;

    std::cout << "Post order traversal: ";
    testTree.ProcessPostOrder(printKey);
    std::cout << std::endl << std::endl;

    int srch1 = 2;
    int srch2 = 7;

    std::cout << srch1;
    if(testTree.SearchKey(srch1))
        std::cout << " found in tree\n";
    else
        std::cout << " not found in tree\n";
    std::cout << std::endl;

    std::cout << srch2;
    if(testTree.SearchKey(srch2))
        std::cout << " found in tree\n";
    else
        std::cout << " not found in tree\n";
    std::cout << std::endl;

    BST<int> testTree2;
    testTree2 = testTree;

    testTree2.DeleteNode(2);
    testTree2.DeleteNode(50);
    testTree2.DeleteNode(100);
    testTree2.DeleteNode(87);

    std::cout << "Deleted 2, 50, 87 & 100 from tree 2 after copy, If different, deep copy successful\n";
    std::cout << "Tree 1: ";
    testTree.ProcessInOrder(printKey);
    std::cout << std::endl;

    std::cout << "Tree 2: ";
    testTree2.ProcessInOrder(printKey);

    std::cout << std::endl;
}
