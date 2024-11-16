// This is the header of the object "Palabras".

#include <string>
#include <vector>

class Palabras
{
    public:
        //  constructor
        Palabras();

        //  observers
        bool contiene(const std::string & p) const;

        //  modifiers
        void agregar_palabras(const std::vector<std::string> & ps);
        void borrar_palabra(const std::string & p);

        //  otras operaciones
        int contar_vocales() const;

    private:
        std::vector<std::string> _palabras;
};