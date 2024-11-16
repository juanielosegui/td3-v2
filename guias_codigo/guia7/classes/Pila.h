//  This is the header of the object "Pila".

#ifndef PILA_H
#define PILA_H

#include <list>

template <typename T>

class Pila
{
    public:
        Pila();
        //  POST: La pila está vacía.
        bool es_vacia() const;
        const T & tope() const;
        //  PRE: es_vacia() da falso.
        void apilar(const T & elem);
        //  PRE: Verdadero
        //  POST: Se agrega a la pila el valor elem, por lo tanto tope() es igual a elem.
        void desapilar();
        //  PRE: es_vacia() da falso.
        //  POST: elimina de la pila el elemento devuelto por tope()

    private:
        std::list<T> _elementos;
};

#endif