#include "funciones.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

vector<string> cargar_listado(const string & nombre_archivo){
    // store every word in a vector
    vector<string> lista_palabras;
    string palabra;

    // open up 'listado'
    ifstream infile (nombre_archivo);


    // base: could not open file
    if (!infile){
        cout << "No se pudo abrir el archivo: '" << nombre_archivo << "'" << endl;
        exit(1);
    }

    // until .txt is over
    while(getline(infile, palabra)){
        lista_palabras.push_back(palabra);
    }

    infile.close();

    return lista_palabras;
}

bool intento_valido(const string & intento, const string & palabra_secreta, const vector<string> &listado){
    // init bool value if try is in the list
    bool a = 0;
    for (int i = 0; i < listado.size(); i++){
        if (listado[i] == intento){
            a = true;
            break;
        } else {
            a = false;
        }
    }

    // if try has proper length or word is in the list
    if (intento.length() == palabra_secreta.size() && a == true) {
        return a = true;
    }
    return a = false;
}

vector<EstadoLetra> evaluar_intento(const string & intento, const string & palabra_secreta){
    // init answer vector
    vector<EstadoLetra> respuesta = {EstadoLetra::NoPresente, EstadoLetra::NoPresente, EstadoLetra::NoPresente, EstadoLetra::NoPresente, EstadoLetra::NoPresente};

    // base - guess is longer or shorter than expected
    if(intento.size() != palabra_secreta.size()){
        cout << "Error! Your guess must contain 5 letters." << endl;
        return {};
    }

    // find every nailed letter
    for(int i=0; i<intento.size(); i++){
        if(intento[i] == palabra_secreta[i]){
            respuesta[i] = EstadoLetra::LugarCorrecto;
        }
    }

    // if letter not in palabra_secreta
    for(int j=0; j<intento.size(); j++){
        if(respuesta[j] != EstadoLetra::LugarCorrecto){
            if(palabra_secreta.find(intento[j]) != string::npos){
                respuesta[j] = EstadoLetra::LugarIncorrecto;
            }
        }
    }
    return respuesta;
}

string respuesta_en_string(const vector<EstadoLetra> & respuesta){
    // init respuesta
    string res;

    // init vector iterator
    int i = 0;

    // run over every element
    while(i<respuesta.size()){
        // replacing on every iteration
        if(respuesta[i] == EstadoLetra::LugarCorrecto){
            res.append("+");
        }
        if(respuesta[i] == EstadoLetra::LugarIncorrecto){
            res.append("-");
        }
        if(respuesta[i] == EstadoLetra::NoPresente){
            res.append("X");
        }
        i++;
    }
    return res;
}