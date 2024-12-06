#include <iostream>

#include <map>
#include <set>
#include <list>
#include <vector>

//  Problema 1
//      a)
std::vector<int> calcular_votos_por_candidato(const std::vector<int> & votos)
{
    /*
    Buscar el maximo identificador del candidato
          votos = {0, 2, 1, 2, 1, 0, 3, 0, 2}
              Candidato 0: tres votos
              Candidato 1: dos votos
              Candidato 2: dos votos
              Candidato 3: un voto
    */
    
    //  Declaracion: O(1)
    int maximo = votos[0];
    int i = 0;
    //  Buscar maximo: O(V)
    while (i < votos.size())
    {
        //  Comparacion: O(1)
        if(votos[i] >= maximo)
        {
            //  Declaracion: O(1)
            maximo = votos[i];
        }
        //  Incrementar: O(1)
        i++;
    }

    /*
    Con cuatro candidatos:
        conteo = {0, 0, 0, 0}

    Si en el vector de votos hay tres 2, quiere decir que es
        tres votos para el candidato 2...
            conteo = {0, 0, 3, 0}
    Se incremento la posicion 2 (porque es el candidato 2)
        tres voto porque se encontraron tres votos en el vector
        votos.    
    */

    //  Declaracion: O(C) porque se recorren todas las posiciones
    std::vector<int> conteo(maximo + 1, 0);
    int j = 0;
    //  Analizar los votos: O(V)
    while (j < votos.size())
    {
        //  Incremento: O(1)
        conteo[j]++;
    }
    
    //  Return: O(1)
    return conteo;
    
/*
    Complejidad:
        O(1) + O(V) x [O(1) + O(1) + O(1)] + O(C) + O(V) x [O(1)] + O(1) =
        O(V) x O(1) + O(C) + O(V) x O(1) =
        O(V) + O(C) + O(V) =
        O(V) + O(C) =
        O(V+C)
*/  
}

std::list<std::list<int>> calcular_resultados(const std::vector<int> & votos_por_candidato, const int & V)
{
    //  TODO: completarrrrr
}

struct Nodo
{
    char op;
    int valor;
    Nodo* izq;
    Nodo* der;
};

void colapsar_multiplicaciones(Nodo *raiz)
{
    //  Reemplaza todo nodo de multiplicación del arbol por una hoja conteniendo el
    //      resultado de calcular ese producto. Borra los nodos excedentes del árbol.

    //  Caso base: arbol vacio
    if(raiz == nullptr) return;

    //  Llamar recursivamente
    colapsar_multiplicaciones(raiz->izq);
    colapsar_multiplicaciones(raiz->der);

    //  Si es una multiplicacion
    if(raiz->op == 'x')
    {
        bool hijoIZQ_OK = raiz->izq != nullptr;
        bool hijoDER_OK = raiz->der != nullptr;

        //  Si no tiene hijo izquierdo, pisar el valor del padre con el del hijo derecho
        if(!hijoIZQ_OK && hijoDER_OK)
        {
            raiz->valor = raiz->der->valor;
            //  Borrar nodos excedentes
            delete raiz->der;
            raiz->der = nullptr;
        }

        //  Si no tiene hijo derecho, pisar el valor del padre con el del hijo izquierdo
        else if(hijoIZQ_OK && !hijoDER_OK)
        {
            //  Operacion
            raiz->valor = raiz->izq->valor;
            //  Borrar nodos excedentes
            delete raiz->izq;
            raiz->izq = nullptr;
        }
        
        //  Si tiene dos hijos, reemplazar al padre por el producto de los dos
        else if(hijoIZQ_OK && hijoDER_OK)
        {
            //  Operacion
            raiz->valor = raiz->izq->valor * raiz->der->valor;
            
            //  Borrar nodos excedentes
            delete raiz->izq;
            delete raiz->der;
            raiz->izq = nullptr;
            raiz->der= nullptr;
        }

        raiz->op = '\0';
    }
}

//  Estas dos funciones son auxiliares
//  No importa la implementacion
void borrar(Nodo *raiz) { return; }
int evaluar(Nodo *raiz) { return 0; }

int evaluar_y_simplificar(Nodo *raiz)
{
    //  Devuelve el resultado de evaluar la expresión del árbol raiz, y
    //      simpliﬁca el árbol reemplazando los nodos de operación cuyo
    //      resultado sea igual a 0 por hojas con valor igual a 0.

    //  Caso base: arbol vacio
    if(raiz == nullptr) return -1;

    //  TODO: llamar recursivamente a un ABB es O(n)?
    //  Llamar recursivamente
    evaluar_y_simplificar(raiz->izq);
    evaluar_y_simplificar(raiz->der);

    //  Si una operacion da como resultado cero en el padre, se puede simplificar
    if(evaluar(raiz) == 0)
    {
        //  Sobreescribir el raiz->valor por el 0
        raiz->valor = 0;

        //  Se simplifica borrando los nodos hijos
        //  Asumiendo que hace delete raiz->der y raiz->nullptr 
        borrar(raiz->izq);
        borrar(raiz->der);
    } else {
        //  Si la operacion no da cero, se sobreescribe raiz->valor por el valor
        //      calculado de sus hijos
        raiz->valor = evaluar(raiz);
    }

    return raiz->valor;
}

