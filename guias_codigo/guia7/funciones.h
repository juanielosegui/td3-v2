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

#endif