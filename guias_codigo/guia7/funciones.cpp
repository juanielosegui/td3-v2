#include "funciones.h"

//  ----------------------------------------------------
//  6)
bool maxHeap_OK(const BST* raiz)
{
    //  base case: empty BST or leaf
    if (raiz == nullptr) return true;
    if (raiz->left == nullptr && raiz->right == nullptr) return true;

    //  verify max heap properties for left child
    bool leftOK = true;
    if (raiz->left != nullptr)
    {
        leftOK = (raiz->val >= raiz->left->val) && maxHeap_OK(raiz->left);
    }

    //  verify max heap properties for right child
    bool rightOK = true;
    if (raiz->right != nullptr)
    {
        rightOK = (raiz->val >= raiz->right->val) && maxHeap_OK(raiz->right);
    }

    return leftOK && rightOK;
}

//  ----------------------------------------------------
//  7)
BST_2* insertar(BST_2* raiz, const int & elem)
{
    //  if BST is empty, create the node
    if(raiz == nullptr)
    {
        //  save previous child_amt val
        int aux = raiz->child_amt;
        return new BST_2(
            {
                elem,
                aux+1,
                nullptr,
                nullptr
            }
        );
    }

    //  if elem is smaller, iterate over right child
    if(elem < raiz->val) raiz->right = insertar(raiz->right, elem);

    //  if elem is greater, iterate over left child
    if(elem > raiz->val) raiz->left = insertar(raiz->left, elem);

    //  return BST
    return raiz;
}
//  Worst case: O(h) in insertion of a node in BSTs.

int contarMenoresA(const BST_2* raiz, const int & valor)
{
    // empty BST
    if(raiz == nullptr) return 0;
    
    // if valor is smaller than val, we're on the "right" track
    if(raiz->val < valor)
    {
        if(raiz->right != nullptr) int rightChildAmt = raiz->right->child_amt + 1;
        else int rightChildAmt = 0;
    } else {
        //  only the right child could have smaller values
        return contarMenoresA(raiz->right, valor);
    }

    //  I don't even know what the fuck I'm doing.
    //  Why on EARTH child_amt is even relevant? like I could just count them manually
    //  Fuck this topic though.
}