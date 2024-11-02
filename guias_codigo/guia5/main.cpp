#include "funciones.h"

// compile running the first command:
// g++ main.cpp funciones.cpp -o main
// ./main.exe

int main()
{
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "                   1)                  " << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    
    std::cout << "Selection sort:" << std::endl;
    std::cout << "Vector: [38, 27, 43, 10]" << std::endl;
    std::vector<int> v1 = {38, 27, 43, 10};
    selection_sort(v1);
    std::cout << "Sorted vector: ";
    printVec(v1);
    std::cout << std::endl;

    std::cout << "Insertion sort:" << std::endl;
    std::cout << "Vector: [35, 17, 77, 8]" << std::endl;
    std::vector<int> v2 = {35, 17, 77, 8};
    insertion_sort(v2);
    std::cout << "Sorted vector: ";
    printVec(v2);
    std::cout << std::endl;

    std::cout << "---------------------------------------" << std::endl;
    std::cout << "                   2)                  " << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    
    std::cout << "a)" << std::endl;
    std::cout << "Merge Sort Mod 1:" << std::endl;
    std::cout << "Vector: [38, 12, 76, 44, 27, 43, 10]" << std::endl;
    std::vector<int> v3 = {38, 12, 76, 44, 27, 43, 10};
    mergesortMod1(v3, 0, v3.size());
    std::cout << "Sorted vector: ";
    printVec(v3);
    std::cout << std::endl;

    std::cout << "b)" << std::endl;
    std::cout << "Merge Sort Mod 2:" << std::endl;
    std::cout << "Vector: [38, 12, 76, 44, 27, 43, 10]" << std::endl;
    std::vector<int> v4 = {38, 12, 76, 44, 27, 43, 10};
    int res = mergesortMod2(v4, 0, v4.size());
    std::cout << "Sorted vector: ";
    printVec(v4);
    std::cout << "Number of swaps: " << res << std::endl;
    std::cout << std::endl;

    std::cout << "---------------------------------------" << std::endl;
    std::cout << "                   3)                  " << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    std::cout << "Merge Lots:" << std::endl;
    std::cout << "Vector: [[18, 12], [6, 44], [20, 3, 10]]" << std::endl;
    std::vector<std::vector<int>> v5 = {{18, 12}, {6, 44}, {20, 3, 10}};
    std::cout << "Sorted vector: ";
    std::vector<int> res2 = merge_lots(v5);
    printVec(res2);
    std::cout << std::endl;

    return 0;
}