#include <string>
#include <map>
#include <list>
#include <set>

typedef int Fecha;
typedef std::string Nombre;

//  El hostel nunca acepta reservas si estas exceden su capacidad de
//      _camas_totales para algún día.

struct Reserva
{
    Fecha desde;
    Fecha hasta;
    int cantidad_camas;
    Nombre huesped;

    // Utilizado internamente por estructuras que requieran orden entre los
    // elementos (como set o map). Asumir complejidad O(1).
    bool operator<(const Reserva& other) const
    {
        return desde < other.desde;
    }
};

class Hostel
{
    public:
        bool reservar(Fecha desde, Fecha hasta, int cantidad_camas, Nombre huesped);

        //  Pre: True
        //  Post: res es la lista de huespedes, en orden decreciente de frecuencia.
        const std::list<Nombre> & huespedes_frecuentes() const;
        //  El método debe devolver la lista completa de huespedes ordenados por frecuencia,
        //      y en caso de empatar, ordenados alfabéticamente por nombre. La complejidad de la
        //      operación debe ser O(1).

    private:
        int _camas_totales;
        std::list<Reserva> _reservas;
        // Estructuras auxiliares para mejorar la complejidad de algunas operaciones.
        std::map<Nombre, std::set<Reserva>> _reservas_por_huesped;
        std::map<Fecha, std::set<Reserva>> _reservas_por_fecha;

        //  Pre: siempre ordenada en orden decreciente
        std::list<Nombre> rankingFrecuentes;
        //  Funcion auxiliar que ordena el ranking cada vez que alguien reserva
        void ordenar_rankingFrecuentes();
};

/*
    1)
        a)  Todas las camas reservadas en _reservas, sumadas, deben ser menores o iguales
                que _camas_totales. Si son menores, hay espacio libre en el hostel. Si
                son iguales, el hostel esta lleno.
            Reserva.desde debe ser menor que Reserva.hasta (pueden ser iguales tambien),
                Reserva.cantidad_camas debe ser mayor o igual a 1, y el Reserva.huesped 
                no puede ser un string vacio.
            _reservas_por_huesped tendra como claves los nombres de los que hicieron la
                reserva (Reserva.huesped) y como valores asociados tendra todos los datos
                de las Reservas.
            _camas_totales ira variando desde cero hasta infinito. Cada vez que se llame a 
                reservar, se le restara cantidad_camas porque es la cantidad que fueron reservadas,
                por lo que ya no estaran disponibles.
            |_reservas| = |_reservas_por_huesped| = |_reservas_por_fecha|
*/

//      b)
bool Hostel::reservar(Fecha desde, Fecha hasta, int cantidad_camas, Nombre huesped)
{
    //  COMMENT: Caso base: no hay camas disponibles
    if(cantidad_camas > _camas_totales) return false;
    //  Caso base: entrada es despues de la salida
    //      (asumiendo que se puede entrar y salir el mismo dia del hostel)
    if(desde > hasta) return false;
    //  Caso base: nombre vacio
    if(huesped.size() == 0) return false;
    return true;

//  TODO: resolver... esta dificil este che...
}

/*
    2)
        a,b)    Agregaria la lista rankingFrecuentes, que tiene la misma cantidad
                    de entradas que _reservas_por_huesped. Esta lista tiene la precondicion
                    de que esta ordenada siempre. Se puede hacer esto con una funcion auxiliar.
                    Tiene los huespedes en orden decreciente de dias en total que han reservado.
        c)      FIXME: Uy la puta madre. No se la verdad, a que se refiere? Creo que ya lo dije antes.
*/

const std::list<Nombre> & Hostel::huespedes_frecuentes() const
{
    //  Return y acceso a variables: O(1)
    return rankingFrecuentes;
}