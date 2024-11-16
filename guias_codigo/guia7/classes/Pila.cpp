#include "Pila.h"

// Declaration of interface

template <typename T>
Pila<T>::Pila() {}  //  No need to initialize manually the list
//  O(1)

template <typename T>
bool Pila<T>::es_vacia() const
{
    //  returns true if _elementos is empty
    return _elementos.empty();
}
//  O(1)

template <typename T>
const T & Pila<T>::tope() const
{
    //  returns first element
    return _elementos.front();
}
//  O(1)

template <typename T>
void Pila<T>::apilar(const T & elem)
{
    //  puts elem in front of list
    _elementos.push_front(elem);
}
//  O(1)

template <typename T>
void Pila<T>::desapilar()
{
    //  removes first element
    _elementos.pop_front();
}
//  O(1)