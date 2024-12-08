#include "Diccionario2.h"

// Declaration of interface
template <typename T1, typename T2>
Diccionario2<T1, T2>::Diccionario2() = default;
//  O(1)

template <typename T1, typename T2>
bool Diccionario2<T1, T2>::esta_definida(const T1 & clave) const
{
    for (auto it = _claves_valores.begin(); it != _claves_valores.end(); it++)
    {
        //  if clave is found. pray this works
        if(it->first == clave) return true;
    }
    return false;
}
//  O(n)

template <typename T1, typename T2>
const T2 & Diccionario2<T1, T2>::obtener_valor(const T1 & clave) const
{
    //  clave is in _claves_valores
    for (auto it = _claves_valores.begin(); it != _claves_valores.end(); it++)
    {
        // if key is found
        if(it->first == clave)
        {
            return it->second;
        }
    }
    //  it should not get to this case. otherwise the compiler
    //  won't stop bitching
    throw std::out_of_range("Key not found!");
}
//  O(n). Clave could be the very last key in _claves_valores. 

template <typename T1, typename T2>
void Diccionario2<T1, T2>::definir(const T1 & clave, const T2 & valor)
{
    _claves_valores.push_back(std::make_pair(clave, valor));
    _iterador_al_ultimo = _claves_valores.end();
}
// O(1)

template <typename T1, typename T2>
void Diccionario2<T1, T2>::borrar(const T1 & clave)
{
    //  find target key
    for (auto it = _claves_valores.begin(); it != _claves_valores.end(); it++)
    {
        if(it->first == clave)
        {
            //  wipe key and value
            _claves_valores.erase(it);
            return;
        }
    }
}
//  O(n). Clave could be the very last element in _claves_valores.

template <typename T1, typename T2>
void Diccionario2<T1, T2>::actualizar_ultimo(const T2 & valor)
{
    //  _iterador_al_ultimo->second = valor;
}

// O(1)