// testTree3.cpp - Unit test for Binary Search Tree constructors (Date txt file).
// Results: March data (Failed)
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

void testDateFile(void);

std::ostream& operator<<(std::ostream& out, const Date& d);

int main()
{
    testDateFile();
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

void testDateFile(void)
{
    std::ifstream inFile("./data/test.csv");
    if(!inFile)
        exit(-1);
    std::string input;
    BST<Date> testTree;

    inFile.ignore(256, '\n');      //get rid of first line (header);
    while(getline(inFile, input, ' '))
    {
        testTree.AddLeaf(input);
        inFile.ignore(256, '\n');
    }
    std::cout << "Tree 1: ";
    testTree.ProcessInOrder(printKey);
    std::cout << std::endl;

    BST<Date> testTree2;
    testTree2 = testTree;
    std::cout << std::endl;

    Date deleteDate("02/07/2015");
    Date deleteDate2("15/09/2015");
    testTree2.DeleteNode(deleteDate);
    testTree2.DeleteNode(deleteDate2);

    std::cout << "Deleted 02/07/2015 & 15/09/2015 from tree 2 after copy, If different, deep copy successful\n";
    std::cout << "Tree 1: ";
    testTree.ProcessInOrder(printKey);

    std::cout << "Tree 2: ";
    testTree2.ProcessInOrder(printKey);
    std::cout << std::endl;
}
