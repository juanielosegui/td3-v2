#include "Reservas.h"

void Reservas::cancelar_reserva(const std::string & nombre)
{
    listado.erase(nombre);
    es_premium.erase(nombre);
}