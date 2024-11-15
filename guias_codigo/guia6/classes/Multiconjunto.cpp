#include "Multiconjunto.h"

// Declaration of interface
<<<<<<< HEAD
<<<<<<< HEAD
Multiconjunto::Multiconjunto(std::vector<int> elems, int c)
{
    _cantidad_distintos = c;
    _elementos = elems;
=======
Multiconjunto::Multiconjunto()
{
    _cantidad_distintos = 0;
    _elementos = {};
>>>>>>> 34bee65 (Modifiqué la guía 1)
=======
Multiconjunto::Multiconjunto(std::vector<int> elems, int c)
{
    _cantidad_distintos = c;
    _elementos = elems;
>>>>>>> 7832a6f (Avance guia6 mas comentarios y recomendaciones)
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

<<<<<<< HEAD
<<<<<<< HEAD
// TODO: fix

void Multiconjunto::quitar(const int & e)
{
    /*
    // check if it is already in vec
    auto it = std::find(_elementos.begin(), _elementos.end(), e);
    if(it != _elementos.end()) _elementos.erase(it);
    */
=======
=======
// TODO: fix

>>>>>>> 7832a6f (Avance guia6 mas comentarios y recomendaciones)
void Multiconjunto::quitar(const int & e)
{
    /*
    // check if it is already in vec
    auto it = std::find(_elementos.begin(), _elementos.end(), e);
    if(it != _elementos.end()) _elementos.erase(it);
<<<<<<< HEAD
>>>>>>> 34bee65 (Modifiqué la guía 1)
=======
    */
>>>>>>> 7832a6f (Avance guia6 mas comentarios y recomendaciones)
}