//  This is the header of the object "DiccionarioDeInt".

#ifndef DICCIONARIODEINT_H
#define DICCIONARIODEINT_H

#include <list>
#include <stack>

template <typename T>
class DiccionarioDeInt
{
    public:
        DiccionarioDeInt();
        bool esta_definida(const int & clave) const;
        const T & obtener_valor(const int & clave) const;
        void definir(const int & clave, const T & valor);
        void borrar(const int & clave);
        ~DiccionarioDeInt();

        //  added operation
        std::list<int> aplanar_ordenado_v1() const;
        std::list<int> aplanar_ordenado_v2() const;

    private:
        struct nodo
        {
            nodo(int c, T v) : clave(c), valor(v), hijo_izq(nullptr), hijo_der(nullptr) {}
            int clave;
            T valor;
            nodo* hijo_izq;
            nodo* hijo_der;
        };
        nodo* raiz;
};

//  This is a BST

#endif