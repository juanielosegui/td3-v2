#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

// auxiliary functions
void merge1(const std::vector<int> & v1, const std::vector<int> & v2, std::vector<int> & res);
std::vector<int> merge2(const std::vector<int> & v1, const std::vector<int> & v2);
std::vector<int> mergeSort(std::vector<int> & v, int d, int h);
void mergeCount(const std::vector<int> & v1, const std::vector<int> & v2, std::vector<int> & res, int & swapCount);

int dividirMod(std::vector<int> & v, const int & d, const int & h);

void printVec(const std::vector<int> & v);

// 1)
void selection_sort(std::vector<int> & v);
void insertion_sort(std::vector<int> & v);

// 2)
void mergesortMod1(std::vector<int> & v, const int & d, const int & h);
int mergesortMod2(std::vector<int> & v, const int & d, const int & h);

// 3)
std::vector<int> merge_lots(std::vector<std::vector<int>> & vs);

// 4)
void quicksortMod(std::vector<int> & v, const int & d, const int & h);


#endif