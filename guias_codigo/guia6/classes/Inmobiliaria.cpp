#include "Inmobiliaria.h"

void Inmobiliaria::cambiar_a_no_disponible(const std::string & direccion)
{
    // if direccion is found in map, set it to false
    if(casas_todas.find(direccion) != casas_todas.end()) casas_todas[direccion] = false;
}