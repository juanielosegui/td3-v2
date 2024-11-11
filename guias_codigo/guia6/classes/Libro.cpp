#include "Libro.h"

// Declaration of interface
Libro::Libro(std::string titulo, std::string autor, int cantidad_paginas)
{
    // Definition of private vars
    _titulo = titulo;
    _autor = autor;
    _paginas_totales = cantidad_paginas;
    _pagina_actual = 0;
}

int Libro::paginas_totales() const
{
    return _paginas_totales;
}

int Libro::pagina_actual() const
{
    return _pagina_actual;
}

float Libro::porcentaje_leido() const
{
    return (_pagina_actual / _paginas_totales) * 100;
}

void Libro::avanzar_paginas(const int & n)
{
    if(n + _pagina_actual <= _paginas_totales)
    {
        _pagina_actual + n; 
    }
}

void Libro::saltar_a_pagina(const int & k)
{
    if(k >= 0 && k <= _paginas_totales)
    {
        _pagina_actual = k;
    }
}

bool Libro::finalizado() const
{
    if(_pagina_actual == _paginas_totales)
    {
        return false;
    } else {
        return true;
    }
}