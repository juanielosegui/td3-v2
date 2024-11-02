// This is the declaration of the object "Usuario".
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

// Declaration of interface
Usuario::Usuario(const std::string & nombre, const int & edad)
{
    _nombre = nombre;
    _edad = edad;
    _amigos = std::set<std::string> {};
    _es_popular = false; 
}

std::string Usuario::nombre() const
{
    return _nombre;
}

int Usuario::edad() const
{
    return _edad;
}

void Usuario::agregar_amigo(const std::string & nombre)
{
    _amigos.insert(nombre);
    if(_amigos.size() >= 10)
    {
        _es_popular = true;
    }
}

bool Usuario::es_amigo(const std::string & nombre) const
{
    return (_amigos.find(nombre) != _amigos.end());
}

bool Usuario::es_popular() const
{
    if(_amigos.size() >= 10) return true;
    return false;
}