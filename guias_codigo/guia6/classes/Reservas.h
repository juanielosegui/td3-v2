// This is the correct header of the object "Reservas".
#include <set>
#include <map>
#include <string>

class Reservas
{
    public:
        /* ... */
        void cancelar_reserva(const std::string & nombre);
        /* ... */

    private:
        int cantidad_premium;
        std::set<std::string> listado;
        std::map<std::string, bool> es_premium;
};