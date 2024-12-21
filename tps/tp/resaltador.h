#pragma once

#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;
 
class Resaltador {
    public:
        // Constructores

        // Crea un resaltador con una sintaxis vacía (sin categorías ni palabras)
        Resaltador();

        // Observadores
        // O(log P)
        bool es_resaltable(const string & palabra) const;

        // PRE: es_resaltable(palabra)
        // O(log P)
        string categoria_de_palabra(const string & palabra) const; 

        // PRE: categoría \in categorias()
        // O(log C)
        int color_categoria(const string & categoria) const;

        // Modificadores        
        
        // PRE: la sintaxis de archivo_sintaxis es correcta
        // POST: reemplaza cualquier sintaxis previamente definida con la de archivo_sintaxis
        void cargar_sintaxis(const string & archivo_sintaxis);

        // PRE: categoria \not \in categorias()
        // O(log C)
        void definir_categoria(const string & categoria, int color);

        // PRE: categoria \in categorias()
        void borrar_categoria(const string & categoria);

        // PRE: categoria \in categorias()
        // POST: es_resaltable(palabra) \land categoria = categoria_de_palabra(palabra)
        void asignar_categoria(const string & palabra, const string& categoria);

        // Quita una palabra del resaltador
        // O(log C + log P)
        void desasignar_palabra(const string & palabra);
        // Otras operaciones
        // Devuelve el conjunto de categorías definidas
        // O(1)
        const set<string> & categorias() const;

        // Devuelve el conjunto total de palabras para las cuales es_resaltable es true
        // O(1)
        const set<string> & palabras_resaltables() const;

        // PRE: es_resaltable(palabra)
        // O(log P + log C)
        int color_resaltado(const string & palabra) const;
        
    private:
        map<string, string> _categoria_de_palabra; //clave palabra, categoria lo asociado, palabra->first y categoria->second;
        map<string, int> _color_categoria; //clave categoria, color asociado, color->second y categoria->first;
        set<string> _categorias;
        set<string> _palabras;
        set<int> _colores;
        set<string> _palabras_resaltables;
};
/*
    Invariante en castellano:
        - Todos los valores en _categoría_de_palabra pertenecen a _categorías. 
        - Toda clave en _categoría_de_palabra tiene que ser una palabra en _palabras_resaltables y a la inversa. 
        - Toda clave en _color_categoria tiene que estar en _categorías y viceversa. 
        - Todo valor en _color_categoria tiene que estar en _colores y viceversa. 
        - No hay categoría vacia("") en _categorías. 
        - Hay tantas categorías en categorías como colores en _colores. 
        - La cantidad de categorías en categorías debe ser menor o igual a la cantidad de palabras en palabras_resaltables. 
        - No hay una palabra vacia ("") en palabras.    
        - Toda palabra en palabras_resaltables tiene que pertenecer a palabras. 
        - Todo color en _colores es un número entre 1 y 16. (En una parte de la consigna decia de 0 a 15 y en otra 1 a 16 asi que nos quedamos con la segunda)

  Invariante formal:
        rep(e:estr) ≡ 
            (∀s:string)(s ∈ e._categorias⇒ s!= "" ∧ s != " ")
            ∧  (∀s:string)(s ∈ e._palabras⇒ s != "" ∧ s != " " )
            ∧  (∀s:string)(s ∈ e._categorias⇒ s != "")
            ∧  (∀i:int)(i ∈ e._colores ⇒ 1<=i<=16 )
            ∧  (∀ palabra: string)(palabra ∈ claves(e._categoría_de_palabra) ⇒ e._categoría_de_palabra[palabra] ∈ e._categorias)
            ∧  (∀ color: int)(color ∈ e._colores ⟺ esValorEnDicc(color, e._color_categoria))
            ∧  (∀palabra:string)(palabra ∈ claves(e._categoria_palabra)) ⟺ palabra ∈ e._palabras_resaltables)
            ∧  (∀ categoria:string)(categoria ∈ claves(e._color_categoria)) ⟺ categoria ∈ e._categorias)
            ∧  |e._colores|=|e.categorias|
            ∧  |e._palabras_resaltables|=|e.categorias|
            ∧  (∀palabra:string)(palabra ∈ e._palabras_resaltables ⇒ palabra ∈ e._palabras )

            esValorEnDicc(valor: int, dicc: map<string, int>) ≡ (∃clave:string)(clave ∈ claves(dicc) ∧ dicc[clave]=valor)


*/