//  This is the header of the object "Diccionario".

#include <list>
#include <utility>  // Cambiado de <pair> a <utility>
#include <stdexcept>

#ifndef DICCIONARIO2_H
#define DICCIONARIO2_H

template <typename T1, typename T2>
// Asumir que el tipo T1 tiene operador de igualdad ==
class Diccionario2
{
    public:
        Diccionario2();
        //  POST: El diccionario está vacío.
        bool esta_definida(const T1 & clave) const;
        //  PRE: Verdadero
        const T2 & obtener_valor(const T1 & clave) const;
        //  PRE: esta_definida(clave)
        void definir(const T1 & clave, const T2 & valor);
        //  PRE: Verdadero
        //  POST: esta_definida(clave) es verdadero y obtener_valor(clave)
        //  es igual a valor. El resto del diccionario se mantiene igual.
        void borrar(const T1 & clave);
        //  PRE: esta_definida(clave)
        //  POST: esta_definida(clave) es falso. El resto del diccionario
        //  se mantiene igual.

        //  added new operation
        void actualizar_ultimo(const T2 & valor);
    
    private:
        std::list<std::pair<T1,T2>> _claves_valores;
        //  new var
        typename std::list<std::pair<T1,T2>>::iterator _iterador_al_ultimo;
};

#endif