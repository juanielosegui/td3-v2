#include "editor_texto.h"

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

EditorSintaxis::EditorSintaxis() {
	this-> _texto_partido = {};
	this-> _pos_misma_categoria = {};
	this-> _resaltador_actual = {};
}


EditorSintaxis EditorSintaxis::con_texto(const string& texto) {
    EditorSintaxis editor;

    //  Variable auxiliar para almacenar la palabra actual
    string palabra;
    for (char c : texto) {
        if (isspace(c)) {   //  Si encontramos un espacio u otro separador
            if (!palabra.empty()) {
                editor._texto_partido.push_back(palabra);   //  Añadimos la palabra al vector
                palabra.clear();    //  Limpiamos para la siguiente palabra
            }
        } else {
            palabra += c;   //  Construimos la palabra
        }
    }

    //  Añadimos la última palabra si no quedó vacía
    if (!palabra.empty()) {
        editor._texto_partido.push_back(palabra);
    }

    return editor;  //  Devolvemos el objeto inicializado
}

int EditorSintaxis::longitud() const {
	return this->_texto_partido.size(); //  (1)
}

const string& EditorSintaxis::palabra_en(int pos) const {
	return this->_texto_partido[pos];   //  (1)
}

const Resaltador & EditorSintaxis::resaltador() const {
	return this->_resaltador_actual;    //  (1)
}


void EditorSintaxis::cargar_texto(const string& archivo_texto) {
    this->_texto_partido.clear();   //  O(N) – Limpiar el vector (en caso de haber datos previos)
    this->_pos_misma_categoria.clear(); //  


    ifstream infile(archivo_texto); //  O(1) – Abrir el archivo
    if (!infile.is_open()) {    //  O(1) – Verificar si el archivo se abrió correctamente
        cerr << "Error al abrir el archivo." << endl;   //  Mensaje de error si no se puede abrir el archivo
        return; //  Salir de la función en caso de error al abrir el archivo
    }

    string palabra; //  O(1) – Declaración de la variable que almacenará las palabras
    while (infile >> palabra) { //  O(1) – Leer una palabra del archivo a la vez
        if (!palabra.empty()) { //  O(1) – Verificar que la palabra no esté vacía
            this->_texto_partido.push_back(palabra);    //  O(1) amortizado – Añadir la palabra al vector
        }
    }

    infile.close(); //  O(1) – Cerrar el archivo
}




void EditorSintaxis::cargar_sintaxis(const string &archivo_sintaxis) {
    this->_pos_misma_categoria.clear(); 
    this->_resaltador_actual.cargar_sintaxis(archivo_sintaxis); 
    for (int i = 0; i < this->_texto_partido.size(); ++i) { 
        if(this->_resaltador_actual.es_resaltable(palabra_en(i))){
            string categoria = this->_resaltador_actual.categoria_de_palabra(this->_texto_partido[i]); 
            if(this->_pos_misma_categoria[categoria]== set<int>{} ){
                set<int> pos= {i};
                this->_pos_misma_categoria[categoria]= pos;

            }else{
                set<int> pos= this->_pos_misma_categoria[categoria];
                pos.insert(i);
                this->_pos_misma_categoria[categoria]=pos;
            }
        }
    }   
}


void EditorSintaxis::insertar_palabra(const string& palabra, int pos) {
	this->_texto_partido.push_back("");
	for(int i = this->_texto_partido.size()-1; i>pos; i--){
		this->_texto_partido[i] = this->_texto_partido[i-1];
        if(this->_resaltador_actual.es_resaltable(_texto_partido[i])){
            string categoria = this->_resaltador_actual.categoria_de_palabra(_texto_partido[i]); 
            set<int> s_pos= posiciones_de_categoria(categoria);
            s_pos.insert(i);
            s_pos.erase(i-1);
            this->_pos_misma_categoria[categoria]=s_pos;
        }
	}
	this->_texto_partido[pos] = palabra;
    if(this->_resaltador_actual.es_resaltable(palabra)){
        string categoria = this->_resaltador_actual.categoria_de_palabra(palabra); 
        if(this->_pos_misma_categoria[categoria]== set<int>{} ){
            set<int> s_pos= {pos};
            this->_pos_misma_categoria[categoria]= s_pos;

        }else{
            set<int> s_pos= this->posiciones_de_categoria(categoria);
            s_pos.insert(pos);
            this->_pos_misma_categoria[categoria]=s_pos;
        }
    }
}

void EditorSintaxis::borrar_palabra(int pos) {
    //  Validar que la posición sea válida
    if (pos < 0 || pos >= _texto_partido.size()) {
        throw std::out_of_range("Posición inválida para borrar palabra");
    }

    //  Obtener la palabra en la posición a borrar
    string palabra_a_borrar = _texto_partido[pos];

    //  Eliminar la palabra del vector _texto_partido
    _texto_partido.erase(_texto_partido.begin() + pos);

    //  Ajustar las posiciones en el mapa de categorías
    for (auto& [categoria, posiciones] : _pos_misma_categoria) {
        //  Si la categoría no tiene la posición, no hacemos nada
        if (posiciones.count(pos)) {
            posiciones.erase(pos);  //  Eliminar la posición borrada
        }

        //  Crear un nuevo conjunto con posiciones ajustadas
        set<int> nuevas_posiciones;
        for (int p : posiciones) {
            if (p > pos) {
                nuevas_posiciones.insert(p - 1);    //  Ajustar las posiciones posteriores
            } else {
                nuevas_posiciones.insert(p);    //  Mantener las posiciones anteriores
            }
        }

        //  Actualizar las posiciones de la categoría
        posiciones = nuevas_posiciones;
    }
}