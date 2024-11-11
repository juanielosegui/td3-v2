// This is the header of the object "Examenes".
#include <string>
#include <set>
#include <map>

class Examenes
{
    public:
        /* ... */
        void agregar_examen(const std::string & nombre_alumno, const int & nota);
        // PRE: 0 <= nota <= 10 y nombre_alumno no fue ingresado
        // al sistema previamente.
        /* ... */

    private:
        std::set<std::string> alumnos_aprobados;
        std::map<std::string, int> notas_por_alumno;
};