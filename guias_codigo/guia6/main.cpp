#include <iostream>
#include "classes/Libro.h"
#include "classes/Fecha.h"
#include "classes/Usuario.h"
#include "classes/Multiconjunto.h"
#include "classes/Carrito.h"

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 7832a6f (Avance guia6 mas comentarios y recomendaciones)
/*
    g++ main.cpp classes/Fecha.cpp classes/Libro.cpp classes/Usuario.cpp classes/Carrito.cpp -o main
    ./main
*/

<<<<<<< HEAD
=======
>>>>>>> 34bee65 (Modifiqué la guía 1)
=======
>>>>>>> 7832a6f (Avance guia6 mas comentarios y recomendaciones)
int main()
{
    std::cout << "----------------------------" << std::endl;
    std::cout << "         Ejercicio 7        " << std::endl;
    std::cout << "----------------------------" << std::endl;

    std::cout << "a) Crear una fecha" << std::endl;

<<<<<<< HEAD
<<<<<<< HEAD
    //  init Fecha
=======
>>>>>>> 34bee65 (Modifiqué la guía 1)
=======
    //  init Fecha
>>>>>>> 7832a6f (Avance guia6 mas comentarios y recomendaciones)
    Fecha nac(23, 6, 2004);
    std::cout << nac.dia() << std::endl;
    std::cout << nac.mes() << std::endl;
    std::cout << nac.anio() << std::endl;
    std::cout << std::endl;

    nac.avanzar_n_dias(365);
    std::cout << nac.dia() << std::endl;
    std::cout << nac.mes() << std::endl;
    std::cout << nac.anio() << std::endl;
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 7832a6f (Avance guia6 mas comentarios y recomendaciones)

    std::cout << std::endl;

    std::cout << "b) Crear un usuario" << std::endl;

    //  init User
    Usuario user("Juani Elosegui", 20);

    //  add friends
    user.agregar_amigo("Felipe Caracoix");
    user.agregar_amigo("Julian Barcia");
    user.agregar_amigo("Gonzalo Peral");
    user.agregar_amigo("Nazaret Seranusoglu");
    user.agregar_amigo("Ramiro Garnero");

    //  check if the following names are friends
    std::cout << user.es_amigo("Gonzalo Peral") << std::endl;   // true (1)
    std::cout << user.es_amigo("Gaston Zarate") << std::endl;   // false (0)

    std::cout << std::endl;

    //  TODO: Fix issue with constructor
    std::cout << "c) Crear un multiconjunto" << std::endl;
    
    //  init Multiconjunto
    std::vector<int> elems = {2, 65, 2, 3, 8, 8, 7, 65, 0};
    //  Multiconjunto m(elems, 6);

    std::cout << std::endl;

    std::cout << "d) Crear un carrito" << std::endl;

    //  init Carrito
    Carrito c(10);

    //  let's say I cooked pizza. here are some ingredients
    c.agregar_item("Flour", 1, 1000);
    c.agregar_item("Sauce", 1, 1000);
    c.agregar_item("Garlic", 1, 500);
    c.agregar_item("Cheese", 1, 2000);

    //  ask for available weight
    std::cout << c.peso_disponible() << std::endl;  // 6kg

    //  ask for total price
    std::cout << c.monto_total() << std::endl;  // $4.500

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 34bee65 (Modifiqué la guía 1)
=======

>>>>>>> 7832a6f (Avance guia6 mas comentarios y recomendaciones)
=======
>>>>>>> cf105b4 (Added changes)
    return 0;
}