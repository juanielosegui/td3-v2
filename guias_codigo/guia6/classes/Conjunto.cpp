#include "Conjunto.h"

void Conjunto::agregar(const int & e)
{
    bool found = false;
    for (int i = 0; i < elementos.size(); i++)
    {
        if(elementos[i] == e)
        {
            bool found = true;
            break;
        }
    }
    if(!found) elementos.push_back(e);
}
