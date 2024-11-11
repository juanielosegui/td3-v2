// This is the header of the object "Libro".
#include <string>

class Libro
{
    public:
        // Constructor
        Libro(std::string titulo, std::string autor, int cantidad_paginas);
        
        // Observers
        int paginas_totales() const;
        int pagina_actual() const;
                
        // Modifiers
        void avanzar_paginas(const int & n);
        void saltar_a_pagina(const int & k);
        
        // Other ops
        float porcentaje_leido() const;
        bool finalizado() const;

    private:
        std::string _titulo;
        std::string _autor;
        int _paginas_totales;
        int _pagina_actual;
};