 #include "resaltador.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Resaltador::Resaltador() {
    this-> _categoria_de_palabra = {};
    this->_color_categoria = {};
    this->_categorias = {};
    this->_palabras = {};
    this->_colores = {};
    this->_palabras_resaltables = {};
}

bool Resaltador::es_resaltable(const string &palabra) const {
    if(this->_categoria_de_palabra.find(palabra) != this->_categoria_de_palabra.end()){
        return true;
    }
    return false;
}
    

string Resaltador::categoria_de_palabra(const string& palabra) const {
    if (es_resaltable(palabra)) {
        auto it = this->_categoria_de_palabra.find(palabra);
        return it->second;
    }
    return "";
}

int Resaltador::color_categoria(const string& categoria) const {
    auto it = this->_color_categoria.find(categoria);
    if (it != this->_color_categoria.end()) {
        return it->second; 
    }
    return 0;//cambiar xq 0 es un color
}

void Resaltador::cargar_sintaxis(const string &archivo_sintaxis){
    ifstream archivo(archivo_sintaxis);
    if (archivo.good() == false) {
        cout << "No se pudo abrir el archivo " << archivo_sintaxis << endl;
        exit(1);
    }
    if (!archivo.is_open()){
        cout << "Error: No se pudo abrir el archivo " << archivo_sintaxis << endl;
        return;
    }

    int cantidad_categorias;
    archivo >> cantidad_categorias;
    archivo.ignore();

    _categorias.clear();
    _palabras_resaltables.clear();
    if (cantidad_categorias == 0){
        return; 
    }

    for (int i = 0; i < cantidad_categorias; ++i){ // O(C)
        string categoria;
        int color, cantidad_palabras;

        archivo >> categoria >> color >> cantidad_palabras;
        archivo.ignore();
        definir_categoria(categoria, color);   // O(log(c))

        vector<string> palabras;
        for (int j = 0; j < cantidad_palabras; ++j) {
            string palabra;
            archivo >> palabra;
            asignar_categoria(palabra, categoria); 
            
        }

        archivo.ignore();  
        
    }

    archivo.close();
}

void Resaltador::definir_categoria(const string & categoria, int color) {
    this->_categorias.insert(categoria);
    this->_colores.insert(color);
    this->_color_categoria[categoria]=color;

} 

void Resaltador::borrar_categoria(const string &categoria_borrar) {
    for (auto it = _categoria_de_palabra.begin(); it != _categoria_de_palabra.end();) {
        if (it->second == categoria_borrar) {
            auto borrar_it = it++; // el iterador avanza antes de borrar
            desasignar_palabra(borrar_it->first);
        } else {
            ++it; // si no se borra nada avanza
        }
    }

    // Eliminar la categoría del set _categorias
    this->_colores.erase(color_categoria(categoria_borrar));  
    this->_color_categoria.erase(categoria_borrar); 
    _categorias.erase(categoria_borrar);
}

void Resaltador::asignar_categoria(const string& palabra, const string &categoria) {   
    this->_categoria_de_palabra[palabra]= categoria;  
    this->_palabras_resaltables.insert(palabra);
}

void Resaltador::desasignar_palabra(const string& palabra) {
    this->_categoria_de_palabra.erase(palabra);
    this->_palabras_resaltables.erase(palabra); 
}

const set<string> & Resaltador::categorias() const{
    return this->_categorias; //O(1)
}

const set<string> &Resaltador::palabras_resaltables() const
{
    return _palabras_resaltables; // O(1)
}

int Resaltador::color_resaltado(const string&palabra) const {
   	string categoria = this->categoria_de_palabra(palabra);
    return this->color_categoria(categoria);
}