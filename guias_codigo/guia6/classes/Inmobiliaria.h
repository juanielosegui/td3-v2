// This is the header of the object "Inmobiliaria".
#include <map>
#include <set>
#include <string>
class Inmobiliaria
{
    public:
        /* ... */
        std::set<std::string> casas() const;
        bool esta_disponible() const;
        void cambiar_a_no_disponible(const std::string & direccion);
        // PRE: la casa 'direccion' ya se encuentra en el
        // sistema y está disponible.
        /* ... */
    private:
        std::set<std::string> casas_disponibles;
        std::set<std::string> casas_no_disponibles;
        std::map<std::string, bool> casas_todas;
};