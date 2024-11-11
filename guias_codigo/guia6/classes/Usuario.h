// This is the header of the object "Usuario".
#include <string>
#include <set>

class Usuario
{
    public:
        // Constructor
        Usuario(const std::string & nombre, const int & edad);
        
        // Observers
        std::string nombre() const;
        int edad() const;

        // Modifiers
        void agregar_amigo(const std::string & nombre);
        
        // Other ops
        bool es_amigo(const std::string & nombre) const;
        bool es_popular() const;

    private:
        std::string _nombre;
        int _edad;
        std::set<std::string> _amigos;
        bool _es_popular;  
};