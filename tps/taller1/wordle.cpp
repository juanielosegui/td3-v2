#include "funciones.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main(){

    vector<string> listado = cargar_listado("/workspaces/taller1/listado.txt");

    // elijo palabra secreta
    srand(time(0));
    int randIndex = rand() % listado.size();
    string palabra_secreta = listado[randIndex];

    cout << "¡Bienvenido a Wordle!" << endl;
    cout << "Prueba escribiendo una palabra: " << endl; 

    int intentos = 5;
    while(intentos != 0){
        // init intento 
        string intento;
        cin >> intento;

        bool test = intento_valido(intento, palabra_secreta, listado);
        if(test == false){
            cout << "Tu intento no es valido. Recorda que tenes que probar con palabras del diccionario." << endl;
            cin >> intento;
            test = intento_valido(intento, palabra_secreta, listado);
        }

        vector<EstadoLetra> respuesta = evaluar_intento(intento, palabra_secreta);
        string respuesta_string = respuesta_en_string(respuesta);

        cout << respuesta_string << endl;

        if(respuesta_string == "+++++"){
            cout << "Correcto, adivinaste la palabra!" << endl;
            break;
        }

        intentos--;
    }

    if(intentos == 0){
        cout << "Perdiste! La palabra secreta era:" << palabra_secreta << endl;
    }

    return 0;
}