#include <iostream>

class Fecha
{
    public:
        Fecha(int dia, int mes, int anio);
        void avanzar_dia();
        void avanzar_n_dias(int n);
        int dia() const;
        int mes() const;
        int anio() const;
        bool operator == (const Fecha & f)const;

    private:
        int _dia;
        int _mes;
        int _anio;
};

Fecha::Fecha(int dia, int mes, int anio)
{
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

//  Literalmente es un ejercicio que hice de la guia.
//      No sean malos, ponganse a pensar en algun ejercicio nuevo!

int main()
{
    //  Prueba (1): Crear una fecha e imprimirla
    Fecha fecha1(28, 2, 2024);  //  Año bisiesto
    std::cout << "Fecha inicial: " << fecha1.dia() << "/" << fecha1.mes() << "/" << fecha1.anio() << std::endl;

    //  Prueba (2): Avanzar un día en año bisiesto
    fecha1.avanzar_dia();
    std::cout << "Avanzar un día: " << fecha1.dia() << "/" << fecha1.mes() << "/" << fecha1.anio() << std::endl;

    //  Prueba (3): Avanzar un día y pasar al mes siguiente
    fecha1.avanzar_dia();
    std::cout << "Avanzar un día (al siguiente mes): " << fecha1.dia() << "/" << fecha1.mes() << "/" << fecha1.anio() << std::endl;

    //  Prueba (4): Avanzar días y cruzar a un nuevo año
    Fecha fecha2(31, 12, 2023);
    std::cout << "\nFecha inicial: " << fecha2.dia() << "/" << fecha2.mes() << "/" << fecha2.anio() << std::endl;
    fecha2.avanzar_dia();
    std::cout << "Avanzar un día (cambiar de año): " << fecha2.dia() << "/" << fecha2.mes() << "/" << fecha2.anio() << std::endl;

    //  Prueba (5): Avanzar varios días en un mes
    Fecha fecha3(25, 7, 2024);
    fecha3.avanzar_n_dias(10);
    std::cout << "\nAvanzar 10 días: " << fecha3.dia() << "/" << fecha3.mes() << "/" << fecha3.anio() << std::endl;

    //  Prueba (6): Verificar igualdad de fechas
    Fecha fecha4(10, 10, 2024);
    Fecha fecha5(10, 10, 2024);
    if (fecha4 == fecha5) {
        std::cout << "\nLas fechas son iguales." << std::endl;
    } else {
        std::cout << "\nLas fechas son distintas." << std::endl;
    }

    return 0;
}
