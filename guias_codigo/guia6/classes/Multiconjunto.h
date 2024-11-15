// This is the header of the object "Multiconjunto".
#include <string>
#include <vector>

class Multiconjunto
{
    public:
        // Constructor
        Multiconjunto(std::vector<int> elems, int c);

        // Observers
        int cardinal() const;
        int contar_apariciones(const int & e) const;
        int cantidad_elementos_distintos() const;

        // Modifiers
        void agregar(const int & e);
        void quitar(const int & e);
    
    private:
        int _cantidad_distintos;
        std::vector<int> _elementos;
};