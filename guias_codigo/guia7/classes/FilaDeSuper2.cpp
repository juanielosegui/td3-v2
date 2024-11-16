#include "FilaDeSuper2.h"

// Declaration of interface

FilaDeSuper2::FilaDeSuper2(const int & cantidad_cajas)
{
    //  Set _cajas size
    std::vector<bool>_cajas(cantidad_cajas, false);
    for (int i = 0; i < cantidad_cajas; i++)
    {
            _disponibles.push(i);
    }
}
//  O(n)

int FilaDeSuper2::cantidad_esperando() const
{
    return _fila_de_espera.size();
}
//  O(1)

std::string FilaDeSuper2::siguiente() const
{
    return _fila_de_espera.front();
}
//  O(1)

bool FilaDeSuper2::esta_ocupada(const int & caja) const
{
    //  base case: out of range (could be a precondition)
    if(caja >= _cajas.size()) return true;
    
    return _cajas[caja];
}
// O(1)

void FilaDeSuper2::llega_persona(const std::string & dni)
{
    //  dni is valid if it's just numbers
    _fila_de_espera.push(dni);
}
//  O(1)

void FilaDeSuper2::atender_siguiente(const int & caja)
{
    //  remove next customer
    _fila_de_espera.pop();

    //  NOTE: caja has to be smaller than _cajas.size()
    //  sets to true. could still blow up. don't type in weird shit
    _cajas[caja] = true;

    // Remove caja from _disponibles
    if (!_disponibles.empty() && _disponibles.front() == caja) _disponibles.pop();
}
//  O(1)

void FilaDeSuper2::liberar_caja(const int & caja)
{
    //  NOTE: caja has to be smaller than _cajas.size()
    _cajas[caja] = false;

    //  add this caja to _disponibles
    _disponibles.push(caja);
}

//  New operation
int FilaDeSuper2::siguiente_caja_disponible() const
{
    return _disponibles.front();
}
//  O(1)