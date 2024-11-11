#include "Examenes.h"

void Examenes::agregar_examen(const std::string & nombre_alumno, const int & nota)
{
    if (notas_por_alumno.find(nombre_alumno) == notas_por_alumno.end())
    {
        // if not registered, it should be added
        notas_por_alumno[nombre_alumno] = nota;
    }
}