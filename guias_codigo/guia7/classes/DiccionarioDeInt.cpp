#include "DiccionarioDeInt.h"

// Declaration of interface
template <typename T>
bool DiccionarioDeInt<T>::esta_definida(const int & clave) const
{
    nodo* act = raiz;

    while(act != nullptr)
    {
        //  RECALL: BSTs have the following property:
        //          left child is smaller, right child is greater
        
        //  if clave is found
        if(clave == act->clave) return true;

        //  if clave is smaller than act->clave
        else if(clave < act->clave) act = act->hijo_izq;

        //  if clave is greater than act->clave
        else if(clave > act->clave) act = act->hijo_der;
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
    
    nodo* act = raiz;

    while (1 > 0)
    {
        if(clave < act->clave)
        {
            //  no left child
            if(act->hijo_izq == nullptr)
            {
                act->hijo_izq = new nodo(clave, valor);
                return;
            }

            //  update left child
            act = act->hijo_izq;
        }

        if(clave > act->clave)
        {
            if(act->hijo_der == nullptr)
            {
                act->hijo_der = new nodo(clave, valor);
            }
            act = act->hijo_der;
        }

        //  update value
        if(clave == act->clave)
        {
            act->valor = valor;
            return;
        }
    }
}

template <typename T>
std::list<int> DiccionarioDeInt<T>::aplanar_ordenado_v1() const
{
    std::list<int> res;
    std::stack<nodo> stack;

    nodo* act = raiz;
    
    while (act != nullptr || !stack.empty())
    {
        //  inorder method
        while (act != nullptr)
        {
            //  find leftest node
            stack.push(act);
            act = act->hijo_izq;
        }

        // leftest node is first value in stack
        act = stack.top();
        stack.pop();
        res.push_back(act->clave);

        // repeat with right node
        act = act->hijo_der;
    }
    return res; 
}

//  TODO: fuck this function. this is hard as shit
template <typename T>
std::list<int> DiccionarioDeInt<T>::aplanar_ordenado_v2() const
{
    //  base case: empty node
    if(raiz == nullptr) return {};
    
    //  how the FUCK can I do DnC
}