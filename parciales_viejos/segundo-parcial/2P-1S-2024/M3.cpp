#include <iostream>

#include <map>
#include <set>
#include <list>
#include <vector>

typedef std::string nombre_artista;
typedef std::string nombre_lista;
typedef std::string nombre_cancion;
//  Punto 2
typedef float popularidad_cancion;

struct Cancion
{
    nombre_artista artista;
    nombre_cancion titulo;
    popularidad_cancion popularidad;
    //  Utilizado internamente por estructuras que requieran orden entre los
    //  elementos (como std::set o std::map). Asumir complejidad O(1).
    bool operator<(const Cancion & other) const 
    {
        return this->titulo < other.titulo;
    }
    //  Permite comparar dos canciones mediante "==". Asumir complejidad O(1).
    bool operator==(const Cancion & other) const
    {
        return this->titulo == other.titulo && artista == other.artista;
    }
};

class BibliotecaMusical
{
    public:
        void agregar_cancion(const Cancion & cancion);
        void eliminar_cancion(const Cancion & cancion);
        void crear_lista(nombre_lista lista);
        void agregar_a_lista(nombre_lista lista, const Cancion & cancion);
        void quitar_de_lista(nombre_lista lista, const Cancion & cancion);

        const std::set<Cancion> & canciones_de(nombre_artista artista) const;
        const std::set<nombre_lista> & listas_que_contienen(const Cancion &) const;

        //  2)
        const std::list<Cancion> & mas_populares_de_artista(const nombre_artista & artista) const;
        //  O(log A)
    
    private:
        std::set<Cancion> _canciones;
        std::map<nombre_lista, std::list<Cancion>> _canciones_por_lista;

        // Estructuras auxiliares para mejorar la complejidad de algunas operaciones.
        std::map<nombre_artista, std::set<Cancion>> _canciones_por_artista;
        //  Punto 2
        std::map<nombre_artista, std::list<Cancion>> _canciones_por_artistaMod;
        std::map<Cancion, std::set<nombre_lista>> _listas_por_cancion;
};

//  Nota: puede haber canciones repetidas en las listas de reproduccion.
//      Puede haber canciones que no esten en ninguna lista.

/*

1)
    a)  En _canciones se guardan todas las canciones, sin repetir.
        Se tiene, aparte, que por cada cancion |nombre_artista|, |nombre_cancion| > 0.
        |nombre_lista| > 0, porque no pueden tener un nombre vacio.
        En _canciones_por_lista, el tamanio de la lista asociada es >= 0. Las canciones
            en esa lista estan si o si tambien en _canciones. Como dije antes, pueden estar
            mas de una vez en una lista de reproduccion.
        El conjunto de canciones asociadas a un artista en _canciones_por_artista
            es estrictamente de menor o igual tamanio que _canciones. Ademas, tambien
            todas las canciones de un artista deben estar registradas en _canciones.
        En _listas_por_cancion, las claves (canciones) son valores de _canciones. Se sabe que
            |_listas_por_cancion| = |_canciones|.

*/

void BibliotecaMusical::quitar_de_lista(nombre_lista lista, const Cancion & cancion)
{
    //  Scope para manejar en _canciones_por_lista
    {
        //  Buscar la lista en un map es O(log L)
        auto it = _canciones_por_lista.find(lista);
        //  Comparacion: O(1)
        if(it != _canciones_por_lista.end())
        {
            //  Si encontramos la lista de reproduccion pedida
            //  Declaracion: O(1)
            auto it2 = it->second.begin();
            //  Tenemos que encontrar la cancion ahora con O(P)
            //  Nota: std::list no tiene l.find(...)
            while (it2 != it->second.end())
            {
                //  Comparacion y borrado: O(1)
                if(*it2 == cancion) it->second.erase(it2);
                //  Incrementar: O(1)
                it2++;
            }
        }
    }

    //  Scope para manejar en _listas_por_cancion
    {
        //  Buscar cancion en un map es O(log C)
        auto it = _listas_por_cancion.find(cancion);
        //  Comparacion: O(1)
        if(it != _listas_por_cancion.end())
        {
            //  Si encontramos la cancion pedida
            //  Buscamos si esta asociada a la lista de reproduccion en O(log L)
            auto it2 = it->second.find(lista);
            //  Si la lista esta asociada a esa cancion
            //  Comparacion: O(1)
            if(it2 != it->second.end())
            {
                //  No va a estar mas la lista asociada a esa cancion
                //  Borrado: O(1)
                it->second.erase(it2);
            }
        }
    }

    /*
    b)  Complejidad:
            Scope de _canciones_por_lista:
                O(log L) + O(1) x [ O(1) + O(P)x(O(1)+O(1)) ] =
                O(log L) + O(1) x [ O(1) + O(P)] =
                O(log L) + O(1) x [ O(P)] =
                O(log L) + O(P)
            Scope de _listas_por cancion:
                O(log P) + O(1) x [ O(log L) + O(1) x [ O(1) ] ] =
                O(log P) + O(1) x [ O(log L) + O(1) ] =
                O(log P) + O(1) x [ O(log L) ] =
                O(log P) + O(log L)
            Complejidad total:
                Scope de _canciones_por_lista + Scope de _listas_por cancion =
                O(log L) + O(C) + O(log C)+ O(log L) =
                O(log L) + O(C) + O(log C)
    */
}

const std::list<Cancion> & BibliotecaMusical::mas_populares_de_artista(const nombre_artista & artista) const
{
    static std::list<Cancion> placeholder;
    //  Busqueda en map: O(log A)
    auto it = _canciones_por_artistaMod.find(artista);
    //  Artista encontrado
    //  Comparacion: O(1)
    if(it != _canciones_por_artistaMod.end())
    {
        //  Return: O(1)
        placeholder = it->second;
        return placeholder;
    } else {
        //  Artista no encontrado
        //  Return O(1)
        return placeholder;
    }

    /*
        Complejidad:
            O(log A) + max[ O(1), O(1) ] =
            O(log A) + O(1) =
            O(log A)
    */
}

/*

2)
    a)  Se deberia modificar la variable _canciones_por_artista. En vez de usar un set
            para guardar las canciones de los artistas, se deberia usar una lista que
            este ordenada siempre. Se cumpliria la complejidad de O(log A) porque para
            buscar los valores asociados (canciones) de los artistas en un map es O(log A)
            en peor caso.
            Ademas, se debe buscar una forma de medir la popularidad de las canciones. Para
            la estructura Cancion agregaria un float popularidad_cancion.
    b)  Solo se deberia agregar que la lista asociada a las claves en _canciones_por_artistaMod
            debe estar siempre ordenada. La insercion depende del algoritmo de ordenamiento que
            se use, logicamente usaria el que menor costo temporal tenga.
    d)  Ninguna. Esta operacion no se ve afectada por la nueva estructura de representacion.

*/