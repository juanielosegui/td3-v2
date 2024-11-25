#include "DiccionarioDeInt.h"

// Declaration of interface
template <typename T>
bool DiccionarioDeInt<T>::esta_definida(const int & clave) const
{
    nodo* actual = raiz;

    while(actual != nullptr)
    {
        //  RECALL: BSTs have the following property:
        //          left child is smaller, right child is greater
        
        //  if clave is found
        if(clave == actual->clave) return true;

        //  if clave is smaller than actual->clave
        else if(clave < actual->clave) actual = actual->hijo_izq;

        //  if clave is greater than actual->clave
        else if(clave > actual->clave) actual = actual->hijo_der;
    }

    //  no clave found
    return false;
}

template <typename T>
void DiccionarioDeInt<T>::definir(const int & clave, const T & valor)
{
    //  base case: empty tree
    if(raiz == nullptr)
    {
        new nodo(clave, valor);
        return;
    }
    
    nodo* actual = raiz;

    while (1 > 0)
    {
        if(clave < actual->clave)
        {
            //  no left child
            if(actual->hijo_izq == nullptr)
            {
                actual->hijo_izq = new nodo(clave, valor);
                return;
            }

            //  update left child
            actual = actual->hijo_izq;
        }

        if(clave > actual->clave)
        {
            if(actual->hijo_der == nullptr)
            {
                actual->hijo_der = new nodo(clave, valor);
            }
            actual = actual->hijo_der;
        }

        //  update value
        if(clave == actual->clave)
        {
            actual->valor = valor;
            return;
        }
    }
}
