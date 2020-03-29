// BinaryTreeAlgs.cpp : This file contains the 'main' function. Program execution begins and ends there.
// I'll skip questions with all those inorder, preorder, postorder traversals (depth first)
// will implement only level order that I prefer for visual tree presentation

#include <iostream>
#include "BinarySearchTree.cpp"

int main()
{
    std::cout << "Hello World!\n";
    BST mytree(5);
    mytree.insert(10);
    mytree.insert(3);
    mytree.insert(18);
    mytree.insert(8);
    std::cout << "min value in mytree is " << mytree.getMinValue() << std::endl;
    std::cout << "only leaf nodes:" << std::endl;
    mytree.printLeafNodes();
    std::cout << "all tree in level:" << std::endl;
    mytree.printLevelOrder();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
