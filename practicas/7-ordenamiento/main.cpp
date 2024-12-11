#include <iostream>
#include <vector>


//  ---------------------------------------
//  2) Counting sort de base...

int buscar_maximo(const std::vector<int> & v)
{
    int i = 1;
    int max = v[0];

    while(i < v.size())
    {
        if(v[i] > max) max = v[i];
        i++;
    }
    return max;
}

bool deCuentas(const std::vector<int> & v)
{
    if(v.size() == 0) return false; 
    //  crear vector en O(|v|)
    std::vector<int> ctr(buscar_maximo(v)+1, 0);

    //  iterar sobre v para contar las ocurrencias
    //      en ctr.
    int i = 0;
    while(i < v.size())
    {
        //  aumentar cantidad de ocurrencias
        ctr[v[i]]++;
        i++;
    }

    //  verificar que la cantidad de ocurrencias en v
    //      es congruente con la posicion en ctr.
    //  O(|ctr|)
    int j = 0;
    while(j < ctr.size())
    {
        if(ctr[j] != j) return false;
    }
    return true;
}

//  ---------------------------------------
//  3) 
std::vector<int> masCercanosAE(const std::vector<int> & v, const int & e, const int & k)
{
    //  PRE: k < |v|
    //  Devuelve los k numeros mas cercanos a e
    
    //  Casos base:
    if(v.size() <= 1) return {};

    //  Declaracion de variables
    std::vector<int> res;

    int aux = 0;
    for (int i = 0; i < v.size(); i++)
    {
        //  TODO: completar (algun dia)
    }
    return res;
}
//  ##########################################
//                    EXTRAS:
//  ##########################################

/*
    Ejercicio 1: Verificar si un arreglo está ordenado
        Escribir un programa que determine si una secuencia de enteros v
            está ordenada en orden no decreciente con un tiempo de ejecución
            de peor caso perteneciente a O(|v|).
        Justificar por qué este algoritmo cumple con dicha complejidad.
*/

bool checkNoDecreciente(const std::vector<int> & v)
{
    //  Caso base: v vacio o con un elemento
    if(v.size() <= 1)           //  4ops
    {
        return 1;               //  1op
    }
    
    int i = 0;  //  1op
    while (i < v.size()+1)      //  5ops
    {
        //  Hay dos elementos de forma creciente
        if(v[i] < v[i+1])       //  3ops
        {
            return false;       //  1op
        }
        i = i + 1;              //  2ops
    }
    return true;                //  1op

/*
    Sigue la consigna, tiene una complejidad en
        peor caso de O(|v|).
    
    Complejidad total:
        => O(1) + O(1) + O(|v|) x (O(1)+O(1)) + O(1)
        => O(1) + O(|v|) x O(1) + O(1)
        => O(|v|) x O(1) + O(1)
        => O(|v|) + O(1)
        => O(|v|)
*/
}

/*
    Ejercicio 2: Encontrar el elemento más frecuente
        Dado un arreglo de enteros  v, escribir un programa que determine el
            número que más se repite en  v, con un tiempo de ejecución de peor 
            caso perteneciente a O(∣v∣).
        Nota: Si hay múltiples números con la misma frecuencia, se puede 
            devolver cualquiera.
        Justificar por qué el algoritmo cumple con dicha complejidad.
*/

int masFrecuente(const std::vector<int> & v)
{
    //  Casos base:
    if(v.size() == 0) return -1;
    if(v.size() == 1) return v[0];
    
    //  Implementar un counting sort
    int maxElem = buscar_maximo(v);
    std::vector<int> ctr(maxElem+1, 0);

    int i = 0;
    while (i < v.size())
    {
        ctr[v[i]] = ctr[v[i]] + 1;
        i = i + 1;
    }

    int maxFrecuencia = 0;
    int resultado = -1;
    int j = 0;
    while (j < ctr.size())
    {
        if (ctr[j] > maxFrecuencia)
        {
            maxFrecuencia = ctr[j];
            resultado = j;
        }
        j = j + 1;
    }

/*
    Sigue la consigna, tiene una complejidad en
        peor caso de O(|v|). Usando el counting sort.
*/  

}

int main()
{
    return 0;
}