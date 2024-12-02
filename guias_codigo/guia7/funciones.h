#ifndef FUNCIONES_H
#define FUNCIONES_H

//  6)
struct BST
{
    int val;
    BST* left;
    BST* right;
};

bool maxHeap_OK(const BST* raiz);

//  9)
struct BST_2
{
    int val;
    int child_amt;
    BST_2* left;
    BST_2* right;
};

BST_2* insertar(BST_2* raiz, const int & elem);
//  Requirement: O(h), h being the height of the BST.
int contarMenoresA(const BST_2* raiz, const int & valor);
//  Requirement: O(log n), n being the total amount of elements.

#endif