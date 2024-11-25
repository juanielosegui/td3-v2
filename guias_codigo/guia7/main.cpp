#include <iostream>
#include "funciones.h"

/*
    g++ main.cpp funciones.cpp -o main
    ./main
*/

int main()
{
    std::cout << "-----------------------" << std::endl;
    std::cout << "  6): Verify Max Heap  " << std::endl;
    std::cout << "-----------------------" << std::endl;

    BST* root1 = new BST{};
    std::cout << "Test Case 1: empty tree       -   " << (maxHeap_OK(root1) ? "PASSED" : "FAILED") << std::endl;
    //  Expected Output: PASSED (an empty tree is a valid max-heap)
    
    BST* root2 = new BST{10, nullptr, nullptr};
    std::cout << "Test Case 2: single node      -   " << (maxHeap_OK(root2) ? "PASSED" : "FAILED") << std::endl;
    //  Expected Output: PASSED (a single node is a valid max-heap)

    BST* node1 = new BST{5, nullptr, nullptr};
    BST* node2 = new BST{7, nullptr, nullptr};
    BST* root3 = new BST{10, node1, node2};
    std::cout << "Test Case 3: valid max heap   -   " << (maxHeap_OK(root3) ? "PASSED" : "FAILED") << std::endl;
    //  Expected Output: PASSED (all parent nodes are greater than or equal to their children)

    BST* node4_1 = new BST{15, nullptr, nullptr};
    BST* node4_2 = new BST{7, nullptr, nullptr};
    BST* root4 = new BST{10, node4_1, node4_2};
    std::cout << "Test Case 4: invalid max heap -   " << (maxHeap_OK(root4) ? "PASSED" : "FAILED") << std::endl;
    //  Expected Output: FAILED (left child is greater than parent)

    BST* node5_1 = new BST{5, nullptr, nullptr};
    BST* node5_2 = new BST{20, nullptr, nullptr};
    BST* root5 = new BST{10, node5_1, node5_2};
    std::cout << "Test Case 5: invalid max heap -   " << (maxHeap_OK(root5) ? "PASSED" : "FAILED") << std::endl;
    //  Expected Output: FAILED (right child is greater than parent)

    return 0;
}