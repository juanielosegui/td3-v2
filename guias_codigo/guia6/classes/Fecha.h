// This is the header of the object "Fecha".
#include <string>
#include <stdexcept>

class Fecha
{
    public:
        // Constructor
        Fecha(const int & dia, const int & mes, const int & anio);

        // Modifiers
        void avanzar_dia();
        void avanzar_n_dias(const int & n);

        // Observers
        int dia() const;
        int mes() const;
        int anio() const;

        // Other ops
        bool operator==(const Fecha & f) const;

    private:
        int _dia;
        int _mes;
        int _anio;
};