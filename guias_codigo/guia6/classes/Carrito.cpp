#include "Carrito.h"

// Declaration of interface
Carrito::Carrito(const int & peso_maximo)
{
    _peso_maximo = peso_maximo;
}

float Carrito::peso_disponible() const
{
    int used_weight = 0;

    // Find amt of used weight
    for(auto it = _pesos_items.begin(); it != _pesos_items.end(); it++)
    {
        used_weight += it->second;
    }

    // calculate unused weight
    return (_peso_maximo - used_weight);
}

bool Carrito::buscar_item(const std::string & nombre) const
{
    // look for item in list
    for (int i = 0; i < _items.size(); i++)
    {
        if(_items[i] == nombre) return true;
    }
    return false;
}

float Carrito::peso_de_item(const std::string & nombre) const
{
    // look for item in weight list
    for (auto it = _pesos_items.begin(); it != _pesos_items.end(); it++)
    {
        if(it->first == nombre) return it->second;
    }

    // not found
    return -1;
}

int Carrito::precio_de_item(const std::string & nombre) const
{
    // look for item in price list
    for (auto it = _precios_por_item.begin(); it != _precios_por_item.end(); it++)
    {
        if(it->first == nombre) return it->second;
    }

    // not found
    return 0;
}

void Carrito::borrar_item(const std::string & nombre)
{
    // delete from maps
    for(auto it = _pesos_items.begin(); it != _pesos_items.end(); it++)
    {
        if(it->first == nombre) it = _pesos_items.erase(it);
    }

    for(auto it = _precios_por_item.begin(); it != _precios_por_item.end(); it++)
    {
        if(it->first == nombre) it = _precios_por_item.erase(it);
    }

    // delete from list
    for(auto it = _items.begin(); it != _items.end(); it++)
    {
        if(*it == nombre) _items.erase(it);
    }
}

void Carrito::agregar_item(const std::string & nombre, const int & peso, const float & precio)
{
    _items.push_back(nombre);
    _pesos_items[nombre] = peso;
    _precios_por_item[nombre] = precio;
}