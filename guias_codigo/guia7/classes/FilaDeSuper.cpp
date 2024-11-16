#include "FilaDeSuper.h"

// Declaration of interface

FilaDeSuper::FilaDeSuper()
{
    _caja_uno_ocupada, _caja_dos_ocupada = false;
}
//  O(1)

int FilaDeSuper::cantidad_esperando() const
{
    return _fila_de_espera.size();
}
//  O(1)

std::string FilaDeSuper::siguiente() const
{
    return _fila_de_espera.front();
}
//  O(1)

bool FilaDeSuper::esta_ocupada(const int & caja) const
{
    //  No other caja values are possible whatsoever
    if(caja == 1) return _caja_uno_ocupada;
    else return _caja_dos_ocupada;
}
//  O(1)

void FilaDeSuper::llega_persona(const std::string & dni)
{
    //  dni is valid if it's just numbers
    _fila_de_espera.push(dni);
}
//  O(1)

void FilaDeSuper::atender_siguiente(const int & caja)
{
    //  remove next customer
    _fila_de_espera.pop();

    //  No other caja values are possible whatsoever
    if(caja == 1) _caja_uno_ocupada = true;
    if(caja == 2) _caja_dos_ocupada = true;
}
//  O(1)

void FilaDeSuper::liberar_caja(const int & caja)
{
    //  No other caja values are possible whatsoever
    if(caja == 1) _caja_uno_ocupada = false;
    if(caja == 2) _caja_dos_ocupada = false;
}
//  O(1)