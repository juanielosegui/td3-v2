//  This is the header of the object "FilaDeSuper".

#include <queue>
#include <string>
#include <vector>

#ifndef FILADESUPER2_H
#define FILADESUPER2_H

class FilaDeSuper2
{
    public:
        FilaDeSuper2(const int & cantidad_cajas);
        //  POST: La FilaDeSuper es vacía y sus cajas están libres.
        int cantidad_esperando() const;
        std::string siguiente() const;
        bool esta_ocupada(const int & caja) const;
        //  PRE: caja es igual a 1 o 2.
        void llega_persona(const std::string & dni);
        //  PRE: dni es un dni válido
        //  POST: El dni se agrega al final de la fila
        void atender_siguiente(const int & caja);
        //  PRE: caja es igual a 1 o 2, cantidad_esperando() no es 0 y esta_ocupada(caja) es false.
        //  POST: Se quita de la fila a la siguiente() persona que estaba esperando.
        //  Y esta_ocupada(caja) se vuelve true.
        void liberar_caja(const int & caja);
        //  PRE: caja es igual a 1 o 2, esta_ocupada(caja) es true.
        //  POST: esta_ocupada(caja) se vuelve false.

        //  Added new operation
        int siguiente_caja_disponible() const;
    
    private:
        std::queue<std::string> _fila_de_espera;
        //  Modified variables
        std::vector<bool> _cajas;
        mutable std::queue<int> _disponibles;
};

#endif