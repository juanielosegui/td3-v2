#pragma once

#include <string>
#include <set>
#include <map>
#include <vector>

#include "resaltador.h"
// Incluya aquí los headers que necesite

using namespace std;

	
class EditorSintaxis {
	public:
		// Constructores
		
		// Constructor de texto vacío
		EditorSintaxis();
		
		// Método estático auxiliar para construir Editor de forma conveniente
		// en base a un string con las palabras a agregar
		static EditorSintaxis con_texto(const string& texto);

		/// Observadores
		// O(1)
		int longitud() const;

		// PRE: 0 <= pos < longitud() 
		// O(1)
		const string& palabra_en(int pos) const;		

		// Devuelve el resaltador en uso
		// O(1)
		const Resaltador & resaltador() const;

		/// Modificadores
		// PRE: archivo_texto es un nombre de archivo existente
		// POST: reemplaza el texto actual con el nuevo y aplica la sintaxis actual
		void cargar_texto(const string& archivo_texto);

		// PRE: el archivo de sintaxis debe existir y ser valido
		// POST: carga la nueva sintaxis y la aplica al texto actual
		void cargar_sintaxis(const string& archivo_sintaxis);

		// PRE: 0 <= pos <= longitud()
		// POST: alarga en 1 longitud(), ubicando en [pos] la nueva palabra y moviendo todas las posteriores
		void insertar_palabra(const string& palabra, int pos);

		// PRE: 0 <= pos < longitud()
		// POST: acorta en uno longitud(), quitando la palabra ubicada en [pos]
		void borrar_palabra(int pos);

		// PRE: true
		// POST: Devuelve el conjunto de posiciones de todas las palabras de [categoría]
		// O(log(C))
		const set<int> & posiciones_de_categoria(const string & categoria) const;

	private:
		vector<string> _texto_partido;
		map<string, set<int>> _pos_misma_categoria;
		Resaltador _resaltador_actual;

};
/*
Invariante castellano:
- Si una palabra en _texto_partido es resaltable, su posicion debe encontrarse en el valor de _pos_misma_categoria de su 
categoria y viceversa
- Toda clave de _pos_misma_categoria tiene que ser una categoria en el resaltador y a la inversa

Invariante formal:
    rep(e:estr) ≡ 
	(∀ i:int)((0<= i < |e._texto_partido| ∧ esResaltable(e._resaltador_actual, e._texto_partido[i])) ⟺ i ∈ e._pos_misma_categoria[categoriaDePalabra(e._resaltador_actual, e._texto_partido[i])])
	∧ (∀ s:string)(s ∈ claves(e._pos_misma_categoria) ⟺ s ∈ categorias(e._resaltador_actual) ) 

*/
