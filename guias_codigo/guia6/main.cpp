#include <iostream>
#include "classes/Libro.h"
#include "classes/Fecha.h"
#include "classes/Usuario.h"
#include "classes/Multiconjunto.h"
#include "classes/Carrito.h"

int main()
{
    std::cout << "----------------------------" << std::endl;
    std::cout << "         Ejercicio 7        " << std::endl;
    std::cout << "----------------------------" << std::endl;

    std::cout << "a) Crear una fecha" << std::endl;

    Fecha nac(23, 6, 2004);
    std::cout << nac.dia() << std::endl;
    std::cout << nac.mes() << std::endl;
    std::cout << nac.anio() << std::endl;
    std::cout << std::endl;

    nac.avanzar_n_dias(365);
    std::cout << nac.dia() << std::endl;
    std::cout << nac.mes() << std::endl;
    std::cout << nac.anio() << std::endl;
    return 0;
}