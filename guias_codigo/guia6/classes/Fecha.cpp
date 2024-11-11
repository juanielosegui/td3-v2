#include "Fecha.h"

// Declaration of interface
Fecha::Fecha(const int & dia, const int & mes, const int & anio)
{
    _dia = dia;
    _mes = mes;
    _anio = anio;

    if (mes < 1 || mes > 12)
    {
        throw std::invalid_argument("Mes invalido. Debe estar entre 1 y 12.");
    }
    
    if (dia < 1 || dia > 31)
    {
        throw std::invalid_argument("Dia invalido. Debe estar entre 1 y 31.");
    }
    
    if (anio < 0)
    {
        throw std::invalid_argument("Anio invalido. Debe ser un valor positivo.");
    }
}

void Fecha::avanzar_dia()
{
    // assuming every month has 31 days
    _dia++;
    if(_dia > 31)
    {
        _dia = _dia-31;
        _mes++;
    }

    if(_mes > 12)
    {
        _mes = _mes - 12;
        _anio++;
    }
}

void Fecha::avanzar_n_dias(const int & n)
{
    _dia = _dia + n;
    
    if(_dia > 31)
    {
        _dia = _dia-31;
        _mes++;
    }

    if(_mes > 12)
    {
        _mes = _mes - 12;
        _anio++;
    }
}

int Fecha::dia() const
{
    return _dia;
}

int Fecha::mes() const
{
    return _mes;
}

int Fecha::anio() const
{
    return _anio;
}

bool Fecha::operator==(const Fecha & f) const
{
    if(_dia == f._dia && _mes == f._mes && _anio == f._anio) return true;
    return false;
}