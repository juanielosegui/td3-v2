// This is the declaration of the object "Multiconjunto".
#include <string>
#include <vector>
#include <bits/algorithmfwd.h>

class Multiconjunto
{
    public:
        // Constructor
        Multiconjunto();

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

// Declaration of interface
Multiconjunto::Multiconjunto()
{
    _cantidad_distintos = 0;
    _elementos = {};
}

int Multiconjunto::cardinal() const
{
    int ctr = 0;
    for (int i = 0; i < _elementos.size(); i++) { ctr++; }
    return ctr;
}

int Multiconjunto::contar_apariciones(const int & e) const
{
    int ctr = 0;
    for (int i = 0; i < _elementos.size(); i++)
    {
        if(_elementos[i] == e) ctr++;
    }
    return ctr;
}

int Multiconjunto::cantidad_elementos_distintos() const
{
    return _cantidad_distintos;
}

void Multiconjunto::agregar(const int & e)
{
    _elementos.push_back(e);

    // check if it is already in vec
    bool found = false;
    for (int i = 0; i < _elementos.size()-1; i++)
    {
        if(_elementos[i] == e)
        {
            found = true;
            break;
        }
    }
    
    if(!found) _cantidad_distintos++;
}

void Multiconjunto::quitar(const int & e)
{
    // check if it is already in vec
    auto it = std::find(_elementos.begin(), _elementos.end(), e);
    if(it != _elementos.end()) _elementos.erase(it);
}