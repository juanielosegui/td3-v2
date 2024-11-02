#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <vector>
#include <string>
#include <iostream>
#include <numeric>
using namespace std;

// 3)
bool todos_positivos(const vector<int> & vec);
bool no_contiene_equis(const vector<char> & str);

// 6)
void sumar_n(vector<int> & ls, const int & n);
int suma_y_reset(vector<int> & v);

// 8)
int sumar_hasta_mitad(const vector<int> & v);

// 12)
bool es_palindromo(const vector<char> & s);
bool es_palindromo2(const vector<char> & s);

// 13)
void invertir_rango(vector<int> & v, const int & i, const int & j);

// 14)
int contar_iguales(const vector<int> & v1, const vector<int> & v2);

// 15)
void sumar_vector_a(vector<int> & v, vector<int> w, const int & k);
void sumar_vector_b(vector<int> & v, vector<int> w);
void sumar_vector_c(vector<int> & v, vector<int> w);
void sumar_vector_d(vector<int> & v, vector<int> w);


#endif // FUNCIONES_H