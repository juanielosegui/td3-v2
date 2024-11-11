#include "Fecha.h"

// Declaration of interface
Fecha::Fecha(const int & dia, const int & mes, const int & anio)
{
    if(_dia > 0 && _dia <= 31)
    {
        _dia = dia;
    }

    if(_mes > 0 && _mes <= 12)
    {
        _mes = mes;
    }

    if(_anio >= 0)
    {
        _anio = anio;
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