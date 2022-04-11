// testTree2.cpp - Unit test for Binary Search Tree constructors (Date txt file).
// Results: Passed
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

void testDateTxtFile(void);

std::ostream& operator<<(std::ostream& out, const Date& d);

int main()
{
    testDateTxtFile();
    return(0);
}


std::ostream& operator<<(std::ostream&, const Date& d)
{
    return(std::cout << d.GetDateString());
}

void printKey(Date key)
{
    std::cout << key << ", ";
}


void testDateTxtFile(void)
{
    std::ifstream inFile("./data/dateTestData.txt");
    if(!inFile)
        exit(-1);
    std::string input;

    BST<Date> testTree;

    while(getline(inFile, input, ','))
    {
        testTree.AddLeaf(input);
    }

    std::cout << "Tree 1: ";
    testTree.ProcessInOrder(printKey);
    std::cout << std::endl;

    BST<Date> testTree2;
    testTree2 = testTree;
    std::cout << std::endl;

    Date deleteDate("15/03/2020");
    Date deleteDate2("15/10/2020");
    testTree2.DeleteNode(deleteDate);
    testTree2.DeleteNode(deleteDate2);


    std::cout << "Deleted 15/03/2020 & 15/10/2020 from tree 2 after copy, If different, deep copy successful\n";
    std::cout << "Tree 1: ";
    testTree.ProcessInOrder(printKey);
    std::cout << std::endl;

    std::cout << "Tree 2: ";
    testTree2.ProcessInOrder(printKey);

    std::cout << std::endl;
}
