#include "Palabras.h"

//  Declaration of interface
Palabras::Palabras()
{
    //  initialize vector of Palabras as empty
    _palabras = {};
}

bool Palabras::contiene(const std::string & p) const
{
    for (int i = 0; i < _palabras.size(); i++)
    {
        if(_palabras[i] == p) return true;
    }
    return false;
}

void Palabras::agregar_palabras(const std::vector<std::string> & ps)
{
    //  iterate over ps and add them to _palabras
    for (int i = 0; i < ps.size(); i++)
    {
        _palabras.push_back(ps[i]);
    }
}

void Palabras::borrar_palabra(const std::string & p)
{
    //  if p is found in _palabras, take it out
    for (auto it = _palabras.begin(); it != _palabras.end(); it++)
    {
        if(*it == p) _palabras.erase(it);
    }   
}

int Palabras::contar_vocales() const
{
    int ctr = 0;
    //  iterate over words
    for (int i = 0; i < _palabras.size(); i++)
    {
        //  iterate over chars in words
        for (int j = 0; j < _palabras[j].size(); j++)
        {
            //  if char is a vowel
            if(_palabras[i][j] == 'a' || _palabras[i][j] == 'e' || _palabras[i][j] == 'i' || _palabras[i][j] == 'o' || _palabras[i][j] == 'u')
            {
                ctr++;
            }
        }
    }
    return ctr;   
}