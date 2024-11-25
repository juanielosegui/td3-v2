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
