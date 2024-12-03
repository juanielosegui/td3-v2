#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "trees/BST.h"
#include "trees/BST_2.h"
#include "trees/BST_3.h"

//  6)
bool maxHeap_OK(const BST* raiz);

//  9)
BST_2* insertar(BST_2* raiz, const int & elem);
    //  Requirement: O(h), h being the height of the BST.
int contarMenoresA(const BST_2* raiz, const int & valor);
    //  Requirement: O(log n), n being the total amount of elements.

//  10)
void multiplyBy(BST_3* raiz, const int & k);
    //  Multiplies each value in node by k. 

#endif